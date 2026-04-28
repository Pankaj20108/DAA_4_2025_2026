class Solution {
public:
    int LIS(vector<int>& nums, vector<vector<int>>& dp, int i, int last, int n){
        if(i==n){
            return 0;
        }
        if(dp[i][last+1]!=-1){
            return dp[i][last+1];
        }
        int pick=0;
        if(last==-1||nums[i]>nums[last]){
            pick=1+LIS(nums, dp, i+1, i, n);
        }
        int notpick=LIS(nums, dp, i+1, last, n);
        return dp[i][last+1]=max(pick, notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int last=-1;
        int i=0;
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return LIS(nums, dp, i, last, n);
        
    }
};