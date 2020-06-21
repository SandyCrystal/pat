//
// Created by wxd on 2020/6/21.
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
struct person {
    string name;
    int height;
};

vector<person> p;

bool cmp(person a, person b) {
    if (a.height == b.height) {
        return a.name < b.name;
    } else {
        return a.height > b.height;
    }
}

int main() {
    scanf("%d%d", &n, &k);
    getchar();
    for (int i = 0; i < n; ++i) {
        person tmp;
        cin>>tmp.name;
        scanf("%d", &tmp.height);
        p.push_back(tmp);
    }
    sort(p.begin(), p.end(), cmp);

    // 最后一排特殊处理
    int last = n-(n/k)*(k-1);
    int pos = last/2;
    vector<string> tmp;
    tmp.resize(last);
    tmp[pos] = p[0].name;
    int tmppos = pos;
    for (int i = 1; i < last; i=i+2) {
        tmp[--tmppos] = p[i].name;
    }
    tmppos = pos;
    for (int i = 2; i < last; i=i+2) {
        tmp[++tmppos] = p[i].name;
    }
    for (int i = 0; i < last; ++i) {
        printf(i==0?"%s":" %s", tmp[i].c_str());
    }
    printf("\n");

    vector<string> now;
    now.resize(n/k);
    int times = 0;
    for (int i = last; i < n; i+=(n/k)) {
        pos = (n/k)/2;
        now[pos] = p[i].name;
        tmppos = pos;
        for (int j = i+1; j < i+(n/k); j=j+2) {
            now[--tmppos] = p[j].name;
        }
        tmppos = pos;
        for (int j = i+2; j < i+(n/k); j=j+2) {
            now[++tmppos] = p[j].name;
        }
        for (int j = 0; j < n/k; ++j) {
            printf(j==0?"%s":" %s", now[j].c_str());
        }
        printf("\n");
    }
}