#include <bits/stdc++.h>
using namespace std;

int n, m, answer;
bool compare(int a, int b) {
    return a > b;
}

vector<int> l, r;
void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x < 0) l.push_back(x);
        else r.push_back(x);
    }
}

void pro() {
    sort(l.begin(), l.end());
    sort(r.begin(), r.end(), compare);

    for(int i = 0; i < l.size(); i += m) { // -39 -37 -29 -28 -6
        answer += abs(l[i]) * 2;
    }
    for(int i = 0; i < r.size(); i += m) // 11 2
        answer += r[i] * 2;
    
    abs(l[0]) > r[0] ? answer -= abs(l[0]) : answer -= r[0];
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}
