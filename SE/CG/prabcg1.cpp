#include<iostream>
#include<graphics.h>
#include<stdlib.h>
using namespace std;
class pixel
{			int dx,dy,max,may,midy,midx;
			int x1,y1,x2,y2;
	public:		pixel()
			{	
				x1=y1=x2=y2=0;
				dx=dy=0;
			}
			void drawmid(int x,int y)
			{	max=x;
				may=y;
				midy=(may/2);
				midx=(max/2);
				line();
			}
			void init(int a,int b,int c,int d)
			{	x1=a;
				y1=b;
				x2=c;
				y2=d;
			}
			void line();
			void ddaline(int l);	//int dda
			void ddaline();			//int bres	
};
void pixel::line()
{			for(int i=0;i<max;i++)
			{
				putpixel(i,midy,WHITE);
			}
			for(int j=0;j<may;j++)
			{	
				putpixel(midx,j,WHITE);
			}
}
void pixel::ddaline(int l)		//int ddA
{			float xinc,yinc;		//float steps
			int steps;
			dx=(x2-x1);
			dy=(y2-y1);
			if(abs(dx)<abs(dy))
			{	steps=dy;
			}
			else
			{	steps=dx;
			}
			xinc=(float)abs(dx)/steps;
			yinc=(float)abs(dy)/steps;
			float xn,yn;
			xn=x1;
			yn=y1;
			putpixel(xn+midx,midy-yn,9);
			delay(50);
			for(int i=0;i<abs(steps);i++)
			{	xn=xn+xinc;
				yn=yn+yinc;
				x1=xn+0.5;
				y1=yn+0.5;
				putpixel(x1+midx,midy-y1,9);
				delay(50);		
			}
}
void pixel::ddaline()				//int bres
{		int exc,s1,s2,x,y,temp;
		float g;
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		x=x1;
		y=y1;
		if((x2-x1)<0)
		{	s1=-1;	}
		if((x2-x1)>0)
		{	s1=1;	}
		if((x2-x1)==0)
		{	s1=0;	}
		if((y2-y1)<0)
		{	s2=-1;	}
		if((y2-y1)>0)
		{	s2=1;	}
		if((y2-y1)==0)
		{	s2=0;	}
		if(dy>dx)
		{	temp=dx;
			dx=dy;
			dy=temp;
			exc=1;
		}
		else
		{	exc=0;	}
		g=2*dy-dx;
		for(int i=0;i<dx;i++)
		{	putpixel(x+midx,midy-y,RED);
			delay(50);
			//while
			if(g>=0)
			{	if(exc==1)
				{	x=x+s1;
					//y=y+s2;
				}
				else
				{	y=y+s2;
					//x=x+s1;	
				}
				g=g+2*dy-2*dx;
			}

			if(exc==1)
			{	y=y+s2;	
				g=g+2*dy;
			}		
			else
			{	x=x+s1;
				g=g+2*dy;
			}	
			//g=g+2*dy;		
		 }
}				
class draw:public pixel
{	public:		int co1,co2,co3,co4;		
			void getint()
			{	cout<<"Enter starting coordinates(x,y):"<<endl;
				cin>>co1>>co2;
				cout<<"Enter end coordinates(x,y):"<<endl;
				cin>>co3>>co4;
				init(co1,co2,co3,co4);
			}
};

int main()
{		int gd=DETECT,gm;
		initgraph(&gd,&gm,NULL);
		draw d;
		int gx,gy;
		gx=getmaxx();
		gy=getmaxy();
		d.drawmid(gx,gy);
		char ch='y';
		int choice;
		while(ch=='y')
		{	cout<<"******************MENU*******************"<<endl;
			cout<<"1.DDA line with int Data type"<<endl;
			cout<<"2.Bresnen line with int Data type"<<endl;
			cout<<"3.Exit:"<<endl;
			cout<<"Enter your Choice(1-3):";
			cin>>choice;
			//d.drawmid(gx,gy);
			switch(choice)
			{	case 1:	cout<<"***********DDA line in BLUE color***************"<<endl;
					d.getint();
					d.ddaline(0);
					break;
				case 2: cout<<"**********Bresnehm line in RED color************"<<endl;
					d.getint();
					d.ddaline();
					break;
				case 3:	return 0;
					break;
				default:	cout<<"Entered wrong choice!!"<<endl;
			}
			cout<<"Want Again(y/n):";
			cin>>ch;
		}
		delay(50);
		closegraph();
		return 0;
}
