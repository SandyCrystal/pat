//
// Created by wxd on 2020/6/12.
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

int n;
string t1, t2;
struct node {
    int num;
    int left;
    int right;
    int dad;
}p[1055];

int flag = 0;

void in_order(int now) {
    if(p[now].left!=-1) {
        in_order(p[now].left);
    }
    flag==0?printf("%d", now):printf(" %d", now);
    flag = 1;
    if (p[now].right!=-1) {
        in_order(p[now].right);
    }
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        p[i].num = i;
        p[i].dad = i;
        p[i].left = -1;
        p[i].right = -1;
    }
    for (int i = 0; i < n; ++i) {
        cin >> t1 >> t2;
//        printf("%s %s\n", t1.c_str(), t2.c_str());
        if(t1[0]!='-') {
            p[i].right = t1[0] - '0';
            p[p[i].right].dad = i;
        }
        if(t2[0]!='-') {
            p[i].left = t2[0] - '0';
            p[p[i].left].dad = i;
        }
    }

    int root;
    for (int i = 0; i < n; ++i) {
        if (p[i].num==p[i].dad) {
            root = i;
        }
    }

    queue<int> q;
    while (!q.empty()) {
        q.pop();
    }
    q.push(root);
    printf("%d", root);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now!=root) {
            printf(" %d", now);
        }
        if(p[now].left!=-1) {
            q.push(p[now].left);
        }
        if(p[now].right!=-1) {
            q.push(p[now].right);
        }
    }
    printf("\n");

    in_order(root);
}