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

double w, t, l;
double sum;

int main() {
    sum = 1;
    for(int i = 0 ; i < 3 ; i++) {
        cin>>w>>t>>l;
        if(w==max(w, max(t, l))) {
            cout<<"W ";
            sum *= w;
        } else if(t==max(w, max(t, l))) {
            cout<<"T ";
            sum *= t;
        } else {
            cout<<"L ";
            sum *= l;
        }
    }

    printf("%.2lf", (sum*0.65-1)*2);
}