#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

long long op = 0;
int depth = 0;

void complexRec(int n, int currdepth) {
    depth = max(depth, currdepth);

    if (n <= 2) {
        return;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            op++;
        }
        p>>=1;
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

    complexRec(n / 2, currdepth + 1);
    complexRec(n / 2, currdepth + 1);
    complexRec(n / 2, currdepth + 1);
}

int main() {
    vector<int>v= {4, 8, 16, 32};

    for(int i=0;i<v.size();i++){
        op = 0;
        depth = 0;

        auto start = high_resolution_clock::now();

        complexRec(v[i], 1);

        auto end = high_resolution_clock::now();
        auto timeTaken = duration_cast<milliseconds>(end - start);

        cout << "n = " <<v[i]<<endl;
        cout << "Operations = "<<op<<endl;
        cout << "Depth = "<<depth<<endl;
        cout << "Execution Time = "<<timeTaken.count()<<" ms"<<endl;
    }

}

/*
Recurrence Relation:
T(n) = 3T(n/2) + O(n log n)

Time Complexity:
O(n^(log2 3))

Recursion Depth:
O(log n)
*/
