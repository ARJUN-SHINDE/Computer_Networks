#include<iostream>
using namespace std;

int main()
{	int i,d[10],p1,p4,p2,p8,e;
    cout<<"Enter code word of length 9 :";
    for(i=1;i<10;i++)
    cin>>d[i];
    
     p1=d[1]^d[3]^d[5]^d[7]^d[9];
     p2=d[2]^d[3]^d[6]^d[7];
     p4=d[4]^d[5]^d[6]^d[7];
     p8=d[8]^d[9];
		 e=p1+(p2*2)+(p4*4)+(p8*8); 
		   if(e==0)                    //it either returns 0 or the position with error
     {
         cout<<"\nNo Error in transmission";
     }
     else
     {
         cout<<"\nError in transmission,Error at bit "<<e;
     }
    return 0;

}
