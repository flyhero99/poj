#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;

int main() {
    string s, t;
    while(cin >> s >> t) {
        int slen = s.length(), tlen = t.length();
        int i = 0, j = 0;
        while(1) {
            if(i == slen) {
                cout << "Yes" << endl;
                break;
            }
            else if(i < slen && j == tlen) {
                cout << "No" << endl;
                break;
            }
            if(s[i] == t[j]) {
                i++; j++;
            }
            else j++;
        }
    }
    return 0;
}