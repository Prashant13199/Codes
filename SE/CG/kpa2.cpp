#include<iostream>
#include<graphics.h>
using namespace std;

int main()
 {
    int gd=DETECT,gm;
    float x1,y1,r,d,P,Q,x,y;
    cout<<"Enter coordinates";
    cin>>x1>>y1;
    cout<<"Enter radius";
    cin>>r;
    initgraph(&gd,&gm,NULL);
    d=3-2*r;
    x=0;
    y=r;
    
    do
      {
      
       putpixel (x1+x,y1+y,1);
       putpixel (x1+y,y1+x,2);
       putpixel (x1+y,y1-x,3);
       putpixel (x1+x,y1-y,4);
       putpixel (x1-x,y1-y,5);
       putpixel (x1-y,y1-x,6);
       putpixel (x1-y,y1+x,7);
       putpixel (x1-x,y1+y,8);
       
        
        if(d<0)
         { x=x+1;
           d=d + (4*x) + 6;
         }
        else if(d>=0)
         {
          x=x+1;
          y=y-1;
          d=d+4*(x-y)+10;
         }
        
      }while(x<=y);
       
       getch();
     
 }     
    
        
    
