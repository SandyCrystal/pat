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

int n, m, k;
int a, b, e[1005][1005];
bool vis[1005];

void dfs(int st, int mis) {
    if(vis[st] || st == mis) {
        return;
    } else {
        vis[st] = true;
        for(int i = 1 ; i <= n ; i++) {
            if(e[st][i]==1 && i!=mis) {
                dfs(i, mis);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
//    cin>>n>>m>>k;
    fill(e[0], e[0]+105*105, 0);
    for(int i = 0 ; i < m ; i++) {
//        cin>>a>>b;
        scanf("%d %d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    for(int i = 0 ; i < k ; i++) {
//        cin>>a;
        scanf("%d", &a);
        memset(vis, false, sizeof(vis));
        vis[a] = true;
        int cnt = 0;
        for(int j = 1 ; j <= n ; j++) {
            if(!vis[j] && j!=a) {
                dfs(j, a);
                cnt++;
            }
        }
        printf("%d\n", cnt-1);
//        cout<<cnt-1<<endl;
    }
}