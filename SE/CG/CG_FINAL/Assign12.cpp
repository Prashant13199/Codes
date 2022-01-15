#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main()
{
 int gd=DETECT, gm,i;
 initgraph(&gd,&gm,NULL);
int cnt=0;
 for(i=0;i<=420;i=i+10)
 {
  rectangle(50+i,275,150+i,400);
  rectangle(150+i,350,200+i,400);
  circle(75+i,410,10);
  circle(125+i,410,10);
 
 switch(cnt){
 
 case 1:{ line(75+i,410,85+i,410);
   line(125+i,410,135+i,410);
   break;
   }
   case 2:{
    line(75+i,410,75+i,420);
    line(125+i,410,125+i,420);
    break;
   }
    case 3:{
     line(75+i,410,65+i,410);
    line(125+i,410,115+i,410);
    break;
   }
    case 4:{
    line(75+i,410,75+i,400); 
 	line(125+i,410,125+i,400);
   
    break;
   }
   
 
 
 }
 cnt++;
  if(cnt==4)
  cnt=0;
  delay(500);
  cleardevice();
 }

delay(500);
closegraph();
return 0;
}
