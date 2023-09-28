class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // int ans = 0;

        // for(int i = 0 ; i < nums.size() ; i++){
        //     ans = ans^nums[i];
        // }

        
        // for(int i = 1  ; i < nums.size() ; i++){
        //     ans = ans^i;
        // }

        
        // return ans;
        int ans = 0;
        unordered_map<int, int> cur;
        for (int x: nums){
            cur[x]++;
        }
        
        for (auto& [x,c] : cur){
            if(cur.count(c) > 1){
                ans = x;
            }
        }
        return ans;
    }