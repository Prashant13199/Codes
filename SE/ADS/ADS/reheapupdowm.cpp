//============================================================================
// Name        : reheapupdowm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#define MAX 20
using namespace std;

class heap
{
	int n,i,value,array[MAX];
public:
	int x;
	void init()
	{
		for(i=0;i<MAX;i++)
		{
			array[i]=0;
		}
	}
	void create();
	//void insert();
	void reheapup(int);
	void reheapdown(int);
	void display();
	void delete1();
	void sort();

};

void heap::create()
{
	init();
	cout<<"Enter the number of subject : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter value : ";
		cin>>value;
		array[i]=value;
		reheapup(i);
	}
	for(i=0;i<n;i++)
			{
				cout<<array[i]<<"  ";
			}
}

void heap::reheapup(int i)
{
	int temp;
	while(((i-1)/2)>=0 && array[i]>array[(i-1)/2])
	{
		temp=array[(i-1)/2];
		array[(i-1)/2]=array[i];
		array[i]=temp;
		i=(i-1)/2;

	}
}

void heap::sort()
{
	x=n;
	for(i=0;i<n;i++)
	{
		delete1();
	}
	cout<<"sorted array :";

	for(i=0;i<n;i++)
		{
			cout<<array[i]<<"  ";
		}
cout<<"minimum value : ";
cout<<array[0];
cout<<"maximum value : ";
cout<<array[n-1];

}

void heap::delete1()
{
	int temp;
	temp=array[x-1];
	array[x-1]=array[0];
	array[0]=temp;
	reheapdown(0);

}

void heap::reheapdown(int i)
{
	int j,temp,flag=1;
	x=x-1;
	while(((2*i)+1)<x && flag==1)
	{
		j=(2*i)+1;
		if(j+1<x && array[j]<array[j+1])
		{
			j=j+1;
		}
		if(array[i]>array[j])
		{
			flag=0;
		}
		else
		{
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			i=j;
		}
	}

}

int main()
{
	heap hp;
	hp.create();
	hp.sort();

}
