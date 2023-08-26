/*
 -https://codeforces.com/contest/356/problem/A
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
const ll Mod = 1e9 + 7;
const int N = 2e5 +  9 , M = 1e2 + 9;
class dsu{
public:
    vector<int>parent;
    dsu(int sz) {
        parent.resize(sz+2);
        for (int i = 1; i <= sz + 1; i++) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (parent[i] == i)return i;
        return parent[i] = find(parent[i]);
    }
};
template<typename T = ll>
istream& operator >> (istream &in ,  vector<ll> &p) {
    for (auto &it : p) { in >> it; }
    return in;
}
template<typename T = int>
ostream& operator << (ostream &out ,  vector<int> &p) {
    for (auto &it : p) { out << it << " ";}
    return out;
}
int main() {
    Klaus_();
    int t = 1, id = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        dsu ds(n);
        vector<int> answer(n + 1, 0);
        while (m--) {
            int l, r, x;
            cin >> l >> r >> x;
            l = ds.find(l);
            while (l <= r) {
                if (l == x) { l++; }
                else {
                    answer[l] = x;
                    ds.parent[l] = l + 1, l++;
                }
                l = ds.find(l);
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << answer[i] << " ";
        }
    }
}
