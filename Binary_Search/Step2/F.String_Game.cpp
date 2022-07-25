/*
    Author: Arnab Ghosh
    Created: 26-07-22 00:03
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.cpp"
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    string t, p;
    cin >> t >> p;
    int n = t.length();
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	a[i]--;
	}
	
	auto isPossible = [&](int m) {
		string d = t, res = "";
		for(int i = 0; i < m; i++) d[a[i]] = '0';
		debug(d);
		for(int i = 0; i < n; i++) {
			if(d[i] != '0') res += d[i];
		}
		debug(res);
		//we have to check for subsequence not substring
		int i = 0, j = 0;
		while(i < res.length() && j < p.length()) {
			if(res[i] == p[j]) {
				i++;
				j++;
			}else i++;
		}
		
		return j == p.length();	
	}; 
	
	int l = 0, r = n, ans = 0;
	while(l <= r) {
		int m = (l + r) >> 1;
		if(isPossible(m)) {
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	cout << ans << "\n";
	//r can also be the answer (ans == r)
