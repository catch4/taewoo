#include<bits/stdc++.h>
using namespace std;

int N, M;
int rides[10000];

bool isOk(int mid) {
    long long num = M;
    for(int i = 0; i < M; i++) {
        num += mid / rides[i];
    }
    return num >= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> rides[i];
    }

    if(N <= M) {
        cout << N;
        return 0;
    }

    long long result = 0;
    long long left = 0;
    long long right = 60000000000;
    
    while(left <= right) {
        long long mid = (left + right) / 2;
        if(isOk(mid)) {
            right = mid - 1;
            result = mid;
        }
        else {
            left = mid + 1;
        }
    }
}