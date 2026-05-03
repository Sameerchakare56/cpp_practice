#include <iostream>

using namespace std ;

class CircularQueue{
    int* arr;
    int currSize , cap ;
    int f , r;

public :
CircularQueue(int size){
    cap = size ;
    arr = new int[cap];
    f = 0 ;
    r = -1;
}
void push(int data){
  if(currSize == cap){
    cout <<"CQ is FULL \n";
    return ;
   }  

   r = (r+1) % cap ;
   arr[r] = data ;
   currSize ++;
}
void pop(){
  if(empty()){
   cout << " CQ is EMPTY\n" ;
  }
  f = (f+1) % cap ; 
  currSize -- ;

}

int front(){
   if(empty()){
   cout << " CQ is EMPTY\n";
   }
   return arr[f];
}

bool empty(){
    currSize == 0;
}
};

int main(){
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    
    while(!cq.empty()){
        cout << cq.front() <<" " ;
        cq.pop();
    }
    cout << endl;
    
    return 0;
}