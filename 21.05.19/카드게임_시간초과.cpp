// 자기 턴일 때 오른쪽첫번째를 가져가거나 왼쪽 첫번째를 가져가거나..
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int answer[2];
vector<int> v;
int go(int left, int right, int flag) {
    if(left >= right) {
        if(flag == 0) return v[left];
        else return 0;
    };

    // 근우가 가져갈 경우 flag = 0
    if(flag == 0) {
        answer[0] = max(go(left + 1, right, 1) + v[left], go(left, right - 1, 1) + v[right]);
        return answer[0];
    }
    
    // 명우가 가져갈 경우 flag = 1
    else {
        answer[1] = min(go(left + 1, right, 0), go(left, right - 1, 0));
        return answer[1];
    }
}

int t, n;
int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        v.clear(); v.resize(n);
        for(int i = 1; i <= n; i++) cin >> v[i];
        go(1, n, 0);
        cout << answer[0] << "\n";
    }
    return 0;
}