#include<iostream>
using namespace std;

class complex
{
        public:
	float x,y;
	
	
		complex()
		{ }
			complex(float real, float img)
			{
				x=real; y=img;
			}
	
			complex operator+(complex);
			complex operator-(complex);
			complex operator*(complex);
			
              friend void operator>>(istream& , complex&);
              friend void operator<<(istream& , complex&);			
};

complex complex::operator+(complex c)
{
	complex temp;
	temp.x=x+c.x;
	temp.y=y+c.y;
	return (temp);
}

complex complex::operator-(complex c)
{
	complex tempo;
	tempo.x=x-c.x;
	tempo.y=y-c.y;
	return (tempo);
}

complex complex::operator*(complex c)
{
	complex tem;
	tem.x=(x*c.x) - (y*c.y);
	tem.y=(x*c.y) + (y*c.x);
	return (tem);
}



void operator>>(istream& s , complex& c)
{
 cout<<"Enter complex number c";
 s>>c.x;
 s>>c.y;
}

void operator<<(ostream& t , complex& c)
{
 cout<<"complex number is";
 t<<c.x<<"+"<<c.y<<"i";
}

int main()
{	complex c1,c2,c3,c4,c5;int z,n;

  do
     {
      cin>>c1;
      cin>>c2;
      cout<<"\n"<<c1;
      cout<<"\n"<<c2;
      cout<<"\nEnter 1 for addition"<<endl;
      cout<<"Enter 2 for subtraction"<<endl;
      cout<<"Enter 3 for multiplication"<<endl;
      cin>>z;
         switch(z)
         {
	
	   case 1:c3 = c1 + c2;cout<<"\n"<<c3;break;
	   case 2:c4 = c1 - c2;cout<<"\n"<<c4;break;
	   case 3:c5 = c1 * c2;cout<<"\n"<<c5;break;
        }
 cout<<"If u want to continue press 1";
 cin>>n;
  }
 while(n==1);
 return 0;
}


