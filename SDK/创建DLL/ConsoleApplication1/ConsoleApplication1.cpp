#include "stdafx.h"
//循环向a函数每次发送200个字节长度（这个是固定的）的buffer,
//a函数中需要将循环传进来的buffer，组成240字节（也是固定的）的新buffer进行处理，
//在处理的时候每次从新buffer中取两个字节打印
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h>
#include <io.h>
//Log{
#define MAXLOGSIZE 10000000
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
#include <time.h>
#include <sys/timeb.h>
#include <stdarg.h>
char logfilename1[] = "MyLog1.log";
char logfilename2[] = "MyLog2.log";
char logstr[16000];
char datestr[16];
char timestr[16];
char mss[4];
CRITICAL_SECTION cs_log;
FILE *flog;
void Lock(CRITICAL_SECTION *l) {
	EnterCriticalSection(l);
}
void Unlock(CRITICAL_SECTION *l) {
	LeaveCriticalSection(l);
}
void LogV(const char *pszFmt, va_list argp) {
	struct tm tempa = { 0 };
	struct tm *now = &tempa;
	struct timeb tb;

	if (NULL == pszFmt || 0 == pszFmt[0]) return;
	if (-1 == _vsnprintf_s(logstr, ARRSIZE(logstr), pszFmt, argp)) logstr[ARRSIZE(logstr) - 1] = 0;
	ftime(&tb);
	localtime_s(now, &tb.time);
	//now = localtime(&tb.time);
	sprintf_s(datestr, "%04d-%02d-%02d", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
	sprintf_s(timestr, "%02d:%02d:%02d", now->tm_hour, now->tm_min, now->tm_sec);
	sprintf_s(mss, "%03d", tb.millitm);
	printf("%s %s.%s %s", datestr, timestr, mss, logstr);
	fopen_s(&flog,logfilename1, "a" );
	if (NULL != flog) {
		fprintf(flog, "%s %s.%s %s", datestr, timestr, mss, logstr);
		if (ftell(flog) > MAXLOGSIZE) {
			fclose(flog);
			if (rename(logfilename1, logfilename2)) {
				remove(logfilename2);
				rename(logfilename1, logfilename2);
			}
			fopen_s(&flog,logfilename1, "a");
			if (NULL == flog) return;
		}
		fclose(flog);
	}
}
void Log(const char *pszFmt, ...) {
	va_list argp;

	Lock(&cs_log);
	va_start(argp, pszFmt);
	LogV(pszFmt, argp);
	va_end(argp);
	Unlock(&cs_log);
}
//Log}
#define ASIZE    200
#define BSIZE    240
#define CSIZE      2
char Abuf[ASIZE];
char Cbuf[CSIZE];
CRITICAL_SECTION cs_HEX;
CRITICAL_SECTION cs_BBB;
struct FIFO_BUFFER {
	int  head;
	int  tail;
	int  size;
	char data[BSIZE];
} BBB;
int No_Loop = 0;
void HexDump(int cn, char *buf, int len) {
	int i, j, k;
	char binstr[80];

	Lock(&cs_HEX);
	for (i = 0; i < len; i++) {
		if (0 == (i % 16)) {
			sprintf_s(binstr, "%03d %04x -", cn, i);
			sprintf_s(binstr, "%s %02x", binstr, (unsigned char)buf[i]);
		}
		else if (15 == (i % 16)) {
			sprintf_s(binstr, "%s %02x", binstr, (unsigned char)buf[i]);
			sprintf_s(binstr, "%s  ", binstr);
			for (j = i - 15; j <= i; j++) {
				sprintf_s(binstr, "%s%c", binstr, ('!' < buf[j] && buf[j] <= '~') ? buf[j] : '.');
			}
			Log("%s\n", binstr);
		}
		else {
			sprintf_s(binstr, "%s %02x", binstr, (unsigned char)buf[i]);
		}
	}
	if (0 != (i % 16)) {
		k = 16 - (i % 16);
		for (j = 0; j < k; j++) {
			sprintf_s(binstr, "%s   ", binstr);
		}
		sprintf_s(binstr, "%s  ", binstr);
		k = 16 - k;
		for (j = i - k; j < i; j++) {
			sprintf_s(binstr, "%s%c", binstr, ('!' < buf[j] && buf[j] <= '~') ? buf[j] : '.');
		}
		Log("%s\n", binstr);
	}
	Unlock(&cs_HEX);
}
int GetFromRBuf(int cn, CRITICAL_SECTION *cs, FIFO_BUFFER *fbuf, char *buf, int len) {
	int lent, len1, len2;

	lent = 0;
	Lock(cs);
	if (fbuf->size >= len) {
		lent = len;
		if (fbuf->head + lent > BSIZE) {
			len1 = BSIZE - fbuf->head;
			memcpy(buf, fbuf->data + fbuf->head, len1);
			len2 = lent - len1;
			memcpy(buf + len1, fbuf->data, len2);
			fbuf->head = len2;
		}
		else {
			memcpy(buf, fbuf->data + fbuf->head, lent);
			fbuf->head += lent;
		}
		fbuf->size -= lent;
	}
	Unlock(cs);
	return lent;
}
void thdB(void *pcn) {
	char        *recv_buf;
	int          recv_nbytes;
	int          cn;
	int          wc;
	int          pb;

	cn = (int)pcn;
	Log("%03d thdB              thread begin...\n", cn);
	while (1) {
		Sleep(10);
		recv_buf = (char *)Cbuf;
		recv_nbytes = CSIZE;
		wc = 0;
		while (1) {
			pb = GetFromRBuf(cn, &cs_BBB, &BBB, recv_buf, recv_nbytes);
			if (pb) {
				Log("%03d recv %d bytes\n", cn, pb);
				HexDump(cn, recv_buf, pb);
				Sleep(1);
			}
			else {
				Sleep(1000);
			}
			if (No_Loop) break;//
			wc++;
			if (wc > 3600) Log("%03d %d==wc>3600!\n", cn, wc);
		}
		if (No_Loop) break;//
	}
}
int PutToRBuf(int cn, CRITICAL_SECTION *cs, FIFO_BUFFER *fbuf, char *buf, int len) {
	int lent, len1, len2;

	Lock(cs);
	lent = len;
	if (fbuf->size + lent > BSIZE) {
		lent = BSIZE - fbuf->size;
	}
	if (fbuf->tail + lent > BSIZE) {
		len1 = BSIZE - fbuf->tail;
		memcpy(fbuf->data + fbuf->tail, buf, len1);
		len2 = lent - len1;
		memcpy(fbuf->data, buf + len1, len2);
		fbuf->tail = len2;
	}
	else {
		memcpy(fbuf->data + fbuf->tail, buf, lent);
		fbuf->tail += lent;
	}
	fbuf->size += lent;
	Unlock(cs);
	return lent;
}
void thdA(void *pcn) {
	char        *send_buf;
	int          send_nbytes;
	int          cn;
	int          wc;
	int           a;
	int          pa;

	cn = (int)pcn;
	Log("%03d thdA              thread begin...\n", cn);
	a = 0;
	while (1) {
		Sleep(100);
		memset(Abuf, a, ASIZE);
		a = (a + 1) % 256;
		if (16 == a) { No_Loop = 1; break; }//去掉这句可以让程序一直循环直到按Ctrl+C或Ctrl+Break或当前目录下存在文件No_Loop
		send_buf = (char *)Abuf;
		send_nbytes = ASIZE;
		Log("%03d sending %d bytes\n", cn, send_nbytes);
		HexDump(cn, send_buf, send_nbytes);
		wc = 0;
		while (1) {
			pa = PutToRBuf(cn, &cs_BBB, &BBB, send_buf, send_nbytes);
			Log("%03d sent %d bytes\n", cn, pa);
			HexDump(cn, send_buf, pa);
			send_buf += pa;
			send_nbytes -= pa;
			if (send_nbytes <= 0) break;//
			Sleep(1000);
			if (No_Loop) break;//
			wc++;
			if (wc > 3600) Log("%03d %d==wc>3600!\n", cn, wc);
		}
		if (No_Loop) break;//
	}
}
int main() {
	InitializeCriticalSection(&cs_log);
	Log("Start===========================================================\n");
	InitializeCriticalSection(&cs_HEX);
	InitializeCriticalSection(&cs_BBB);

	BBB.head = 0;
	BBB.tail = 0;
	BBB.size = 0;

	_beginthread((void(__cdecl *)(void *))thdA, 0, (void *)1);
	_beginthread((void(__cdecl *)(void *))thdB, 0, (void *)2);

	if (!_access("No_Loop", 0)) {
		remove("No_Loop");
		if (!_access("No_Loop", 0)) {
			No_Loop = 1;
		}
	}
	while (1) {
		Sleep(1000);
		if (No_Loop) break;//
		if (!_access("No_Loop", 0)) {
			No_Loop = 1;
		}
	}
	Sleep(3000);
	DeleteCriticalSection(&cs_BBB);
	DeleteCriticalSection(&cs_HEX);
	Log("End=============================================================\n");
	DeleteCriticalSection(&cs_log);
	return 0;
}