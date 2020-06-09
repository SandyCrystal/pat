//
// Created by wxd on 2020/6/9.
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

int n, m;
struct node {
    string id;
    string title;
    string author;
    string keyword;
    string publisher;
    string year;
} p[10005];

bool cmp(string a, string b) {
    return a < b;
}

int main() {
//    std::ios::sync_with_stdio(false);
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        getline(cin, p[i].id);
        getline(cin, p[i].title);
        getline(cin, p[i].author);
        getline(cin, p[i].keyword);
        getline(cin, p[i].publisher);
        getline(cin, p[i].year);
    }
//    for (int j = 0; j < n; ++j) {
//        printf("1:%s\n2:%s\n3:%s\n4:%s\n5:%s\n6:%s\n----------\n", p[j].id.c_str(), p[j].title.c_str(), p[j].author.c_str(), p[j].keyword.c_str(), p[j].publisher.c_str(), p[j].year.c_str());
//    }
    cin >> m;
    getchar();
    string wxd;
    for (int i = 0; i < m; i++) {
        getline(cin, wxd);
        cout << wxd << endl;
        vector<string> v;
        if (wxd[0] == '1') {
            wxd = wxd.substr(3, wxd.length());
            v.clear();
            for (int j = 0; j < n; ++j) {
                if (p[j].title == wxd) {
                    v.push_back(p[j].id);
                }
            }
            sort(v.begin(), v.end(), cmp);
            if (v.size() != 0) {
                for (int j = 0; j < v.size(); ++j) {
                    cout << v[j] << endl;
                }
            } else {
                cout << "Not Found" << endl;
            }
        } else if (wxd[0] == '2') {
            wxd = wxd.substr(3, wxd.length());
            v.clear();
            for (int j = 0; j < n; ++j) {
                if (p[j].author == wxd) {
                    v.push_back(p[j].id);
                }
            }
            sort(v.begin(), v.end(), cmp);
            if (v.size() != 0) {
                for (int j = 0; j < v.size(); ++j) {
                    cout << v[j] << endl;
                }
            } else {
                cout << "Not Found" << endl;
            }
        } else if (wxd[0] == '3') {
            wxd = wxd.substr(3, wxd.length());
            v.clear();
            for (int j = 0; j < n; ++j) {
                int idx = p[j].keyword.find(wxd);
                if (idx >= 0 && idx < p[j].keyword.length()) {
                    v.push_back(p[j].id);
                }
            }
            sort(v.begin(), v.end(), cmp);
            if (v.size() != 0) {
                for (int j = 0; j < v.size(); ++j) {
                    cout << v[j] << endl;
                }
            } else {
                cout << "Not Found" << endl;
            }
        } else if (wxd[0] == '4') {
            wxd = wxd.substr(3, wxd.length());
            for (int j = 0; j < n; ++j) {
                if (p[j].publisher == wxd) {
                    v.push_back(p[j].id);
                }
            }
            sort(v.begin(), v.end(), cmp);
            if (v.size() != 0) {
                for (int j = 0; j < v.size(); ++j) {
                    cout << v[j] << endl;
                }
            } else {
                cout << "Not Found" << endl;
            }
        } else if (wxd[0] == '5') {
            wxd = wxd.substr(3, wxd.length());
            v.clear();
            for (int j = 0; j < n; ++j) {
                if (p[j].year == wxd) {
                    v.push_back(p[j].id);
                }
            }
            sort(v.begin(), v.end(), cmp);
            if (v.size() != 0) {
                for (int j = 0; j < v.size(); ++j) {
                    cout << v[j] << endl;
                }
            } else {
                cout << "Not Found" << endl;
            }
        }
    }
}