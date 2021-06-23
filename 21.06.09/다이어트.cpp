#include <bits/stdc++.h>
using namespace std;

struct Node {
    int p, f, s, v, cost;
} node[16];
int ret = 987654321;
int n, p, f, s, v, cost;
map<int, vector<vector<int>>> mp; // 사전 순을 위해서

void input() {
    cin >> n;
    cin >> p >> f >> s >> v;
    for(int i = 0; i < n; i++)
        cin >> node[i].p >> node[i].f >> node[i].s >> node[i].v >> node[i].cost;
}

void pro() {
    for(int i = 1; i < (1 << n); i++) {
        int a, b, c, d, sum;
        a = b = c = d = sum = 0;
        vector<int> vec;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                vec.push_back(j + 1);
                a += node[j].p;
                b += node[j].f;
                c += node[j].s;
                d += node[j].v;
                sum += node[j].cost;
            }
        }
        if(a >= p && b >= f && c >= s && d >= v) {
            if(ret >= sum) {
                ret = sum;
                mp[ret].push_back(vec);
            }
        }
    }
    if(ret == 987654321) {
        cout << -1 << "\n";
    }
    else {
        sort(mp[ret].begin(), mp[ret].end());
        cout << ret << "\n";
        for(auto ref : mp[ret][0])
            cout << ref << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    pro();
}