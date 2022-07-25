/*Solution by ARNAB GHOSH*/
/*-------------------------------DEFINE MACROS--------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define fastio(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD (long long)1000000007
#define MOD1 (long long)998244353
#define umap unordered_map
#define pb push_back
#define eb emplace_back
#define sz(a) (a).size()
#define B begin()
#define E end()
#define all(a) (a).begin(), (a).end()
#define pyes cout << "YES\n"
#define pno cout << "NO\n"
#define gcd __gcd
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define nline "\n"
#define EXECUTION_TIME(); cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#define ff(i, a, b) for(ll i = a; i < b; i++)
#define rf(i, a, b) for(ll i = a; i >= b; i--)
/*-----------------------------------------------------------------------------*/

/*--------------------------------TYPEDEF------------------------------------*/
typedef long int li; typedef long long ll; typedef long long int lli;typedef long double ldb; typedef vector<int> vi; typedef vector<li> vli; typedef vector<ll> vll; typedef unordered_map<int, int> umapi; typedef pair<int, int> pii; typedef pair<long, long> pll; 
/*-----------------------------------------------------------------------------*/

/*-------------------------------DEBUGING--------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << ": ";_print(x); cerr << nline;
#else
#define debug(x)
#endif

template<class T> void _print(T x) {cerr << x;}
template<class T> void _print(vector<T> v) {cerr << "[ ";for(T i: v){_print(i);cerr << " ";}cerr << "]";}
template<class T> void _print(set<T> s) {cerr << "[ ";for(T i: s){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template<class T, class V> void _print(umap<T, V> mp) {cerr << "[ ";for(auto i: mp) {_print(i); cerr << " ";}cerr << "]";}
template<class T, class V> void _print(map<T, V> mp) {cerr << "[ ";for(auto i: mp) {_print(i); cerr << " ";}cerr << "]";}
/*-----------------------------------------------------------------------------*/

/*-------------------------------FUNCTIONS---------------------------------*/
template<class T> T lcm(T a, T b) { return a * b / __gcd(a, b); }
template<class T> T mpow(T a, T n, T m) { T res = 1; while(n) {if(n % 2) {res = ((res % m) * (a % m)) % m; n--;} else { a = ((a % m) * (a % m)) % m; n /= 2;} } return res % m; }
template<class T> bool isPrime(T n) {T cnt = 0;for(T i = 1; i * i <= n; i++) {if(n % i == 0) cnt++;}return (cnt == 1 && n != 1);}
template<class T> void display(vector<T> a) {for(T i: a) {cout << i << " ";}cout << nline;}
void google(ll t) {cout << "Case #" << t << ": ";}
/*-------------------------------------------------------------------------*/
/*------------------ACCHE SE SOCH LIYE? PAKKA SAHI SOLUTION HAI NA??-----------------*/

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll l = 0, r = 1;
    if(x > y) swap(x, y);
    while(((r/x) + ((r - x) / y)) < n) {
        r *= 2;
    }
    while((r - l) > 1) {
        ll m = (l + r) >> 1ll;
        ll cnt = (m / x) + ((m - x) / y);

        if(cnt >= n) r = m;
        else l = m;
    }
    cout << r << nline;
}

int main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ll T = 1; 
    // cin >> T;
    while(T--) solve();

#ifndef ONLINE_JUDGE
    EXECUTION_TIME();
#endif
}
