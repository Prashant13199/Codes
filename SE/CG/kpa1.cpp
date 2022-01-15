#include<iostream>
#include<graphics.h>
using namespace std;

int main()
 {
    int gd=DETECT,gm,i;
    float x,y,x1,y1,x2,y2,dx,dy,step;
    cout<<"Enter co-ordinates for A:";
    cin>>x1>>y1;
    cout<<"Enter co-ordinates for B:";
    cin>>x2>>y2;
    initgraph(&gd,&gm,NULL);
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    
     if(dx>dy)
      {
          step=dx;
      }
      
     else
      {
         step=dy;
      }
     
     dx=(x2-x1)/step;
     dy=(y2-y1)/step;
     x=x1+0.5;
     y=y1+0.5;
     i=1;
     while(i<=step)
      {
         putpixel(x,y,WHITE);
         x=x+dx;
         y=y+dy;
         i=i+1;
         delay(500);
      }
   getch();
 }     
    
