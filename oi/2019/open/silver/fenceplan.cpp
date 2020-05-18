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
const int MX = 100001;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

int N,M,per=INT_MAX;
pii rect[MX][4];
int beenthere[MX];
pii pos[MX];
vi moo[MX];
int cntcmp;

void visit (int cow) {
  if(beenthere[cow]) return;
  beenthere[cow]=cntcmp;
  if(pos[cow].s>rect[cntcmp][0].s)
    rect[cntcmp][0]=pos[cow];
  if(pos[cow].f>rect[cntcmp][3].f)
    rect[cntcmp][3]=pos[cow];
  if(pos[cow].s<rect[cntcmp][1].s)
    rect[cntcmp][1]=pos[cow];
  if(pos[cow].f<rect[cntcmp][2].f)
    rect[cntcmp][2]=pos[cow];
  trav(buddy,moo[cow]) visit(buddy);
}

int32_t main () {
  setIO("fenceplan");
  cin>>N>>M;
  FOR1(i,N+1)
    cin>>pos[i].f>>pos[i].s;
  FOR(i,M) {
    int a,b;
    cin>>a>>b;
    moo[a].pb(b);
    moo[b].pb(a);
  }
  FOR(i,MX) {
    rect[i][0] = mp(-1,-1);
    rect[i][1] = mp(INT_MAX,INT_MAX);
    rect[i][2] = mp(INT_MAX, INT_MAX);
    rect[i][3] = mp(-1,-1);
  }
  FOR1(cow,N+1) {
    if(!beenthere[cow]) {
      ++ cntcmp;
      visit(cow);
    }
  }
  if(cntcmp)
    FOR1(i,cntcmp+1)
      per=min(per,(2*(rect[i][0].s-rect[i][1].s))+(2*(rect[i][3].f-rect[i][2].f)));
  cout << per << "\n";
}
