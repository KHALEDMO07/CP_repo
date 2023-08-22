//https://codeforces.com/contest/1688/problem/B
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
const int N = 1e4 +  9 , M = 1e2 + 9;
int n;
int A[] = {0 , 0 , 1 , -1};
int B[] = {1 , -1 , 0 , 0};
template<typename T = int>
istream& operator >> (istream &in , vector<T>&v){
    for(auto &it : v){in >>  it;}
    return in;
}
template<typename T = int>
ostream& operator << (ostream &out , vector<T>&v){
    for(auto &it : v){out << it << " ";}
    out << '\n';
    return out;

}
int main() {
    Klaus_();
    int t = 1, id = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        cin >> v;
        int minOp = 34, cn = 0;
        for (auto &it: v) {
            cn += (it & 1);
            if (it % 2 == 0) {
                for (int j = 0; j < 32; j++) {
                    if ((it >> j) & 1) {
                        minOp = min(minOp, j);
                        break;
                    }
                }
            }
        }
        int out = n - cn;
        if (out > 0) {
            cout << (cn == 0 ? minOp + (n - 1) : n - cn) << '\n';
        } else cout << 0 << '\n';
    }
}
/*
 * what if all  elements are even ?
 * find the min cost to convert even to odd ->2 2 8 8 , make 2 -> 1 ,cost = 1
 * make the rest of elements odd , cost = min_cost + (n - 1)
 * 2 4 8 - > 1 4 8 , cost = 1
 * 5 8 -> cost = 2
 * 13 -> cost = 3
 */
