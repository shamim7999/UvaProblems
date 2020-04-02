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
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc=1;

struct node
{
    bool endmark;
    node *next[4];
    int cnt;
    node()
    {
        endmark=0,cnt=0;
        for(int i=0; i<2; i++) next[i]=NULL;
    }
} *root;

void Insert(string s1)
{
    node *curr = root;
    for(int i=0; s1[i]; i++){
        int id = s1[i]-'0';
        if(curr->next[id] == NULL){
            curr->next[id] = new node();
            //curr->cnt
        }
        curr->cnt++;
        curr = curr->next[id];
    }
    curr->cnt++;
    curr->endmark=1;
}

bool Search(string s1)
{
    node *curr = root;
    for(int i=0; s1[i]; i++){
        int id = s1[i]-'0';
        if(curr->next[id] == NULL){
            return 0;
        }
        curr = curr->next[id];
    }
    return curr->endmark;
}

void delAll(node *curr)
{
    for(int i=0; i<2; i++){
        if(curr->next[i]) delAll(curr->next[i]);
    }
    delete(curr);
    //return 1;
}

bool isEmpty(node *curr)
{
    for(int i=0; i<2; i++) if(curr->next[i]) return 0;
    return 1;
}

node *del_String(node *curr, string s1, int pos=0)
{
    if(curr == NULL) return NULL;
    if(pos == s1.size()){
        if(curr->endmark) curr->endmark=0;
        if(isEmpty(curr)){
            delete(curr);
            curr = NULL;
        }
        return curr;
    }
    int id = s1[pos]-'0';
    curr->next[id] = del_String(curr->next[id], s1, pos+1);

    if(curr->endmark == 0 && isEmpty(curr)){
        delete(curr);
        curr = NULL;
    }
    return curr;

}

int search_prefix(string s1)
{
    node *curr = root;
    for(int i=0; s1[i]; i++){
        int id = s1[i]-'0';
        if(curr->next[id] == NULL) return 0;
        curr = curr->next[id];
    }
    return curr->cnt;
}

void solve(int kk)
{
    root = new node();
    int n;
    cin >> n;
    string s1[n+2];
    for(int i=0; i<n; i++) cin >> s1[i], Insert(s1[i]);

    ll Max=-1;

    for(int i=0; i<n; i++){

        string ss = s1[i], hold="";

        for(int j=0; ss[j]; j++){
            hold+=ss[j];
            ll cnt = search_prefix(hold);

            Max = max(Max,(j+1)*cnt);
        }
    }
    cout << Max << "\n";

    delAll(root);
}

int main()
{
   fast;
   int kk=0;
   cin >> tc;
   while(++kk<=tc) solve(kk);

   return 0;
}
