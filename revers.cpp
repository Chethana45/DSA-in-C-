class Solution {
public:
    int reverseNumber(int n) {
        int reverse=0;
        int lastdigit;
        while(n>0){
             lastdigit= n%10;
            reverse=reverse*10+lastdigit;
            n=n/10;
        }
return reverse;
    }
};
