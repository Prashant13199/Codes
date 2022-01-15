#include<iostream>
#include<string.h>
using namespace std;
class client
{
public:
	int clno;
	char name[20];
	int ph_no;

};
class hash:public client
{

	public:
	client arr[20];

	void insert(int,char[],int,int);
	void search();
	hash();
	void display();

};

hash::hash()
{
for(int i=0;i<20;i++)
{
	arr[i].clno=-1;
	strcpy(arr[i].name," ");
	arr[i].ph_no=0;


}
}


void hash::insert(int no,char name1[],int num,int n)
{
int index=no%20;
if(arr[index].clno==-1)
{
arr[index].clno=no;
cout<<arr[index].clno;
strcpy(arr[index].name,name1);
arr[index].ph_no=num;
}
else
{
	index=((index+1)%20);
}

}
void hash::search()
{
   	int id,index,flag=0;
   	int clno,ph_no;
   	char name[20];
	cout<<"\n enter clino  of the client to be searched in hashtable :";
	cin>>id;
	index=(index%20);

		if(arr[index].clno==id)
		{
			flag=0;
		}
		else
		{
			for(int i=0;i<20;i++)
			{
				index=((index+1)%20);
				if(arr[index].clno==id)
				{
				flag=0;
				break;
				}
				else
				{
				  flag=1;
				}
			}
		}

		if(flag==1)
		{
		  cout<<"\n Client not found";
		}
		else
		{
		  	cout<<"\n client ID is found in the list \n ";
			cout<<"\t"<<arr[index].clno;
			cout<<"\t"<<arr[index].name[20];
			cout<<"\t"<<arr[index].ph_no;
			//break;
		}

}

void hash::display()
{
	cout<<"client no \t client Name \t phone no"<<endl;
	for(int i=0;i<20;i++)
	{
		cout<<"\t"<<arr[i].clno;
		cout<<"\t"<<arr[i].name;
		cout<<"\t\t"<<arr[i].ph_no;
		cout<<"\n";
	}
}
int main()
{
	hash h;
	 int n,ch,no,num;
	 char name[20];

	 do
	 {
	 cout<<"\n";
	cout<<"1.Insert";
	cout<<"\n";
	cout<<"2.Search";
	cout<<"\n";
	cout<<"3.display";
	cout<<"\n";
	cout<<"enter your choice";
	cin>>ch;

	switch(ch)
	{
	case 1:
		 cout<<"enter the number of clients";
			 		cin>>n;
			 for(int i=0;i<n;i++)
			        {
			 	    cout<<"\nclient no";
			 		cin>>no;
			 		cout<<"\nname";
			 		cin>>name;
			 		cout<<"\nphon no";
			 		cin>>num;
			 		cout<<"\n";
			 			h.insert(no,name,num,n);
			        }


   break;
	case 2:

	h.search();
		break;

	case 3:

		h.display();
		break;
	}
	 }while(ch!=4);
return 0;
}
