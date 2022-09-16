
#include<iostream>
using namespace std;
int main()
{
	int at[10], bt[10], x[10];
	int waiting[10], turnaround[10], completion[10];
	int i, j, smallest, count = 0, time, n;
	double avg = 0, tt = 0, end;
	cout<<"Enter the number of processes:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter the arrival time and burst time of process"<<i+1<<" ";
		cin>>at[i];
		cin>>bt[i];
	}
	for(i=0;i<n;i++)
	{
		x[i] = bt[i];
	}
		bt[9] = 999;

		
	time = 0;
	while(count!= n)
	{
		
		smallest = 9;
		for(i=0;i<n;i++)
		{
			if (at[i]<=time && bt[i] < bt[smallest] && bt[i] > 0)
				smallest = i;
		}	
			
		bt[smallest] --;
		if (bt[smallest] == 0)
		{
			count ++;
			end = time+1;
			completion[smallest] = end;
			waiting[smallest] = end - at[smallest] - x [smallest];
			turnaround[smallest] = end - at[smallest];
			
		}
		time++;
	}
		
	cout<<"Process"<<"\t"<<"arrival time"<<"\t"<<"burst time"<<"\t"<<"Waiting time"<<"\t"<<"turrnaound time"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<"\t\t"<<at[i]<<"\t\t"<<x[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<endl;
		avg += waiting[i];
		tt += turnaround[i];
	}
	cout<<"\n Average waiting time = "<<avg/n<<"\n";
	cout<<"Average turanound time = "<<tt/n<<endl;
	return 0;	
	}

