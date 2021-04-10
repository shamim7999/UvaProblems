#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 300005
#define ll long long
#define mod 1000000007
#define ld long double

int n;

struct Aho_Corasick
{
	int to[mx][55]={0}, dph[mx]={0}, par[mx], suffix_link[mx], letter_Of_Node[mx];
	int nxt[mx][55]={0}, cnt[mx] = {0};
	vector < int > Tree[mx], vv;
	int tot_nodes = 1;

	int f(char ch)
	{
		int id = 0;
		if(ch>='a' && ch<='z'){
			id = ch-'a';
		}
		else{
			ch = tolower(ch);
			id = ((ch-'a'))+26;
		}
		return id;
	}

	void clr()
	{
		memset(to, 0, sizeof to);
		memset(nxt, 0, sizeof nxt);
		for(int i=0; i<=tot_nodes; i++){
			dph[i] = letter_Of_Node[i] = suffix_link[i] = par[i] = cnt[i] = 0;
			Tree[i].clear();
		}
		tot_nodes = 1;
		vv.clear();

	}

	void Build_Trie(string &s1, int idx)
	{
		int now = 1;
		for(int i=0; s1[i]; i++){
			int id = f(s1[i]);

			if(to[now][id] == 0){

				++tot_nodes;

				to[now][id] = tot_nodes;

				letter_Of_Node[tot_nodes] = id;

				par[tot_nodes] = now;

				dph[tot_nodes] = dph[par[tot_nodes]] + 1;
			}

			now = to[now][id];
		}

		vv.push_back(now);
	}

	void bfs()
	{
		par[1] = 0;
		letter_Of_Node[1] = 0;
		dph[1] = 0;
		queue < int > q;
		q.push(1);

		while(!q.empty()){
			int x = q.front();
			q.pop();

			if(dph[x]<=1)
				suffix_link[x] = 1;
			else{
				int v = suffix_link[par[x]];
				int letter = letter_Of_Node[x];
				while(v>1 && to[v][letter] == 0)
					v = suffix_link[v];
				if(to[v][letter])
					v = to[v][letter];
				suffix_link[x] = v;
			}

			if(x>1)
				Tree[suffix_link[x]].push_back(x);
			for(int i=0; i<52; i++){
				if(to[x][i])
					q.push(to[x][i]);
			}
		}

	}

	void dfs(int node, int father)
	{
		for(auto child : Tree[node]){
			if(child == father)
				continue;
			dfs(child, node);
			cnt[node]+=cnt[child];
		}
	}

	int jump(int u, int c)
	{
		if(nxt[u][c])
			return nxt[u][c];
		int v = u;
		while(v>1 && to[v][c] == 0)
			v = suffix_link[v];
		if(to[v][c])
			v = to[v][c];
		return v;
	}

	void calc(string &s1)
	{
		int now = 1;
		for(int i=0; s1[i]; i++){

			int cc = jump(now, f(s1[i]));
			cnt[cc]++;
			nxt[now][f(s1[i])] = cc;
			now = cc;
		}

		dfs(1, -1);
	}

}Aho;

void solve(int kk)
{
	Aho.clr();
	string ss;
	int N;
	cin >> ss >> n;

    for(int i=0; i<n; i++){
    	string s1;
    	cin >> s1;
    	Aho.Build_Trie(s1, i);
    }

    Aho.bfs();
    Aho.calc(ss);
    //cout << "Case " << kk << ":\n";
    for(auto it : Aho.vv){
    	//cout << Aho.cnt[it] << "\n";
    	Aho.cnt[it]>0 ? cout << "y\n" : cout << "n\n";
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
