/*
    Author:    Arnab Ghosh
    Created:   05.08.2022 10:44:25
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.h"
#else 
#define debug(x)
#endif
using namespace std;
typedef long long ll;


long long n, k;

        
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
	cin >> n >> k;
   	long long l = 1, r = n *n;
   	while(l <= r) {
   		long long m = (l + r) >> 1ll;
   		long long small = 0;
   		for(ll i = 1; i <= n; i++ ){       	
   			if(i < m) {
   				if(m > n * i) small += n;
   				else small += (m / i - (m % i == 0)); 
   			}
   		}                                          
   		if(small <= k-1){
   		  l = m + 1;
   		} 
   		else r = m - 1;
   	}
   	cout << r << '\n';
}
