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

const int maxn = 100005;
ll n, k, tmp;
double p, r;
vector<int> retailers;
int father[maxn];
map<int, int> mp;

int main() {
    scanf("%lld%lf%lf", &n, &p, &r);
    for(int i = 0 ; i < n ; i++) {
        scanf("%lld", &k);
        if(k==0) {
            retailers.push_back(i);
        } else {
            for (int j = 0; j < k; j++) {
                scanf("%lld", &tmp);
                father[tmp] = i;
            }
        }
    }
    father[0] = -1;
    int maxl = 1e9+7;
    int cnt = 1;
    for (int i = 0; i < retailers.size(); ++i) {
        ll now = retailers[i];
        int length = 0;
        if(mp[father[now]]==0) {
            while (father[now]!=-1) {
                length++;
                now = father[now];
            }
            mp[father[retailers[i]]] = length;
        } else {
            length = mp[father[now]];
        }

        if(length<maxl) {
            maxl = length;
            cnt = 1;
        } else if(length==maxl) {
            cnt++;
        }
    }
    double ans = p;
    for(int i = 0 ; i < maxl; i++) {
        ans *= (1.0+r/100);
    }
    printf("%.4lf %d\n", ans, cnt);
}