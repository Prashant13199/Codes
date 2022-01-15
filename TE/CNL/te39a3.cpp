#include<iostream>
using namespace std;

int main()
 {
   int data[11],i,datarec[11],c1,c2,c3,c4,c;
   
   cout<<"\nEnter bits one by one(7bits)";
   
   cin>>data[0]>>data[1]>>data[2]>>data[4]>>data[5]>>data[6]>>data[8];
   
   data[10] = data[8]^data[6]^data[4]^data[2]^data[0];
   data[9] = data[8]^data[5]^data[4]^data[1]^data[0];
   data[7] = data[6]^data[5]^data[4];
   data[3] = data[2]^data[1]^data[0];
   
   cout<<"\nEncoded data is:";
   for(i=0;i<11;i++)
    {
      cout<<data[i];
    }
    
   cout<<"\nEnter received bits one by one";
   for(i=0;i<11;i++)
     {
       cin>>datarec[i];
     }
   
   c1 = datarec[10]^datarec[8]^datarec[6]^datarec[4]^datarec[2]^datarec[0];
   c2 = datarec[9]^datarec[8]^datarec[5]^datarec[4]^datarec[1]^datarec[0];
   c3 = datarec[7]^datarec[6]^datarec[5]^datarec[4];
   c4 = datarec[3]^datarec[2]^datarec[1]^datarec[0];
   
   c=c4*8+c3*4+c2*2+c1*1;
   
   if(c == 0)
    {
      cout<<"\nNo error while transmission of data";
    }
   
   else {
            cout<<"\nError on postion: "<<c;
       
          cout<<"\nData received :";
           for(i=0;i<11;i++)
            {
                cout<<datarec[i];
            }
          cout<<"\ncorrected data is:";
          
         
		    if(datarec[11-c]==0)
		     	datarec[11-c]=1;
           else
		    	datarec[11-c]=0;
		   for (i=0;i<11;i++) 
		      {
		    	cout<<datarec[i];
	    	  } 
	   }
	
	return 0;
}
   
