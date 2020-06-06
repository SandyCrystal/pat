//
// Created by wxd on 2020/6/6.
//

#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, maxm1, maxm2;
double a[1005], b[1005], ans[3005];

int main() {
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
        cin>>m>>a[m];
        maxm1 = max(maxm1, m);
    }
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
        cin>>m>>b[m];
        maxm2 = max(maxm2, m);
    }

    for(int i = 0; i <= maxm1 ; i++) {
        for(int j = 0 ; j <= maxm2; j++) {
            ans[i+j] += a[i]*b[j];
        }
    }

    int cnt = 0;
    for(int i = 0 ; i < 3003 ; i++) {
        if(ans[i]!=0) {
            cnt++;
        }
    }
    cout<<cnt;
    for(int i = 3003; i >= 0 ; i--) {
        if(ans[i]!=0) {
            printf(" %d %.1lf", i, ans[i]);
        }
    }
}

/*

*/