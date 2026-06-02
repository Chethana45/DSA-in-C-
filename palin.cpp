class Solution {
public:
    bool isPalindrome(int n) {
        int num=n;
           int reverse=0;
        int lastdigit;
        while(num>0){
             lastdigit= num%10;
            reverse=reverse*10+lastdigit;
            num=num/10;}
            return reverse==n;

    }
};
