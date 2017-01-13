
#include "types.h"
#include "shell.h"
#include "luffar.h"
#include "mouse.h"

CBoard::CBoard(CPlayer* p1,CPlayer* p2)
{
	m_bSearchAll = TRUE;
	//Rensa arrayen
	for (int temp=0;temp<MAX_X;temp++)
	{
		for (int temp1=0;temp1<MAX_Y;temp1++)
		{
			m_nBoard[temp][temp1]=0;
		}
	}

	m_bIsEmpty = TRUE;
	m_pPlayer1 = p1;
	m_pPlayer2 = p2;
	m_pCurrentPlayer = p1;
	m_nWhoBegins=1;

	x0 = 25;
	y0 = 45;
	x1 = 435;
	y1 = 455;
	m_nMargin = 10;
	m_nShadow = 5;
	m_nCellX = (x1-x0)/MAX_X;
	m_nCellY = (y1-y0)/MAX_Y;
	//Justera storleken p?br„det s?att det blir delbart
	x1=x0+m_nCellX*MAX_X;
	y1=y0+m_nCellY*MAX_Y;

	msg[0]='\0';
	CreateImages();
}

void CBoard::ResetBoard()
{
	if (!m_bIsEmpty)
	{
		for (int temp=0;temp<MAX_X;temp++)
		{
			for (int temp1=0;temp1<MAX_Y;temp1++)
			{
				m_nBoard[temp][temp1]=0;
			}
		}
		m_lastPt = CPoint();
		m_nextlPt = CPoint();
		if (m_nWhoBegins==1)
		{
			m_pCurrentPlayer = m_pPlayer2;
			m_nWhoBegins=2;
		}else
		{
			m_pCurrentPlayer = m_pPlayer1;
			m_nWhoBegins=1;
		}
		m_bIsEmpty = TRUE;
		Draw();
      Message("-----------------");
		Message("New game ... ");
	}
}

CBoard::~CBoard()
{
	free(m_pImage1);
	free(m_pImage2);
}

void CBoard::CreateImages()
{
	int r = (m_nCellX>m_nCellY)?m_nCellY:m_nCellX;
	r/=2;
	r-=1;
	int x = 465;
	int y = 60;
	unsigned int size;

	/* calculate the size of the image */
	size = imagesize(0,0,r*2,r*2);

	/* allocate memory to hold the image */
	m_pImage1 = malloc(size);
	m_pImage2 = malloc(size);

	//F”rsta image
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(x,y,r,r);
	setfillstyle(SOLID_FILL,DGRAY);
	fillellipse(x-3,y-3,r-4,r-4);
	setcolor(LGRAY);
	setfillstyle(SOLID_FILL,LGRAY);
	fillellipse(x-3,y-3,r-7,r-7);

   /* grab the image */
	getimage(x-r,y-r,x+r,y+r, m_pImage1);

	x = 465;
	y = 85;

	//Andra image
	setcolor(DGRAY);
	setfillstyle(SOLID_FILL,DGRAY);
	fillellipse(x,y,r,r);
	setfillstyle(SOLID_FILL,LGRAY);
	fillellipse(x-1,y-2,r-2,r-2);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	fillellipse(x-3,y-3,r-7,r-7);

	getimage(x-r,y-r,x+r,y+r, m_pImage2);

//	putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
}

void CBoard::Draw()
{
	//Bakgrunden f”r schackbr„det
	HidePoint();
	CRect rect(x0-m_nMargin,y0-m_nMargin,
					x1+m_nMargin,y1+m_nMargin);
	rect.Draw(BROWN,NOCOLOR,TRUE,m_nShadow);

	setcolor(BLACK);
	for (int temp=0;temp<MAX_Y+1;temp++)
		line(x0,y0+temp*m_nCellY,x1,y0+temp*m_nCellY);
	for (temp=0;temp<MAX_X+1;temp++)
		line(x0+temp*m_nCellX,y0,x0+temp*m_nCellX,y1);
	ShowPoint();
}

int CBoard::Go()
{
	int scrx=-1,scry=-1,b;
	CPoint newPt;
	BOOL redraw=FALSE;

	if (m_pCurrentPlayer->IsComputer())
	{
		newPt = Think();
      m_nBoard[newPt.x][newPt.y]=m_pCurrentPlayer->WhichPlayer();
		redraw = TRUE;
		m_bIsEmpty = FALSE;
		m_nextlPt = m_lastPt;
		m_lastPt = newPt;
	}else
	{
		ReadMouse(scrx,scry,b);
		if (b==1)
		{
			if (CRect(x0,y0,x1,y1).PtInRect(CPoint(scrx,scry)))
			{
				newPt = CPoint((scrx-x0)/m_nCellX,(scry-y0)/m_nCellY);
				if (newPt.x>=MAX_X) newPt.x=MAX_X-1;
				if (newPt.y>=MAX_Y) newPt.y=MAX_Y-1;
				if (m_nBoard[newPt.x][newPt.y]==0)
				{
					m_nBoard[newPt.x][newPt.y]=m_pCurrentPlayer->WhichPlayer();
					redraw = TRUE;
					m_bIsEmpty = FALSE;
					m_nextlPt = m_lastPt;
					m_lastPt = newPt;
				}
			}
		}
	}

	//Rita p?sk„rmen
	if (newPt.x!=-1 && newPt.y!=-1 && redraw)
	{
		HidePoint();
		if (m_pCurrentPlayer->WhichPlayer() == 1)
		{
			putimage(x0+newPt.x*m_nCellX+1,y0+newPt.y*m_nCellY+1,
				m_pImage1,COPY_PUT);

		}
		else
			putimage(x0+newPt.x*m_nCellX+1,y0+newPt.y*m_nCellY+1,
				m_pImage2,COPY_PUT);
			ShowPoint();

		//Visa meddelande
		msg[0]='\0';
		if (m_pCurrentPlayer->IsComputer())
			strcat(msg,"Computer  ( ");
		else
		{
			strcat(msg,"Player ");
			if (m_pCurrentPlayer->WhichPlayer()==1)
				strcat(msg,"1  ( ");
			else if (m_pCurrentPlayer->WhichPlayer()==2)
				strcat(msg,"2  ( ");
		}
		char temp[3];
		IntToChar(newPt.x,temp);
		strcat(msg,temp);
		strcat(msg,":");
		IntToChar(newPt.y,temp);
		strcat(msg,temp);
		strcat(msg," )");
		Message(msg);

		//Žndra p?current player
		if (m_pCurrentPlayer==m_pPlayer1)
			m_pCurrentPlayer=m_pPlayer2;
		else
			m_pCurrentPlayer=m_pPlayer1;

		return GetWinner();
	}

	return -1;
}

CPoint CBoard::RandomPoint()
{
	CPoint pt;
	do
	{
		randomize();
		pt = CPoint(random(19),random(19));
	}while (m_nBoard[pt.x][pt.y]!=0);
	return pt;
}

CPoint CBoard::GetEndPoint(int x, int y, Direction d, BOOL& closed)
{
	closed = TRUE;
	int player=m_nBoard[x][y];
	switch (d)
	{
	case UP:
		if (y==0)
			return CPoint();

		if (m_nBoard[x][y-1]==player && m_nBoard[x][y-1]!=0)
			return GetEndPoint(x,y-1,UP,closed);
		if (m_nBoard[x][y-1]==0) closed = FALSE;
		return CPoint(x,y-1);
	case UPRIGHT:
		if (y==0 || x==MAX_X-1)
			return CPoint();
		if ((m_nBoard[x+1][y-1]==player) && ((m_nBoard[x+1][y-1]!=0)))
			return GetEndPoint(x+1,y-1,UPRIGHT,closed);
		if (m_nBoard[x+1][y-1]==0) closed = FALSE;
		return CPoint(x+1,y-1);
	case RIGHT:
		if (x==MAX_X-1)
			return CPoint();
		if (m_nBoard[x+1][y]==player && m_nBoard[x+1][y]!=0)
			return GetEndPoint(x+1,y,RIGHT,closed);
		if (m_nBoard[x+1][y]==0) closed = FALSE;
		return CPoint(x+1,y);
	case DOWNRIGHT:
		if (y==MAX_Y-1 || x==MAX_X-1)
			return CPoint();
		if (m_nBoard[x+1][y+1]==player && m_nBoard[x+1][y+1]!=0)
			return GetEndPoint(x+1,y+1,DOWNRIGHT,closed);
		if (m_nBoard[x+1][y+1]==0) closed = FALSE;
		return CPoint(x+1,y+1);
	case DOWN:
		if (y==MAX_Y-1)
			return CPoint();
		if (m_nBoard[x][y+1]==player && m_nBoard[x][y+1]!=0)
			return GetEndPoint(x,y+1,DOWN,closed);
		if (m_nBoard[x][y+1]==0) closed = FALSE;
		return CPoint(x,y+1);
	case DOWNLEFT:
		if (y==MAX_Y-1 || x==0)
			return CPoint();
		if (m_nBoard[x-1][y+1]==player && m_nBoard[x-1][y+1]!=0)
			return GetEndPoint(x-1,y+1,DOWNLEFT,closed);
		if (m_nBoard[x-1][y+1]==0) closed = FALSE;
		return CPoint(x-1,y+1);
	case LEFT:
		if (x==0)
			return CPoint();
		if (m_nBoard[x-1][y]==player && m_nBoard[x-1][y]!=0)
			return GetEndPoint(x-1,y,LEFT,closed);
		if (m_nBoard[x-1][y]==0) closed = FALSE;
		return CPoint(x-1,y);
	case UPLEFT:
		if (x==0 || y==0)
			return CPoint();
		if (m_nBoard[x-1][y-1]==player && m_nBoard[x-1][y-1]!=0)
			return GetEndPoint(x-1,y-1,UPLEFT,closed);
		if (m_nBoard[x-1][y-1]==0) closed = FALSE;
		return CPoint(x-1,y-1);
	} return CPoint();
}

CPoint CBoard::SearchAll(int player, int count, int param)
{
	CPoint pt;
	// S”k genom hela spelet
	for (int temp=0;temp<MAX_X;temp++)
	{
		for (int temp1=0;temp1<MAX_Y;temp1++)
		{
			if (m_nBoard[temp][temp1]==player)
			{
				pt = Analyse(temp,temp1,count,param);
				if (pt.x != -1) return pt;
			}
		}
	}
	return pt;
}

CPoint CBoard::Think()
{
	Message("I'm thinking...");
	CPoint pt;

	//Om det „r ett nytt spel
	if (m_lastPt.x==-1)
		return CPoint(10,9);
	else if (m_nextlPt.x==-1)
		return CPoint(m_lastPt.x+1,m_lastPt.y);
	else
	{
   	// 1. Se om jag har 4 i rad eller 3 i rad med 1 till i n„rheten
		pt = Analyse(m_nextlPt.x, m_nextlPt.y, 4);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_nextlPt.x][m_nextlPt.y],4);
			if (pt.x != -1) return pt;
		}
		// 2. Se om motst†ndaren har 4 i rad.
		pt = Analyse(m_lastPt.x, m_lastPt.y, 4);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_lastPt.x][m_lastPt.y],4);
			if (pt.x != -1) return pt;
		}

		// 3. Se om jag har 3 i rad eller 2 i rad plus en till i n„rheten
		pt = Analyse(m_nextlPt.x, m_nextlPt.y, 3);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_nextlPt.x][m_nextlPt.y],3);
			if (pt.x != -1) return pt;
		}

		// 4. Se om motst†ndaren har 3 i rad
		pt = Analyse(m_lastPt.x, m_lastPt.y, 3);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_lastPt.x][m_lastPt.y],3);
			if (pt.x != -1) return pt;
		}

      //Tre i rad med en sida st„ngd
      pt = Analyse(m_nextlPt.x, m_nextlPt.y, 3, 2);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_nextlPt.x][m_nextlPt.y],3,2);
			if (pt.x != -1) return pt;
		}

      pt = Analyse(m_nextlPt.x, m_nextlPt.y, 2, 1);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_nextlPt.x][m_nextlPt.y],2,1);
			if (pt.x != -1) return pt;
		}

		pt = Analyse(m_lastPt.x, m_lastPt.y, 2, 1);
		if (pt.x != -1) return pt;
      if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_lastPt.x][m_lastPt.y],2,1);
			if (pt.x != -1) return pt;
		}

		//Tre i rad med en sida st„ngd
		pt = Analyse(m_lastPt.x, m_lastPt.y, 3, 2);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_lastPt.x][m_lastPt.y],3,2);
			if (pt.x != -1) return pt;
		}


		pt = FindDangerPt(m_nBoard[m_lastPt.x][m_lastPt.y]);
		if (pt.x != -1) return pt;

		pt = FindDangerPt(m_nBoard[m_nextlPt.x][m_nextlPt.y]);
		if (pt.x != -1) return pt;

		//Inte viktig
		pt = Analyse(m_nextlPt.x, m_nextlPt.y, 2);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_nextlPt.x][m_nextlPt.y],2);
			if (pt.x != -1) return pt;
		}

		pt = Analyse(m_lastPt.x, m_lastPt.y, 2);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_lastPt.x][m_lastPt.y],2);
			if (pt.x != -1) return pt;
		}

		pt = Analyse(m_nextlPt.x, m_nextlPt.y, 1);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_nextlPt.x][m_nextlPt.y],1);
			if (pt.x != -1) return pt;
		}

		pt = Analyse(m_lastPt.x, m_lastPt.y, 1);
		if (pt.x != -1) return pt;
		if (m_bSearchAll)
		{
			pt = SearchAll(m_nBoard[m_lastPt.x][m_lastPt.y],1);
			if (pt.x != -1) return pt;
		}
	}
	return RandomPoint();
}
CPoint CBoard::Analyse(int x,int y, int count,int param)
{
//    Se om n†gon har "count" i rad eller "count-1" i rad
//		med 1 till i n„rheten
// 	eller tv?"count-1" bredvid varandra
	CPoint topPt,endPt, tempPt;
	BOOL topClosed, endClosed, closed, closed1;
	int length;

	int length1, sum=0;
	Direction temp, temp1, temp2;

	if (x != -1 && y != -1)
	{
		for (temp=LEFT; temp<RIGHT;temp++)
		{
			length = Calculate(x, y, temp)+
						Calculate(x, y, (Direction)(temp+4))+1;
			topPt = GetEndPoint(x, y, temp, topClosed);
			endPt = GetEndPoint(x, y, (Direction)(temp+4), endClosed);
			if (length>=2 && count == 2 )
			{
				if ((!topClosed) && (topPt.x!=-1) &&
					m_nBoard[topPt.x][topPt.y]==0)
				{
					for (temp1=LEFT; temp1<=DOWNLEFT;temp1++)
					{
						length1 = Calculate(topPt.x, topPt.y, temp1,
							m_nBoard[x][y]);
						tempPt = GetEndPoint(topPt.x, topPt.y, temp1, closed);
						GetEndPoint(tempPt.x, tempPt.y, temp1, closed);
						if ((temp1 != temp) && (temp!=temp1-4) &&
							(length1>=2) && (!closed))
							return topPt;
						if (m_nBoard[tempPt.x][tempPt.y]==0 && (!endClosed)
							 && (endPt.x!=-1) &&	m_nBoard[endPt.x][endPt.y]==0)
						{
							for (temp2=LEFT; temp2<=DOWNLEFT;temp2++)
							{
								tempPt = GetEndPoint(tempPt.x, tempPt.y, temp2, closed);
								tempPt = GetEndPoint(tempPt.x, tempPt.y, temp2, closed);
								length1 = Calculate(tempPt.x, tempPt.y, temp2,
									m_nBoard[x][y])+1;
								if ((temp2 != temp1) &&
									(length1>=2) && (!closed))
									return topPt;
							}
						}

					}
				}
				if ((!endClosed) && (endPt.x!=-1) &&
					m_nBoard[endPt.x][endPt.y]==0)
				{
					for (temp1=LEFT; temp1<DOWNLEFT;temp1++)
					{
						length1 = Calculate(endPt.x, endPt.y, temp1,
							m_nBoard[x][y]);
						tempPt = GetEndPoint(endPt.x, endPt.y, temp1, closed);
						tempPt = GetEndPoint(tempPt.x, tempPt.y, temp2, closed);
						GetEndPoint(tempPt.x, tempPt.y, temp1, closed);
                  if ((temp !=temp1) && (temp != temp1-4) &&
							(length1>=2) && (!closed))
							return endPt;

						if (m_nBoard[tempPt.x][tempPt.y]==0 && (!topClosed)
								 && (topPt.x!=-1) &&	m_nBoard[topPt.x][topPt.y]==0)
						{
							for (temp2=LEFT; temp2<=DOWNLEFT;temp2++)
							{
								tempPt = GetEndPoint(tempPt.x, tempPt.y, temp2, closed);
								length1 = Calculate(tempPt.x, tempPt.y, temp2,
									m_nBoard[x][y])+1;
								if ((temp2 != temp1) &&
									(length1>=2) && (!closed))
									return topPt;
							}
						}
					}
				}
			}
			//     X   X
			//               Det h„r situationen
			//     X   X
			else if (length>=1 && count ==2)
			{
				if ((!topClosed) && (topPt.x!=-1) &&
					m_nBoard[topPt.x][topPt.y]==0)
				{
					for (temp1=LEFT; temp1<RIGHT;temp1++)
					{
						length1 = Calculate(topPt.x, topPt.y, temp1,
							m_nBoard[x][y]);
						tempPt = GetEndPoint(topPt.x, topPt.y, temp1, closed);
						tempPt = GetEndPoint(tempPt.x, tempPt.y, temp1, closed);
						if ((length1 >= 1) && (!closed))
						{
							length1 = Calculate(topPt.x, topPt.y, (Direction)(temp1+4),
								m_nBoard[x][y]);
							tempPt = GetEndPoint(topPt.x, topPt.y, (Direction)(temp1+4), closed);
							tempPt = GetEndPoint(tempPt.x, tempPt.y, (Direction)(temp1+4), closed);
							if ((length1 >= 1) && (!closed)) sum++;
						}
						if (sum>=2)
							return topPt;
					}
					sum=0;
				}
				if ((!endClosed) && (endPt.x!=-1) &&
					m_nBoard[endPt.x][endPt.y]==0)
				{
					for (temp1=LEFT; temp1<RIGHT;temp1++)
					{
						length1 = Calculate(endPt.x, endPt.y, temp1,
							m_nBoard[x][y]);
						tempPt = GetEndPoint(endPt.x, endPt.y, temp1, closed);
						tempPt = GetEndPoint(tempPt.x, tempPt.y, temp1, closed);
						if ((length1 >= 1) && (!closed))
						{
							length1 = Calculate(endPt.x, endPt.y, (Direction)(temp1+4),
								m_nBoard[x][y]);
							tempPt = GetEndPoint(endPt.x, endPt.y, (Direction)(temp1+4), closed);
							tempPt = GetEndPoint(tempPt.x, tempPt.y, (Direction)(temp1+4), closed);
							if ((length1 >= 1) && (!closed)) sum++;
						}
						if (sum>=2)
							return endPt;
					}
					sum=0;
				}
			}
			if (length>=count && param!=1)
			{
				if ((!topClosed) && (topPt.x!=-1) &&
						(m_nBoard[topPt.x][topPt.y]==0) &&
						(!endClosed) && (endPt.x!=-1) &&
						m_nBoard[endPt.x][endPt.y]==0)
				{
					if (length<=3)
					{
						GetEndPoint(topPt.x, topPt.y, temp, closed);
						GetEndPoint(endPt.x, endPt.y, Direction(temp+4), closed1);
						if ((!closed) && (!closed1))
							return topPt;
					}else
						return topPt;
				}
				else if (length>=4 || param==2)
				{
					if ((!topClosed) && (topPt.x!=-1) &&
						m_nBoard[topPt.x][topPt.y]==0)
							return topPt;
					if ((!endClosed) && (endPt.x!=-1) &&
						m_nBoard[endPt.x][endPt.y]==0)
						return endPt;
				}
			}
			else if ((!topClosed) && (topPt.x!=-1) &&
					m_nBoard[topPt.x][topPt.y]==0 && param!=1)
			{
				if (Calculate(topPt.x,topPt.y,temp,m_nBoard[x][y])>=count-length)
				{
					if (count>=4)
						return topPt;
					else
					{
						tempPt = GetEndPoint(topPt.x, topPt.y, temp, closed);
						tempPt = GetEndPoint(tempPt.x, tempPt.y, temp, closed);

					 if ((!endClosed) && (endPt.x!=-1) &&
						m_nBoard[endPt.x][endPt.y]==0 && (!closed))
						return topPt;
					}
				}
			}
			else if ((!endClosed) && (endPt.x!=-1) &&
					m_nBoard[endPt.x][endPt.y]==0 && param!=0 )
			{
				if (Calculate(endPt.x,endPt.y,(Direction)(temp+4),m_nBoard[x][y])>=count-length)
				{
					if (count>=4)
						return endPt;
					else
					{
						tempPt = GetEndPoint(endPt.x, endPt.y, temp, closed);
						tempPt = GetEndPoint(tempPt.x, tempPt.y, temp, closed);

                  if ((!topClosed) && (topPt.x!=-1) &&
							m_nBoard[topPt.x][topPt.y]==0 && (!closed))
							return endPt;
					}
				}
			}
		}
	}
	return CPoint();
}
int CBoard::Calculate(int x,int y,Direction d, int player)
{
	if (player==-1)
		player=m_nBoard[x][y];

	switch (d)
	{
	case UP:
		if (y==0 || m_nBoard[x][y-1]!=player)
			return 0;
		return 1+Calculate(x,y-1,d,player);
	case UPRIGHT:
		if (y==0 || x==MAX_X-1 || m_nBoard[x+1][y-1]!=player)
			return 0;
		return 1+Calculate(x+1,y-1,d,player);
	case RIGHT:
		if (x==MAX_X-1 || m_nBoard[x+1][y]!=player)
			return 0;
		return 1+Calculate(x+1,y,d,player);
	case DOWNRIGHT:
		if (y==MAX_Y-1 || x==MAX_X-1 || m_nBoard[x+1][y+1]!=player)
			return 0;
		return 1+Calculate(x+1,y+1,d,player);
	case DOWN:
		if (y==MAX_Y-1 || m_nBoard[x][y+1]!=player)
			return 0;
		return 1+Calculate(x,y+1,d,player);
	case DOWNLEFT:
		if (y==MAX_Y-1 || x==0 || m_nBoard[x-1][y+1]!=player)
			return 0;
		return 1+Calculate(x-1,y+1,d,player);
	case LEFT:
		if (x==0 || m_nBoard[x-1][y]!=player)
			return 0;
		return 1+Calculate(x-1,y,d,player);
	case UPLEFT:
		if (y==0 || x==0 || m_nBoard[x-1][y-1]!=player)
			return 0;
		return 1+Calculate(x-1,y-1,d,player);
	} return 0;
}

CPoint CBoard::FindDangerPt(int player)
{
	CPoint pt;
	int count=0, closedCount=0;
	BOOL closed;
	// S”k genom hela spelet
	for (int temp=0;temp<MAX_X;temp++)
	{
		for (int temp1=0;temp1<MAX_Y;temp1++)
		{
			if (m_nBoard[temp][temp1]==0)
			{
				for (Direction tmp=LEFT;tmp<=DOWNLEFT;tmp++)
				{
					pt = GetEndPoint(temp,temp1,tmp,closed);
					if (pt.x!=-1 && pt.y!=-1)
					{
						if (m_nBoard[pt.x][pt.y]==player)
							count++;
						if (m_nBoard[pt.x][pt.y]==player && (!closed))
						closedCount++;
               }
					if (count>=3 || closedCount>=2)
						return CPoint(temp,temp1);
					count=0;
					closedCount=0;
				}
			}
		}
	}
	return CPoint();
}

//return 1 om första spelaren vinner
//return 2 om andra spelaren vinner
//return -1 om ingen vinner
int CBoard::GetWinner()
{
	if (m_lastPt.x==-1 || m_lastPt.y==-1)
		return -1;
	int x=m_lastPt.x;
	int y=m_lastPt.y;

	if ((Calculate(x,y,UP)+Calculate(x,y,DOWN)>=4))
		{	ShowWinner(x,y,UP);
			ShowWinner(x,y,DOWN); }
	else if ((Calculate(x,y,UPLEFT)+Calculate(x,y,DOWNRIGHT)>=4))
		{	ShowWinner(x,y,UPLEFT);
			ShowWinner(x,y,DOWNRIGHT);}
	else if ((Calculate(x,y,LEFT)+Calculate(x,y,RIGHT)>=4))
		{	ShowWinner(x,y,LEFT);
			ShowWinner(x,y,RIGHT);}
	else if ((Calculate(x,y,UPRIGHT)+Calculate(x,y,DOWNLEFT)>=4))
		{	ShowWinner(x,y,UPRIGHT);
			ShowWinner(x,y,DOWNLEFT);}
	else
		return -1;

	delay(400);
	return m_nBoard[x][y];
}

void CBoard::ShowWinner(int x,int y,Direction start,int player)
{
	if (player==-1)
		player = m_nBoard[x][y];

	if (m_nBoard[x][y]!=player)
		return;

	HidePoint();
	/*putimage(x0+x*m_nCellX+1,y0+y*m_nCellY+1,
				m_pImage1,NOT_PUT);*/

	setcolor(YELLOW);
	circle(x0+x*m_nCellX+m_nCellX/2,
				y0+y*m_nCellY+m_nCellY/2,
				((m_nCellX>m_nCellY)?m_nCellY:m_nCellX)/2);

	ShowPoint();

	switch (start)
	{
	case UP:
		ShowWinner(x,y-1,UP,player);
		break;
	case DOWN:
		ShowWinner(x,y+1,DOWN,player);
		break;
	case UPLEFT:
		ShowWinner(x-1,y-1,UPLEFT,player);
		break;
	case DOWNRIGHT:
		ShowWinner(x+1,y+1,DOWNRIGHT,player);
		break;
	case LEFT:
		ShowWinner(x-1,y,LEFT,player);
		break;
	case RIGHT:
		ShowWinner(x+1,y,RIGHT,player);
		break;
	case UPRIGHT:
		ShowWinner(x+1,y-1,UPRIGHT,player);
		break;
	case DOWNLEFT:
		ShowWinner(x-1,y+1,DOWNLEFT,player);
		break;
	}
}

CMessagePad::CMessagePad()
{
	x0 = 450;
	y0 = 120;
	x1 = 620;
	y1 = 400;

	m_nShadow = 5;

	mx0 = x0 + 10;
	my0 = y0 + 25;
	mx1 = x1 - 10;
	my1 = y1 - 22;

	m_nLineSpace = 15;
	m_nLines = (my1-my0)/m_nLineSpace;
	my1 = my0 + m_nLineSpace * m_nLines;
	m_nCurrentLine = 0;

}

void CMessagePad::Draw()
{
	HidePoint();
	CRect rect(x0,y0,x1,y1);
	rect.Draw(BROWN,WHITE,TRUE,m_nShadow);

	//Titel
	CRect title(x0,y0,x1,y0+15);
	title.Draw(WHITE,WHITE);

	setcolor(BLACK);
	outtextxy(title.x0+6,title.y0+6,"Messages");

	ShowPoint();
}

void CMessagePad::Message(char* msg)
{
   HidePoint();

	if (m_nCurrentLine == m_nLines)
	{
		ScrollMessages();
		m_nCurrentLine--;
	}

	setcolor(BLACK);
	outtextxy(mx0+1,my0+m_nCurrentLine*m_nLineSpace+1,msg);
	setcolor(WHITE);
	outtextxy(mx0,my0+m_nCurrentLine*m_nLineSpace,msg);
	m_nCurrentLine++;

	ShowPoint();
}

void CMessagePad::ScrollMessages()
{
	void *oldImage;
	unsigned int size;

	/* calculate the size of the image */
	size = imagesize(mx0,my0+m_nLineSpace,mx1,my1+m_nLineSpace);

	/* allocate memory to hold the image */
	oldImage = malloc(size);

	/* grab the image */
	HidePoint();
	getimage(mx0,my0+m_nLineSpace,mx1,my1+m_nLineSpace,oldImage);

	putimage(mx0,my0,oldImage,COPY_PUT);
	ShowPoint();

	/* clean up */
	free(oldImage);
}
