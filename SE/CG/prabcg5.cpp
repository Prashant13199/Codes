//Transformation
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class base
{		int tx,ty,sx,sy,vert,edg,flag,ym,xm;
		int tramat[3][3],scamat[3][3],cormat[10][3];//newcord[10][3];
		float rotmat[3][3],deg,newcord[10][3];
	public:	base()
		{	tx=ty=sx=sy=vert=edg=flag=0;
		}	
		void get()
		{	cout<<"Enter No. of Vertices of polygon:";
			cin>>vert;
			cout<<"\t\t\tEnter Co-ordinates of Vertices:"<<endl;
			for(int i=0;i<vert;i++)
			{	cout<<"\t\tVertices "<<i+1<<endl;	
				for(int j=0;j<2;j++)
				{	cin>>cormat[i][j];
					cormat[i][2]=1;
				}
				cout<<endl;
			}
		}
		void maxmin(int a,int b)
		{	xm=a;
			ym=b;
		}
		void halfquad()
		{	for(int i=0;i<ym;i+=4)
			{	putpixel((xm/2),i,RED);
			}
			for(int i=0;i<(xm/2);i+=4)
			{	putpixel(i,(ym/2),GREEN);
			}
			for(int i=(xm/2);i<xm;i+=4)
			{	putpixel(i,(ym/2),BLUE);
			}
			for(int i=0;i<ym;i+=4)
			{	putpixel((xm/4),i,WHITE);
				putpixel((3*xm)/4,i,WHITE);
			}
		}
		
		void scaproc()
		{	cout<<"Enter value of X-Scale & Y-Scale:";
			cin>>sx>>sy;
			for(int i=0;i<3;i++)
			{	for(int j=0;j<3;j++)
				{	scamat[i][j]=0;
				}
			}
			scamat[0][0]=sx;
			scamat[1][1]=sy;
			scamat[2][2]=1;
		}
		void traproc()
		{	cout<<"Enter X & Y Value :";
			cin>>tx>>ty;
			for(int i=0;i<3;i++)
			{	for(int j=0;j<3;j++)
				{	tramat[i][j]=0;
				}
			}
			tramat[2][0]=tx;
			tramat[2][1]=ty;
			tramat[0][0]=1;
			tramat[1][1]=1;
			tramat[2][2]=1;
		}
		void rotproc()
		{	float deg1;
			for(int i=0;i<3;i++)
			{	for(int j=0;j<3;j++)
				{	rotmat[i][j]=0;
				}
			}
			cout<<"Enter angle to rotate:";
			cin>>deg1;
			deg=((3.14*deg1)/180);
			rotmat[0][0]=cos(deg);
			rotmat[0][1]=sin(deg);
			rotmat[1][0]=-sin(deg);
			rotmat[1][1]=cos(deg);
			rotmat[2][2]=1;
		}
		void scale()
		{
			for(int i=0;i<vert;i++)
			{	for(int j=0;j<3;j++)
				{	newcord[i][j]=0;
					for(int k=0;k<3;k++)
					{	newcord[i][j]=newcord[i][j]+(cormat[i][k]*scamat[k][j]);
					}
				}
			}
		}
		void translate()
		{
			for(int i=0;i<vert;i++)
			{	for(int j=0;j<3;j++)
				{	newcord[i][j]=0;
					for(int k=0;k<3;k++)
					{	newcord[i][j]=newcord[i][j]+(cormat[i][k]*tramat[k][j]);
					}
				}
			}
		}
		void rotate()
		{	
			for(int i=0;i<vert;i++)
			{	for(int j=0;j<3;j++)
				{	newcord[i][j]=0;
					for(int k=0;k<3;k++)
					{	newcord[i][j]=newcord[i][j]+(cormat[i][k]*rotmat[k][j]);
					}
				}
			}
		}
		void origpoly()
		{	for(int l=0;l<vert-1;l++)
			{	
				line((xm/4)+cormat[l][0],(ym/2)-cormat[l][1],(xm/4)+cormat[l+1][0],(ym/2)-cormat[l+1][1]);
			}
			line((xm/4)+cormat[vert-1][0],(ym/2)-cormat[vert-1][1],(xm/4)+cormat[0][0],(ym/2)-cormat[0][1]);
		}	
		void newpoly()
		{	for(int i=0;i<vert-1;i++)
			{	
			line((3*xm/4)+newcord[i][0],(ym/2)-newcord[i][1],(3*xm/4)+newcord[i+1][0],(ym/2)-newcord[i+1][1]);
			}
			line((3*xm/4)+newcord[vert-1][0],(ym/2)-newcord[vert-1][1],(3*xm/4)+newcord[0][0],(ym/2)-newcord[0][1]);
		}	
};
int main()
{		int gd=DETECT,gm;
		base d;
		initgraph(&gd,&gm,NULL);
		int x,y,choice;
		x=getmaxx();
		y=getmaxy();
		d.maxmin(x,y);
		d.get();
		char ch;
		do
		{
			d.halfquad();	
			cout<<"***************MENU********************"<<endl;
			cout<<"1.Translate"<<endl;
			cout<<"2.Scaling"<<endl;
			cout<<"3.Rotate"<<endl;
			cout<<"4.Exit"<<endl;
			cout<<"Enter your choice:"<<endl;
			cin>>choice;
			switch(choice)
			{	case 1:	d.traproc();
					d.translate();
					d.origpoly();
					d.newpoly();
					break;
				case 2:	d.scaproc();
					d.scale();
					d.origpoly();
					d.newpoly();
					break;
				case 3:	d.rotproc();
					d.rotate();	
					d.origpoly();
					d.newpoly();
					break;
				case 4:	return 0;
			}	
			cout<<"Want other operation(y/n):"<<endl;
			cin>>ch;
			cleardevice();
		}while(ch=='y'||ch=='Y');
	
	return 0;
}
















