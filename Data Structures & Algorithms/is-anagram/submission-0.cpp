class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size()!=t.size()) return false;
       unordered_map<char,int>mp;
       for(char c:s){
            mp[c]++;
       }
       int count = mp.size();

       for(char c:t){
        if(mp.find(c)!= mp.end()){
            mp[c]--;
            if(mp[c]==0){
                mp.erase(c);
                count--;
            }
        }
       }
       return count ==0;
    }
};
