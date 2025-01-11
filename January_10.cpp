class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> target(26, 0);
        
        for (const auto& word : words2) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                target[i] = max(target[i], freq[i]);
            }
        }

        vector<string> ans;
        for (const auto& word : words1) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < target[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
