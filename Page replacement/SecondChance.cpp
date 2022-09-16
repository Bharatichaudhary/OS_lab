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
 int getHitIndex(int data)
{
    int hitind;
    for(k=0; k<nf; k++)
    {
        if(p[k]==data)
        {
            hitind=k;
            break;
        }
    }
    return hitind;
}
void secondchance()
{
    int usedbit[50];
    int victimptr=0;
pgfaultcnt=0;
    for(i=0; i<nf; i++){
	
        p[i]=9999;    
	//for(i=0; i<nf; i++)
        usedbit[i]=0;}
    for(i=0; i<n; i++)
    {
        cout<<"\nFor "<<in[i]<<" :";
        if(isHit(in[i]))
        {
            cout<<"No page fault!";
            int hitindex=getHitIndex(in[i]);
            if(usedbit[hitindex]==0)
                usedbit[hitindex]=1;
        }
        else
        {
            pgfaultcnt++;
            if(usedbit[victimptr]==1)
            {
                do
                {
                    usedbit[victimptr]=0;
                    victimptr++;
                    if(victimptr==nf)
                        victimptr=0;
                }
                while(usedbit[victimptr]!=0);
            }
            if(usedbit[victimptr]==0)
            {
                p[victimptr]=in[i];
                usedbit[victimptr]=1;
                victimptr++;
            }

    for (k=0; k<nf; k++)
    {
        if(p[k]!=9999)
            cout<<p[k];
    }
  
        }
        if(victimptr==nf)
            victimptr=0;
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
           // fifo();
           // optimal();
            //lru();
            //lfu();
           secondchance();
}
