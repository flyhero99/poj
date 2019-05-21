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
// const int maxm = 1005;
const int inf = 0x3f3f3f3f;

vector<string> vec;

int nxt[105];

void getNext(string s) {
    int slen = s.length();
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < slen) {
        if(j == -1 || s[i] == s[j]) {
            i++, j++;
            nxt[i] = j;
        }
        else
            j = nxt[j];
    }
}

int kmp(string s, string p) {
    int i = 0, j = 0, slen = s.length(), plen = p.length();
    while(i < slen && j < plen) {
        if(j == -1 || s[i] == p[j]) {
            i++, j++;
        }
        else
            j = nxt[j];
    }
    if(j == plen) return i-j;
    return -1;
}

int main() {
    int t; cin >> t;
    while(t--) {
        vec.clear();
        int n; cin >> n;
        for(int i = 1; i <= n; i++) {
            string s; cin >> s; vec.push_back(s);
        }
        string ans = "";
        for(int len = 1; len <= vec[0].length(); len++) {
            bool flag = 0;
            for(int j = 0; j <= vec[0].length()-len; j++) {
                string ss = vec[0].substr(j, len);
                getNext(ss);
                bool flag = 0;
                for(int k = 1; k < vec.size(); k++) if(kmp(vec[k], ss) == -1) flag = 1;
                if(!flag) {
                    if(ans.length() < ss.length()) ans = ss;
                    else if(ans.length() == ss.length()) ans = min(ans, ss); 
                }
            }
        }
        if(ans.length() < 3) cout << "no significant commonalities" << endl;
        else cout << ans << endl;
    }
    return 0;
}

/*
3
2
GATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
3
GATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATA
GATACTAGATACTAGATACTAGATACTAAAGGAAAGGGAAAAGGGGAAAAAGGGGGAAAA
GATACCAGATACCAGATACCAGATACCAAAGGAAAGGGAAAAGGGGAAAAAGGGGGAAAA
3
CATCATCATCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
ACATCATCATAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
AACATCATCATTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
*/