//
// Created by wxd on 2020/6/7.
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

const int INF = 1e9+7;
const int maxn = 505;
int cmax, n, sp, m, x, y; // cmax车站最大容量, n车站总数, sp有问题的车站编号, m路径数
int minNeed = INF, minBack = INF;
int t[maxn][maxn];	// t[i][j]表示从i到j所需要花费的时间
int dis[maxn];	// dis[i]表示从起点到i号车站的最短距离
int num[maxn];	// num[i]表示第i个车站的车数与5的差，也就是离完美状态的差值
bool vis[maxn];	// vis[i]=true表示i点已访问，vis[i]=false表示i点未访问

vector<int> pre[maxn]; //pre[i]用来记录到达i点的前一个点的编号(可能有多个，所以是二维的)
vector<int> path, tmppath;	//path用来存储答案，tmppath用来计算

void dijkstra()	{ //Dijkstra求最短路径
    dis[0] = 0;
    for (int i = 0; i <= n; i++) {
        int index = -1, minn = INF;
        for (int j = 0; j <= n; j++) {   //从未选择点集中选择一个距离最短的点
            if (vis[j] == false && dis[j] < minn) {
                index = j;
                minn = dis[j];
            }
        }
        if (index == -1)
            break;
        vis[index] = true;

        for (int j = 0; j <= n; j++) {   //判断是否有通过一个中转到达使距离更短
            if (vis[j] == false && t[index][j] != INF) {
                if (dis[j] > dis[index] + t[index][j]) {
                    dis[j] = dis[index] + t[index][j];    //求最短路径
                    pre[j].clear();
                    pre[j].push_back(index);    //记录到达这个点的上一个点
                } else if (dis[j] == dis[index] + t[index][j]) {
                    pre[j].push_back(index);    //记录到达这个点的上一个点
                }
            }
        }
    }
}

void dfs(int v) {	//dfs求minNeed和minBack和path
    tmppath.push_back(v);    //将当前点推进vector数组中
    if (v == 0) { //结束条件
        int need = 0, back = 0;    //need记录正向路径需求的车辆数，back记录反向路径需求的车辆数
        for (int i = tmppath.size() - 1; i >= 0; i--) {   //暴力搜索更优的路径
            int now = tmppath[i];    //记录当前编号
            if (num[now] > 0) {   //如果当前站点有车多下来，直接算入反向路径中，因为sp点缺车
                back += num[now];   // 能给后面节点num[now]辆
            } else {    // 当前节点缺车
                if (back > (0 - num[now])) {   // 发现带的车子足够让当前节点变得完美，先把这个节点变完美
                    back += num[now];
                } else {   // 无法保证当前节点完美，只能增加开始的需求量
                    need += ((0 - num[now]) - back);
                    back = 0;
                }
            }
        }
        if (need < minNeed) {   //不断更新最小搬运车辆
            minNeed = need;
            minBack = back;
            path = tmppath;    //路径赋值
        } else if (need == minNeed && back < minBack) {   //当正向路径所需搬运车辆相同时，取反向路径小的那一条路
            minBack = back;
            path = tmppath;    //路径赋值
        }
        tmppath.pop_back();    //弹出当前点
        return;
    }
    for (int i = 0; i < pre[v].size(); i++)    //从终点开始不断向前暴力计算前一个路径的状态
        dfs(pre[v][i]);
    tmppath.pop_back();    //弹出当前点
}

int main() {
    fill(t[0], t[0] + maxn * maxn, INF);
    fill(dis, dis + maxn, INF);
    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        num[i] -= cmax / 2;
    }
    while (m--) {
        cin >> x >> y;
        cin >> t[x][y];
        t[y][x] = t[x][y];
    }

    dijkstra();    //求最短路径
    dfs(sp);    //从终点开始dfs前推优化路径

    cout << minNeed << " 0";
    for (int i = path.size() - 2; i >= 0; i--)    //因为path是从最后一个节点到底一个节点记录的，所以要倒着输出
        cout << "->" << path[i];
    cout << " " << minBack << endl;
    return 0;
}