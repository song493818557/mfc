
#include "TYPES.h"
#include "mouse.h"

// INITERAR ALLA MS KOMPATIBLA MUS F™R BRUK I PROGRAMMET
//#################################################
void InitMouse()
{
 unsigned int error=0;
 asm{
		mov ax,0h
		int 33h
		mov error,ax
	  }
 if (!error)
 {
  cout << "Error mouse not found! \n ";
  exit(1);
 }

}

//SŽTTER PEKAREN P?ANGIVNA PLATSEN
//######################################################
void SetPoint(unsigned int x,unsigned int y)
{
asm{
	  mov ax,4h
	  mov cx,x
	  mov dx,y
	  int 33h

	 }
}

// VISAR MUSPEKAREN (TESTAT I TEXT MODE)
//#################################################
void ShowPoint()
{
 asm{
		mov ax,1
		int 33h
	 }
}


// G™MMER MUSPEKAREN VAR DEN ŽN ŽR
//##################################################
void HidePoint()
{
 asm{
	  mov ax,02h
	  int 33h
	 }
}

// G™MMER MUSPEKAREN OM DEN KOMMER IN I EN VISS AREA
//################################################
void HidePointXY(unsigned int cordx,unsigned int cordy,unsigned int x,unsigned int y)
{
asm{
	 mov ax,10h
	 mov cx,cordx
	 mov dx,cordy
	 mov SI,x
	 mov DI,y
	 int 33h
	}
}

//ANGER VAR MUS PEKAREN ŽR OCH OM NGON HAR KLICKT P?MUSEN
//#######################################################
void ReadMouse(int &xcordi,int &ycordi,int &bbutt)
{
unsigned int x,y,b;
asm{
	 mov ax,3h
	 int 33h
	 mov x,cx
	 mov y,dx
	 mov b,bx
	}
xcordi=x;
ycordi=y;
bbutt=b;
}


//ANGER VAR DEN ACTUELLA KNAPPEN SIST TRYCKDES NER
//#######################################################
void PressXY(int &xcordi,int &ycordi,unsigned int bbutt)
{
unsigned int x,y;
xcordi=0;
ycordi=0;

asm{
	 mov ax,5h
	 MOV BX,bbutt
	 int 33h
	 mov x,cx
	 mov y,dx

	 }
xcordi=x;
ycordi=y;
}


//ANGER VAR DEN ACTUELLA KNAPPEN SIST SLŽPTES
//#######################################################
void ReleaseXY(int &xcordi,int &ycordi,unsigned int bbutt)
{
unsigned int x,y;
xcordi=0;
ycordi=0;

asm{
	 mov ax,06h
	 mov bx,bbutt
	 int 33h
	 mov x,cx
	 mov y,dx

	 }
xcordi=x;
ycordi=y;
}

//ANGER GRŽNSERNA F™R MUSPEKAREN
//#######################################################
void Limits(unsigned int minx,unsigned maxX,unsigned miny,unsigned maxY)
{
asm{
	 mov ax,07h
	 mov  cx,minx
	 mov  dx,maxX
	 int 33h
	 mov ax,08h
	 mov cx,miny
	 mov dx,maxY
	 int 33h
	}
}

//ANGER STORLEKEN P?MUSBUFFRTERN I BYTE
// #####################################################
int MouseSize()
{
unsigned int tmp=0;
asm{
	 mov ax,15h
	 int 33h
	 mov tmp,bx
	}
return tmp;
}
