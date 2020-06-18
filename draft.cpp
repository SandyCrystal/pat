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

const int maxn = 1005;
int n, m, cnt, good;
vector<int> v[maxn];
set<int> s;
int father[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        scanf("%d:", &m);
        for (int j = 0; j < m; ++j) {
            int tmp;
            scanf("%d", &tmp);
            v[i].push_back(tmp);
            if(j==0) {
                good = tmp;
            } else {
                father[tmp] = good;
            }
        }
    }


}