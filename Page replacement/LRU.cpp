 #include<iostream>
 using namespace std;
int n,nf;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;
int isHit(int data)
{
    hit=0;
    for(j=0; j<nf; j++)
    {
        if(p[j]==data)
        {
            hit=1;
            break;
        }
 
    }
 
    return hit;
}
void lru()
{
pgfaultcnt=0;
    for(i=0; i<nf; i++)
        p[i]=9999; 
    int least[50];
    for(i=0; i<n; i++)
    {
 
        cout<<"\nFor "<<in[i]<<":";
 
        if(isHit(in[i])==0)
        {
 
            for(j=0; j<nf; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i-1; k>=0; k--)
                {
                    if(pg==in[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0; j<nf; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
            pgfaultcnt++;
 
for (k=0; k<nf; k++)
    {
        if(p[k]!=9999)
            cout<<p[k];
    }        }
        else
            cout<<"No page fault!";
    }
	cout<<"\nTotal no of page faults: "<<pgfaultcnt;

}

 
int main()
{
    cout<<"\nEnter length of page reference sequence:";
    cin>>n;
    cout<<"\nEnter the page reference sequence:";
    for(i=0; i<n; i++)
        cin>>in[i];
    cout<<"\nEnter no of frames:";
    cin>>nf;
            lru();
}
