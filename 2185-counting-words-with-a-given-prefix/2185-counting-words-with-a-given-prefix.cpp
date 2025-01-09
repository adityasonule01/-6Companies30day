class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count =0;
        for(auto word:words){
            bool isprefix = true;
            for(int i=0;pref[i];i++){
                if(word[i]!=pref[i]){
                    isprefix=false;
                    break;
                }
            }
            if(isprefix==true){
                count++;
            }
        }
        return count;
    }
};