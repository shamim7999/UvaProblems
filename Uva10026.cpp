#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 100005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(int n, int pos){ return (n&(1<<pos)); }
bool Set(int n, int pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int t;

struct hello
{
   ld fr;
   int se;
};

bool cmp(const hello &p1, const hello &p2)
{
    if(p1.fr == p2.fr) return p1.se<p2.se;
    return p1.fr>p2.fr;
}

void solve(int kk)
{
    int n;
    cin >> n;

    vector <hello> p(n);
    
    for(int i=0,a,b; i<n; i++) cin >> a >> b, p[i] = {(ld)b/(ld)a,i+1};
    stable_sort(p.begin(),p.end(),cmp);
    cout << p[0].se;
    for(int i=1; i<n; i++){
        cout << " " << p[i].se;
    }
    End;
    if(kk<t) End;
}

int main()
{
   fast;
   int kk=0;
   cin >> t;
   while(++kk<=t) solve(kk);

   return 0;
}
