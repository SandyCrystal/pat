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

char str[105];

map<char, int> mp1;
map<int, string> mp2;

int main() {
    cin>>str;
    mp1.insert(pair<char, int>('0', 0));
    mp1.insert(pair<char, int>('1', 1));
    mp1.insert(pair<char, int>('2', 2));
    mp1.insert(pair<char, int>('3', 3));
    mp1.insert(pair<char, int>('4', 4));
    mp1.insert(pair<char, int>('5', 5));
    mp1.insert(pair<char, int>('6', 6));
    mp1.insert(pair<char, int>('7', 7));
    mp1.insert(pair<char, int>('8', 8));
    mp1.insert(pair<char, int>('9', 9));
    mp2.insert(pair<int, string>(0, "zero"));
    mp2.insert(pair<int, string>(1, "one"));
    mp2.insert(pair<int, string>(2, "two"));
    mp2.insert(pair<int, string>(3, "three"));
    mp2.insert(pair<int, string>(4, "four"));
    mp2.insert(pair<int, string>(5, "five"));
    mp2.insert(pair<int, string>(6, "six"));
    mp2.insert(pair<int, string>(7, "seven"));
    mp2.insert(pair<int, string>(8, "eight"));
    mp2.insert(pair<int, string>(9, "nine"));
    int sum = 0;
    for(int i = 0 ; i < 105; i++) {
        sum += mp1[str[i]];
    }

    int tmp = sum;
    int len = 0;
    while(tmp!=0) {
        tmp /= 10;
        len ++;
    }
    int flag = 1;
    if(sum==0) {
        cout<<"zero";
    }
    while(len) {
        if(flag==1) {
            flag = 0;
            cout<<mp2[sum/(int)pow(10,len-1)];
        } else {
            cout<<" "<<mp2[sum/(int)pow(10,len-1)];
        }
        sum = sum%(int)pow(10,len-1);
        len = len-1;
    }
}