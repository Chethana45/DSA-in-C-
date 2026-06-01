#include <iostream>

using namespace std;

int main(){
    int n=4;
for(int i=0;i<n;i++){
          int start=0;
          if(i%2==0){
              start=0;
          }else{
              start=1;
          }
for(int j=1;j<=i;j++){
    cout<<start;
     start=1-start;
   
}
        
    cout<<endl;}




    return 0;
}
