//
// Created by wxd on 2020/6/14.
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

double v[100005];
ll n;
double sum = 0;
ll t[100005];

int main() {
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
    }

    ll start = 1;
    ll end = n;
    for(int i = 0 ; i < n ; i++) {
        t[i] = start*end;
        start++;
        end--;
    }

    for (int i = 0; i < n; ++i) {
        sum += v[i]*t[i];
    }

    printf("%.2lf\n", sum);
}