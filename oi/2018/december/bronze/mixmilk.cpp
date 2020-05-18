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
#define RAJIICRAWFORDWITHABUCKETOFMUD(y) for(int x=0;x<y;x++)

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
const int MX = 101;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

int cap[4];
int amt[4];

int32_t main () {
  setIO("mixmilk");
  FOR(i,3) cin>>cap[i+1]>>amt[i+1];
	int from=1,to=2;
	RAJIICRAWFORDWITHABUCKETOFMUD(100) {
		while(amt[from]>0&&amt[to]<cap[to]) {
			-- amt[from];
			++ amt[to];
		}
		if(from==2) {
			from=3;
			to=1;
		}
		else if(from==3) {
			from=1;
			to=2;
		}
		else {
			++from;
			++to;
		}
	}
	FOR1(i,4)
		cout<<amt[i]<<'\n';
}
