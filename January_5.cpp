class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>effectiveShift(s.size()+1, 0);
        for(auto i : shifts){
            int start = i[0];
            int end = i[1];
            int direction = i[2]==1?1:-1;
            effectiveShift[start] += direction;
            effectiveShift[end+1] -= direction;
        }
        int cumulativeShift = 0;
        for (int i = 0; i < s.size(); ++i) {
            cumulativeShift += effectiveShift[i];
            int shift = cumulativeShift % 26;
            if (shift < 0) shift += 26;             
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return s;
    }
};