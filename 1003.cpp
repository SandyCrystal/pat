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

const int INF = 1e9+7;
int n, m, a, b, c, st, ed;
int e[505][505];
bool vis[505];
int dis[505], dcnt[505];
int people[505], p[505];

void dijkstra(int st)
{
//    for(int i = 0 ; i < n ; i++) {
//        if(e[i][st] < INF) {
//            dis[i] = e[i][st];
//        } else {
//            dis[i] = INF;
//        }
//    }
    for(int i = 0 ; i < n ; i++) {
        int index = -1;
        int tmp = INF;
        for(int j = 0 ; j < n ; j++) {
            if(!vis[j] && dis[j]<tmp) {
                tmp = dis[j];
                index = j;
            }
        }
        if(index==-1) {
            break;
        }
        vis[index] = true;
        for(int j = 0 ; j < n ; j++) {
            if(!vis[j] && dis[j]>dis[index]+e[index][j]) {
                dis[j] = dis[index]+e[index][j];
                p[j] = p[index] + people[j];
                dcnt[j] = dcnt[index];
            } else if(!vis[j] && dis[index]+e[index][j]==dis[j] ) {
                dcnt[j] += dcnt[index];
                if(p[j] < p[index] + people[j])
                    p[j] = p[index]+people[j];
            }
        }
    }
}

int main()
{
    fill(e[0],e[0]+505*505, INF);
    fill(dis,dis+505,INF);
    fill(p,p+505,0);
    fill(dcnt,dcnt+505,0);
    memset(vis, false, sizeof(vis));

    cin>>n>>m>>st>>ed;
    for(int i = 0 ; i < n ; i++) {
        cin>>people[i];
    }

    while(m--) {
        cin>>a>>b>>c;
        e[a][b] = e[b][a] = c;
    }

    dis[st] = 0;
    p[st] = people[st];
    dcnt[st] = 1;
    dijkstra(st);
    cout<<dcnt[ed]<<" "<<p[ed];
}