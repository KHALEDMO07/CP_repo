//Destiny is all
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
const int N = 2e3+9 , M = 600;
template<typename T>
istream& operator >> (istream &in ,  vector<T> &p) {
    for (auto &it : p) { in >> it; }
    return in;
}
template<typename T>
ostream& operator << (ostream &out ,  vector<T> &p) {
    for (auto &it: p) { out << it << ' '; }
    cout << '\n';
    return out;
}
ll dp[N][N];
int a , n , m , l , r , x , w;
vector<int>rain;
vector<int>p;
ll solve(int i , int j) {
    if (i == a)return 0;
    ll &ret = dp[i][j + 1];
    if (~ret)return ret;
    ret = 1e9;
    //validition case .. we can not complete in this way
    if (rain[i] > 0 && j == -1 && p[i] == 1e9)return ret;
    //we have umb here try to get it..
    if (p[i] != 1e9)ret = min(ret, solve(i + 1, i) + p[i]);
    //Safe road..
    if (rain[i] == 0) {
        ret = min(ret, solve(i + 1, -1));
    }
    //we alredy have umb try to move with it..
    if (~j) {
        ret = min(ret, solve(i + 1, j) + p[j]);
    }
    return ret;
}
int main() {
    Klaus_();
    int t = 1, id = 1;
    //  cin >> t;
    while (t--) {
        cin >> a >> n >> m;
        rain = vector<int>(N + 1, 0);
        p = vector<int>(N + 1, 1e9);
        for (int i = 0; i < n; i++) {
            cin >> l >> r;
            rain[l]++, rain[r]--;
        }
        for (int i = 1; i <= N; i++)rain[i] += rain[i - 1];
        for (int i = 0; i < m; i++) {
            cin >> x >> w;
            p[x] = min(w, p[x]);
        }
        memset(dp, -1, sizeof dp);
        cout << (solve(0, -1) < 1e9 ? solve(0, -1) : -1) << '\n';
    }
}
