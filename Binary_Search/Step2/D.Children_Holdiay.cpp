/*
	Author: Arnab Ghosh
	Created: 22-07-22 11:21
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD (long long)1000000007
#define MOD1 (long long)998244353 

vector<long long> goodBaloons(long long n, long long m, long long r, vector<long long> t, vector<long long> z, vector<long long> y) {
	vector<long long> res(n);
	for(long long i = 0; i < n; i++) {
		long long each = (r / (t[i]*z[i]+y[i])) * z[i] + min(((r % (t[i] * z[i] + y[i])) / t[i]), z[i]);
		res[i] = each;
	}
	return res;
}

int main()
{
    fastio();
#ifndef Arnab_Ghosh
    freopen("error.txt", "w", stderr);
#endif
	long long m, n;
	cin >> m >> n;
	vector<long long> t(n), z(n), y(n);
	for(long long i = 0; i < n; i++) {
		cin >> t[i];
		cin >> z[i];
		cin >> y[i];
	}
	
	auto good = [&](long long time) {
		long long total = 0LL;
		for(long long i = 0; i < n; i++) {
			long long each = (time / (t[i]*z[i]+y[i])) * z[i] + min(((time % (t[i] * z[i] + y[i])) / t[i]), z[i]); 
			total += each; 
		}
		return total >= m;
	};

	long long l = -1, r = 1e9;
	while(r - l > 1) {
		long long mid = (l + r) >> 1LL;
		if(good(mid)) r = mid;
		else l = mid;
	}
	cout << r << "\n";
	vector<long long> maxBaloons = goodBaloons(n, m, r, t, z, y);
	long long total = 0LL;
	for(long long i = 0; i < n; i++) {
		if(total + maxBaloons[i] <= m) {
			cout << maxBaloons[i] << " ";
			total += maxBaloons[i];
		}else {
			if(total == m) cout << 0 << " ";
			else {
				cout << (m - total) << " ";
				total = m;
			}
		} 
	}
	cout << '\n';	
}
