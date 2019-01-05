// 400ms
class Solution {
public:
    int count;
    void DP(vector<int>& nums, int S, int index, int sum){
        
        if(index == nums.size()){
            if(sum == S) count++;
            return;
        }
        
        DP(nums, S, index+1, sum + nums[index]);
        DP(nums, S, index+1, sum - nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0 || nums.size() > 20 || S > 1000) return 0;
        
        DP(nums, S, 0, 0);
        return count;
    }
};
