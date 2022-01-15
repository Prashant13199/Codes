/*
Title :Seedfill Algorithm to fill polygon
*/

#include<iostream>
#include<graphics.h>
using namespace std;
class FillPolygon
{
	float input[10][3];
	int edges;
     public :
	void drawPoly()
	{      
               string s;
		int x1,y1,rad;
		cout<<"\nWhat do you want to draw(circle/polygon)";
		cin>>s;
		if(s=="circle")
		{
			cout<<"\nEnter centre and radius:";
			cin>>x1>>y1>>rad;
			initialiseGraph();
			circle(x1,y1,rad);
		}
		else
		{
			cout<<"\nEnter the edges : ";
			cin>>edges;
			cout<<"\nEnter the co-ordinates : ";
			for(int i=0;i<edges;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(j==2)
					input[i][j]=1;
					else
					cin>>input[i][j];
				}
			}	
			int i,j;
			initialiseGraph();
			for(i=0;i<edges-1;i++)
			{
				line(input[i][0],input[i][1],input[i+1][0],input[i+1][1]);
			}
			line(input[i][0],input[i][1],input[0][0],input[0][1]);
		}
	}

	
	void initialiseGraph()
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,NULL);
	}
	void floodFill(int x,int y,int oldColor,int newColor)
	{
		if(getpixel(x,y)==oldColor)
		{
			delay(1);
			putpixel(x,y,newColor);
			floodFill(x,y+1,oldColor,newColor);
			floodFill(x+1,y,oldColor,newColor);
			floodFill(x-1,y,oldColor,newColor);
			floodFill(x,y-1,oldColor,newColor);
		}
	}
};
int main()
{
	FillPolygon f1;
	int x,y,code;
	f1.drawPoly();
	cout<<"\nEnter the seed point : ";
	cin>>x>>y;
	cout<<"\nCOLOR               INT VALUES\n-------------------------------\nBLACK                   0\nBLUE                     1\nGREEN                   2\nCYAN                    3\nRED                     4\nMAGENTA                 5\nBROWN                   6\nLIGHTGRAY               7\nDARKGRAY                8\nLIGHTBLUE               9\nLIGHTGREEN             10\nLIGHTCYAN              11\nLIGHTRED               12\nLIGHTMAGENTA           13\nYELLOW                 14\nWHITE                  15";     
		
	cout<<"\nEnter the colorcode : ";
	cin>>code;
	f1.floodFill(x,y,0,code);
	getch();
	closegraph();
}
/*OUTPUT :

What do you want to draw??(circle/polygon)polygon

Enter the edges : 4

Enter the co-ordinates : 100
100
100
200
200
200
200
100

Enter the seed point :150
150

COLOR               INT VALUES
-------------------------------
BLACK                   0
BLUE                    1
GREEN                   2
CYAN                    3
RED                     4
MAGENTA                 5
BROWN                   6
LIGHTGRAY               7
DARKGRAY                8
LIGHTBLUE               9
LIGHTGREEN             10
LIGHTCYAN              11
LIGHTRED               12
LIGHTMAGENTA           13
YELLOW                 14
WHITE                  15
Enter the colorcode : 1

What do you want to draw??(circle/polygon)circle
Enter centre and radius : 200
200
50

Enter the seed point : 200
200

COLOR               INT VALUES
-------------------------------
BLACK                   0
BLUE                    1
GREEN                   2
CYAN                    3
RED                     4
MAGENTA                 5
BROWN                   6
LIGHTGRAY               7
DARKGRAY                8
LIGHTBLUE               9
LIGHTGREEN             10
LIGHTCYAN              11
LIGHTRED               12
LIGHTMAGENTA           13
YELLOW                 14
WHITE                  15
Enter the colorcode : 9




*/


		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	


