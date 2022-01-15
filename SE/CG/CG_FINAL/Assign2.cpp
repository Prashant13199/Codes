#include<iostream>
#include<graphics.h>
using namespace std;
class circle
{
 friend class bresenham;
 public:
  void draw(int ,int ,int ,int);
  
};
void circle::draw(int x,int y,int x1,int y1)
{
  putpixel(x+x1 ,y+y1, RED);
  putpixel(x+x1 ,y-y1, RED);
  putpixel(x-x1 ,y+y1, RED);
  putpixel(x-x1 ,y-y1, RED);
  putpixel(x+y1 ,y+x1, RED);
  putpixel(x+y1 ,y-x1, RED);
  putpixel(x-y1 ,y+x1, RED);
  putpixel(x-y1 ,y-x1, RED);
}

class bresenham:public circle
{
  public:
  void bres(int ,int ,int);
};

void bresenham::bres(int x,int y,int r)
{
  int x1,y1;
  float d;
  d=3-2*r;
  x1=0;
  y1=r;
  while(x1<=y1)
  {
     if(d<0)
      d+=(4*x1)+6;
     else
     {
       d+=4*(x1-y1)+10;
       y1--;
       }
     x1++;
     draw(x,y,x1,y1);
   }
}

int main()
{
 int x,y,r;
 bresenham b;
 int gd = DETECT , gm;
 cout<<"\nEnter co-ordinate of the centre of the circle:";
 cin>>x>>y;
 cout<<"\nEnter radius of the circle: ";
 cin>>r;
 initgraph(&gd,&gm,NULL);
 b.bres(x,y,r);
 getch();
 closegraph();
 return 0;
}
