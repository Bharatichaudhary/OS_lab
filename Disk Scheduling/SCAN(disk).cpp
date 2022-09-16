#include <iostream>
#include<math.h>

using namespace std;

int main()
{
  //  clrscr();
    int n,d[8],a,b,c=0,j,i=0;
    char ch='y';
    cout<<"Enter no. of request : ";
    cin>>n;
    cout<<"enter value of initial head position : ";
    cin>>a;


    cout<<"Enter the requests ";

    for(i=0;i<n;i++)
    {
        cin>>d[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {

            if(d[i]<d[j])
            {
                b=d[i];
                d[i]=d[j];
                d[j]=b;
            }

        }
    }

    for(i=0;i<n;i++)
    {
        if(d[i]>a)
        {
            j=i;
            break;
        }
    }

    c=0;
    b=0;

    do
    {
        c+=abs(b-d[j]);
        b=d[j];
        j++;
    }while(j<n);

    c=c+a;
    cout<<" \nTotal head movement = "<<c<<" cylinders";
    //getch();
}
