#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define LEN 1 << 21
int N;
int treeSize;
int tree[LEN];
int answer;

int go(int idx) {
    if(idx * 2 >= treeSize) {
        answer += tree[idx];
        return tree[idx];
    }
    
    int left = go(idx * 2);
    int right = go(idx * 2 + 1);
    answer += tree[idx] + abs(left - right);
    return tree[idx] + max(left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    treeSize = 1 << (N + 1);
    for(int i = 2; i < treeSize; i++) cin >> tree[i];
    
    go(1);
    cout << answer << "\n";
    return 0;
}