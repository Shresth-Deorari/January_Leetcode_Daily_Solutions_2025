class Solution {
private :
    int findNumberOfBits(const int& n){
        int targetBits = 0;
        for (int i = 0; i < 32; i++) {
            targetBits += (n & (1 << i)) != 0;
        }
        return targetBits;
    }
public:
    int minimizeXor(int num1, int num2) {
        int currBits = findNumberOfBits(num1);
        int targetBits = findNumberOfBits(num2);
        int rem = 0;
        int diff = 0;
        if(currBits == targetBits){
            return num1;
        }
        if(currBits > targetBits){
            int rem = currBits - targetBits;
            int diff = 0;
            for(int i = 0;i<32 && rem; i++){
                if((num1 & (1<<i))){
                    diff += 1<<i;
                    rem--;
                }
            }
            return num1 - diff;
        }
        rem = targetBits - currBits;
        for(int i = 0;i<32 && rem; i++){
            if((num1 & (1<<i))==0){
                diff += 1<<i;
                rem--;
            }
        }
        return num1 + diff;
    }
};