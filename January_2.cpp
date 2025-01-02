class Solution {
private:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefix(n, 0);
        int i = 0;
        for(auto word : words){
            prefix[i] = isVowel(word[0]) && isVowel(word.back());
            if(i!=0)
            prefix[i] += prefix[i-1];
            i++;
        }
        vector<int>ans;
        for(auto query : queries){
            int left = query[0];
            int right = query[1];
            int isValid = isVowel(words[left][0]) && isVowel(words[left][words[left].size()-1]);
            ans.push_back(prefix[right] - prefix[left] + isValid);
        }
        return ans;
    }
};