#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
class function
{		int xc,yc,r,xm,ym,dx,dy,col;
		float ang;
		void dda(int x1,int y1,int x2,int y2);
		void circle(int r);
		void drawarc(int x,int y);
	public:	function()
		{	xc=yc=0;
			ang=0.0;
		}
		void input();
		void drawtriangle();	
		void drawcircle()
		{	col=RED;	
			circle(r);
			col=GREEN;
			circle(r/2);
		}	
		void initmaxmin(int x,int y)
		{	xm=x/2;
			ym=y/2;
		}
		void quad();		
};
void function::quad()
{		int x,y;
		x=xm+xc;
		y=ym-yc;
		for(int i=x-6;i<x+6;i++)
		{	putpixel(i,y,BLUE);
		}
		for(int j=y-6;j<y+6;j++)
		{	putpixel(x,j,BLUE);
		}
}
void function::dda(int x1,int y1,int x2,int y2)
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
		{	putpixel(x,y,WHITE);
			//delay(50);
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
void function::drawtriangle()
{		int x1,y1,x2,y2,x3,y3;
		ang=asin(0.5);
		x1=xm-(((sin(1.57-ang))*r))+xc;
		y1=(ym)+(r/2)-yc;
		x2=xc+(((sin(1.57-ang))*r)+(xm));
		y2=y1;		
		x3=xc+xm;
		y3=ym-(r+yc);
	//	dda(x3,y3,x1,y1);
	//	dda(x3,y3,x2,y2);
		dda(x1,y1,x2,y2);
		line(x1,y1,x3,y3);
		line(x2,y2,x3,y3);

}
void function::circle(int r)
{			float d;
			int x,y;
			x=0;
			y=r;
			d=3-2*r;
			while(x<=y)
			{	
				if(d<=0)
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
void function::drawarc(int x,int y)
{			//delay(500);
			putpixel(xc+x+(xm),(ym)-(yc+y),col);
			putpixel(xc+x+(xm),(ym)-(yc-y),col);
			putpixel(xc-x+(xm),(ym)-(yc+y),col);
			putpixel(xc-x+(xm),(ym)-(yc-y),col);
			putpixel(xc+y+(xm),(ym)-(yc+x),col);
			putpixel(xc+y+(xm),(ym)-(yc-x),col);
			putpixel(xc-y+(xm),(ym)-(yc+x),col);
			putpixel(xc-y+(xm),(ym)-(yc-x),col);
}	
void function::input()
{			cout<<"Enter Radius of Outer Circle:";
			cin>>r;
			cout<<"Enter Co-ordinates of Center of Circle:"<<endl;
			cin>>xc;
			cin>>yc;
}
int main()
{			function d;
			int gd=DETECT,gm,ch;
			initgraph(&gd,&gm,NULL);
			int x,y;
			x=getmaxx();
			y=getmaxy();
			d.initmaxmin(x,y);
			d.input();
			d.quad();
			d.drawcircle();
			d.drawtriangle();
			while(ch==0)
			{	ch=getchar();
			}
			cleardevice();
			return 0;
}


		

