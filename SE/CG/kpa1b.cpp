#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int main()
 {
    int gd=DETECT,gm,i;
    float x,y,x1,y1,x2,y2,dx,dy,step,e;
    cout<<"Enter co-ordinates for A:";
    cin>>x1>>y1;
    cout<<"Enter co-ordinates for B:";
    cin>>x2>>y2;
    initgraph(&gd,&gm,NULL);
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    x=x1;
    y=y1;
    e=2*dy-dx;
    i=1;
    
    do{
      putpixel(x,y,15);
      
      while(e>=0)
       {
         y=y+1;
         e=e-2*dx;
       }
     
           x=x+1;
           e=e+2 * dy;
           i=i+1;
      }while(i<=dx);
      
      getch();
      closegraph();
 }     
    
  
