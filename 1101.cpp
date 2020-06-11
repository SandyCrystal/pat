//
// Created by wxd on 2020/6/11.
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

int n;
int a[100005];
int l_max[100005];
int r_min[100005];

int main() {
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }

    int maxn = -1;
    for (int i = 1; i < n; ++i) {
        maxn = max(maxn, a[i-1]);
        l_max[i] = maxn;
    }
    int minn = 1999999999;
    for(int i = n-2; i>=0; i--) {
        minn = min(minn, a[i+1]);
        r_min[i] = minn;
    }
    l_max[0] = -1;
    r_min[n-1] = 1999999999;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if(a[i]>l_max[i] && a[i]<r_min[i]) {
            v.push_back(a[i]);
        }
    }
    sort(v.begin(), v.end());

    printf("%d\n", v.size());
    if(v.size()==0)
        printf("\n");
    for(int i = 0 ; i < v.size(); i++) {
        i==0?printf("%d", v[i]):printf(" %d", v[i]);
    }
}