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

double toDouble(string s) {
    double ret = 0;
    int now = 1;
    for(int i = s.length()-1; i>=0; i--) {
        if(s[i]!='.') {
            ret += (s[i]-'0')*now;
            now *= 10;
        } else {
            ret = ret/now;
            now = 1;
        }
    }
    return ret;
}

bool judge(string s) {
    int times = 0;
    if(s == "")
        return false;
    for(int i = 0 ; i < s.length(); i++) {
        if(s[0] == '-')
            continue;
        if(s[i] < '0' || s[i] > '9') {
            if(s[i] == '.' && i >= s.length()-3) {
                times++;
                if(times==2) {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    if(toDouble(s)<-1000 || toDouble(s)>1000)
        return false;
    return true;
}

int main() {
    cout<<toDouble("-3.2");
}