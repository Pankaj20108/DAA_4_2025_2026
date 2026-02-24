#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool isplaced(vector<int>&v , int mid, int n, int a){
    int cows=1;
    int last_pos=v[0];
    for(int i=1;i<n;i++){
      if(v[i]-last_pos>=mid){
         cows++;
      }
      if(cows==a){
         return true;
      }
    }
    return false;
}
int cowsaggres(vector<int>&v, int left, int right, int n, int a){
   int k=-1;
   while(left<=right){
      int mid=left+(right-left)/2;
      if(isplaced(v, mid, n, a)){
         k=mid;
         left=mid+1;
      }
      else{
         right=mid-1;
      }
   }
   return k;
}
int main(){
   vector<int>v={0,3,4,7,9,10};
   sort(v.begin(),v.end());
   int n=v.size();
   int left=1;
   int right=v[n-1]-v[0];
   int a=4;
   cout<<cowsaggres(v, left, right, n, a);
}
