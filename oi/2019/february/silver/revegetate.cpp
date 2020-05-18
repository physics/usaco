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

struct pasture {
  char type;
  int x, y;
};

char type;
bool zero;
int N,M,x,y,cntcmp,beenthere[MX];
vi adj[MX];
map<pii,char> con;
char grass[MX];
pasture rule[MX];

void visit(int c, char g) {
  if(beenthere[c]) return;
  beenthere[c]=cntcmp;
  grass[c] = g;
  trav(f,adj[c]) {
    if(con[mp(c,f)]=='S')
      visit(f,g);
    else if(g=='A') visit(f,'B');
    else visit(f,'A');
  }
}

int32_t main () {
  setIO("revegetate");
  cin >> N >> M;
  FOR(i,M) {
    cin>>type>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
    con[mp(x,y)]=type;
    con[mp(y,x)]=type;
    rule[i]={type,x,y};
  }
  FOR1(i,N+1) {
    if(!beenthere[i]) {
      ++ cntcmp;
      visit(i,'A');
    }
  }
  FOR(i,M) {
    if(rule[i].type=='S'&&grass[rule[i].x]!=grass[rule[i].y])
      zero=true;
    if(rule[i].type=='D'&&grass[rule[i].x]==grass[rule[i].y])
      zero=true;
  }
  if(zero) cout<<0;
  else {
    cout<<1;
    FOR(i,cntcmp) cout<<0;
  }
}
