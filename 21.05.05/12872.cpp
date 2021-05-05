#include <iostream>
#include <cstring>
using namespace std;

int N, M, P;
int dp[101][101]; // 선택한 노래 개수, 플레이리스트 길이

int go(int pick, int playList) {

    int &ret = dp[pick][playList];
    if(ret != -1) return ret;

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> P;

    memset(dp, -1, sizeof(dp));
    int answer = go(0, 0);
}