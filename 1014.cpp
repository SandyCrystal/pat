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

int n, m, k, q, a;
int t[1005], ans[1005], fa[1005];
queue<int> que[25];

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &q);
    if (m == 0) {
        m = 1;
    }
    for(int i = 1 ; i <= k ; i++) {
        scanf("%d", &t[i]);
    }
    for(int i = 1 ; i <= k; i++) {
        if(i<=n*m) {
            if(i%n==0) {
                que[n].push(t[i]);
                fa[i] = n;
            } else {
                que[i % n].push(t[i]);
                fa[i] = i % n;
            }
        } else {
            int minn = 1e8;
            int index = -1;
            for(int j = 1 ; j <= n ; j++) {
                if(que[j].front()<minn) {
                    minn = que[j].front();
                    index = j;
                }
            }
            for(int j = 1 ; j <= n ; j++) {
                if(j!=index) {
                    que[j].front() = que[j].front()-minn;
                }
            }
            que[index].pop();
            que[index].push(t[i]);
            fa[i] = index;
        }
    }

    for(int i = 0 ; i < q ; i++) {
        scanf("%d", &a);

        int father = fa[a];
        int minu = 0;
        int minute = 0;
        for(int j = 1 ; j <= a ; j++) {
            if(fa[j]==father) {
                if(a!=j) {
                    minu += t[j];
                }
                minute += t[j];
            }
        }
        if(minu>=540) {
            printf("Sorry\n");
        } else {
            int hour = 8+minute/60;
            minute = minute%60;
            printf("%02d:%02d\n", hour, minute);
        }
    }
}