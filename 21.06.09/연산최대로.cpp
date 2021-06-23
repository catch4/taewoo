#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll arr[9], N, answer;
int P, Q;
bool used[9];
ll V[10], op[10], value[10];

// 연산자 경우의 수 구하기
void dfs2(int cnt) {
    if(cnt == N - 1) {
        int idx = 0;
        value[idx ++] = V[0];
        for(int i=1;i<N;i++) {
            if(op[i - 1]) value[idx ++] = V[i];
            else value[idx - 1] += V[i];
        }
        // 값을 크게 하기 위해선 더하기를 진행하고 곱하기를 나중에하면 값이 커짐.
        ll cur = 1;
        for(int i=0;i<idx;i++) cur *= value[i];
        answer = max(answer, cur);
        return;
    }

    if(P) {
        P --;
        op[cnt] = 0;
        dfs2(cnt + 1);
        P ++;
    }
    if(Q) {
        Q --;
        op[cnt] = 1;
        dfs2(cnt + 1);
        Q ++;
    }
}

// 숫자 경우의 수 구하기
void dfs(int cnt) {
    if(cnt == N) {
        dfs2(0);
        return;
    }

    for(int i=0;i<N;i++) {
        if(used[i]) continue;
        used[i] = true;
        V[cnt] = arr[i];
        dfs(cnt + 1);
        used[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    cin >> P >> Q;
    dfs(0);
    cout << answer;

    return 0;
}