#include <iostream>
#include <cstring>
using namespace std;

int N, M, P;
int dp[101][101]; // ������ �뷡 ����, �÷��̸���Ʈ ����

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