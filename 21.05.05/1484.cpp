/*
Comment: G를 기준으로 하나씩 늘려나가면서 값 찾기
*/

#include <iostream>
using namespace std;

int G;
int main() {
    cin >> G;
    int left = 1; int right = 1;
    bool flag = false;
    while(left <= right & right <= 1e5) {
        int tmp = right * right - left * left;
        if(G < tmp) {
            left++;
        }
        else if(G == tmp) {
            flag = true;
            cout << right << "\n";
            right++;
        }
        else if(G > tmp) {
            right++;
        }
    }
    if(!flag) cout << - 1 << '\n';
    return 0;
}