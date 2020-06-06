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

int k, n;
double input, a[1005] = {0};
//set<int, greater<int>> s;

int main() {
//    s.clear();
    for(int j = 0 ; j < 2 ; j++) {
        cin>>k;
        for(int i = 0 ; i < k ; i++) {
            cin>>n>>input;
            a[n] = a[n]+input;
//            s.insert(n);
        }
    }
//    cout<<s.size();
    int cnt = 0;
    for(int i = 1004; i >= 0; i--) {
        if(a[i]!=0) {
            cnt++;
        }
    }
    cout<<cnt;
    for(int i = 1004; i >= 0; i--) {
        if(a[i]!=0) {
            printf(" %d %.1lf", i, a[i]);
        }
    }
}