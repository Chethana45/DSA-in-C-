bool isPalindrome(int x) {
    int reverse=0;
    int n=x;
    if(x<0){
        return false;
    }
    
    while(n!=0){
        int lastdigit= n%10;
          if(reverse > 214748364 || reverse < -214748364)
            return false;
       reverse = reverse*10+lastdigit;
        

        n=n/10;
    }

    if(reverse==x){
        return true;    }
        else{
            return false;
        }}
    
