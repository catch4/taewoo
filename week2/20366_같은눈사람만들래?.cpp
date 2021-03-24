/*
Comment: 완전탐색으로 구현하여 시간초과발생
         600C4로 4개를 뽑는것자체에서 부터 시간초과가 발생하여 하면안됨.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, answer;
int snows[601];
void input() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> snows[i];
    }    
}

long long int make_snow(vector<int> &candid) {
    sort(candid.begin(), candid.end());
    ll ret = 2e9;
    ll sum = 0;
    for(auto i : candid) sum += i;

    ll subsum = 0;
    ll subsum2 = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j) continue;
            subsum = candid[i] + candid[j];
            subsum2 = sum - subsum;
            ret = min(ret, abs(subsum - subsum2));
        }
    }
    return ret;
}

vector<int> tmp;
void find_four() {
    for(int i = 0; i < n - 4; i++) tmp.push_back(0);
    for(int i = 0; i < 4; i++) tmp.push_back(1);
    
    vector<int> candid;
    do {
        candid.clear();
        for(int i = 0; i < tmp.size(); i++) {
            if(tmp[i]) candid.push_back(snows[i + 1]);
        }
        
        answer = make_snow(candid);
    } while(next_permutation(tmp.begin(), tmp.end()));
}

void pro() {
    find_four();
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
    return 0;
}