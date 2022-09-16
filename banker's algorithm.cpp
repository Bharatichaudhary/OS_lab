#include<iostream>
using namespace std;
int main(){
	int p[10],allocation[10][10],max[10][10],available[10],n1,n2,i,j,need[10][10],safe,seq,order[10];
	cout<<"Enter the no. of process(max 10): ";
	cin>>n1;
	cout<<"\nEnter the no. of resources(max 10): ";
	cin>>n2;
	for(i=0;i<n1;i++){
		//cout<<"Enter the value for process "<<i+1<<endl;
		cout<<"Enter the allocation for process "<<i+1<<": ";

		for(j=0;j<n2;j++){
			cin>>allocation[i][j];	
		}
		cout<<"Enter the maximum required for process"<<i+1<<": ";
		for(j=0;j<n2;j++){
			cin>>max[i][j];	
		}
	}
	cout<<"Enter the available resources: ";
	for(j=0;j<n2;j++){
			cin>>available[j];	
	}
	for(i=0;i<n1;i++){
		cout<<"Resources needed for process "<<i+1<<": ";
		for(j=0;j<n2;j++){
			need[i][j]=max[i][j]-allocation[i][j];
			cout<<need[i][j]<<" ";
		}
		cout<<"\n";	
		order[i]=0;			
	}
	do{
	for(i=0;i<n1;i++){
		safe=1;
		if(order[i]==0){
		
		cout<<"For Process "<<i+1<<endl;
		for(j=0;j<n2;j++){
			if(need[i][j]>available[j]){
				safe=0;
			}
		}
		if(safe==1){
			cout<<"Process "<<i+1<<" is in safe state"<<endl;
			for(j=0;j<n2;j++){
				available[j]=available[j]+allocation[i][j];
			}
			seq++;
			order[i]=seq;	
		}
		else{
			cout<<"Process "<<i+1<<" is not in safe state"<<endl;
			
		}
	}
	}
}while(seq<n1);
cout<<"Sequence of process:";
for(i=0;i<n1;i++){
	for(j=0;j<n1;j++){
		if(order[j]==i+1)
		cout<<"process "<<j+1<<">>";
	}
}
}

