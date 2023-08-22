/*
 -https://codeforces.com/contest/1385/problem/E
 - read about DAG , and Topoligical sort graph
 - think FIRST
*/
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
int n , m , f , to , dis;
vector<bool>vis;
stack<int>topo_sort;
vector<int>dir[N];
int A[] = {0 , 0 , 1 , -1};
int B[] = {1 , -1 , 0 , 0};
void dfs(int node) {
    vis[node] = 1;
    for (auto &it: dir[node]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
    topo_sort.push(node);
}
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
        cin >> n >> m;
        vis.resize(n + 1);
        for(int i = 1 ; i <= n ; i++){vis[i] = 0;}
        for(int i = 1 ; i <= n ; i++){
            dir[i].clear();
        }
        vector<pair<int, pair<int, int>>> a(m);
        for (int i = 0; i < m; i++) {
            cin >> dis >> f >> to;
            if (dis) {
                dir[f].push_back(to);
            }
            a[i].F = f, a[i].S.F = to, a[i].S.S = dis;
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        int mx = n + 1;
        vector<int> order(n + 2);
        while (topo_sort.size() > 0) {
            int x = topo_sort.top();
            order[x] = mx--, topo_sort.pop();
        }
        bool v = 1;
        for (int i = 0; i < m; i++) {
            if (a[i].S.S == 1) {
                if (order[a[i].F] < order[a[i].S.F]) {
                    v = 0;
                    break;
                }
            }
        }
        if (!v) { cout << "NO" << '\n'; }
        else {
            cout << "YES" << '\n';
            for (int i = 0; i < m; i++) {
                if (order[a[i].F] > order[a[i].S.F]) {
                    cout << a[i].F << " " << a[i].S.F << '\n';
                } else cout << a[i].S.F << " " << a[i].F << '\n';
            }
        }
    }
}
