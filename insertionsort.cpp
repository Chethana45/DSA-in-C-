#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> nums ={3,5,1,2,7};
    int n=nums.size();
  for(int i=0;i<n;i++){
      int key=nums[i];
      int j=i-1;
      while(j>=0&&nums[j]>key){
          nums[j+1]=nums[j];
          j--;
      }
      nums[j+1]=key;
      
    
            }
        
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
}
