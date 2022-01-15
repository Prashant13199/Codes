#include<iostream>
using namespace std;

int main(){
    int ds,gs,data[20],gen[20],i;
        cout<<"\nEnter data size in bits";
        cin>>ds;
        cout<<"\nEnter data";
        for(i=0;i<ds;i++){
            cin>>data[i];
        }
        
        cout<<"\nEnter generator size in bits";
        cin>>gs;
        cout<<"\nEnter generator";
        for(i=0;i<gs;i++){
            cin>>gen[i];
        }
        
        //Displaying data
         cout<<"\nOriginal data : ";
         for(i=0;i<ds;i++){
            cout<<data[i];
        }
        cout<<"\nGenerator : ";
         for(i=0;i<gs;i++){
            cout<<gen[i];
        }
        //Appending bits to data
        
        int ab = gs-1;
        for(i=ds;i<ds+ab;i++){
            data[i]=0;
        }
        cout<<"\nAfter appending data : ";
         for(i=0;i<ds+ab;i++){
            cout<<data[i];
        }
        
        //Process
        //cout<<"\ntemp";
        int temp[20],j,k;
        //temp=data;
         for(i=0;i<ds+ab;i++){
            temp[i]=data[i];
        }
        
        for(i=0;i<ds;i++){
            j=0,k=i;
                if(temp[k] >= gen[j])
                {
                    for(j=0,k=i;j<gs;j++,k++)
                    {
                        if((temp[k]==1 && gen[j]==1) ||  (temp[k]==0 && gen[j]==0))
                        {
                            temp[k]=0;
                        }
                        else{
                            temp[k]=1;
                        }
                    }
                }           
        }
        
        
        //CRC BITS
        
        int crc[20];
            for(i=0,j=ds;i<ab;j++,i++)
            {
                crc[i]= temp[j];
            }
            cout<<"\nCRC bits : ";
            for(i=0;i<ab;i++){
                cout<<crc[i];
            } 
            int tf[20];
            cout<<"\nTransmitted data : ";
             for(i=0;i<ds;i++){
               tf[i]=data[i];
            }
            for(i=ds,j=0;i<ds+ab;i++,j++){
                tf[i]=crc[j];
            }  
            
             for(i=0;i<ds+ab;i++){
                cout<<tf[i];
            }
        
        cout<<"\nReciever's End...";
        cout<<"\nRecieved data : ";
        
         for(i=0;i<ds+ab;i++){
            cout<<tf[i];
        }
        
        for(i=0;i<ds+ab;i++){
            temp[i]=tf[i];
        }
        
        
         for(i=0;i<ds;i++){
            j=0,k=i;
                if(temp[k] >= gen[j])
                {
                    for(j=0,k=i;j<gs;j++,k++)
                    {
                        if((temp[k]==1 && gen[j]==1) ||  (temp[k]==0 && gen[j]==0))
                        {
                            temp[k]=0;
                        }
                        else{
                            temp[k]=1;
                        }
                    }
                }           
        }
        
        int rem[20];
        
        for(i=0,j=ds;i<ab;j++,i++)
            {
                rem[i]= temp[j];
            }
            cout<"\nRemainder";
            for(i=0;i<ab;i++)
            {
                 cout<<rem[i]; //ccrc[i]= temp[j];
            }
        int flag=0;
        for(i=0;i<ab;i++)
            {
                if(rem[i]!=0)
                    flag=1;
            }
            if(flag==0)
                cout<<"\nRemainde is 0 so it is an errorless data";
            else
                cout<<"\nErroe occured while receiving  data";
                
           return 0;
        
}


