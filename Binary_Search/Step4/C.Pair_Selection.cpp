/*
    Author: Arnab Ghosh
    Created: 04-08-2022 12:23:12
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.h"
#else 
#define debug(x)
#endif
using namespace std;
typedef long long ll;

int n, k;  
vector<long double> a, b;   
bool good(long double m) {
   long double sum = 0.0;
   vector<long double> v;
   for(int i = 0; i < n; i++) {
        v.emplace_back(a[i] - b[i] * m);
   }

   sort(v.rbegin(), v.rend());
   for(int i = 0; i < k; i++) {
        sum += v[i];
   }

   return sum >= 0;
}  

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        a.emplace_back(x);
        b.emplace_back(y);
    }

    long double l = 0.0, r = (long double)1e18;
    for(int i = 0; i <= 100; i++) {
        long double m = (l + r) / 2.0;
        if(good(m)) l = m;
        else r = m;
    } 

    cout << l << '\n';
}
