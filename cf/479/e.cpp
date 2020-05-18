#include <bits/stdc++.h>

using namespace std;
 
#define int long long

typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ld,ld> pdd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<pii> vpii;
typedef vector<pdd> vpdd;

#define FOR(x,y) for(int x=0;x<y;x++)
#define FOR1(x,y) for(int x=1;x<y;x++)
#define LOOP(y) for(int x=0;x<y;x++)

#define trav(a, x) for (auto a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
const int INF = 1e18;
const int MX = 200002;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

int N,M,cntcmp;
vi path[MX];
int edges[MX];
int sizes[MX];
int beenthere[MX];
int ans;

void dfs (int v) {
	beenthere[v] = cntcmp;
	++ sizes[cntcmp];
	trav(n,path[v]) {
		if(!beenthere[n]) {
			++ edges[cntcmp];
			dfs(n);
		}
	}	
}

int32_t main () {
	cin>>N>>M;
	for(int i=0;i<M;++i) {
		int x,y;cin>>x>>y;
		path[x].pb(y);
		path[y].pb(x);
	}
	for(int i=1;i<=N;++i) {
		if(!beenthere[i]) {
			++ cntcmp;
			dfs(i);
		}
	}
	for(int i=1;i<=cntcmp;++i)
		if(edges[cntcmp]==sizes[cntcmp])
			++ ans;
	cout << ans << '\n';
}
