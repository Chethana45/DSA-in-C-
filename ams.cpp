class Solution {
public:
    bool isArmstrong(int n) {
           int ams=0;
           int num=n;
        int lastdigit;
        while(num>0){
             lastdigit= num%10;
            ams+= lastdigit*lastdigit*lastdigit;
            num=num/10;}
            return ams==n;

    }
};
