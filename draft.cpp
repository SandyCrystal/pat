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

int n, m, cnt;
bool vis[1005], ok[1005];
vector<int> ans;
int times[1005];
vector<int> v[1005];

bool cmp(int a, int b) {
    return a>b;
}

void init() {
    for (int i = 0; i < n; ++i) {
        vis[i] = false;
        ok[i] = false;
        times[i] = 0;
        v[i].clear();
    }
    ans.clear();
}

int main() {
    init();

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &m);
        for (int j = 0; j < m; ++j) {
            int tmp;
            scanf("%d", &tmp);
            times[tmp]++;
            v[i].push_back(tmp);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt = 1;
            vis[i] = true;
            vector<int> tmp;
            for (int j = 0; j < v[i].size(); ++j) {
                times[v[i][j]]--;
                if (times[v[i][j]] != 0) {
                    tmp.push_back(v[i][j]);
                    ok[v[i][j]] = true;
                }
            }
            while (tmp.size() != 0) {
                for (int j = 1; j <= n; ++j) {
                    if (!vis[j]) {
                        int flag = 0;
                        for (int k = 0; k < v[j].size(); ++k) {
                            if (ok[v[j][k]] == true) {
                                flag = 1;
                            }
                        }
                        if (flag == 1) {
                            vis[j] = true;
                            cnt++;
                            for (int k = 0; k < v[j].size(); ++k) {
                                times[v[j][k]]--;
                                if (times[v[j][k]] != 0 && ok[v[j][k]] == false) {
                                    tmp.push_back(v[i][k]);
                                    ok[v[j][k]] = true;
                                }
                            }
                            for (int k = 0; k < tmp.size(); ++k) {
                                if (times[tmp[k]] == 0) {
                                    tmp.erase(tmp.begin() + k);
                                    ok[tmp[k]] = false;
                                }
                            }
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end(), cmp);

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        i == 0 ? printf("%d", ans[i]) : printf(" %d", ans[i]);
    }
}