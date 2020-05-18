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
const int MX = 50001;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

int N,K,d[MX],avoid[MX];
int cage_one;
bool works (int s) {
	int l=0,r=s-1;
	while(r<N) {
		if(d[r]-d[l]<=K) return true;
		++l; ++r;
	}
	return false;
}
bool reworks (int s, vi x) {
	int l=0,r=s-1;
	while(r<N) {
		if(x[r]-x[l]<=K) return true;
		++l; ++r;
	}
	return false;
}
int32_t main () {
  //setIO("diamond");
  cin >> N >> K;
	FOR(i,N) cin>>d[i];
	sort(d,d+N);
	int l=0,r=N,ans=0;
	while(l<=r) {
		int m=l+(r-l)/2;
		if(works(m)) {
			ans=m;
			l=m+1;
		}
		else
			r=m-1;
	}
	l=0;r=ans-1;
	cage_one = r-l+1;
	while(r<N) {
		if(d[r]-d[l]<=K) break;
		++ l; ++ r;
	}
	for(int i=l;i<=r;++i) avoid[i] = true;
	vi re; // removed
	FOR(i,N) if(!avoid[i]) re.pb(d[i]);
	N = sz(re);
	l=0;r=N;ans=0;
	while(l<=r) {
		int m=l+(r-l)/2;
		if(reworks(m,re)) {
			ans=m;
			l=m+1;
		}
		else
			r=m-1;
	}
	cout<<cage_one+ans<<'\n';
}
