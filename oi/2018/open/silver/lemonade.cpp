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
#define F0R1(x,y) for(int x=1;x<y;x++)
#define LOOP(n) for(int i=0;i<n;i++)

#define trav(a, x) for (auto a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define D greater<int>()

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
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

int N, ANS;
int main () {
  setIO("lemonade");
  cin>>N;
  int LL[N];
  FOR(C,N) cin>>LL[C];
  sort(LL,LL+N,D);
  FOR(C,N) if(C<=LL[C]) ANS++;
  cout<<ANS<<endl;
}
