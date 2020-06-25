//
// Created by wxd on 2020/6/24.
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

const int inf = 1e9+7;
const int maxn = 505;
int n, m;
int a, b, c, d, e;
int st, ed;
int d1[maxn], d2[maxn];
int l[maxn][maxn], t[maxn][maxn];
bool vis1[maxn], vis2[maxn];
int path1[maxn], path2[maxn];

void init() {
    fill(d1, d1 + maxn, inf);
    fill(d2, d2 + maxn, inf);
    fill(vis1, vis1 + maxn, false);
    fill(vis2, vis2 + maxn, false);
    fill(l[0], l[0] + maxn * maxn, inf);
    fill(t[0], t[0] + maxn * maxn, inf);
    fill(path1, path1 + maxn, -1);
    fill(path2, path2 + maxn, -1);
}

void dijkstra1() {
    d1[st] = 0;
    for (int i = 0; i < n; ++i) {
        int index = -1;
        int tmp = inf;
        for (int j = 0; j < n; ++j) {
            if (!vis1[j] && d1[j] < tmp) {
                tmp = d1[j];
                index = j;
            }
        }
        if (index == -1) {
            break;
        }
        vis1[index] = true;
        for (int j = 0; j < n; ++j) {
            if (!vis1[j] && d1[index] + l[index][j] < d1[j]) {
                d1[j] = d1[index] + l[index][j];
                path1[j] = index;
            } else if (!vis1[j] && d1[index] + l[index][j] == d1[j]) {
                if (d2[index] + t[index][j] <= d2[j]) { // 绕一下时间少一点
                    path1[j] = index;
                }
            }
        }
    }
}

void dijkstra2() {
    d2[st] = 0;
    for (int i = 0; i < n; ++i) {
        int index = -1;
        int tmp = inf;
        for (int j = 0; j < n; ++j) {
            if (d2[j] < tmp && !vis2[j]) {
                index = j;
                tmp = d2[j];
            }
        }
        if (index == -1) {
            break;
        }
        vis2[index] = true;
        for (int j = 0; j < n; ++j) {
            if (!vis2[j] && d2[index] + t[index][j] < d2[j]) {
                d2[j] = d2[index] + t[index][j];
                path2[j] = index;
            }
        }
    }
}

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
    init();
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        l[a][b] = d;
        t[a][b] = e;
        if (c == 0) {
            l[b][a] = d;
            t[b][a] = e;
        }
    }
    scanf("%d%d", &st, &ed);
    dijkstra2();
    dijkstra1();

    int now = ed;
    stack<int> st1;
    while (now != -1) {
        st1.push(now);
        now = path1[now];
    }
    now = ed;
    stack<int> st2;
    while (now != -1) {
        st2.push(now);
        now = path2[now];
    }

    int dd1[505], dd2[505], now1 = 0, now2 = 0;
    while (st1.empty() == 0) {
        now = st1.top();
        st1.pop();
        dd1[++now1] = now;
    }
    while (st2.empty() == 0) {
        now = st2.top();
        st2.pop();
        dd2[++now2] = now;
    }

    if (same(dd1, now1, dd2, now2)) {
        printf("Distance = %d; Time = %d: %d", d1[ed], d2[ed], dd1[1]);
        for (int i = 2; i <= now1; i++)
            printf(" -> %d", dd1[i]);
        printf("\n");
    } else {
        printf("Distance = %d: %d", d1[ed], dd1[1]);
        for (int i = 2; i <= now1; i++)
            printf(" -> %d", dd1[i]);
        printf("\n");
        printf("Time = %d: %d", d2[ed], dd2[1]);
        for (int i = 2; i <= now2; i++)
            printf(" -> %d", dd2[i]);
        printf("\n");
    }

}