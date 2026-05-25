class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<char>s;
        int ts = 0;

        for(char ch : password){
            if (s.count(ch)){
                continue;
            }
            s.insert(ch);

            if(ch >= 'a' && ch <= 'z') {
                ts += 1;
            }else if(ch >= 'A' && ch <= 'Z') {
                ts += 2;
            }else if(ch >= '0' && ch <= '9'){
                ts += 3;
            }else if(ch == '!' || ch == '@' ||ch == '#' || ch == '$') {
                ts +=5;
            }
        }
        return ts;
        
    }
};