#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll,ll> pllll;
typedef pair<ld,ld> pldld;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pllll> vpllll;

#define FOR(x,y) for(int x=0;x<y;++x)
#define FOR1(x,y) for(int x=1;x<y;++x)

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
#define back(x) x.back()
#define front(x) x.front()
#define pop(x) x.pop()
#define resz resize

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

ll L, N, rF, rB, ans;
ld Vf;
int main () {
	setIO("reststops");
	cin >> L >> N >> rF >> rB;
	pllll tasty[N];
	Vf = 1.0/rF;
	FOR(i,N) {
		ll x,c;
		cin>>x>>c;
		tasty[i]=mp(x,c);
	}
	ll waited = 0;
	FOR(i,N) {
		ll stop = tasty[i].f;
		ll value = tasty[i].s;
		ll time = stop * rB + waited;
		ld behind = stop-(1.0*time/rF);
		ll waitable = (ll)(behind / Vf);
		ans += waitable*value;
		waited += waitable;
	}
	cout<<ans<<"\n";
}