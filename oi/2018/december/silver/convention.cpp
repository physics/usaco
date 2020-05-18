#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(x,y) for(int x=0;x<y;x++)
#define FOR1(x,y) for(int x=1;x<y;x++)

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

int N, M, C;
int cows[MX];

bool works (int K) {
	int start = cows[0];
	int buses = 1;
	int curbus = 1;
	int gap = 0;
	FOR1(i,N) {
		gap = cows[i] - start;
		if(gap > K || curbus == C) { // bus is full or gap > K
			start = cows[i];
			gap = 0;
			curbus = 1;
			buses++;
		}
		else {
			curbus++;
		}
	}
	if(buses > M) return false;
	else return true;
}

int solve () {
	int l = 1, r = (int)*max_element(cows,cows+N), least = r;
	while (l <= r) {
		int m = l + (r-l) / 2;
		if(works(m)) {
			least = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return least;
}

int main () {
	setIO("convention");
	cin >> N >> M >> C;
  FOR(i,N) cin>>cows[i];
  sort(cows,cows+N);
  cout<<solve()<<"\n";
}