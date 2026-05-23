int romanToInt(char* s) {
    int ans=0;
    int num=0;
    for(int i= strlen(s)-1;i>=0;i--){
        switch(s[i]){
            case 'I':
            num =1;
            break;
            case 'V':
            num=5;
            break;
            case 'X':
            num = 10;
            break;
            case 'L':
            num =50;
            break;
            case 'C':
            num= 100;
            break;
            case 'D':
            num=500;
            break;
            case 'M':
            num =1000;
            break; }
            if(4*num<ans)
                ans-=num;
             else
                ans+=num;
    }
            return ans;

        
    }
    
