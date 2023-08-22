/*
 -https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1558
 - think of using (dp->(ranges))
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
const int N = 1e3 +  9 , M = 1e2 + 9;
int n , ID = 0 , vis[70][70];
string s;
ll dp[70][70];
ll solve(int i , int j) {
    if (i > j) { return 0; }
    ll &ret = dp[i][j];
    if (vis[i][j] == ID) { return ret; }
    vis[i][j] = ID;
    ret = 0;
    if (s[i] == s[j]) { ret = 1 + solve(i + 1, j - 1); }
    ret = ret + solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1);
    //sub-problem overlap (i + 1 , j) and (i , j - 1) both of them contain (i + 1 , j - 1)
    return ret;
}
int main() {
    Klaus_();
    int t = 1, id = 1;
    cin >> t;
    while (t--) {
        ++ID;
        cin >> s;
        n = s.size();
        cout << solve(0, n - 1) << '\n';
    }
}
