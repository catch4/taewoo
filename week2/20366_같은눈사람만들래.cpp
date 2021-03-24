#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
int snows[601];
int answer = 2e9;
void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> snows[i];
    }
    sort(snows, snows + n);
}

void pro() {
    int left, right;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j< n; j++) {
            int snow = snows[i] + snows[j];
            left = 0;
            right = n - 1;

            while(1) {
                while(left == i || left == j) {
                    left++;
                }
                while(right == i || right == j) {
                    right--;
                }
                if(left >= right) break;

                int snow2 = snows[left] + snows[right];
                answer = min(answer, abs(snow - snow2));
                if(snow < snow2) right--;
                else left++;
            }
        }
    }
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
    return 0;
}