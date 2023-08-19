/*
  -https://codeforces.com/contest/1263/problem/D
  - this solution with dsu , try to solve it with yourself first
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define PI 3.14159265
#define all(v) v.begin(),v.end()
#define  lla(v) v.rbegin(),v.rend()
#define lld long double
#define fix(n) cout << fixed << setprecision(n);
ll gcd(ll a, ll b){if (b == 0) return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void Klaus_() {
    // freopen("icecream.in", "r", stdin);

    //    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int DX[] = {2 , 2 , -2 , -2 , 1 , 1 , -1 , -1};
int DY[] = {-1 , 1 , -1 , 1 , 2 , -2 , 2 , -2};
const int OO = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 5e1 +  9 , M = (1<<9) + 9;
ll n, m , a , b;
class DSU {
public:
    vector<int>parent;
    DSU() {
        parent.resize(26);
        for (int i = 0; i < 26 ; i++) {
            parent[i] = i;
        }
    }

    char FindLeader(int node) {
        if (parent[node] == node)return node;
        return parent[node] = FindLeader(parent[node]);
    }

    void Union(int a, int b) {
        char lead1 = FindLeader(a), lead2 = FindLeader(b);
        if (lead1 == lead2) {
            return;
        }
        parent[lead2] = lead1;
    }

};
int main() {
    Klaus_();
    int t = 1, k;
    //  cin >> t;
    while (t--) {
        cin >> n;
        vector<string> v(n);
        DSU dsu;
        set<int> st, ans;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            string s = v[i];
            for (int j = 0; j < s.size(); j++) {
                for (int q = 0; q < s.size(); q++) {
                    if (dsu.FindLeader(int(s[j]-'a')) != dsu.FindLeader(int(s[q]-'a'))) {
                        dsu.Union(int(s[j]-'a'), int(s[q]-'a'));
                    }
                }
                st.insert(int(s[j]-'a'));
            }
        }

        for (auto &it: st) {
            ans.insert(dsu.FindLeader(it));
        }
        cout << ans.size() << '\n';
    }
}
