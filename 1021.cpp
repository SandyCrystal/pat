//
// Created by wxd on 2020/6/8.
//

#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

int n, a, b, cnt;
bool e[10005][10005];
bool vis[10005];
vector<int> ans;
set<int> res;
int mindeep;

void travel(int st) {
    if(vis[st]) {
        return;
    } else {
        vis[st] = true;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && e[st][i]==true) {
                travel(i);
            }
        }
    }
}

void dfs(int now, int depth) {
    vis[now] = true;
    if(depth==mindeep) {
        ans.push_back(now);
    } else if(depth>mindeep) {
        ans.clear();
        ans.push_back(now);
        mindeep = depth;
    }
    for(int i = 1 ; i <= n; i++) {
        if(i!=now && !vis[i] && e[now][i]==true) {
            dfs(i, depth+1);
        }
    }
}

int main() {
    fill(e[0], e[0]+(n+1)*(n+1), false);
    fill(vis+1, vis+n+1, false);
    scanf("%d", &n);
    for(int i = 0 ; i < n-1 ; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = true;
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            travel(i);
            cnt++;
        }
    }
    if(cnt!=1) {
        printf("Error: %d components", cnt);
    } else {
        mindeep = 0;
        fill(vis+1, vis+n+1, false);
        dfs(1, 0);
        for (int i = 0; i < ans.size(); ++i) {
            res.insert(ans[i]);
        }
        ans.clear();
        mindeep = 0;
        fill(vis+1, vis+n+1, false);
        dfs(ans[0], 0);
        for (int i = 0; i < ans.size(); ++i) {
            res.insert(ans[i]);
        }
        for(set<int>::iterator it = res.begin(); it!=res.end(); it++) {
            printf("%d\n", *it);
        }
    }
}