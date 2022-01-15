#include<iostream>
#include<graphics.h>
using namespace std;
class pixel
{	protected:	int xc,yc,r;
			int xm,ym;
	public:		pixel()
			{	xc=yc=r=0;
				xm=ym=0;
			}
			void drawarc(int x,int y);
			void drawcirc();
			void maxmin(int x,int y);
};
void pixel::maxmin(int x,int y)
{			xm=x;
			ym=y;
}
void pixel::drawarc(int x,int y)
{			delay(50);
			putpixel(xc+x+(xm/2),(ym/2)-(yc+y),9);
			putpixel(xc+x+(xm/2),(ym/2)-(yc-y),8);
			putpixel(xc-x+(xm/2),(ym/2)-(yc+y),7);
			putpixel(xc-x+(xm/2),(ym/2)-(yc-y),6);
			putpixel(xc+y+(xm/2),(ym/2)-(yc+x),5);
			putpixel(xc+y+(xm/2),(ym/2)-(yc-x),4);
			putpixel(xc-y+(xm/2),(ym/2)-(yc+x),3);
			putpixel(xc-y+(xm/2),(ym/2)-(yc-x),2);
}
void pixel::drawcirc()
{			float d;
			int x,y;
			x=0;
			y=r;
			d=3-2*r;
			while(x<=y)
			{	if(d<=0)
				{	d=d+(4*x)+6;
				}
				else
				{	d=d+4*(x-y)+10;
					y--;
				}
				x++;
				drawarc(x,y);
				
			}
}
class point:public pixel
{	public:		void init(int a,int b,int c)
			{	xc=a;
				yc=b;
				r=c;
			}
			void draw()
			{	drawcirc();
			}
			void quad(int x,int y)
			{	for(int i=0;i<x;i++)
				{	putpixel(i,y/2,WHITE);
				}
				for(int j=0;j<y;j++)
				{	putpixel(x/2,j,WHITE);
				}
			}
};
int main()
{			int gd=DETECT,gm=VGAMAX;
			point p;
			char ch='y';
			int x,y,r,xm,ym,m;
			cout<<"Enter x and y coordinate of center of circle:"<<endl;
			cin>>x>>y;
			cout<<"Enter radius:";
			cin>>r;
			p.init(x,y,r);
			initgraph(&gd,&gm,NULL);
			xm=getmaxx();
			ym=getmaxy();
			p.maxmin(xm,ym);
			p.quad(xm,ym);
			p.draw();
			m=0;
			while(m==0)
			{	m=getchar();
			}
			closegraph();
			return 0;
}	

			
			
