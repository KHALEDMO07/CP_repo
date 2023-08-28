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
const int N = 2e5 +  9 , M = 1e2 + 9;
template<typename T = int>
istream& operator >> (istream &in ,  vector<int> &p) {
    for (auto &it : p) { in >> it; }
    return in;
}
template<typename T = ll>
ostream& operator << (ostream &out ,  deque<ll> &p) {
    for (auto &it: p) { out << it << '\n'; }
    return out;
}
int main() {
    Klaus_();
    int t = 1, id = 1;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 1, val = 2;
        ll cur = 2;
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        while (cur < n) {
            if (cur + val >= n) {
                ans++;
                break;
            }
            cur += (2 * val), ans += 2, val++;
        }
        cout << ans << '\n';
    }
}
