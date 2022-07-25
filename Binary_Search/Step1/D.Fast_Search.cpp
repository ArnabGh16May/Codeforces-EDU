/*Solution by ARNAB GHOSH*/
/*-------------------------------DEFINE MACROS--------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define fastio(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353
#define umap unordered_map
#define pb push_back
#define eb emplace_back
#define B begin()
#define E end()
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define EXECUTION_TIME(); cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#define ff(i, a, b) for(ll i = a; i < b; i++)
#define rf(i, a, b) for(ll i = a; i >= b; i--)
/*-----------------------------------------------------------------------------*/
/*--------------------------------TYPEDEF------------------------------------*/
typedef long int li; typedef long long ll; typedef long long int lli; typedef vector<int> vi; typedef vector<li> vli; typedef vector<ll> vll; typedef unordered_map<int, int> umapi; typedef pair<int, int> pii; typedef pair<long, long> pll; 
/*-----------------------------------------------------------------------------*/

/*-------------------------------FUNCTIONS---------------------------------*/
ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }
ll mpow(ll a, ll n, ll m) { ll res = 1; while(n) {if(n % 2) {res = ((res % m) * (a % m)) % m; n--;} else { a = ((a % m) * (a % m)) % m; n /= 2;} } return res % m; }

// For calculating gcd in O(logN) inbuilt __gcd() is used
#define gcd __gcd
//For Calculating Power inbuilt pow() fundction
/*-------------------------------------------------------------------------*/
/*------------------ACCHE SE SOCH LIYE? PAKKA SAHI SOLUTION HAI NA??-----------------*/

int main()
{
    fastio();
    ll n, k; cin >> n;
    vll a(n);
    ff(i, 0, n) cin >> a[i];
    sort(all(a));   //1 3 4 10 10
    cin >> k;
    while(k--) {
        ll l, r; cin >> l >> r;
        ll ind1 = lb(all(a), l) - a.B;
        ll ind2 = ub(all(a), r) - a.B;
        ind2--;
        if((ind1 >= 0 && ind1 <= n - 1) && (ind2 >= 0 && ind2 <= n - 1)) 
            cout << (ind2 - ind1 + 1) << " ";
        else cout << 0 << " ";

    }


    // EXECUTION_TIME();
    return 0;
}
