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

int n, cnt;
string str;

double toDouble(string s) {
    double ret = 0;
    int now = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '.') {
            ret = ret / now;
            now = 1;
        } else if (s[i] == '-' && i == 0) {
            ret = -ret;
        } else {
            ret += (s[i] - '0') * now;
            now *= 10;
        }
    }
    return ret;
}

bool judge(string s) {
    int times = 0;
    if (s == "")
        return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[0] == '-')
            continue;
        if (s[i] < '0' || s[i] > '9') {
            if (s[i] == '.' && i >= s.length() - 3) {
                times++;
                if (times == 2) {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    if (toDouble(s) < -1000 || toDouble(s) > 1000)
        return false;
    return true;
}

int main() {
    scanf("%d", &n);
    getchar();
    cnt = 0;
    double ans = 0;
    while (n--) {
        cin >> str;
//        printf("!!!%s!!!", str.c_str());
        bool flag = judge(str);
        if (flag == false) {
            printf("ERROR: %s is not a legal number\n", str.c_str());
        } else {
            cnt++;
            ans += toDouble(str);
        }
    }
    if (cnt == 0)
        printf("The average of 0 numbers is Undefined");
    else if (cnt == 1)
        printf("The average of 1 number is %.2lf", ans);
    else
        printf("The average of %d numbers is %.2lf", cnt, ans / cnt);
}