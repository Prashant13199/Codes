#include <iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class reflection
{
public:
	int n,b[20][20],c[20][20];

	void accept()
	{
		cout<<"Enter the number of edges : "<<endl;
		cin>>n;
		cout<<"Enter the co-ordinates : "<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<2;j++)
			{
				cin>>b[i][j];
			}
			b[i][2]=1;
		}
	}


	void display()
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,NULL);
		int i;
		line(320,0,320,480);
		line(0,240,640,240);
		for(i=0;i<n-1;i++)
		{
			line(320+b[i][0],240-b[i][1],320+b[i+1][0],240-b[i+1][1]);
		}
		line (320+b[i][0],240-b[i][1],320+b[0][0],240-b[0][1]);

		for(i=0;i<n-1;i++)
		{
			line(320+c[i][0],240-c[i][1],320+c[i+1][0],240-c[i+1][1]);
		}
		line (320+c[i][0],240-c[i][1],320+c[0][0],240-c[0][1]);
		getch();
		closegraph();
	}
	void multiply(double a[3][3])
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				c[i][j]=0;
				for(int k=0;k<n;k++)
				{
					c[i][j]=c[i][j]+(b[i][k]*a[k][j]);
				}
			}
		}
	}
};
int main()
{
	reflection b;
	b.accept();
	int choice;
	double mat[3][3];
	do{
	menu:
	cout<<"1)Reflection about x-axis "<<endl;
	cout<<"2)Reflection about y-axis "<<endl;
	cout<<"3)Reflection about x=y axis "<<endl;
	cout<<"4)Rotation about arbitrary point "<<endl;
	cout<<"5)Exit"<<endl;
	cin>>choice;
	switch(choice)
	{
	case 1:
		mat[0][0]=1;
		mat[0][1]=0;
		mat[0][2]=0;
		mat[1][0]=0;
		mat[1][1]=-1;
		mat[1][2]=0;
		mat[2][0]=0;
		mat[2][1]=0;
		mat[2][2]=1;
		b.multiply(mat);
		b.display();
		break;
	case 2:
		mat[0][0]=-1;
		mat[0][1]=0;
		mat[0][2]=0;
		mat[1][0]=0;
		mat[1][1]=1;
		mat[1][2]=0;
		mat[2][0]=0;
		mat[2][1]=0;
		mat[2][2]=1;
		b.multiply(mat);
		b.display();
		break;
	case 3:
		mat[0][0]=0;
		mat[0][1]=1;
		mat[0][2]=0;
		mat[1][0]=1;
		mat[1][1]=0;
		mat[1][2]=0;
		mat[2][0]=0;
		mat[2][1]=0;
		mat[2][2]=1;
		b.multiply(mat);
		b.display();
		break;
	case 4:
		float theta,angle;
		int xc=25,yc=25;
		cout<<"Enter the angle of rotation "<<endl;
		cin>>angle;
		theta=angle*(3.14/180);
		cout<<"Enter the coordinates of arbitrary point "<<endl;
		cin>>xc>>yc;
		mat[0][0]=cos(theta);
		mat[0][1]=sin(theta);
		mat[0][2]=0;
		mat[1][0]=-sin(theta);
		mat[1][1]=cos(theta);
		mat[1][2]=0;
		mat[2][0]=-xc*cos(theta)+yc*sin(theta)+xc;
		mat[2][1]=-xc*sin(theta)+yc*cos(theta)+yc;
		mat[2][2]=1;
		b.multiply(mat);
		b.display();
		break;
	}
	}while(choice <5);

	return 0;
}
