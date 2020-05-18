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

int t;
pii pos;
int32_t main () {
  cin>>t;
	while(t--) {
		set<ppii> beenthere;
		string path;
		int ans = 0;
		pos=mp(0,0);
		cin>>path;
		FOR(i,sz(path)) {
			char dir = path[i];
			pii prev = pos;
			if(dir=='N') pos=mp(pos.f,pos.s+1);
			if(dir=='E') pos=mp(pos.f+1,pos.s);
			if(dir=='S') pos=mp(pos.f,pos.s-1);
			if(dir=='W') pos=mp(pos.f-1,pos.s);
			if(beenthere.count(mp(prev,pos))) ans += 1;
			else ans += 5;
			beenthere.insert(mp(prev,pos));
			beenthere.insert(mp(pos,prev));
		}
		cout<<ans<<"\n";
	}
}
