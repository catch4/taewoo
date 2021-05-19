#include <bits/stdc++.h>
using namespace std;
int answer;
int h, w;
int main() {

    cin >> h >> w;
    vector<int> v(w);

    for (int i = 0; i < w; i++)
        cin >> v[i];

    for (int i = 1; i < w - 1; i++) {
        int left = 0; int right = 0;
        for (int j = 0; j < i; j++) left = max(left, v[j]); // 내 기준 가장 왼쪽에서 큰 값
        for (int j = w - 1; j > i; j--) right = max(right, v[j]); // 내 기준 가장 오른쪽에서 큰 값
        answer += max(0, min(left, right) - v[i]); // 내 위치에 들어올 수 있는 빗물의 값
    }

    cout << answer << endl;
    return 0;
}