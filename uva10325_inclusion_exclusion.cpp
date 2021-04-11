#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 100005
#define ll long long
#define mod 1000000007
#define ld long double

int m;

ll n;

int Set(int N,int pos)
{
    return N=N|(1<<pos);
}
 
int Reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}
 
bool chk(int N,int pos)
{
    return (bool)(N &(1<<pos));
}

ll __lcm(ll aa, ll bb)
{
	return((aa*bb)/__gcd(aa, bb));
}

void solve(int kk)
{
    while(cin >> n >> m){
      
	    vector < ll > a; 

	    for(int i=0; i<m; i++){
	    	ll x;
	    	cin >> x;
	    	if(x == 1)
	    		continue;
	    	a.push_back(x);
	    }

	    m = a.size();
	    
	    ll sum = 0, sub = 0, lc;

	    for(int i=1; i<(1<<m); i++){
	    	
	    	int ss = 0;
	    	
	    	bool paisi = 0;
	    	
	    	for(int j=0; j<m; j++){
	    		bool ok = chk(i, j);
	    		if(ok){
	    			
	    			++ss;
	    			if(paisi)
	    				lc = __lcm(lc, a[j]);
	    		}
	    		if(!paisi && ok){
	    			paisi = 1;
	    			lc = a[j];
	    		}
	    	}
	    
	    	ss%2 == 0 ? sub += (ll)(n/lc) : sum += (ll)(n/lc);
	    }
	    cout << n-(sum-sub) << "\n";

    }
}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  //cin >> t;
  //for(int i=1; i<=t; i++)
    //solve(i);
  solve(1);
  return 0;
}
