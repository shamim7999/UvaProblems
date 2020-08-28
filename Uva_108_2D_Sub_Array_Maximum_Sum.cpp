#include <bits/stdc++.h>
using namespace std;

#define mx 104
#define ll long long

int tc = 1, r, c;
int pre[mx][mx], a[mx][mx];

void solve(int kk)
{
    cin >> r;
    for(int i=0; i<r; i++){
        for(int j=0; j<r; j++)
            cin >> a[i][j];
    }
    ll mm = 0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=r; j++){
            pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i-1][j-1];
        }
    }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=r; j++){
            for(int k=r; k>=j; k--){
                for(int l=r; l>=i; l--){
                    int x1 = i, y1 = j, x2 = l, y2 = k;
                    ll sum = pre[x2][y2]+pre[x1-1][y1-1]-pre[x1-1][y2]-pre[x2][y1-1];
                    mm = max(mm, sum);
                }
            }
        }
    }
    cout << mm << "\n";
    

}

int main()
{
     #ifndef ONLINE_JUDGE
    freopen("D:\\Codings\\CPP\\input.in", "r", stdin);
    freopen("D:\\Codings\\CPP\\output.in", "w", stdout);
    #endif
    
    int kk = 0;
    //cin >> tc;
    //scanf("%d", &tc);
    while (++kk <= tc)
        solve(kk);

    return 0;
}
