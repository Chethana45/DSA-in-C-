int reverse(int x){
        int reverse=0;
            while(x!=0){
                int lastdigit=x%10;
                    if(reverse > 214748364 || reverse < -214748364)
                                return 0;
                                    reverse = reverse *10+lastdigit;
                                        x =x/10;}
                                            return reverse;

                                            }
