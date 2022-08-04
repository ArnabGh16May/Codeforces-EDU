/*
	Author: Arnab Ghosh
    Created: 04-08-2022 08:36:45
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.h"
#else 
#define debug(x)
#endif
using namespace std;
typedef long long ll;


pair<int, int> goodInd(vector<long double> a, long double x, int d) {
	int n = (int)a.size();
	vector<long double> pa(n);
    vector<int> m(n);
    for(int i = 0; i < n; i++) {
        pa[i] = (a[i] - x) + (i ? pa[i - 1] : 0);
    }

    for(int i = 0; i < n; i++) {
        if(i == 0) m[0] = 0;
        else if(pa[i] < pa[m[i - 1]]) m[i] = i;
        else m[i] = m[i - 1];
    }

    if(pa[d - 1] >= 0) return make_pair(0, d - 1);
    for(int r = d; r < n; r++) {
        if (pa[r] >= 0) return make_pair(0, r);
    	if(pa[r] >= pa[m[r - d]]) return make_pair(m[r - d] + 1, r);
    }

    return make_pair(-1, -1);
}	

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    int n, d;
    cin >> n >> d;
    vector<long double> a(n);
    long double minn = 101.0, maxx = 0.0;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }

    long double lo = minn, hi = maxx;
    pair<int, int> seg;
    for(int i = 0; i <= 100; i++) {
    	long double x = (lo + hi) / 2.0;
    	pair<int, int> temp = goodInd(a, x, d);
    	if(temp != make_pair(-1, -1)) {
            seg = temp;
            lo = x;
        }
        else hi = x;
    }

    cout << seg.first + 1 << " " << seg.second + 1 << '\n';
}
