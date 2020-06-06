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

ll n, d;
stack<ll> s;

int main() {
    while(scanf("%lld", &n)) {
        if(n<0) {
            break;
        } else {
            scanf("%lld", &d);
            ll tmp = n;
            while(tmp!=0) {
                s.push(tmp%d);
                tmp /= d;
            }
            ll cnt = 0;
            ll sum = 0;
            while(!s.empty()) {
                sum += s.top()*pow(d, cnt);
                cnt++;
                s.pop();
            }
            if(sum==1) {
                printf("No\n");
                continue;
            }
            ll flag = 1;
            for(ll i = 2 ; i < sum; i++) {
                if(sum%i==0) {
                    flag = 0;
                    break;
                }
            }
            for(ll i = 2 ; i < n; i++) {
                if(n%i==0) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
}