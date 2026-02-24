#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;
int upperbound(vector<int>&nums, int x){
    int l=0;
    int r=nums.size()-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(nums[mid]>x){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(nums[l]<=x){
        return nums.size();
    }
    else{
        return l;
    }
}
int main(){
    vector<int>nums={1,3,3,5,7,8};
    int x=9;
    cout<<upperbound(nums, x);
}
