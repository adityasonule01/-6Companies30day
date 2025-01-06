class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>answer(n,0);
        int curvalue=0;
        int currvaluesum =0;
        for(int i=0;i<n;i++){
            answer[i]+=currvaluesum;
            curvalue += boxes[i]=='0'?0:1;
            currvaluesum += curvalue;
        }
        
          curvalue=0;
        currvaluesum =0;
        for(int i=n-1;i>=0;i--){
            answer[i]+=currvaluesum;
            curvalue += boxes[i]=='0'?0:1;
            currvaluesum += curvalue;
        }
        return answer;
    }
};