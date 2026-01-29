//Experiment–3: Stable Attendance Window
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<char>v(n,0);
    for (int i=0;i<n;i++) {
        cin >> v[i];
    }
    unordered_map<int, int>m;
    m[0]=-1;
    int sum=0, maxLen=0;
    for (int i=0;i<n;i++) {
        if(v[i]=='P'||v[i]=='p'){
            sum+=1;}
        else{
            sum-=1;}
        if (m.find(sum)!= m.end()) {
            maxLen = max(maxLen, i - m[sum]);
        } else {
            m[sum]=i;
        }
    }
    cout<<maxLen;
    return 0;
}
//Time Complexity:- O(n)
//Space Complexity:- O(n)
