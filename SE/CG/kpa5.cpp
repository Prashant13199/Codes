#include<iostream>
#include<graphics.h>
using namespace std;

class pixel
 {
   float x,y,x1,y1,x2,y2,dx,dy,step,e;
   int i;
   public:
    
    void getdata()
     {
       cout<<"Enter co-ordinates for A:";
       cin>>x1>>y1;
       cout<<"Enter co-ordinates for B:";
       cin>>x2>>y2;
     }
   
    
   
   void dda()
    {
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
     for(i=0;i<=step;i++)
      {
         putpixel(x,y,WHITE);
         x=x+dx;
         y=y+dy;
         i=i+1;
         delay(0);
      }
    }
  void bres()
   {
      dx=abs(x2-x1);
    dy=abs(y2-y1);
    x=x1;
    y=y1;
    e=2*(dy-dx);
    i=1;
    
    do{
      putpixel(x,y,15);
      
      while(e>=0)
       {
         y=y+1;
         e=e-2*dx;
       }
     
           x=x+1;
           e=e+2*dy;
           i=i+1;
      }while(i<=dx);
    }
  };
    
    
       
int main()
 {    int gd=DETECT,gm,i,n;
      pixel b;
      b.getdata();
      int ch;
      cout<<"1.dda"<<"2.bres";
      cin>>ch;
      initgraph(&gd,&gm,NULL);
   
     
    switch(ch)
     {
       case 1:b.dda();break;
       case 2:b.bres();
     }
    
      getch();
 }     
    
