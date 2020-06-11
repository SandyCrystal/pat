//
// Created by wxd on 2020/6/10.
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

string a;
int cnt[25];    // cnt[a]=b表示a出现了b次
int num[25];    // 存放a乘2后的数

int main() {
    cin>>a;
    // 计算每一位的出现次数
    for (int i = 0; i < a.length(); ++i) {
        cnt[a[i]-'0']++;
    }
//    ------------------------------------------------------------
    // 用小学生乘法的公式求值
    for(int i = a.length()-1; i>=0; i--) {
        num[i+1] += ((a[i]-'0')*2);
        if(num[i+1]>=10) {
            num[i] += 1;
            num[i+1] -= 10;
        }
    }
    for(int i = 0 ; i <= a.length(); i++) {
        cnt[num[i]]--;
    }
//    ------------------------------------------------------------
    // 依次输出
    int ff = 1;
    for(int i = 1; i <= 9; i++) {
        if(cnt[i]!=0) {
            ff = 0;
            break;
        }
    }
    ff==1?printf("Yes\n"):printf("No\n");

    for(int i = 0; i <= a.length(); i++) {
        if(i==0 && num[i]==0) {
            continue;
        }
        printf("%d", num[i]);
    }
    printf("\n");

    return 0;
}