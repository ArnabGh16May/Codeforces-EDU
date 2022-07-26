/*
    Author: Arnab Ghosh
    Created: 26-07-22 15:07
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.cpp"
#else
#define debug(x)
#endif
using namespace std;
typedef long long int ll;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    string rec;
    long long int nb, ns, nc, pb, ps, pc;
    long long int cb = 0, cs = 0, cc = 0;
    long long int r;
    cin >> rec >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    for(char i: rec) {
    	cb += (i == 'B');
    	cs += (i == 'S');
    	cc += (i == 'C');
	}
	
	auto possible = [&](long long int m) {
		long long int needb = m * cb, needs = m * cs, needc = m * cc, remb, rems, remc;
		if(needb <= nb) remb = 0;
		else remb = needb - nb;
		
		if(needs <= ns) rems = 0;
		else rems = needs - ns;
		
		if(needc <= nc) remc = 0;
		else remc = needc - nc;
		
		return (remb * pb + rems * ps + remc * pc <= r);
	};
	
	long long int maxx = (cb ? ll(nb / cb) : 0) + (cs ? ll(ns / cs) : 0) + (cc ? ll(nc / cc) : 0) + (cb ? ll(r / pb) / cb : 0) + (cs ? ll(r / ps) / cs : 0) + (cc ? ll(r / pc) / cc : 0); 
	long long int l = 0, h = maxx, hamburger = 0;
	while(l <= h) {
		long long int m = (l + h) >> 1ll;
		if(possible(m)) {
			hamburger = m;
			l = m + 1;
		}else h = m - 1;
	}
	
	cout << hamburger << "\n";
}
