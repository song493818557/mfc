
#ifndef _TYPES_H_
#define _TYPES_H_

#include <iostream.h>
#include <graphics.h> // c++ grafik,Inte sj„lv gjorda. ( ska „nd?inte g”ra n†got grafisk avancerat sak )
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <alloc.h>
#include <dos.h>

#define MAX_X	19
#define MAX_Y	19

#define SCR_MAX_X	639
#define SCR_MAX_Y 479

#define NOCOLOR -1
#define BLACK 	0
#define BLUE	1
#define GREEN	2
#define CYAN	3
#define RED		4
#define MAGENTA 5
#define BROWN	6
#define LGRAY	7
#define DGRAY	8
#define LBLUE	9
#define LGREEN	10
#define LCYAN	11
#define LRED	12
#define LMAGENTA 13
#define YELLOW	14
#define WHITE	15

enum BOOL{TRUE=1, FALSE=0};
enum Direction {LEFT,UPLEFT,UP,UPRIGHT,RIGHT,DOWNRIGHT,DOWN,DOWNLEFT};

class CPoint
{
public:
	int x,y;
	CPoint()	{x=-1;y=-1;}
	CPoint(int xx,int yy)	{x=xx; y=yy;}
	CPoint(const CPoint* pt) {x=pt->x; y=pt->y;}

	BOOL operator== (const CPoint& pt) const;
	const CPoint& operator= (const CPoint& pt);
};

class CRect
{
public:
	int x0,y0,x1,y1;
	CRect(int xx0,int yy0,int xx1,int yy1)	{x0=xx0; y0=yy0; x1=xx1; y1=yy1;}
	CRect(const CRect* r)		{x0=r->x0; y0=r->y0; x1=r->x1; y1=r->y1;}
	const CRect& operator= (const CRect& pt);	

	BOOL PtInRect(const CPoint& pt);
	void Draw(int,int lineColor=NOCOLOR,BOOL shadow=FALSE,int deep=0);
};

class CButton
{
public:
	CRect m_Rect;
	char* m_pchName;
	BOOL m_bPressed;

	CButton(const CRect& rect,char* ch);
	~CButton()	{delete m_pchName;}
	void Draw();
	//Kolla om n†gon har klickat p?knappen
	BOOL Clicked(int,int,int);
	void SetWindowText(char*);
};

#endif