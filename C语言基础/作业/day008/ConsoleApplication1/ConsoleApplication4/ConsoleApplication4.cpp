#include "stdafx.h"
#include <iostream>  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

#define Y_MAX 30  
#define X_MAX Y_MAX*4  

#define MAX_TIME X_MAX  
using namespace std;
int main(void)
{

	char sheet[X_MAX][Y_MAX];
	int chosen_x = 0;
	int chosen_y = 0;
	int x_direction = 0;
	int y_direction = 0;

	int old_x = 0;
	int old_y = 0;

	int x, y, z, w;
	for (y = 0; y < Y_MAX; ++y)
		for (x = 0; x < X_MAX; ++x)
			sheet[x][y] = '#';
	system("clear");

	for (w = Y_MAX; w < X_MAX; w = w + Y_MAX)
	{
		old_x = w;
		for (z = 1; z <= MAX_TIME; ++z)
		{
			/*chosen for x */
			srand(time(NULL));
			int chosen = 0;
			x_direction = rand() % 3;

			/*chosen for y */
			system("sleep 1");
			srand(time(NULL));
			y_direction = rand() % 3;

			/*clear screen*/
			system("clear");
			/* direction set */
			if (x_direction == 2)
				x_direction = -1;
			if (y_direction == 0 || y_direction == 2)
				y_direction = -1;

			chosen_y = old_y + y_direction;
			chosen_x = old_x + x_direction;
			if (chosen_y < 0)
				chosen_y = Y_MAX;
			else if (chosen_y > Y_MAX)
				chosen_y = 0;
			else if (chosen_x < 0)
				chosen_x = X_MAX;
			else if (chosen_x > X_MAX)
				chosen_x = 0;

			old_y = chosen_y;
			old_x = chosen_x;

			sheet[chosen_x][chosen_y] = ' ';

			for (y = 0; y < Y_MAX; ++y)
			{
				for (x = 0; x < X_MAX; x++)
					printf("%c", sheet[x][y]);
				printf("\n");
			}
			printf("Time=%d\n", z);
			printf("old_x=%d\n", old_x);
		}
	}
	int ii = 0;

}