class Solution {
public:
    bool isAnagram(string s, string t) {
        // just check the lenght first
        if(s.length() != t.length()) return false;

        // now sort them
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // now loop and compare
        for(int i = 0; i < s.length(); i++){
            if(s[i] != t[i]){
                return false;
            }
                

        }
        return true;


    }
};
