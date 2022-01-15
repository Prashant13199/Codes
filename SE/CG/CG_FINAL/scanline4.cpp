/*
  Title : Scanline algorithm to fill polygon
*/

#include<iostream>
#include<graphics.h>
using namespace std;

void scanline(int [] ,int [],int);
int main()
{
int xx[10],yy[10],n,i=0,x,y,gd=DETECT,gm=0;

cout<<"Enter No. of vertices::";
cin>>n;
 for(i=0;i<n;i++)
  {
cout<<"\n Enter vertices of poly::";
cin>>xx[i];
cin>>yy[i];
  }

  xx[i] = xx[0];
  yy[i] = yy[0];

initgraph(&gd,&gm,NULL);
  for(i=0;i<=n-1;i++)
   {
    line(xx[i],yy[i],xx[i+1],yy[i+1]);
   }
 scanline(xx,yy,n);
getch();
closegraph();
 return 0;
 }

 void scanline(int xx[10],int yy[10],int n)
 {
int i,k,temp,ymax=0,ymin=480,inx[50],y;
    float m[50],dx,dy;
   for(i=0;i<n;i++)
   {
    if(yy[i]>=ymax)
	ymax=yy[i];
    if(yy[i]<=ymin)
ymin=yy[i];

     dx = xx[i+1] - xx[i];
dy = yy[i+1]-yy[i];

if(dx == 0)
	m[i] = 0;
if(dy == 0)
	m[i] =1;

if(dx!=0 &&dy!=0)
	m[i]= (float) (dx/dy);
  }

   for(y=ymax;y>=ymin;y--)
      {
int cnt=0;
       for(i=0;i<n;i++)
	{
	  if((yy[i]>y && yy[i+1]<=y) || ( yy[i]<=y && yy[i+1]>y))
	    {
	inx[cnt]=(xx[i]+(m[i] * (y-yy[i])));
	cnt++;
	    }
	 }
	for(k=0;k<cnt-1;k++)
	  {
	    for(i=0;i<cnt-1;i++)
	     {
	       if(inx[i]>inx[i+1])
		{
		  temp = inx[i];
		inx[i] = inx[i+1];
		inx[i+1] = temp;
		}
	     }
	 }
	 for(i=0;i<cnt-1;i+=2)

	  {
	     line(inx[i],y,inx[i+1]+1,y);
	delay(100);
	   }
     }
 }

/*OUTPUT
Enter No. of vertices::5

 Enter vertices of poly::50
100

 Enter vertices of poly::50
50

 Enter vertices of poly::200
50

 Enter vertices of poly::200
100

 Enter vertices of poly::150
75

*/
