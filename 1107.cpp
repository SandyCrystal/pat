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
int n, i, k;
vector<int> v;

int find(int x) {
    int now = x;
    while (father[now] >= 0) {
        now = father[now];
    }
    while (x != now) {
        int tmp = x;
        father[x] = now;
        x = father[tmp];
    }
    return now;
}

void merge(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    if (r1 != r2) {
        if (father[r1] < father[r2]) {
            father[r1] += father[r2];
            father[r2] = r1;
        } else {
            father[r2] += father[r1];
            father[r1] = r2;
        }
    }
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
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

    for (i = 1; i <= n; i++) {
        if (father[i] < 0) {
            v.push_back(-father[i]);
        }
    }

    sort(v.begin(), v.end(), cmp);
    printf("%d\n", v.size());
    for (i = 0; i < v.size(); i++) {
        printf("%d%c", v[i], i == v.size() - 1 ? '\n' : ' ');
    }
}