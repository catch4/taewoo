#include<bits/stdc++.h>
using namespace std;

string str;
void input () { cin >> str; }

// a b a b a b a b a b a b a b a
int answer = 2e9;
int sz;
int go(int idx) {
    int ret = 0;
    for(int i = idx; i < idx + sz; i++) {
        if(str[(i + 1) % str.size()] == 'a') ret++;
    }
    return ret;
}
void pro () {
    for(int i = 0; i < str.size(); i++)
        if(str[i] == 'b') sz++;

    for(int i = 0; i < str.size(); i++)
        answer = min(answer, go(i));
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}