#include <iostream>
#include <cstring>
#define MAX 300001
using namespace std;

int uf[MAX];
int n;

int uf_find(int x) {
    return uf[x] == -1 ? x : uf[x] = uf_find(uf[x]);
}

bool uf_union(int x, int y) {
    int X = uf_find(x);
    int Y = uf_find(y);
    if(X == Y) return false;
    uf[X] = Y;
    return true;
}

int main() {
    cin >> n;
    memset(uf, -1, sizeof(uf));
    for(int i = 0; i < n - 2; i++) {
        int a, b;
        cin >> a >> b;
        uf_union(a, b);
    }
    for(int i = 2; i <= n; i++) {
        if(uf_union(1, i)) {
            cout << 1 << " " << i;
            return 0;
        }
    }
    return 0;
}