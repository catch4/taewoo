#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

pair<int, int> mat[501];
int dp[501][501];
int n;

int go(int x, int y) {
    if(x == y) return 0;
    int &ret = dp[x][y];
    if(ret != -1) return ret;

    ret = 987654321;
    for(int i = x; i < y; i++) {
        ret = min(ret, go(x, i) + go(i + 1, y) + mat[x].first * mat[i].second * mat[y].second);
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> mat[i].first >> mat[i].second;
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0, n - 1);
}