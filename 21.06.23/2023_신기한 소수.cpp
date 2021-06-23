#include<bits/stdc++.h>
using namespace std;

int n;
void input() {
    cin >> n;
}
int prime[] = {2, 3, 5, 7};

bool isOk(int num) {
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void go(int val, int cnt) {
    if(n - 1 == cnt) cout << val << "\n";

    for(int i = 1; i <= 10; i++) {
        int temp = val * 10 + i;
        if(isOk(temp)) go(temp, cnt + 1);
    }
}
void pro() {
    for(int i = 0; i < 4; i++) go(prime[i], 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}