#include <iostream>

using namespace std;

int main(){
    int n=6;
for(int i=0;i<n;i++){
for(int j=0;j<(n-i-1);j++){
   cout<<" ";
}for(int j=0;j<=i;j++){
 cout<<char('A'+j);}
 for(int j=i-1;j>=0;j--){
   cout<<char('A'+j);}
    cout<<endl;}

    return 0;
}
