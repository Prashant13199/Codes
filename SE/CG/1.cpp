#include<graphics.h>
#include<iostream>
int main(){
int gd=DETECT;
int gm;
initgraph(&gd, &gm, NULL);
line(100,100,200,250);
getch();
closegraph();
return 0;
}

