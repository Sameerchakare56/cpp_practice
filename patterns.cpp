#include <iostream>
using namespace std;

int main(){

   int n ; 
   cout << "enter the number : ";
   cin >>n;

//    square pattern
   for(int i =1 ; i<=n;i++){
       
       for(int j =1 ;j<=n;j++){
        cout<<j;
       }
   cout <<endl;
    }
//     ABCD
//     ABCD
//     ABCD
//     ABCD
   for(int i =1 ; i<=n;i++){
       char ch ='A';
       for(int j =1 ;j<=n;j++){
        cout<<ch;
        ch =ch+1;
       }
    cout <<endl;
   }

    cout<<endl;
// 123
// 456
// 789
   int m=1 ;
   for(int i =1 ; i<=n;i++){
      
       for(int j =1 ;j<=n;j++){
        cout<<m;
        m =m+1;
       }
    cout <<endl;
   }

   cout<<endl;
// ABC
// DEF
// GHI
   char m2='A' ;
   for(int i =1 ; i<=n;i++){
      
       for(int j =1 ;j<=n;j++){
        cout<<m2;
        m2 =m2+1;
       }
    cout <<endl;
   }
   cout<<endl;

// *
// **
// ***
   for(int i=0;i<n;i++){
    for(int j =0;j<i+1;j++){
        cout<<"* ";
    }
cout<<endl;
   }   cout<<endl;

// 1
// 22
// 333
// 4444
   for(int i=1;i<=n;i++){
    for(int j =0;j<i;j++){
        cout<<i;
    }
cout<<endl;
   }
cout<<endl;
// 1
// 12
// 123
// 1234
   for(int i=1;i<=n;i++){
    for(int j =1;j<=i;j++){
        cout<<j;
    }
cout<<endl;
   }
cout<<endl;

// 1
// 21
// 321
// 4321
   for(int i=0;i<n;i++){
    for(int j =i+1;j>0;j--){
        cout<<j;
    }
cout<<endl;
   }
   cout<<endl;
  
// 1
// 23
// 456
// 78910
   int flo =1;
  for(int i =1;i<=n;i++){
    for(int j =1; j<=i;j++ ){
    cout<<flo;
    flo =flo+1;
    }
    cout<<endl;
    
  }
      cout<<endl;

// 1111
//  222
//   33
//    4
  for(int i =0;i<n;i++){
   // space
   for(int j= 0;j<i;j++){
      cout<<" ";
   }
   for(int j =0;j<n-i;j++){
      cout<<(i+1) ;
   }

   cout<<endl;
  }
   cout<<endl;

//    1
//   121
//  12321
// 1234321
   for(int i =0;i<n;i++){
      for(int j =0;j<n-i-1;j++){
         cout<<" ";
      }
      for(int j = 1;j<=i+1;j++){
         cout<<j;
      }
      for(int j=i;j>0;j--){
         cout<<j;
      }
      cout<<endl;
   }
      cout<<endl;

//    *
//   * *
//  *   *
// *     *
//  *   *
//   * *
//    *      

   // top
   for(int i =0;i<n;i++){
      for(int j =0;j<n-i-1;j++){
         cout<<" ";
      } cout<<"*";
      if(i !=0){
         // space
         for(int j =0;j<2*i-1;j++){
            cout<<" ";
         }
         cout<<"*";
      }
      cout<<endl;

   }
   // bottom
   for(int i =0;i<n-1;i++){
      for(int j = 0;j<i+1;j++){
         cout<< " ";
      }
      cout<<"*";
      if(i!=n-2){
         for(int j=0;j<2*(n-i)-5;j++){
            cout<<" ";

         }cout<<"*";
      }cout<<endl;
   }
   cout<<endl;

// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *
   for(int i=1;i<=2*n;i++){
      for(int j =1;j<=2*n;j++){
      if(i<=n){
        if(j<=i||j>2*n-i){
         cout<<"*";
        }else{cout<<" ";}
      }
      else{
      if(j<=2*n-i+1||j>i-1){
         cout<<"*";
      }else{cout<<" ";}
    }
   }cout<<endl;
   }
    return 0;
}
