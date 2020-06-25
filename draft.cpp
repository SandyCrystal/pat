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

const int inf = 0x3f3f3f3f;
int path[505][505], tim[505][505];
int tmp1[505];
int vis[505],dis[505];
int point, m;
int road1[505],road2[505];
int cnt[505];
//求最短路的，如果路最短有多个 则求最快的
int Dij1(int beginn, int endd) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < point; i++) {
        dis[i] = path[beginn][i];
        tmp1[i] = tim[beginn][i];
        if (dis[i] == inf || dis[i] == 0)
            road1[i] = -1;
        else
            road1[i] = beginn;
    }
    vis[beginn] = 1;
    for (int i = 0; i < point; i++) {
        int maxn = inf, u = -1;
        for (int j = 0; j < point; j++) {
            if (vis[j] == 0 && dis[j] < maxn) {
                maxn = dis[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        vis[u] = 1;
        for (int j = 0; j < point; j++) {
            if (vis[j] == 0) {
                if (dis[u] + path[u][j] < dis[j]) {
                    dis[j] = dis[u] + path[u][j];
                    tmp1[j] = tmp1[u] + tim[u][j];
                    road1[j] = u;//表示i前一个节点
                } else if (dis[u] + path[u][j] == dis[j] && tmp1[u] + tim[u][j] < tmp1[j])
                    road1[j] = u;
            }
        }
    }
    return dis[endd];
}

//求最快路的，如果最快路有多个，则求经过点最少的
int Dij2(int beginn, int endd) {
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < point; i++) {
        dis[i] = tim[beginn][i];
        if (dis[i] == inf || dis[i] == 0)
            road2[i] = -1;
        else
            road2[i] = beginn;
    }
    cnt[beginn] = 1;
    vis[beginn] = 1;
    for (int i = 0; i < point; i++) {
        int maxn = inf, u = -1;
        for (int j = 0; j < point; j++) {
            if (vis[j] == 0 && dis[j] < maxn) {
                maxn = dis[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        vis[u] = 1;
        for (int j = 0; j < point; j++) {
            if (vis[j] == 0) {
                if (dis[u] + tim[u][j] < dis[j]) {
                    dis[j] = dis[u] + tim[u][j];
                    road2[j] = u;
                    cnt[j] = cnt[u] + 1;
                } else if (dis[u] + tim[u][j] == dis[j]) {
                    if (cnt[u] + 1 < cnt[j]) {
                        cnt[j] = cnt[u] + 1;
                        road2[j] = u;
                    }
                }
            }
        }
    }
    return dis[endd];
}
//判断两条路是否相等
bool same(int dd1[], int now1, int dd2[], int now2) {
    if (now1 != now2)
        return false;
    for (int i = 1; i <= now1; i++) {
        if (dd1[i] != dd2[i])
            return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &point, &m);
    for (int i = 0; i <= point; i++) {
        for (int j = 0; j <= point; j++)
            path[i][j] = inf, tim[i][j] = inf;
        path[i][i] = 0, tim[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z, u, v;
        scanf("%d %d %d %d %d", &x, &y, &z, &u, &v);
        if (z == 1) {
            path[x][y] = u;
            tim[x][y] = v;
        } else {
            path[x][y] = path[y][x] = u;
            tim[x][y] = tim[y][x] = v;
        }
    }
    int beginn, endd;
    scanf("%d %d", &beginn, &endd);
    int totalpath = Dij1(beginn, endd);
    int totaltim = Dij2(beginn, endd);
    int gg = endd;
    stack<int> st1, st2;
    while (gg != -1) {
        st1.push(gg);
        gg = road1[gg];
    }
    gg = endd;
    while (gg != -1) {
        st2.push(gg);
        gg = road2[gg];
    }
    int dd1[505], dd2[505], now1 = 0, now2 = 0;
    while (st1.empty() == 0) {
        gg = st1.top();
        st1.pop();
        dd1[++now1] = gg;
    }
    while (st2.empty() == 0) {
        gg = st2.top();
        st2.pop();
        dd2[++now2] = gg;
    }
//	for(int i = 1; i <= now1; i++)
//		printf("%d%c",dd1[i]," \n"[i==now1]);
//	for(int i = 1; i <= now2; i++)
//		printf("%d%c",dd2[i]," \n"[i==now2]);
    if (same(dd1, now1, dd2, now2)) {
        printf("Distance = %d; Time = %d: %d", totalpath, totaltim, dd1[1]);
        for (int i = 2; i <= now1; i++)
            printf(" -> %d", dd1[i]);
        printf("\n");
    } else {
        printf("Distance = %d: %d", totalpath, dd1[1]);
        for (int i = 2; i <= now1; i++)
            printf(" -> %d", dd1[i]);
        printf("\n");
        printf("Time = %d: %d", totaltim, dd2[1]);
        for (int i = 2; i <= now2; i++)
            printf(" -> %d", dd2[i]);
        printf("\n");
    }
    return 0;
}