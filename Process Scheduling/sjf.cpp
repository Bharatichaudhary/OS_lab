#include<iostream>
using namespace std;

int main(){
	int at[10],bt[10],wt[10],tat[10],n,burst,complete,temp,p[10];
	float avg_tat,avg_wt,TAT,WT;
	cout<<"Enter the no. of process:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter the arrival time and burst time of process"<<i+1<<" ";
		cin>>at[i];
		cin>>bt[i];
		p[i]=i+1;
	}
	
	complete=0;
//	int temp2=0;
	for(int i=0;i<n;i++){
			if(i==0){
				wt[i]=at[i];
				complete+=bt[i];
				tat[i]=complete-at[i];
			}
			else{
				
				for(int j=1;j<n;j++){
					if(bt[i]<bt[j]){
						temp=bt[i];
						bt[i]=bt[j];
						bt[j]=temp;
						temp=at[i];
						at[i]=at[j];
						at[j]=temp;
						temp=p[i];
						p[i]=p[j];
						p[j]=temp;
						//temp2=1;
					}
				}
			}
		}
		for(int i=1;i<n;i++){
			complete+=bt[i];
			tat[i]=complete-at[i];
			wt[i]=tat[i]-bt[i];
		}
	/*	cout<<"arranged order of process according to arrival time:"<<endl;
	for(int i=0;i<n;i++){
		cout<<"process"<<p[i]<<" "<<at[i]<<" "<<bt[i]<<" "<<complete<<endl;
	}	*/
	for(int i=0;i<n;i++){
		TAT+=tat[i];
		WT+=wt[i];
	}
	avg_tat=TAT/n;
	avg_wt=WT/n;
	cout<<"process\t arrival time\t"<<"burst time\t waiting time\t"<<"turnaround time"<<endl;
	for(int i=0;i<n;i++){
		cout<<p[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	cout<<"Average turnaraound time is: "<<avg_tat<<endl;
	cout<<"Average waiting time is: "<<avg_wt<<endl;
}

