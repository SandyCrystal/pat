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

int a,b,c;
string str;

int main() {
    cin>>a>>b;
    c = a+b;
    if(c<0) {
        cout<<'-';
        c = -c;
    } else if(c==0) {
        cout<<0;
        return 0;
    }
    str = to_string(c);
    int len = str.length();
    int pre = len%3;
    for(int i = 0; i < pre; i++) {
        cout<<str[i];
    }
    if(len>3 && pre!=0) {
        cout<<",";
    }
    int cnt = 0;
    for(int i = pre; i < len; i++) {
        cout<<str[i];
        cnt++;
        if(cnt==3 && i!=len-1) {
            cnt = 0;
            cout<<",";
        }
    }
}