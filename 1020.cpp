//
// Created by wxd on 2020/6/6.
//

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> hou, zhong;
map<int, int> level;

void pre(int root, int start, int end, int index) {
    if (start > end) return;
    int i = start;
    // 找到根的下标
    while (i < end && zhong[i] != hou[root]) i++;
    level[index] = hou[root];
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}

int main() {
    int n;
    scanf("%d", &n);
    hou.resize(n);
    zhong.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &hou[i]);
    for (int i = 0; i < n; i++) scanf("%d", &zhong[i]);
    pre(n - 1, 0, n - 1, 1);
    for (auto it = level.begin(); it != level.end(); it++)
        it == level.begin() ? printf("%d", it->second) : printf(" %d", it->second);
}