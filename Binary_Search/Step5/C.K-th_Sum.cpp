/*
    Author:    Arnab Ghosh
    Created:   05.08.2022 12:10:46
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.h"
#else 
#define debug(x)
#endif
using namespace std;
typedef long long ll;


long long n, k, mnsum = 0, mxsum = 0;
        
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    cin >> n >> k;
    vector<long long> a(n), b(n);
    long long mna = 2e9, mxa = 0, mnb = 2e9, mxb = 0;
    for(long long &i: a) {
    	cin >> i;
    	mna = min(mna, i);
    	mxa = max(mxa, i);
    }for(long long &i: b) {
    	cin >> i;
    	mnb = min(mnb, i);
    	mxb = max(mxb, i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    mnsum = mna + mnb;
    mxsum = mxa + mxb;
    long long l = mnsum, r = mxsum;
    while(l <= r) {
    	long long m = (l + r) >> 1ll;
    	long long small = 0;
    	for(ll i= 0 ; i < n; i++ ){
    		
    	long long ind = lower_bound(b.begin(), b.end(), m - a[i]) - b.begin();
    	ind--;
    	if(ind >= 0 && ind < n) small += ind + 1;
    	}                               
		if(small <= k - 1) l = m + 1;
		else r = m - 1;	
    }
    cout << r << '\n';

}       