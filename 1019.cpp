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

ll n, k;
vector<ll> a, b;

int main() {
    cin >> n >> k;
    if (n == 0) {
        printf("Yes\n0\n");
        return 0;
    } else if (n == 1) {
        printf("Yes\n1\n");
        return 0;
    }
    int cnt = 0;
    while (n != 0) {
        ll res = n % k;
        n /= k;
        a.push_back(res);
        cnt++;
    }
    b = a;
    std::reverse(b.begin(), b.end());

    int f = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            printf("No\n");
            f = 1;
            break;
        }
    }
    if (!f) {
        printf("Yes\n");
    }
    for (int i = 0; i < b.size(); i++) {
        i==0?printf("%d", b[i]):printf(" %d", b[i]);
    }
}