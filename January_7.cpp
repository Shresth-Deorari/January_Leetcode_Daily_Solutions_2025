class Solution {    
    static bool comparator(string & a, string &b){
        return a.size()<=b.size();
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n = words.size();
        sort(words.begin(), words.end(), comparator);
        for(int i =0;i<n;i++){
            string comp = words[i];
            string match = "";
            for(int j= i+1;j<n && match==""; j++){
                string curr = words[j];
                string temp = curr.substr(0,comp.size());
                if(temp == comp){
                    match = temp;
                    break;
                }
                for(int k = comp.size(); k<curr.size(); k++){
                    temp.erase(0, 1);
                    temp.push_back(curr[k]);
                    if(temp == comp){
                        match = temp;
                        break;
                    }
                }
            }
            if(match!="")ans.push_back(match);
        }
        return ans;
    }
};