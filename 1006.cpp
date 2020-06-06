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

string earlyId;
string lateId;
string id;
int earlyTime = 9999999;
int latetime = 0;
int time1, time2;
int n, h, m, s;

int main() {
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
        cin>>id;
        scanf("%d:%d:%d", &h, &m, &s);
        time1 = h*60*60+m*60+s;
        scanf("%d:%d:%d", &h, &m, &s);
        time2 = h*60*60+m*60+s;
        if(time1 < earlyTime) {
            earlyId = id;
            earlyTime = time1;
        }
        if(time2 > latetime) {
            lateId = id;
            latetime = time2;
        }
    }
    cout<<earlyId<<" "<<lateId;
}