#include<iostream>
using namespace std;

class stud
{int i,j,size,size2,size3;
 public:
 struct se {
        char prn[30];
        int date,month;
       };
       
     se s1[12],s2[12],s3[12];
 void input()
 {
 cout<<"Enter size for s1 ";
 cin>>size;
 for(i=0;i<size;i++)
 {
 cout<<"Enter your prn number"<<endl;
  cin>>s1[i].prn;
  cout<<"enter your birth month"<<endl;
  cin>>s1[i].month;
  cout<<"Enter date of the birth"<<endl;
  cin>>s1[i].date;
  }
  }
  
  void input2()
 {
 cout<<"Enter size for s2 ";
 cin>>size2;
 for(i=0;i<size2;i++)
 {
 cout<<"Enter your prn number"<<endl;
  cin>>s2[i].prn;
  cout<<"enter your birth month"<<endl;
  cin>>s2[i].month;
  cout<<"Enter date of the birth"<<endl;
  cin>>s2[i].date;
  }
  }
  
 void output()
 {for(i=0;i<size;i++)
 
{  cout<<"Your prn number is:\t"<<"your birth month is:\t"<<"your date is:\t"<<endl;
   cout<<s1[i].prn<<"\t\t\t\t"<<s1[i].month<<"\t\t\t\t"<<s1[i].date<<"\t\t\t\t"<<endl;
  
  }
  }
  
  void output2()
 {for(i=0;i<size2;i++)
 
{  cout<<"Your prn number is:\t"<<"your birth month is:\t"<<"your date is:\t"<<endl;
   cout<<s2[i].prn<<"\t\t\t\t"<<s2[i].month<<"\t\t\t\t"<<s2[i].date<<"\t\t\t\t"<<endl;
  
  }
  }
 
  
  void sort()
  {int i=0,j=0,pos=0,min=0;
  se temp;
   for(i=0;i<size;i++)
   {
    min=s1[i].month;
    pos=i;
    for(j=i;j<size;j++)
    {
     if(s1[j].month<min)
     {
      pos=j;
     }
     }
     temp=s1[pos];
     s1[pos]=s1[i];
     s1[i]=temp;
    }
    

  
                    int m;
                  for(i=0;i<size;i++)
            		{
            			m=s1[i].month;
            			min=s1[i].date;
            			pos=i;
            			for(j=i;j<size;++j)
            			{
            				if(s1[j].month==m)
            				{
            			   if(s1[j].date<min)
            			   {
            			   min=s1[j].month;
            			   pos=j;
            			   }
            			   }
            			}
            			temp=s1[pos];
            			s1[pos]=s1[i];
            			s1[i]=temp;
            		     }    
            		
            		cout<<"\nmonth"<<"\t"<<"date"<<"\t"<<"PRN"<<"\t"<<endl;
    for(i=0;i<size;i++)
    {
    
    cout<<"\n"<<s1[i].month<<"\t"<<s1[i].date<<"\t"<<s1[i].prn<<endl;
  }
                 }
  
  
  void sort2()
  {int i=0,j=0,pos=0,min=0;
  se temp;
   for(i=0;i<size2;i++)
   {
    min=s2[i].month;
    pos=i;
    for(j=i;j<size2;j++)
    {
     if(s2[j].month<min)
     {
      pos=j;
     }
     }
     temp=s2[pos];
     s2[pos]=s2[i];
     s2[i]=temp;
    }
   
   int m;
                  for(i=0;i<size2;++i)
            		{
            			m=s2[i].month;
            			min=s2[i].date;
            			pos=i;
            			for(j=i;j<size2;++j)
            			{
            				if(s2[j].month==m)
            				{
            			   if(s2[j].date<min)
            			   {
            			   min=s2[j].month;
            			   pos=j;
            			   
            			   }
            			   }
            			}
            			
            			temp=s2[pos];
            			s2[pos]=s2[i];
            			s2[i]=temp;
            		    }    
            		
            		cout<<"\nmonth"<<"\t"<<"date"<<"\t"<<"PRN"<<"\t"<<endl;
    for(i=0;i<size2;i++)
    {
    
    cout<<"\n"<<s2[i].month<<"\t"<<s2[i].date<<"\t"<<s2[i].prn<<endl;
  }
                 
                 }
void merge()
{
 int i=0,j=0,k=0;
 while(i<size&&j<size2)
 {
  if(s1[i].month>s2[j].month)
   {
    s3[k]=s2[j];
    k++;
    j++;
   }
  if(s1[i].month<s2[j].month)
  {
   s3[k]=s1[i];
   i++;
   k++;
  }
  if(s1[i].month==s2[j].month)
  {
   if(s1[i].date<s2[j].date)
    {
     s3[k]=s1[i];
     k++;
     i++;
    }
    else
        {
         s3[k]=s2[j];
         k++;
         j++;
        }
      
      }
      }
    while(i<size)
    {
     s3[k]=s1[i];
     k++;
     i++;
    }
   while(j<size2)
   {
    s3[k]=s2[j];
    k++;
    j++;
   }
   
   cout<<"\nmonth"<<"\t"<<"date"<<"\t"<<"PRN"<<"\t"<<endl;   
    for(i=0;i<k;i++)
    {
     cout<<endl;
     
     cout<<"\n"<<s3[i].month<<"\t"<<s3[i].date<<"\t"<<s3[i].prn<<endl;
    }
    size3=k;
   }
   
   
void checkbday()
{
 int dt,mn,till,till2,mn2,flag,l,bboy;

 cout<<"Enter todays's date";
 cin>>dt;
 cout<<"Enter current month";
 cin>>mn;
 
 till=dt+7;
 
 
 for(i=0;i<size3;i++)
 { 
 if(dt==s3[i].date&&mn==s3[i].month)
  {
   cout<<"today is birthday of student with prn:"<<s3[i].prn;
  }
 }
  cout<<"Upcoming birthdays:";
 
  for(j=till;j>dt;j--)
  {
   for(i=0;i<size3;i++)
    {
     if(s3[i].date==j&&s3[i].month==mn)
     {
      
        flag=1;
        cout<<"Students with prn:"<<s3[i].prn;
        
      }
     }
    }
    
 if(till>31)
 {
  till2=till-31;
  mn2=mn+1;
 for(j=till2;j>0;j--)
  {
   for(i=0;i<size3;i++)
    {
     if(s3[i].date==j&&s3[i].month==mn2)
     {
      
        flag=1;
        cout<<"Students with prn:"<<s3[i].prn;
        
      }
     }
    }

  
    }
   
   
   if(flag==0)
   {
    cout<<"no birthdays";
   }
  }
  
   
    };
    int main()
    {
     stud c1;
     c1.input();
     c1.input2();
     c1.output2();
     c1.output();
     c1.sort();
     c1.sort2();
     c1.merge();
     c1.checkbday();
     return 0;
     }
  
  
