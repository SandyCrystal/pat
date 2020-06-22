//
// Created by wxd on 2020/6/22.
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

struct node{
    int l, r;
}a[100];
int maxn = -1, ans;

void dfs(int root, int index) {
    if (index > maxn) {
        maxn = index;
        ans = root;
    }
    if (a[root].l != -1)
        dfs(a[root].l, index * 2);
    if (a[root].r != -1)
        dfs(a[root].r, index * 2 + 1);
}

int main() {
    int n, root = 0, vis[100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if (l == "-") {
            a[i].l = -1;
        } else {
            a[i].l = stoi(l);
            vis[stoi(l)] = 1;
        }
        if (r == "-") {
            a[i].r = -1;
        } else {
            a[i].r = stoi(r);
            vis[stoi(r)] = 1;
        }
    }
    while (vis[root] != 0) root++;
    dfs(root, 1);
    if (maxn == n)
        cout << "YES " << ans;
    else
        cout << "NO " << root;
}