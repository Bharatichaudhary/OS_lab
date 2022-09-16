
#include <iostream>
#include <stdlib.h>

#define LOW 0
#define HIGH 199
using namespace std;

int main(){
  int queue[20], head, q_size, i,j, seek=0, diff, max, temp, queue1[20], queue2[20], temp1=0, temp2=0;
 // float avg;

  cout<<"Enter the no of request: ";
  cin>>q_size;

  cout<<"Enter initial head position: ";
  cin>>head;

  cout<<"Enter the request:";

  for(i=0; i<q_size; i++){
    cin>>temp;
    //queue1 - elems greater than head
    if(temp >= head){
        queue1[temp1] = temp;
        temp1++;
    } else {
        queue2[temp2] = temp;
        temp2++;
    }
  }

  //sort queue1 - increasing order
  for(i=0; i<temp1-1; i++){
   for(j=i+1; j<temp1; j++){
       if(queue1[i] > queue1[j]){
         temp = queue1[i];
         queue1[i] = queue1[j];
         queue1[j] = temp;
       }
    }
  }

  //sort queue2 - decreasing order
  for(i=0; i<temp2-1; i++){
    for(j=i+1; j<temp2; j++){
      if(queue2[i] < queue2[j]){
          temp = queue2[i];
          queue2[i] = queue2[j];
          queue2[j] = temp;
      }
    }
  }

  if(abs(head-LOW) >= abs(head-HIGH)){

      for(i=1,j=0; j<temp1; i++,j++){
          queue[i] = queue1[j];
      }

      for(i=temp1+1, j=0; j<temp2; i++, j++){
          queue[i] = queue2[j];
      }

  } else {

      for(i=1,j=0; j<temp2; i++,j++){
          queue[i] = queue2[j];
      }

      for(i=temp2+1, j=0; j<temp1; i++, j++){
          queue[i] = queue1[j];
      }

  }

  queue[0] = head;

  for(j=0; j<q_size; j++){
      diff=abs(queue[j+1] - queue[j]);
        seek += diff;
        cout<<"Disk head moves from "<<queue[j]<<" to "<<queue[j+1]<<" with seek "<<diff<<endl;

  }

  cout<<"Total seek time is "<<seek;
 // avg = seek/(float)q_size;
 // printf("Average seek time is %f\n", avg);

  return 0;
}
