class Solution{
public:
    void reverse(int arr[], int n,int i=0){
        if(i>=n/2)
        return;
        swap(arr[i],arr[n-i-1]);
        reverse(arr,n,i+1);
        
    }
};
