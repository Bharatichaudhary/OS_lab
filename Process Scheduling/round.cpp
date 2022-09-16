#include <iostream>
using namespace std;
// #include<conio.h>

int main()
{
    // initlialize the variable name
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    cout<<" Total number of process in the system: ";
    cin>>NOP;
    y = NOP; // Assign the number of process to variable y

    // Use for loop to enter the details of the process like Arrival time and the Burst Time
    for (i = 0; i < NOP; i++)
    {
        cout<<"\n Enter the Arrival and Burst time of the Process"<< i + 1<<":";
        cin>>at[i];
        cin>>bt[i];
        temp[i] = bt[i]; // store the burst time in temp array
    }
    // Accept the Time qunat
    cout<<"Enter the Time Quantum for the process: ";
    cin>>quant;
    // Display the process No, burst time, Turn Around Time and the waiting time
    cout<<"\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ";
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0) // define the conditions
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--; // decrement the process no.
            cout<<"\nProcess No["<<i+1<<"] \t\t "<<bt[i]<<"\t\t\t\t "<<sum-at[i]<<"\t\t\t "<<sum - at[i] - bt[i];
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == NOP - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    // represents the average waiting time and Turn Around time
    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;
    cout<<"\n Average Turn Around Time: "<<avg_wt;
    cout<<"\n Average Waiting Time: "<<avg_tat;
}
