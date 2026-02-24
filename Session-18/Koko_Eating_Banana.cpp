class Solution {
public:
    typedef long long ll;
    bool valid(vector<int>& piles, int mid, int n, int h){
        ll time=0;
        for(int i=0;i<n;i++){
            if(piles[i]%mid==0){
                time+=piles[i]/mid;
            }
            else{
                time+=piles[i]/mid+1;
            }
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll left=1;
        ll right=*max_element(piles.begin(), piles.end());
        int ans=0;
        int n=piles.size();
        while(left<=right){
            ll mid=left+(right-left)/2;
            if(valid(piles, mid, n, h)){
                right=mid-1;
                ans=mid;
            }
            else{
                left=mid+1;
            }

        }
        return ans;
        
    }
};