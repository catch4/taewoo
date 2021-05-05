#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int arr[50001];
int prefix_sum[50001];
int dp[3][50001]; // 0,1,2 번째 소형기관차를 사용해 idx에서 최대 인구값

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    prefix_sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    }
    cin >> m;
}

int go(int small_train, int idx) {
    
    if(small_train >= 3) return 0;
    if(idx >= n) return 0;

    int &ret = dp[small_train][idx];
    if(ret != -1) return dp[small_train][idx];

    // 현재 소형 기관차를 사용하지 않은경우..
    // 소형 기관차를 사용하는 경우..
    if(idx + m - 1 < n) {
        ret = max(go(small_train, idx + 1), go(small_train + 1, idx + m) + prefix_sum[idx + m] - prefix_sum[idx]);
    }
    return ret;
}

void pro(){
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    pro();
    return 0;
}