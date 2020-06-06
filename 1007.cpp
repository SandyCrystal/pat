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

int k, n, st, ed;
int a[10005] = {0};

int main() {
    cin>>k;
    int zheng = 0;
    for(int i = 0 ; i < k ; i++) {
        cin>>a[i];
        if(a[i] >= 0) {
            zheng = 1;
        }
    }
    int maxsum = 0;
    for(int i = 0 ; i < k ; i++) {
        if(a[i]>0) {
            int sum = 0;
            for(int j = i ; j < k ; j++) {
                sum += a[j];
                if(sum > maxsum) {
                    st = a[i];
                    ed = a[j];
                    maxsum = sum;
                }

            }
        }
    }
    if(zheng)
        cout<<maxsum<<" "<<st<<" "<<ed;
    else
        cout<<0<<" "<<a[0]<<" "<<a[k-1];
}

/*
10
-10 1 2 3 4 -5 -23 3 7 -21

8
1 2 3 -4 5 -6 7 -8

5
1 -4 3  -3 2

*/