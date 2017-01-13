#include <stdio.h>

typedef void(*PRINT)(PPoint3d );

typedef struct _Point3d
{
	float x;
	float y;
	float z;
	//void print(const Point3d* pd);     //error
	//void (*print)(const Point3d* pd);  //right,但是不优雅
	PRINT print;
} Point3d,*PPoint3d;

void Point3d_print(const Point3d* pd)
{
	printf("%f %f %f ", pd->x, pd->y, pd->z);
}

void main()
{
	//以前面向过程的使用方法
	// Point3d a;
	// a.x = 1;
	// a.y = 2;
	// a.z = 3;
	// 
	// Point3d_print(&a);

	//改进后面向对象的使用方法
	Point3d a = {10,20,30,Point3d_print};
	a.print(&a);

}

