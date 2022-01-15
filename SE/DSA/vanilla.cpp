#include<iostream>
using namespace std;

class node
{	public:
	int rollno;
	node *next, *prev;
	
	node(int r)
	{
		rollno=r;
		next=NULL;
		prev=NULL;
		
	}
	
};

class SE
{
	node *head,*head1,*head2,*head3,*head4,*head5,*head6,*head7;
	public:
	SE()
	{
		head=NULL;
		head1=NULL;
		head2=NULL;
		head3=NULL;
		head4=NULL;
		head5=NULL;
		head6=NULL;
		head7=NULL;
	}
	void input()
	{	
		int n;
		cout<<"\nEnter no of students ";
		cin>>n;
		int r;
		node *temp,*nn;
		for(int i=0;i<n;i++)
		{	
			
			nn=new node(i+1);
			if (head==NULL)
			{
				head=nn;
			}
			else
			{
				temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=nn;
				nn->prev=temp;
			}
		}
		
		int n1;
		cout<<"\nEnter no of students that like vanilla  ";
		cin>>n1;
		int r1;
		node *temp1,*nn1;
		for(int i=0;i<n1;i++)
		{	
			cout<<"\nEnter roll no of student "<<i+1<<" that like vanilla  ";
			cin>>r1;
			nn1=new node(r1);
			if (head1==NULL)
			{
				head1=nn1;
			}
			else
			{
				temp1=head1;
				while(temp1->next!=NULL)
				{
					temp1=temp1->next;
				}
				temp1->next=nn1;
				nn1->prev=temp1;
			}
		}
		
		int n2;
		cout<<"\nEnter no of students that like chocolate  ";
		cin>>n2;
		int r2;
		node *temp2,*nn2;
		for(int i=0;i<n2;i++)
		{	
			cout<<"\nEnter roll no of student "<<i+1<<"  ";
			cin>>r2;
			nn2=new node(r2);
			if (head2==NULL)
			{
				head2=nn2;
			}
			else
			{
				temp2=head2;
				while(temp2->next!=NULL)
				{
					temp2=temp2->next;
				}
				temp2->next=nn2;
				nn2->prev=temp2;
			}
		}
		
	}
	
	
	void display()
	{
		cout<<"\nStudents in class    ";
		node *temp;
		temp=head;
		if(temp==NULL)
		{
			cout<<"\nList is empty..";
			
		}
		else
		{	
			
			while(temp!=NULL)
			{
				cout<<temp->rollno<<" ";
				temp=temp->next;
			}
		}
		
		
		cout<<"\n\nStudents in class that like vanila are : ";
		node *temp1;
		temp1=head1;
		if(temp1==NULL)
		{
			cout<<"\nList is empty..";
			
		}
		else
		{	
			
			while(temp1!=NULL)
			{
				cout<<temp1->rollno<<" ";
				temp1=temp1->next;
			}
		}
		
		
		cout<<"\n\nStudents in class that like chocolate are : ";
		node *temp2;
		temp2=head2;
		if(temp2==NULL)
		{
			cout<<"\nList is empty..";
			
		}
		else
		{	
			
			while(temp2!=NULL)
			{
				cout<<temp2->rollno<<" ";
				temp2=temp2->next;
			}
		}
	}
	
	
	void unio()
	{	
		int n,flag=0;
		cout<<"\n\nStudents that like either of two or both : ";
		node *temp1,*temp2,*temp3,*nn3;
		temp1=head1;
		temp3=head3;
		while(temp1!=NULL)
		{	
			nn3=new node(temp1->rollno);
			if(head3==NULL)
			{
				head3=nn3;
			}
			else
			{
				temp3=head3;
				while(temp3->next!=NULL)
				{
					
					temp3=temp3->next;
				}
				temp3->next=nn3;
				nn3->prev=temp3;
			}
			
			temp1=temp1->next;
			
		}
		temp1=head1;
		temp2=head2;
		while(temp2!=NULL)
		{
			temp1=head1;
			while(temp1!=NULL)
			{
				if(temp2->rollno==temp1->rollno)
				{	flag=0;
					break;
					
			
				}
			
				else
				{	
					flag=1;
					temp1=temp1->next;
				}
			}
			if(flag==1)
			{	
				nn3=new node(temp2->rollno);
				if(head3==NULL)
				{
					head3=nn3;
				}
				else
				{
				temp3=head3;
					while(temp3->next!=NULL)
					{
					
					temp3=temp3->next;
					}
					temp3->next=nn3;
					nn3->prev=temp3;
				}
							
			}
			temp2=temp2->next;
		}
		
		temp3=head3;
		if(temp3==NULL)
		{
			cout<<"\nList is empty..";
			
		}
		else
		{	
			
			while(temp3!=NULL)
			{
				cout<<temp3->rollno<<" ";
				temp3=temp3->next;
			}
		}
		
		
		
	}
	 
	 void both()
	 {
	 	cout<<"\n\nStudents that like both the ice creams.: ";	
		 node *temp4,*temp1,*temp2,*nn3;
	 	temp1=head1;
	 	temp2=head2;
	 	while(temp1!=NULL)
	 	{
	 		temp2=head2;
	 		while(temp2!=NULL)
	 		{
	 			if(temp1->rollno==temp2->rollno)
	 			{
	 				nn3=new node(temp2->rollno);
	 				if(head4==NULL)
	 				{
	 					head4=nn3;
	 					
					 }
					 else
					 {
					 	temp4=head4;
					 	while(temp4->next!=NULL)
					 	{
					 		temp4=temp4->next;
						 }
						 temp4->next=nn3;
						 nn3->prev=temp4;
					 }
	 				break;
				 }
				else{
				 		temp2=temp2->next;
				 	} 
			}
			temp1=temp1->next;
			
		}
		
		temp4=head4;
		if(temp4==NULL)
		{
			cout<<"List is Empty......";
		}
		
		
		else{
				while(temp4!=NULL)
				{
					cout<<temp4->rollno<<" ";
					temp4=temp4->next;
				}
			}
		
		 }
	
		
	void none()
	{
		cout<<"\n\nStudents that like none of the ice creams.: ";	
		 node *temp5,*temp1,*temp2,*nn3;
	 	temp1=head;
	 	temp2=head3;
	 	while(temp1!=NULL)
	 	{
	 		temp2=head3;
	 		while(temp2!=NULL)
	 		{
	 			if(temp1->rollno==temp2->rollno)
	 			{
	 				temp1=temp1->next;
	 				break;
				}
				temp2=temp2->next;
			}
			if (temp2==NULL)
			{
				nn3=new node(temp1->rollno);
	 				if(head5==NULL)
	 				{
	 					head5=nn3;
	 					
					 }
					 else
					 {
					 	temp5=head5;
					 	while(temp5->next!=NULL)
					 	{
					 		temp5=temp5->next;
						 }
						 temp5->next=nn3;
						 nn3->prev=temp5;
					 }	
			
			temp1=temp1->next;
			}
				
		}
		temp5=head5;
		if(temp5==NULL)
		{
			cout<<"List is Empty......";
		}
		
		
		else{
				while(temp5!=NULL)
				{
					cout<<temp5->rollno<<" ";
					temp5=temp5->next;
				}
			}
		
		 }
		 
		 void onlyv()
		 {
		 	cout<<"\n\nStudents that like only vanilla.: ";	
		 node *temp6,*temp1,*temp2,*nn3;
	 	temp1=head1;
	 	temp2=head2;
	 	while(temp1!=NULL)
	 	{
	 		temp2=head2;
	 		while(temp2!=NULL)
	 		{
	 			if(temp1->rollno==temp2->rollno)
	 			{
	 				temp1=temp1->next;
	 				break;
				}
				temp2=temp2->next;
			}
			if (temp2==NULL)
			{
				nn3=new node(temp1->rollno);
	 				if(head6==NULL)
	 				{
	 					head6=nn3;
	 					
					 }
					 else
					 {
					 	temp6=head6;
					 	while(temp6->next!=NULL)
					 	{
					 		temp6=temp6->next;
						 }
						 temp6->next=nn3;
						 nn3->prev=temp6;
					 }	
			
			temp1=temp1->next;
			}
				
		}
		temp6=head6;
		if(temp6==NULL)
		{
			cout<<"List is Empty......";
		}
		
		
		else{
				while(temp6!=NULL)
				{
					cout<<temp6->rollno<<" ";
					temp6=temp6->next;
				}
			}
		
	 	
		 }
		 
		 
	  void onlyc()
		 {
		 	cout<<"\n\nStudents that like only chocolate.: ";	
		 node *temp7,*temp1,*temp2,*nn3;
	 	temp1=head1;
	 	temp2=head2;
	 	while(temp2!=NULL)
	 	{
	 		temp1=head1;
	 		while(temp1!=NULL)
	 		{
	 			if(temp1->rollno==temp2->rollno)
	 			{
	 				temp2=temp2->next;
	 				break;
				}
				temp1=temp1->next;
			}
			if (temp1==NULL)
			{
				nn3=new node(temp2->rollno);
	 				if(head7==NULL)
	 				{
	 					head7=nn3;
	 					
					 }
					 else
					 {
					 	temp7=head7;
					 	while(temp7->next!=NULL)
					 	{
					 		temp7=temp7->next;
						 }
						 temp7->next=nn3;
						 nn3->prev=temp7;
					 }	
			
			temp2=temp2->next;
			}
				
		}
		temp7=head7;
		if(temp7==NULL)
		{
			cout<<"List is Empty......";
		}
		
		
		else{
				while(temp7!=NULL)
				{
					cout<<temp7->rollno<<" ";
					temp7=temp7->next;
				}
			}
		
	 	
		 }
		 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	
};


int main()
{
	int choice;
	char ch;
	SE class1;
	do
	{
	cout<<"\nWhat do you want to perform?\n1.Input data\n2.Display data\n3.Union \n4.Both the icecreams\n5.None of the icecreams\n6.Only vanilla\n7.Only chocolate\n";
	cin>>choice;
	switch(choice)
	{
	case 1:
	class1.input();
	break;
	case 2:
	class1.display();
		break;
	case 3:
	class1.unio();
		break;
	case 4:
	class1.both();
		break;
	case 5:
	class1.none();
		break;
	case 6:
	class1.onlyv();
		break;
	case 7:
	class1.onlyc();
		break;
	default:
		cout<<"\n\nWrong input!!!!!!!!!!\n";
	}
	cout<<"\nDO YOU WANT TO CONTINUE? y/n";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
	
	return 0;		
	}

