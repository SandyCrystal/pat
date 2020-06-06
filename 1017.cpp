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

struct node {
    int h, m, s, t, p;
};

vector<node> a;
int b[105];
char str[100];

bool cmp(node a,node b) {
    return a.t < b.t;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        node tmp;
        scanf("%s%d", str, &tmp.p);
        tmp.p = tmp.p * 60;
        tmp.h = (str[0] - '0') * 10 + str[1] - '0';
        tmp.m = (str[3] - '0') * 10 + str[4] - '0';
        tmp.s = (str[6] - '0') * 10 + str[7] - '0';
        tmp.t = tmp.h * 60 * 60 + tmp.m * 60 + tmp.s;
        if (tmp.t < 61200)
            a.push_back(tmp);
    }
    sort(a.begin(), a.end(), cmp);
    double sum = 0;
    // 有效人数
    int cnt = 0;
    for (int i = 28800;; i++) {
        for (int j = 0; j < k; j++) {
            if (b[j] != 0)
                b[j]--;
            // 有一个位置能处理，如果还有人要来，有人已经再等了。
            if (b[j] == 0 && a.size() != 0 && i >= a[0].t) {
                // 如果有空位能处理
                if (a.size() != 0) {
                    cnt++;
                    sum += i - a[0].t;
                    b[j] = min(a[0].p, 60 * 60);
                }
                if (a.size() != 0)
                    a.erase(a.begin());
            }
        }
        if (a.size() == 0)
            break;
    }
    if (cnt != 0) {
        printf("%.1f\n", sum / 60 / cnt);
    } else {
        printf("0.0\n");
    }
}