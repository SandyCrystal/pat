//
// Created by wxd on 2020/6/15.
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

int num;
vector<int> v;
int ans[1005][1005];
bool vis[1005][1005];

bool cmp(int a, int b) {
    return a>b;
}

int main() {
    scanf("%d", &num);
    for (int i = 0; i < 1005; i++) {
        for (int j = 0; j < 1005; ++j) {
            ans[i][j] = -1;
            vis[i][j] = true;
        }
    }
    for (int i = 0; i < num; i++) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);

    int n, m;
    for (int i = sqrt(num); i >= 1; i--) {
        if ((int) (num / i) * i == num) {
            m = num / i;
            n = i;
            break;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; ++j) {
            vis[i][j] = false;
        }
    }

    int step = 0; // 0横正，1竖下，2横负，3竖上
    int nowi = 1;
    int nowj = 1;
    for (int i = 0; i < v.size(); ++i) {
        if (step == 0) {
            if (vis[nowi][nowj] == false) {
                vis[nowi][nowj] = true;
                ans[nowi][nowj] = v[i];
                if (vis[nowi][nowj + 1] == false) {
                    nowj++;
                } else {
                    nowi++;
                    step = 1;
                }
            }
        } else if (step == 1) {
            if (vis[nowi][nowj] == false) {
                vis[nowi][nowj] = true;
                ans[nowi][nowj] = v[i];
                if (vis[nowi+1][nowj] == false) {
                    nowi++;
                } else {
                    nowj--;
                    step = 2;
                }
            }
        } else if (step == 2) {
            if (vis[nowi][nowj] == false) {
                vis[nowi][nowj] = true;
                ans[nowi][nowj] = v[i];
                if (vis[nowi][nowj-1] == false) {
                    nowj--;
                } else {
                    nowi--;
                    step = 3;
                }
            }
        } else if (step == 3) {
            if (vis[nowi][nowj] == false) {
                vis[nowi][nowj] = true;
                ans[nowi][nowj] = v[i];
                if (vis[nowi-1][nowj] == false) {
                    nowi--;
                } else {
                    nowj++;
                    step = 0;
                }
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            j == 1 ? printf("%d", ans[i][j]) : printf(" %d", ans[i][j]);
        }
        printf("\n");
    }

}