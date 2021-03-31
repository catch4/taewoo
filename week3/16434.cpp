/*
Comment : 최소로 필요한 hp구하기에 이분탐색 느낌 물씬..
        : 최대로 가질 수 있는 hp 값이 무엇일까...
*/
#include<bits/stdc++.h>
using namespace std;

int n, attack;
int t[123457], a[123457], h[123457];
void input() {
    cin >> n >> attack;
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> h[i];
    }
};

bool isOk(int mid) {
    int max_hp = mid;
    int init_atk = attack;
    // 모든 방 들어가보기;;
    for(int i = 0; i < n; i++) {
        // 물약인 방
        if(t[i] == 2) {
            mid = (max_hp, mid + h[i]); // 물약을 먹고 난 후
            init_atk += a[i]; // 공격력 올리기
        }
        // 몬스터가 있는 방
        else {
            
        }
    }
    return true;
}

void pro() {
    int left = 1; int right = 1e6;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(isOk(mid)) {

        }
        else {

        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    pro();
    return 0;
}