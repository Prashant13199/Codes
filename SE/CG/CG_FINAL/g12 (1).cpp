#include<iostream>
#include<graphics.h>
using namespace std;
class drop{
	public:
	void display()
	{
		int i,j,k,t;
		ellipse(320,300,0,360,2*30,30-10);
		
		for(int j=10;j<=295;j++)
		{
			setcolor(BLUE);
			line(320,j,315,j+10);
			line(320,j,325,j+10);
			arc(320,j+10,180,360,5);
			delay(40);
			setcolor(BLACK);
			line(320,j,315,j+10);
			line(320,j,325,j+10);
			arc(320,j+10,180,360,5);
		}
		for(int i=30;i<130;i++)
		{
			setcolor(BLUE);
			ellipse(320,300,0,360,2*i,i-10);
			delay(40);
		}
	}
};
int main()
{
	int gd=DETECT;
	int gm;
	initgraph(&gd,&gm,NULL);
	drop d;
	d.display();
	getch();
	return 0;
}
