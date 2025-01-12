class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) return false;
        int balance = 0, free = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                free++;
            } else if (s[i] == '(') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;
                } else if (free > 0) {
                    free--;
                } else {
                    return false;
                }
            }
        }
        if (balance > free) return false;
        balance = 0, free = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                free++;
            } else if (s[i] == ')') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;
                } else if (free > 0) {
                    free--;
                } else {
                    return false;
                }
            }
        }
        
        return balance <= free;
    }
};
