/*https://codeforces.com/contest/1195/problem/C
*  we can solve this problem using dp
*  first try to think , if u can not solve it , check the code  
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
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void Klaus_() {
    // freopen("icecream.in", "r", stdin);

    //    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int DX[] = { 2 , 2 , -2 , -2 , 1 , 1 , -1 , -1 };
int DY[] = { -1 , 1 , -1 , 1 , 2 , -2 , 2 , -2 };
const int OO = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 1e5 + 9, M = (1 << 9) + 9;
int n;
vector<vector<int>>v;
ll dp[N][2];
ll solve(int i, int cur) {
    if (i == n) { return 0; }
    ll& ret = dp[i][cur];
    if (~ret)return ret;
    if (cur == 0) {
        ret = max({ solve(i + 1, 1), solve(i + 1, 1) + v[0][i], solve(i + 1, 0) });
    }
    else ret = max({ solve(i + 1, 1), solve(i + 1, 0) + v[1][i], solve(i + 1, 0) });
    return ret;
}
int main() {
    Klaus_();
    int t = 1, id = 1;
    // cin >> t;
    while (t--) {
        cin >> n;
        v = vector<vector<int>>(2, vector<int>(n));
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < 2; i++) { for (auto& it : v[i]) { cin >> it; } }
        cout << max(solve(0, 1), solve(0, 0)) << '\n';
    }
}
