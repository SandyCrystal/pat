//
// Created by wxd on 2020/6/12.
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

int n, k, p;
int a[401];
int path[404];
vector<int> pp, ans, tmp;
int maxWei = -1;

void dfs(int index, int num, int nowK, int wei) {
//    printf("%d %d %d %d\n", index, num, nowK, wei);
    if(num>n || nowK>k)
        return;
    if(num==n && nowK==k) {
        if(wei>maxWei) {
            maxWei = wei;
            ans = tmp;
        }
        return;
    }

    if(index>0) {
        // 选
        tmp.push_back(index);
        dfs(index, num + pp[index], nowK + 1, wei + index);
        // 不选
        tmp.pop_back();
        dfs(index - 1, num, nowK, wei);
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; pow(i, p) <= n; i++) {
        pp.push_back((int)pow(i, p));
    }

    dfs(pp.size()-1, 0, 0, 0);
    if (ans.size() == 0) {
        printf("Impossible");
    } else {
        printf("%d", n);
        for (int i = 0; i < k; ++i) {
            i == 0 ? printf(" = %d^%d", ans[i], p) : printf(" + %d^%d", ans[i], p);
        }
    }
}