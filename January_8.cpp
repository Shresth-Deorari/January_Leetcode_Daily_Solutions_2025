class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0;i< words.size(); i++){
            string curr = words[i];
            for(int j =i+1; j<words.size(); j++){
                if(curr.size()>words[j].size())continue;
                string pre = words[j].substr(0, curr.size());
                string suff = words[j].substr(words[j].size() - curr.size(), curr.size());
                if(pre == curr && suff == curr){
                    ans++;
                }
            }
        }
        return ans;
    }
};