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
struct node {
    string id;
    double c, m, e, a;
}p[2005];

double cc[2005], mm[2005], ee[2005], aa[2005];
string a;
double b,c,d;

bool cmp(double a, double b) {
    return a>b;
}
map<string, int> mp;

int find(double fen, string name) {
    if(name=="la") {
        for(int i = 0 ; i < n; i++)
            if(aa[i] == fen)
                return i;
    } else if(name=="lc") {
        for(int i = 0 ; i < n; i++)
            if(cc[i] == fen)
                return i;
    } else if(name=="lm") {
        for(int i = 0 ; i < n; i++)
            if(mm[i] == fen)
                return i;
    } else if(name=="le") {
        for(int i = 0 ; i < n; i++)
            if(ee[i] == fen)
                return i;
    }
}

int main() {
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>a>>b>>c>>d;
        p[i].id = a;
        mp[a] = i+1;
        p[i].c = cc[i] = b;
        p[i].m = mm[i] = c;
        p[i].e = ee[i] = d;
        p[i].a = aa[i] = b+c+d;
    }
    sort(cc, cc+n, cmp);
    sort(mm, mm+n, cmp);
    sort(ee, ee+n, cmp);
    sort(aa, aa+n, cmp);
//    for(int i = 0 ; i < n ; i++) {
//        cout<<cc[i];
//    }
//    for(int i = 0; i < n; i++) {
//        printf("%s %lf %lf %lf %.0lf\n", p[i].id.c_str(), p[i].c, p[i].m, p[i].e, p[i].a);
//    }

//        for(int i = 0 ; i < m ; i++) {
//            string id;
//            cin>>id;
//            cout<<mp[id]<<endl;
//        }

    for(int i = 0; i < m ; i++) {
        string id;
        cin>>id;
        int index = mp[id]-1;
        if(index<0) {
            cout<<"N/A"<<endl;
        } else {
            int la, lc, lm, le;
            la = find(p[index].a, "la");
            lc = find(p[index].c, "lc");
            lm = find(p[index].m, "lm");
            le = find(p[index].e, "le");
            if(la == min(la, min(lc, min(lm, le)))) {
                cout<<la+1<<" "<<"A"<<endl;
            } else if(lc == min(la, min(lc, min(lm, le)))) {
                cout<<lc+1<<" "<<"C"<<endl;
            } else if(lm == min(la, min(lc, min(lm, le)))) {
                cout<<lm+1<<" "<<"M"<<endl;
            } else if(le == min(la, min(lc, min(lm, le)))) {
                cout<<le+1<<" "<<"E"<<endl;
            }
        }
    }
}