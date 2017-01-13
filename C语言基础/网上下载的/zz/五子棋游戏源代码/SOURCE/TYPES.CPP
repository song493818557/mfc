#include "TYPES.H"
#include "MOUSE.H"

BOOL CPoint::operator== (const CPoint& pt) const
{
	if ((x==pt.x) && (y==pt.y))
		return TRUE;
	return FALSE;
}

const CPoint& CPoint::operator= (const CPoint& pt)
{
	if (this != &pt)
	{
		x = pt.x;
		y = pt.y;
	}
	return *this;
}

const CRect& CRect::operator= (const CRect& rect)
{
	if (this != &rect)
	{
		x0 = rect.x0;
		y0 = rect.y0;
		x1 = rect.x1;
		y1 = rect.y1;
	}
	return *this;
}

BOOL CRect::PtInRect(const CPoint& pt)
{
	if (pt.x>=x0 && pt.x<=x1 && pt.y>=y0 && pt.y<=y1)
		return TRUE;
	return FALSE;
}

void CRect::Draw(int color,int lineColor,BOOL shadow,int deep)
{
	setfillstyle(SOLID_FILL,color);
	bar(x0,y0,x1,y1);

	if(shadow)
	{
		//Skuggan
		int poly[8];
		poly[0]=x1;	//F”rsta punkten
		poly[1]=y0;
		poly[2]=x1+deep; //Andra punkten
		poly[3]=y0+deep;
		poly[4]=x1+deep; //Tredje punkten
		poly[5]=y1+deep;
		poly[6]=x1;
		poly[7]=y1;
		setcolor(DGRAY);
		setfillstyle(SOLID_FILL,DGRAY);
		fillpoly(4,poly);

		poly[0]=x1+deep; //Tredje punkten
		poly[1]=y1+deep;
		poly[2]=x0+deep; //Fj„rde punkten
		poly[3]=y1+deep;
		poly[4]=x0;	//Femte punkten
		poly[5]=y1;
		poly[6]=x1;
		poly[7]=y1;

		setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		fillpoly(4,poly);
	}

 	if (lineColor!=-1)
	{
		setcolor(lineColor);
		rectangle(x0,y0,x1,y1);
	}

}

CButton::CButton(const CRect& rect,char* ch):m_Rect(rect)
{
	m_pchName = new char[strlen(ch)+1];
	strcpy(m_pchName,ch);
	m_bPressed=FALSE;
}

void CButton::Draw()
{
	HidePoint();
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	if (!m_bPressed)
	{
		m_Rect.Draw(WHITE,BLACK,TRUE,2);

		//Skriv ut titel
		setcolor(BLACK);
		outtextxy((m_Rect.x1-m_Rect.x0)/2+m_Rect.x0,
					(m_Rect.y1-m_Rect.y0)/2+m_Rect.y0,
					m_pchName);
	}else
	{
		m_Rect.Draw(BLACK,BLACK,TRUE,1);

		//Skriv ut titel
		setcolor(LGRAY);
		outtextxy((m_Rect.x1-m_Rect.x0)/2+m_Rect.x0,
					(m_Rect.y1-m_Rect.y0)/2+m_Rect.y0,
					m_pchName);
	}
   settextjustify(LEFT_TEXT,TOP_TEXT);
	ShowPoint();
}

void CButton::SetWindowText(char* title)
{
   delete m_pchName;
	m_pchName = new char[strlen(title)+1];
	strcpy(m_pchName,title);
	Draw();
}

BOOL CButton::Clicked(int x,int y,int b)
{
	if (m_Rect.PtInRect(CPoint(x,y)) && b!=0)
	{
		if (!m_bPressed)
		{
			m_bPressed = TRUE;
			Draw();
		}
		return TRUE;
	}else
	if (m_bPressed)
	{
		m_bPressed = FALSE;
		Draw();
	}
	return FALSE;
}