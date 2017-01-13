
#include "types.h"
#include "mouse.h"
#include "shell.h"

CMessagePad mp;

// INITERAR C++ GRAFIK
//#################################################
void InitGraphics()
{
	int gdriver = VGA, gmode=VGAHI, errorcode;

	if (!(registerbgidriver(EGAVGA_driver)<0))
	{
		initgraph(&gdriver, &gmode, "");
		errorcode = graphresult();
		if (errorcode == grOk)
			return;
	}
	cout << "Error detected when initialize graphics...\n";
	cout << "No VGA compatible graphics card is found...\n";
	ReadKey();
	exit(1);
}

// RENSAR SKŽRMEN
//################################################
void Cls()
{

int maxx, maxy;
maxx = getmaxx();
maxy = getmaxy();
setcolor(0);
for(int tmp=0;tmp<(maxy+1);tmp++)
line(0,tmp,maxx,tmp);

}

// LŽSER ETT TECKEN FRM TANGET BORDET
//################################################
char ReadKey()
{
 unsigned char tmp;
 asm{
	  mov ax,0
	  mov ah,0
	  int 16h
	  mov tmp,al
	 }
return tmp;
}

void DrawBackground()
{
	Cls();

	//Bakgrunden
	setfillstyle(LTBKSLASH_FILL,GREEN);
	bar(0,0,SCR_MAX_X,SCR_MAX_Y);

	//Titel
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,SCR_MAX_X,15);
	setcolor(BLACK);
	outtextxy(5,4,"Luffar schack 0.99 (Beta release)  by Yuheng Zhao");
	line(0,15,SCR_MAX_X,15);

	//About info
	CRect rect(450,40,620,105);
	rect.Draw(BROWN,NOCOLOR,TRUE,5);

	mp.Draw();
}

void Rectangle(int x0,int y0,int x1,int y1,int color,BOOL shadow,int deep)
{
	setfillstyle(SOLID_FILL,color);
	bar(x0,y0,x1,y1);

	if(shadow)
	{
		//Skuggan
		setcolor(BLACK);
		setfillstyle(INTERLEAVE_FILL,color);

		int poly[12];
		poly[0]=x1;	//F”rsta punkten
		poly[1]=y0;
		poly[2]=x1+deep; //Andra punkten
		poly[3]=y0+deep;
		poly[4]=x1+deep; //Tredje punkten
		poly[5]=y1+deep;
		poly[6]=x0+deep; //Fj„rde punkten
		poly[7]=y1+deep;
		poly[8]=x0;	//Femte punkten
		poly[9]=y1;
		poly[10]=x1;
		poly[11]=y1;

		fillpoly(6,poly);
	}
}

int ShowWinDlg(CPlayer* winner)
{
	CRect rect(200,200,440,300);
	CRect title(200,200,440,215);
	CButton okButton(CRect(215,270,315,290),"OK");
	CButton quitButton(CRect(325,270,425,290),"Cancel");
	void *oldImage;
	unsigned int size;
	int newGame=-1;
	int x,y,b;

	/* calculate the size of the image */
	size = imagesize(rect.x0,rect.y0,rect.x1+10,rect.y1+10);

	/* allocate memory to hold the image */
	oldImage = malloc(size);

	/* grab the image */
	HidePoint();
	getimage(rect.x0,rect.y0,rect.x1+10,rect.y1+10,oldImage);

	//Rita dialogen
	rect.Draw(LBLUE,WHITE,TRUE,5);
	title.Draw(WHITE,WHITE);

	setcolor(BLACK);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	outtextxy(title.x0+10,title.y0+5,(winner->IsComputer())?"You lose !!!":
												((winner->WhichPlayer()==1)?"Player 1 wins !!!":
														"Player 2 wins !!!"));
	outtextxy(rect.x0+18,rect.y0+36,"Do you want to play again?");

	setcolor(WHITE);
	outtextxy(rect.x0+17,rect.y0+35,"Do you want to play again?");

	okButton.Draw();
	quitButton.Draw();
	ShowPoint();

	while (newGame==-1)
	{
		ReadMouse(x,y,b);

		if (b==1)
		{
			if (okButton.Clicked(x,y,b))
				newGame = 1;
			if (quitButton.Clicked(x,y,b))
				newGame = 0;
		}
	}

	HidePoint();
	putimage(rect.x0,rect.y0,oldImage,COPY_PUT);
	ShowPoint();

	/* clean up */
	free(oldImage);
	WaitDlg(0,300);

	return newGame;
}

//nMode = 0 visa dlg med delay
//nMode = 1 visa dlg
//nMode = 2 Hide dlg
void WaitDlg(int nMode, int nDelay)
{
	CRect rect(240,210,400,280);
	CRect title(240,210,400,225);
	static void *oldImage;
	unsigned int size;
	int x,y,b;

	if (nMode == 0 || nMode == 1)
	{
		/* calculate the size of the image */
		size = imagesize(rect.x0,rect.y0,rect.x1+10,rect.y1+10);

		/* allocate memory to hold the image */
		oldImage = malloc(size);

		/* grab the image */
		HidePoint();
		getimage(rect.x0,rect.y0,rect.x1+10,rect.y1+10,oldImage);

		//Rita dialogen
		rect.Draw(LBLUE,WHITE,TRUE,5);
		title.Draw(WHITE,WHITE);

		setcolor(BLACK);
		settextjustify(LEFT_TEXT,TOP_TEXT);
		outtextxy(rect.x0+21,rect.y0+36,"Please wait...");

		setcolor(WHITE);
		outtextxy(rect.x0+20,rect.y0+35,"Please wait...");

		ShowPoint();
	}

	if (nMode == 0)
		delay(nDelay);

	if (nMode == 0 || nMode == 2)
	{
		HidePoint();
		putimage(rect.x0,rect.y0,oldImage,COPY_PUT);
		ShowPoint();

		/* clean up */
		free(oldImage);
	}
}

//n<100
void IntToChar(int n, char* ch)
{
	ch[0]=(char)(n/10+'0');
	ch[1]=(char)(n-(n/10)*10+'0');
	ch[2]='\0';
}

void Message(char* msg)
{
	mp.Message(msg);
}