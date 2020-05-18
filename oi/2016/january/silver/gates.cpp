#include <bits/stdc++.h>

using namespace std;
 
#define int long long

typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ld,ld> pdd;
typedef pair<pii, pii> ppii;

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
const int MX = 100001;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

int N;
char fence[MX];
set<ppii> edges;
set<pii> nodes;
pii cur = mp(0,0);

int32_t main () {
	setIO("gates");
	cin >> N >> fence;
	nodes.insert(cur);
	FOR(i,N) {
		char dir = fence[i];
		if(dir=='N') {
			pii end = mp(cur.f,cur.s+1);
			nodes.insert(end);
			edges.insert(mp(cur,end));
			edges.insert(mp(end,cur));
			cur = end;
		}
		else if(dir=='E') {
			pii end = mp(cur.f+1,cur.s);
			nodes.insert(end);
			edges.insert(mp(cur,end));
			edges.insert(mp(end,cur));
			cur = end;
		}
		else if(dir=='S') {
			pii end = mp(cur.f,cur.s-1);
			nodes.insert(end);
			edges.insert(mp(cur,end));
			edges.insert(mp(end,cur));
			cur = end;
		}
		else {
			pii end = mp(cur.f-1,cur.s);
			nodes.insert(end);
			edges.insert(mp(cur,end));
			edges.insert(mp(end,cur));
			cur = end;
		}
	}
	cout<<edges.size()/2-nodes.size()+1<<"\n";
}