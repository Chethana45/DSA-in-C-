class Solution{
public:
    bool palindromeCheck(string& s){
        return check(s, 0);
    }

    bool check(string& s, int i){

        if(i >= s.size()/2)
            return true;

        if(s[i] != s[s.size()-i-1])
            return false;

        return check(s, i+1);
    }
};
