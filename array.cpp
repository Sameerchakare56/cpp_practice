#include <iostream>
using namespace std;


int linearSearch(int arr[],int size,int target ){
   for(int i= 0 ;i<size;i++){
      if(arr[i]==target){
         return i;
      }
   }
   return -1;

}

void reversearray(int arr[],int size){
   int start =0,end =size -1;

   while (start<end)
   {
      swap(arr[start],arr[end]);
      start ++;
      end --;
      /* code */
   }
   

}

int sumofarray(int arr[], int size){
   int sum = 0 ;
   for(int i= 0 ;i<size;i++){
      sum += arr[i];
      }
   return sum ;
}

void swapminormax(int arr[],int size){
   int smallest = INT8_MAX;
   int small_ind =0;
   for(int i = 0 ;i <size;i++){
   if(arr[i]<smallest){
        smallest = arr[i];
        small_ind =i;

    }
   }
   int largest = INT8_MIN;
   int largest_in =0;
   for(int i = 0 ;i <size;i++){
    if(arr[i]>largest){
        largest = arr[i];
        largest_in = i;
    }
   }
   swap(arr[largest_in],arr[small_ind]);
}


int main(){
   int marks[5]={65,87,97,45,54};
   double price[] ={99.9,54.5,455}; 
   cout <<marks[2]<<endl;
   marks[3]= 65;
      cout <<marks[3];

   int smallest = INT8_MAX;
   for(int i = 0 ;i <(sizeof(marks)/sizeof(int));i++){
    smallest = min(marks[i], smallest);
    // if(marks[i]<smallest){
    //     smallest = marks[i];
    // }
   }
   int largest = INT8_MIN;
   int in =0;
   for(int i = 0 ;i <(sizeof(marks)/sizeof(int));i++){
   //  largest = max(marks[i], largest);
    if(marks[i]>largest){
        largest = marks[i];
        in = i;
        
        
    }
   }
   cout<<"\nsmallest = "<< smallest<<endl;
   cout<<"\nlargest  = "<< largest<<endl;
   cout<<"\nlargest  = "<< in<<endl;

   int arr[]= {54,646,48,41,1,2,3,45,6,4,6};
   int size =(sizeof(arr)/sizeof(int));
   int target = 6;

   cout <<linearSearch(arr,size,target)<<endl;
   reversearray(arr,size);
   for(int i =0;i<size;i++){
      cout << arr[i] <<" ";
   }
   cout <<endl;
   cout <<sumofarray(arr, size)<<endl;
   swapminormax(arr, size);
   for(int i =0;i<size;i++){
      cout << arr[i] <<" ";
   }
   cout <<endl;


   for(int i =0;i<size;i++){
      cout << arr[i] <<" ";
   }
   cout <<endl;
   return 0 ;


}