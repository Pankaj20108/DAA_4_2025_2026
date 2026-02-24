#include<bits/stdc++.h>
using namespace std;
bool can_paint(vector<int>&nums, int mid, int A, int n){
    int sum=0;
    int painters=1;
    for(int i=0;i<n;i++){
        if(nums[i]+sum>mid){
            painters++;
            sum=nums[i];
        }
        else{
            sum+=nums[i];
        }
    }
    if(painters<=A){
        return true;
    }
    else{
        return false;
    }
}
int paint(vector<int>nums, int left, int right, int A, int B, int n){
    int k=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(can_paint(nums, mid, A, n)){
            k=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return (k*B)%10000003;
}
int main(){
    vector<int>nums={1,8,11,3};
        int A=3;
        int B=2;
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(), 0);
        int n=nums.size();
        cout<<paint(nums, left, right, A, B, n);
    }
