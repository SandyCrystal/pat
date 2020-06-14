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

vector<double> v;
int n;
double tmp;
double sum = 0;
int t[100005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &tmp);
        v.push_back(tmp);
        t[i] = 0;
    }

    for (int k = 1; k <= n; ++k) {
        if(k==1 || k==n) {
            for (int i = 0; i < n; ++i) {
                t[i]++;
            }
        } else {
            int cnt = 1;
            for (int i = 0, j = n - 1; i <= j; i++, j--) {
                if(i!=j) {
                    t[i]+=cnt;
                    t[j]+=cnt;
                } else {
                    t[i]+=cnt;
                }
                if(cnt<k)
                    cnt++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        sum += v[i]*t[i];
    }

    printf("%.2lf\n", sum);
}