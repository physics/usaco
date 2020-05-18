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
      if(sizes[a]<sizes[b])
        swap(a,b);
      dsu[b]=a;
      sizes[a]+=sizes[b];
      --cc;
    }
  }
  bool tg (int a, int b) {
    return find(a)==find(b);
  }
};

int N,M,cows[MX];
int pos[MX];
tuple<int,int,int> worm[MX];

bool works (int width) {
  struct DSU farm;
  farm.init(N);
  for(int i=0;i<M;++i) {
    int x = get<0>(worm[i]);
    int y = get<1>(worm[i]);
    int w = get<2>(worm[i]);
    if(w >= width)
      farm.merge(x,y);
  }
  for(int i=0;i<N;++i) {
    if(pos[i]!=i&&!farm.tg(i,cows[i])) {
      return false;
    }
  }
  return true;
}

int32_t main () {
  setIO("wormsort");
  cin >> N >> M;
  for(int i=0;i<N;++i) {
    cin>>cows[i];
    --cows[i];
    pos[cows[i]]=i;
  }
  for(int i=0;i<M;++i) {
    int x,y,z;cin>>x>>y>>z;
    --x; --y;
    worm[i]=make_tuple(x,y,z);
  }
  int l=1,r=1e9+1,ans=-1;
  while(l<=r) {
    int width = l+(r-l)/2;
    if(works(width)) {
      ans=width;
      l=width+1;
    }
    else
      r=width-1;
  }
  if(is_sorted(cows,cows+N))
    cout<<-1<<'\n';
  else
    cout<<ans<<'\n';
}
