//
// Created by wxd on 2020/6/16.
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

int father[1001], h[1001];
int n, k;

int find(int x) {
    int node = x;
    while (father[node] >= 0)
        node = father[node];
    while (x != node) {
        int temp = x;
        father[x] = node;
        x = father[temp];
    }
    return node;
}

void merge(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    if (r1 != r2) {
        father[r1] += father[r2];
        father[r2] = r1;
    }
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        father[i] = -1;
        scanf("%d:", &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            if (h[x] == 0) {
                h[x] = i;
            } else {
                merge(i, h[x]);
            }
        }
    }

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (father[i] < 0) {
            v.push_back(-father[i]);
        }
    }

    sort(v.begin(), v.end(), cmp);
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++) {
        printf(i==0?"%d":" %d", v[i]);
    }
}