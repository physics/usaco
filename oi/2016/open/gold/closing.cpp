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
const int MX = 200001;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

struct DSU {
  int cc;
  int dsu[MX+1];
  int sizes[MX+1];
  void init (int v) {
    cc = v;
    for(int i=0;i<v;++i) {
      dsu[i]=i;
      sizes[i]=1;
    }
  }
  int find (int a) {
    if(dsu[a]==a) return a;
    return(dsu[a]=find(dsu[a]));
  }
  void merge (int a, int b) {
    a=find(a);
    b=find(b);
    if(a!=b){
      if(sizes[a]<sizes[b]){
        swap(a,b);
        dsu[b]=a;
        sizes[a]+=sizes[b];
      }
      --cc;
    }
  }
  bool connected (int a, int b) {
    return find(a)==find(b);
  }
};

int N,M;
bool beenthere[MX];
int re[MX];
vi path[MX];
vector<string> ans;
int32_t main () {
  //setIO("closing");
  cin >> N >> M;
  struct DSU farm;
  struct DSU start;
  farm.init(N);
  start.init(N);
  for(int i=0;i<M;++i) {
    int x,y; cin>>x>>y;
    path[x-1].pb(y-1);
    path[y-1].pb(x-1);
    start.merge(x-1,y-1);
  }
  for(int i=0;i<N;++i) {
    cin>>re[i];
    -- re[i];
  }
  for(int i=N-1;i>0;--i) {
    int node = re[i];
    trav(v, path[node])
      if(beenthere[v])
        farm.merge(node,v);
    if(farm.cc-i==1)
      ans.pb("YES\n");
    else
      ans.pb("NO\n");
    beenthere[node]=true;
  }
  if(start.cc==1)
    cout<<"YES\n";
  else
    cout<<"NO\n";
  for(int i=sz(ans)-1;i>=0;--i)
    cout<<ans[i];
}
