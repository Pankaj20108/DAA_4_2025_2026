class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int>result;
        int n=arr.size();
        priority_queue<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push({arr[i], i});
            while(p.top().second<=i-k){
                p.pop();
            }
            if(i>=k-1){
                result.push_back(p.top().first);
        }
        }
        return result;
    }
};
//Time Complexity:-O(nlogn)
//Space Complexity:-O(n)