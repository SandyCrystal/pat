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

int n, m, k, dad, son, root, cnt, sum;
int father[105];
vector<int> sons, now, tmpnow;

vector<int> haveSon(int p) {
    vector<int> tmp;
    for(int i = 0 ; i <= n ; i++) {
        if(father[i] == p && i!=p)
            tmp.push_back(i);
    }
    return tmp;
}

int main() {
    cin>>n>>m;
    for(int i = 0 ; i <= n ; i++) {
        father[i] = i;
    }
    for(int i = 0 ; i < m ; i++) {
        cin>>dad>>k;
        for(int j = 0 ; j < k ; j++) {
            cin>>son;
            father[son] = dad;
        }
    }
    for(int i = 0 ; i <= n ; i++) {
        if(father[i] == i) {
            root = i;
        }
    }
    now.push_back(root);
    tmpnow.push_back(root);
    int flag = 1;
    while(!tmpnow.empty()) {
        cnt = 0;
        now = tmpnow;
        tmpnow.clear();
        sons.clear();
        for(int j = 0 ; j < now.size(); j++) {
            sons = haveSon(now[j]);
            if(sons.empty()) {
                cnt++;
            } else {
                for(int k = 0 ; k < sons.size(); k++) {
                    tmpnow.push_back(sons[k]);
                }
            }
        }
        if(flag==1) {
            cout<<cnt;
            flag = 0;
        } else {
            cout<<" "<<cnt;
        }
    }
}