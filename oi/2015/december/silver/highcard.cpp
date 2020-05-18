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

int N, ELSIE[MX], BESSIE[MX], ans;
unordered_set<int> used;
int main () {
	setIO("highcard");
	cin >> N;
  FOR(C,N) {
  	int card; cin >> card;
  	ELSIE[C] = card;
  	used.insert(card);
  }
  int ptr = 0;
  FOR1(i,N*2+1) {
  	if(!used.count(i)) {
  		BESSIE[ptr] = i;
  		++ ptr;
  	}
  }
  sort(BESSIE,BESSIE+N);
  sort(ELSIE,ELSIE+N);
  FOR(i,N) {
  	int card = ELSIE[i];
  	int win = ub(BESSIE,BESSIE+N,card)-BESSIE;
  	if(win != N) BESSIE[win] = -1;
  }
  FOR(i,N) if(BESSIE[i]==-1) ans++;
  cout<<ans<<"\n";
}