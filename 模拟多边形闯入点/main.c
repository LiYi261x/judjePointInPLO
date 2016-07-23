#include <stdio.h>
#include "data.h"
#define MAXNUM(a,b) (a>b? a:b)
#define MINNUM(a,b) (a<b? a:b)

int main()
{
	Point plo[5] = { { 0, 0 }, { -4.1, 0.1 }, { -4.2, 4.4 }, { -3, 2 }, { 0, 4 } };
	int flg = 0;
	Point point1, point2;
	point1.x = 1;
	point1.y = 0;
	point2.x = -1;
	point2.y = -1;
	///////////////////////////////////
	/*
	
	int i;
	int flg = 0;
	Point pointText = {-1,1};

	for (i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			if (pointText.y > MINNUM(plo[4].y, plo[0].y) && pointText.y <= MAXNUM(plo[4].y, plo[0].y))
			    if (plo[4].x + (pointText.y - plo[4].y)*(plo[0].x - plo[4].x) / (plo[0].y - plo[4].y) <= pointText.x)
			    {
				    flg++;				
			    }
			    break;
		}
		if (pointText.y > MINNUM(plo[i].y,plo[i+1].y) && pointText.y <= MAXNUM(plo[i].y,plo[i+1].y))
		    if (plo[i].x +(pointText.y - plo[i].y)*(plo[i+1].x - plo[i].x) / (plo[i+1].y - plo[i].y) <= pointText.x)
		    {
			    flg++;
	        }
	}

	printf("%d\n",flg);
	*/
		///////////////////////////////

	flg = IsLineSegmCross(plo[0],plo[2],plo[1],plo[4]);
//	flg = IsLineCrossTwoPoint(0, 1, 0,  point1, point2);

	printf("%d",flg);

}
int IsLineCrossTwoPoint(int A, int B, int C, Point point1, Point point2)
{
	if ((point1.x * A + point1.y * B + C) * (point2.x * A + point2.y * B + C) < 0)
	{
		return 1;
	}
	return 0;
}

int IsLineSegmCross(Point pointa, Point pointb, Point pointc, Point pointd)
{
	int flga, flgb;
	int A1, B1, C1, A2, B2, C2;

	A1 = pointb.y - pointa.y;
	B1 = pointa.x - pointb.x;
	C1 = pointa.y * pointb.x - pointa.x * pointb.y;
	A2 = pointd.y - pointc.y;
	B2 = pointc.x - pointd.x;
	C2 = pointc.y + pointd.x - pointc.x * pointd.y;

	if (IsLineCrossTwoPoint(A1, B1, C1, pointc, pointd) && IsLineCrossTwoPoint(A2, B2, C2, pointa, pointb))
	{
		return 1;
	}
	return 0;


}