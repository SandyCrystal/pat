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

int n, m;

int main() {
    cin>>n;
    int now = 0;
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        cin>>m;
        if(m>now) {
            sum += 6*(m-now)+5;
        } else if(m<now) {
            sum += 4*(now-m)+5;
        } else {
            sum += 5;
        }
        now = m;
    }
    cout<<sum;
}

/*

*/