#include<iostream>
#include<graphics.h>
using namespace std;
class transform
{
	int O[3][3],O1[4][3];
	int C[3][3],C1[4][3];
	int mat[3][3];
	void mul(int a[][3],int b[][3]);
	void mul1(int a[][3],int b[][3]);
	void display();
	void display1();
	public:
	transform()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(i==j)
				mat[i][j]=1;
				else
				mat[i][j]=0;
				O[i][j]=0;
				C[i][j]=0;
			}
		}
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<3;j++)
			{
				O1[i][j]=0;
				C1[i][j]=0;
			}
		}
	}
	void shear_tri();
	void shear_squ();
};
void transform::mul(int a[][3],int b[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
			C[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}
void transform::mul1(int a[][3],int b[][3])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
			C1[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}	
void transform::shear_tri()
{
	int shx,shy;
	O[0][0]=O[0][1]=O[1][1]=100;
	O[1][0]=150; O[2][0]=125; O[2][1]=57;
	O[0][2]=O[1][2]=O[2][2]=1;
	cout<<"\nEnter shear in x direction: ";
	cin>>shx;
	cout<<"\nEnter shear in y direction: ";
	cin>>shy;
	mat[0][1]=shy;
	mat[1][0]=shx;
	mul(O,mat);
	display();
}
void transform::shear_squ()
{
	int shx,shy;
	O1[0][0]=O1[0][1]=O1[1][1]=O1[3][0]=100;
	O1[1][0]=O1[2][0]=O1[2][1]=O1[3][1]=150;
	O1[0][2]=O1[1][2]=O1[2][2]=O1[3][2]=1;
	cout<<"\nEnter shear in x direction: ";
	cin>>shx;
	cout<<"\nEnter shear in y direction: ";
	cin>>shy;
	mat[0][1]=shy;
	mat[1][0]=shx;
	mul1(O1,mat);
	display1();
}
void transform::display()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setcolor(RED);
	line(100,100,150,100);
	line(150,100,125,57);
	line(125,57,100,100);
	
	setcolor(BLUE);
	line(C[0][0],C[0][1],C[1][0],C[1][1]);
	line(C[1][0],C[1][1],C[2][0],C[2][1]);
	line(C[0][0],C[0][1],C[2][0],C[2][1]);
	getch();
	closegraph();
}
void transform::display1()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setcolor(RED);
	line(100,100,150,100);
	line(150,100,150,150);
	line(150,150,100,150);
	line(100,150,100,100);
	
	setcolor(BLUE);
	line(C1[0][0],C1[0][1],C1[1][0],C1[1][1]);
	line(C1[1][0],C1[1][1],C1[2][0],C1[2][1]);
	line(C1[2][0],C1[2][1],C1[3][0],C1[3][1]);
	line(C1[3][0],C1[3][1],C1[0][0],C1[0][1]);
	getch();
	closegraph();
}
int main()
{
	transform t,t1;
	int ch;
	do
	{
		cout<<"\n1)Equilateral triangle\n2)Rhombus\n3)Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: t.shear_tri();
				break;
			case 2: t1.shear_squ();
				break;
			case 3: return 0;
			default:cout<<"Wrong choice!";		
		}
	}while(ch!=3);
	return 0;
}

