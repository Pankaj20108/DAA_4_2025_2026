#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lowerBound(vector<int> &nums, int x){
        int left=0;
        int right=nums.size()-1;
        while(left<right){//understand why you used '<' instead of '<='
            int mid=left+(right-left)/2;//If you want an answer in which you have to leave the loop then never use "<=".It will cause overflow
            if(nums[mid]<x){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        if(nums[left]<x){//If value is out of bound.
            return nums.size();
        }
        return left;
    }
int main(){
    vector<int>nums={3,4,4,7,8,12};
    int x=13;
    cout<<lowerBound(nums, x);
}