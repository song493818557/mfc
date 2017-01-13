
#ifndef _MOUSE_H_
#define _MOUSE_H_

void InitMouse();
void ShowPoint();
void SetPoint(unsigned int x,unsigned int y);
void HidePoint();
void HidePointXY(unsigned int cordx,unsigned int cordy,unsigned int x,unsigned int y);
void ReleaseXY(int &xcordi,int &ycordi,unsigned int bbutt);
void PressXY(int &xcordi,int &ycordi,unsigned int bbutt);
void ReadMouse(int &x,int &y,int &b);
void Limits(unsigned int minx,unsigned maxX,unsigned miny,unsigned maxY);
int MouseSize();

#endif