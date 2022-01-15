#include<iostream>
#include<string.h>
using namespace std;

class Client
{

int no,id;
float bill;
long int tel;
char name[20],city[20];
public:
Client()
{
	id=0;
	strcpy(name,"__");
	tel=0;
	strcpy(city,"__");
	bill=0;
}

int getId()
{
	return id;
}

void setId(int ID)
{
	id=ID;
}

int getTeleNo()
{
	return no;
}

void setTeleNo(int t)
{
	no=t;
}

char* getName()
{
	return name;
}

void setName(char* N)
{
	strcpy(name,N);
}

char* getCity()
{
	return city;
}

void setCity(char* c)
{
	strcpy(city,c);
}

float getBill()
{
	return bill;
}

void setBill(int B)
{
	bill=B;
}


};



class hash
{
Client HashTable[50]; // 50 times constructor call

public:
	
void insert()
{
int flag=0;
int loc,cid;
long int tel;
float Bill;
char cname[20],City[20]; 

cout<<"\n Enter clients Details: ";
cout<<"\n Enter client ID: ";
cin>>cid;
cout<<"\n Enter client Name: ";
cin>>cname;
cout<<"\n Enter client telephone no: ";
cin>>tel;
cout<<"\n Enter client City: ";
cin>>City;
cout<<"\n Enter client Bill: ";
cin>>Bill;


for(int i=0;i<50;i++)
{
	
	loc=(loc%50);
  	if(HashTable[loc].getId()==0)
	{
		HashTable[loc].setId(cid);
		HashTable[loc].setName(cname);
		HashTable[loc].setTeleNo(tel);
		HashTable[loc].setCity(City);
		HashTable[loc].setBill(Bill);		
		break;
	}
	else
	{
		loc=((loc+1)%50);
	}
}
	
	
}

void Display()
{
  cout<<"\tId\t Name\t City\t Bill"<<endl;
  for(int i=0;i<50;i++)
  {
cout<<"\t"<<HashTable[i].getId()<<"\t"<<HashTable[i].getName()<<"\t"<<HashTable[i].getCity()<<"\t"<<HashTable[i].getBill()<<endl;
  }
}

 void search()
{
   	int cidd,loc,flag=0;
	cout<<"\n enter ID of the client to be searched in hashtable :";
	cin>>cidd;
	loc=(loc%50);
	
		if(HashTable[loc].getId()==cidd)
		{
			flag=0;
		}
		else
		{
			for(int i=0;i<50;i++)
			{
				loc=((loc+1)%50);
				if(HashTable[loc].getId()==cidd)
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
			cout<<"\t"<<HashTable[loc].getId();
			cout<<"\t"<<HashTable[loc].getName();
			cout<<"\t"<<HashTable[loc].getCity();
			cout<<"\t"<<HashTable[loc].getTeleNo();
			cout<<"\t"<<HashTable[loc].getBill();
			//break;
		}
		
}
};
	
int main()
{
hash h;
int ch;

do
{
cout<<"\n Enter youe choice:\n 1.Insert \n 2.search \n 3.Display";
cin>>ch;

switch(ch)
{

case 1:
h.insert();
break;

case 2:
h.search();
break;

case 3:
h.Display();
break;
}
}while(ch!=3);
return 0;

}





