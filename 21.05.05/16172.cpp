/*
Comment: �־��� ���ڿ����� ���� ���� ��, ���ϴ� ���ڿ����� Ȯ���ϱ�
*/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string tmp;
    string s;
    getline(cin, tmp);
    for(char c: tmp) {
        if('0' <= c && c <='9') continue;
        s.push_back(c);
    }
    string t;
    getline(cin, t);
    if(s.find(t) != string::npos) cout << 1 << "\n";
    else cout << 0 << "\n";
}