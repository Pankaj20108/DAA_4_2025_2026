#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
//Method i used to find the depth of recursive call works only if all leaf nodes are at same level
//In other words, I don't know how to find the depth. So, i used simple logic.
bool valid=0;
void complexRec(int n, int& op, int& depth) {
   if(valid==0) depth+=1;
   if (n <= 2) {
    valid=1;
       return;
   }
   
   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           op++;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       op++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       op++;
   } else {
       reverse(small.begin(), small.end());
       op++;
   }
   
   complexRec(n / 2, op, depth);
   complexRec(n / 2, op, depth);
   complexRec(n / 2, op, depth);
   
}
int main(){
    int n=8;
    int op=0;
    int depth=0;
    auto start = high_resolution_clock::now();
    complexRec(n, op, depth);
    auto end = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Operations:"<<op<<endl;
    cout << "Depth:"<<depth<<endl;
    cout << "Execution Time:"<<duration.count()<<"ms"<<endl;

//Recurrence Relation:
//T(n)=3T(n/2)+O(n log n)

//Final Time Complexity:
//T(n) = O(n^(log2 3))

//Recursion Depth:
//O(log n)

}