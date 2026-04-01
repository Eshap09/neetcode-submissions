class Solution {
public:
    int characterReplacement(string s, int k) {
        int mf=0, ml=0,i=0,j=0;
        vector<int>freq(26,0);
        while(j<s.size()){
            freq[s[j]-'A']++;
            mf = max(mf, freq[s[j]-'A']);

            if(j-i+1>mf+k){
                freq[s[i]-'A']--;
                i++;
            }
            ml = max(ml,j-i+1);
            j++;
        }
        return ml;
    }
};
