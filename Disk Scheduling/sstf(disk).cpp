
#include<iostream>
//#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
             int queue[100],t[100],head,seek=0,n,i,j,temp;
         // clrscr();
             cout<<"*** SSTF Disk Scheduling Algorithm ***\n";
             cout<<"Enter the size of Queue\t";
             cin>>n;
             cout<<"Enter the Queue\t";
             for(i=0;i<n;i++)
             {
                          cin>>queue[i];
             }
             cout<<"Enter the initial head position\t";
             cin>>head;
             for(i=1;i<n;i++)
             t[i]=abs(head-queue[i]);
             for(i=0;i<n;i++)
             {
                          for(j=i+1;j<n;j++)
                          {
                                       if(t[i]>t[j])
                                       {
                                                    temp=t[i];
                                                    t[i]=t[j];
                                                    t[j]=temp;
                                                    temp=queue[i];
                                                    queue[i]=queue[j];
                                                    queue[j]=temp;
                                       }
                         }
             }
             for(i=1;i<n-1;i++)
             {
                          seek=seek+abs(head-queue[i]);
                          head=queue[i];
             }
             cout<<"\nTotal Seek Time is "<<seek;
}
