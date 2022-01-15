#include<iostream>
using namespace std;

class sport
{
	int cric[30],n,bad[30],i,j,k,b,c,q,p,x,o,y,stud[30],un[30],in[30],onc[30],onb[30],ne[30];
	public:
	void input()
	{
		cout<<"\n Enter the Number of Students in the class";
		cin>>n;
		cout<<"\n Roll Numbers of students in class are : ";
		for(i=0;i<n;i++)
		{
			stud[i]=i+1;
			cout<<"\n"<<stud[i]<<endl;
			
		}
		
		cout<<"\n Enter the number of Students who play cricket"<<endl;
		cin>>c;
		cout<<"\n Enter the Roll numbers of Students who play cricket"<<endl;
		for (i=0;i<c;i++)
		{
			cin>>cric[i];
		}
		
		cout<<"\n Enter the number of Students who play Badminton"<<endl;
		cin>>b;
		cout<<"\n Enter the Roll numbers of Students who play Badminton"<<endl;
		for (i=0;i<b;i++)
		{
			cin>>bad[i];
		}
			
		cout<<"\n Roll number of Students who play Cricket";
		for(i=0;i<c;i++)
		{
			cout<<cric[i]<<endl;
		}
		
		cout<<"\n Roll number of Students who play badminton";
		for(i=0;i<b;i++)
		{
			cout<<bad[i]<<endl;
		}
		}
		
	void uni()
	{
		
		 k=0;
		for(i=0;i<c;i++)
		{
			un[k]=cric[i];
			k++;
		}
		
		for(j=0;j<b;j++) 
		{
			for(i=0;i<c;i++)
			{
				if (bad[j]==cric[i])
				break;
			}
			if (i==c)
			{
				un[k]=bad[j];
				k++;
			}
		}
		cout<<"Roll numbers of students who play badminton or cricket or both : "<<endl;
		for(i=0;i<k;i++)
		{
			cout<<"\n"<<un[i]<<endl;
		}
	}
	
	void inter()
	{
		int o=0;
		for(j=0;j<b;j++) 
		{
			for(i=0;i<c;i++)
			{
				if (bad[j]==cric[i])
				{
					in[o]=cric[i];
					o++;	
					break;
				}
			}
		}
		cout<<"Roll numbers of students who play both badminton and cricket : "<<endl;
		for(i=0;i<o;i++)
		{
			cout<<"\n"<<in[i]<<endl;
		}
	}
		
	void oc()
	{
		int q=0;
		for(i=0;i<c;i++)
		{
			for(j=0;j<b;j++)
			{
				if (bad[j]==cric[i])
				break;
			}
			if (j==b)
			{
				onc[q]=cric[i];
				q++;
			}
		}
		cout<<"Roll numbers of students who play only cricket : "<<endl;
		for(i=0;i<q;i++)
		{
			cout<<"\n"<<onc[i]<<endl;
		}
	}
	
	void ob()
	{
		int x=0;
		for(i=0;i<b;i++)
		{
			for(j=0;j<c;j++)
			{
				if (bad[i]==cric[j])
				break;
			}
			if (j==b)
			{
				onb[x]=bad[i];
				x++;
			}
		}
		cout<<"Roll numbers of students who play only badminton : "<<endl;
		for(i=0;i<x;i++)
		{
			cout<<"\n"<<onb[i]<<endl;
		}
	}
	
	void nei()
	{
		int y=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<k;j++)
			{
				if (stud[i]==un[j])
				break;
			}
			if (j==k)
			{
				ne[y]=stud[i];
				y++;
			}
		}
		cout<<"Roll numbers of students who play neither badminton nor cricket : "<<endl;
		for(i=0;i<y;i++)
		{
			cout<<"\n"<<ne[i]<<endl;
		}
	}
	
				
			
};

	int main()
	
	{int p,z;
	sport obj;
	obj.input();
	obj.inter();
	do
	{
	cout<<"Enter the choice you want to perform\n"
	    <<"\n1 for union"
	    <<"\n2 for only cric"
	    <<"\n3 for only badm"
	    <<"\n4 for neither";
	cin>>p;
	
	switch(p)
	{
	case 1:{obj.uni();break;}
	case 2:{obj.oc();break;}
	case 3:{obj.ob();break;}
	case 4:{obj.nei();break;}
	default:cout<<"Wrong choice";
     }
     cout<<"If you want to continue press 1";
     cin>>z;
     }while(z==1);
     return 0;
     }
	
