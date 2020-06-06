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

string a, b;
ll n, r, maxn;

ll calNum(string str, int radix) {
    long long sum = 0;
    int index = 0;
    int per_digit = 0;
    for(auto t = str.rbegin();t!=str.rend();t++){
        per_digit = isdigit(*t)? *t - '0':*t - 'a' + 10;
        sum+=per_digit*pow(radix,index++);
    }
    return sum;
}

int main() {
    while(cin>>a>>b>>n>>r) {
//        cin>>a>>b>>n>>r;
        if(n==2)    swap(a,b);
//    计算值
        ll sum = calNum(a, r);
//    二分查值
        char it = *max_element(b.begin(),b.end());
        ll left = (isdigit(it)?it - '0':it - 'a' + 10) + 1;
        ll right = max(left, sum+1);
        while(left <= right) {
            ll mid = (left+right)/2;
            ll now = calNum(b, mid);

            if(now==sum) {
                cout<<mid<<endl;
                return 0;
            } else if(now>sum || now<0) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        cout<<"Impossible";
    }
}