#include <bits/stdc++.h> 
using namespace std; 
 
const int N=100; 
 
void fifo_page_replacement(int frame_size, int n,int pages[]) 
{ 
 	int mark[N];     queue<int> Q; 
    int page_faults=0; 
 
    for(int i=0; i<n; i++) 
    { 
        if(mark[pages[i]]==true) 
        { 
        }         else 
        { 
            Q.push(pages[i]);             
			mark[pages[i]]=true; 
            if(Q.size()>frame_size) 
            { 
                int p= Q.front();                 
				mark[p]=false; 
                Q.pop(); 
            } 
            page_faults++; 
             
        } 
 
    }    
    cout<<"Frame size: "<<frame_size<<endl;
	cout<<"Page faults: "<<page_faults<<endl;
	cout<<"Page Hits: "<<n-page_faults<<endl; 
 	return; 
} 
int main() 
{ 
 	int frame_size; 
	 int pages[N]; 
int n;  
cout<<"Enter the frame size:"; cin>>frame_size;  
    cout<<"Page Reference Stream Length: ";    
	 cin>>n; 
 cout<<"Page Reference Stream:\n";     
 for(int i=0; i<n; i++)        
  cin>>pages[i]; 
  	fifo_page_replacement(frame_size,n,pages);  	
	  return 0; 
} 
 

			 
						  
			 
						 					

