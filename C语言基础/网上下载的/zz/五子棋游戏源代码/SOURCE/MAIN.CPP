
#include "types.h"
#include "mouse.h"
#include "shell.h"
#include "luffar.h"

int main(void)
{
	InitMouse();
	InitGraphics();
	DrawBackground();

   SetPoint(1,1);                   // L„gger musen p?punkten 1,1.
	ShowPoint();

	BOOL bWantToExit = FALSE;
	CPlayer player1(1);
	CPlayer player2(2);
	player2.ChangePlayer(TRUE);
	CBoard board(&player1,&player2);
	int winner=-1;
	int nCode=-1;
	int x,y,b=-1;

	CButton player1Button(CRect(480,50,610,70),"Player 1");
	CButton player2Button(CRect(480,75,610,95),"Computer");
	CButton newButton(CRect(450,430,530,450),"New");
	CButton quitButton(CRect(540,430,620,450),"Quit");

	board.Draw();
	newButton.Draw();
	quitButton.Draw();
	player1Button.Draw();
	player2Button.Draw();

	Message("Luffar Schack! 0.99");
	Message("Written by");
	Message("Yuheng Zhao 1997-5");
	Message("------------------");
	Message("New game ...");

	while (!bWantToExit)
	{
		ReadMouse(x,y,b);

		if (b==1)
		{
			if (quitButton.Clicked(x,y,b))
			{
				Message("Exit...");
				player2.ChangePlayer(FALSE);
				bWantToExit = TRUE;
				delay(200);
			}
			if (newButton.Clicked(x,y,b))
			{
				board.ResetBoard();
			}
			if (player1Button.Clicked(x,y,b))
			;
			if (player2Button.Clicked(x,y,b))
			{
				if (player2.IsComputer())
				{
					player2.ChangePlayer(FALSE);
					player2Button.SetWindowText("Player 2");
				}else
				{
					player2.ChangePlayer(TRUE);
					player2Button.SetWindowText("Computer");
				};
				delay(200);
			}
			b=-1;
		}
		winner=board.Go();
			if (winner==1 || winner==2)
			{
				Message((winner==1)?"Player 1 wins.":
					(player2.IsComputer())?"Computer wins":"Player 2 wins");
				nCode=(winner==1)?ShowWinDlg(&player1):ShowWinDlg(&player2);
				if (nCode==1)
					board.ResetBoard();
			}
	}

	HidePoint();
	closegraph();
	return 0;
}
