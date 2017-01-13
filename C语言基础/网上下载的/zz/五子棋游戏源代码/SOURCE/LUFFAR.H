
#ifndef _LUFFAR_H_
#define _LUFFAR_H_
#include "shell.h"

//Visa upp informationen
class CMessagePad
{
private:
	int x0,y0,x1,y1;
	int m_nShadow;

	//ruta d„r texten ska visas
	int mx0,my0,mx1,my1;
	int m_nLineSpace, m_nLines, m_nCurrentLine;
public:
	CMessagePad();
	void ScrollMessages();
	void Draw();
	void Message(char* msg);
};

class CPlayer
{
private:
	BOOL m_bComputer; //Om det „r dator som k”r.
	int m_nPlayer;	// Vilken spelare det „r
public:
	CPlayer(int p)	{m_bComputer = FALSE; m_nPlayer=p;}
	void ChangePlayer(BOOL com)	{m_bComputer = com;}
	int WhichPlayer()		{return m_nPlayer;}
	BOOL IsComputer()	{return m_bComputer;}
};

class CBoard
{
private:
	//V„rdet 0 om platsen „r tom, 1 f”r spelaren 1, 2, f”r spelare 2
	int m_nBoard[MAX_X][MAX_Y];

	//Var schackbr„de ligger p?sk„rmen.
	int x0,y0,x1,y1;	//Positionen p?br„det
	int m_nMargin; // Hur stor Marginal det br„det ska ha
	int m_nShadow; // Hur l†ngt skuggan det ska vara
	int m_nCellX;	//Storleken p?en cell p?br„det
	int m_nCellY;
	CPlayer* m_pPlayer1;
	CPlayer* m_pPlayer2;
	int m_nWhoBegins;
	CPlayer* m_pCurrentPlayer;
	BOOL m_bIsEmpty;

	//Skapa bilder i minnet och anv„nda PutImage() sedan
	void CreateImages();
	void *m_pImage1, *m_pImage2;
	CPoint m_lastPt;
	CPoint m_nextlPt; //N„st sista punkten

	//Kalkylera ut hur m†nga i rad det finns i ett visst h†ll
	int Calculate(int x,int y,Direction d,int player=-1);
	CPoint Analyse(int x, int y, int count,int param=0);

	char msg[30];
	CPoint RandomPoint();
	CPoint Think();
	CPoint GetEndPoint(int x, int y, Direction d, BOOL& closed); //Returnera punkten efter den sista punkten i en viss rad
	CPoint FindDangerPt(int player);

	BOOL m_bSearchAll;
	CPoint SearchAll(int,int, int param=0);
public:
	CBoard(CPlayer* p1,CPlayer* p2);
	~CBoard();
	void ResetBoard();

	void Draw();
	int Go();	//L†t current player g”ra n„sta drag, returnera vinnare om det finns
	int GetWinner();
	void ShowWinner(int x,int y,Direction start,int player=-1);
};
#endif