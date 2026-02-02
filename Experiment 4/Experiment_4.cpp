#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,int>m;
    int  first=0;
    int second=0;
    long long subarray=0;
    while(second<v.size()){
        m[v[second]]++;
        while(second-first+1>m.size()){
            m[v[first]]--;
            if(m[v[first]]==0){
                m.erase(v[first]);
            }
            first++;
        }
        subarray+=(second-first+1);
        second++;
    }
    cout<<subarray<<endl;
}
//Time Complexity:-O(2n)
//Space Complexity:-O(n)