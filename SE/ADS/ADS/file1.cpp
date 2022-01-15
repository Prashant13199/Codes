#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class record
{
	public:
	int rollno,marks;
	char name[20];
	 
	 record()
	 {
	 	rollno =0;
	 	marks=0;
	 	strcpy(name,"");
	 }
void getdata()
{
	cout<<"\n Enter roll no of the student";
	cin>>rollno;
	cout<<"\n Enter name of the student";
	cin>>name;
	cout<<"\n Enter marks  of the student";
	cin>>marks;
}

void putdata()
{
	
	cout<<"\n  roll no of the student is:  ";
	cout<<rollno;
	cout<<"\n  name of the student is:     ";
	cout<<name;
	cout<<"\n  marks  of the student:      ";
	cout<<marks;
}
};

class file
{
	public:
	ifstream fin;
	ofstream fout;
	record r;	
	void insert();
	void display();
	int search(int);
	void update();
	void del();
};



void file:: insert()
{		
	fout.open("a3.txt",ios::app|ios::ate);
	r.getdata();
	fout.write((char *)&r,sizeof(r));
	fout.close();
}

void file:: display()
{
	fin.open("a3.txt");
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&r,sizeof(r)))
	{
		r.putdata();
	}
	fin.close();
		
}
int file:: search(int rol)
{
	int flag=0;
	fin.open("a3.txt");
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&r,sizeof(r)))
	{
		if(r.rollno==rol)
		{
			r.putdata();
			flag=1;
			
			break;
		}
		
	}return flag;
	
}
void file::del()
{
ifstream f1;
ofstream f2;
f1.open("a3.txt",ios::in);
f2.open("b.txt",ios::out);

int id;
cout<<"\nenter roll no that is to be del:=\n";
cin>>id;
f1.read((char*)&r,sizeof(r));
while(!f1.eof())
{
	if(id!=r.rollno)
	{
	f2.write((char*)&r,sizeof(r));
	}
        f1.read((char*)&r,sizeof(r));
}
f1.close();
f2.close();
remove("a3.txt");
rename("b.txt","a3.txt");
}
void file::update()
{
int i=0;
int id,flag=0;
fstream f;
f.open("a3.txt",ios::in|ios::out);
cout<<"\nenter student rollno to be modify\n";
cin>>id;
f.read((char*)&r,sizeof(r));
while(!f.eof())
{
	if(id==r.rollno)
	{
	flag=1;
	break;
	}
i++;
f.read((char*)&r,sizeof(r));

}
	if(flag==1)
	{
	f.seekp(i*sizeof(r),ios::beg);
	cout<<"\nEnter rollno,name,marks to be modified:\n";
	cin>>r.rollno>>r.name>>r.marks;
	f.write((char*)&r,sizeof(r));
	}
	else
	{cout<<"record not found";}
	f.close();
}	
int main()
{	
	file p;
	int flag=0;
	int choice,n;
	cout<<"\n Student databse";
	do
	{
	cout<<"\n 1.. create";
	cout<<"\n 2.. insert";
	cout<<"\n 3.. display";
	cout<<"\n 4.. update";
	cout<<"\n 5.. delete";
	cout<<"\n 6.. search";
	cout<<"\n 7.. exit";
	cout<<"\n Enter your choice";					
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			
			cout<<"\n Enter how many students you want to insert in database";		
			cin>>n;
			for(int i=0;i<n;i++)
			{
				p.insert();
			}
			
			break;
		
		case 2 :
			p.insert();	
			break;
		case 3 :
			p.display();
			break;
		case 4:
			p.update();
			break;
		case 5:
			p.del();
			break;	
		case 6:
			int rol;
			cout<<"\n Enter roll no the student you want to search";
			cin>>rol; 
			flag=p.search(rol);
			if(flag==1)
			{
			cout<<"\ndata is found in database\n";
			}
			else
			{
			cout<<"\ndata not found in database";
			}
			break;	
		case 7: return 0;	
			break;
	}
	}while(choice!=7);
	return 0;
}			
	/*[fedora@localhost ~]$ g++ file1.cpp
[fedora@localhost ~]$ ./a.out

 Student databse
 1.. create
 2.. insert
 3.. display
 4.. update
 5.. delete
 6.. search
 7.. exit
 Enter your choice1

 Enter how many students you want to insert in database 1

 Enter roll no of the student 10

 Enter name of the student harshada

 Enter marks  of the student 80

 1.. create
 2.. insert
 3.. display
 4.. update
 5.. delete
 6.. search
 7.. exit
 Enter your choice 2

 Enter roll no of the student 12

 Enter name of the student prashansa

 Enter marks  of the student 85

 1.. create
 2.. insert
 3.. display
 4.. update
 5.. delete
 6.. search
 7.. exit
 Enter your choice 3

  roll no of the student is:  10
  name of the student is:     harshada
  marks  of the student:      80
  roll no of the student is:  12
  name of the student is:     prashansa
  marks  of the student:      85
 1.. create
 2.. insert
 3.. display
 4.. update
 5.. delete
 6.. search
 7.. exit
 Enter your choice 4

enter student rollno to be modify
12

Enter rollno,name,marks to be modified:
11 prashansa 85

 1.. create
 2.. insert
 3.. display
 4.. update
 5.. delete
 6.. search
 7.. exit
 Enter your choice 5

enter roll no that is to be del:=
10

 1.. create
 2.. insert
 3.. display
 4.. update
 5.. delete
 6.. search
 7.. exit
 Enter your choice 3

  roll no of the student is:  11
  name of the student is:     prashansa
  marks  of the student:      85
 1.. create
 2.. insert
 3.. display
 4.. update
 5.. delete
 6.. search
 7.. exit
 Enter your choice 6

 Enter roll no the student you want to search 11

  roll no of the student is:  11
  name of the student is:     prashansa
  marks  of the student:      85
data is found in database
 1.. create
 2.. insert
 3.. display
 4.. update
 5.. delete
 6.. search
 7.. exit
 Enter your choice 6

 Enter roll no the student you want to search13

data not found in database



	*/
