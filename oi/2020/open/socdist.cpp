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

int N,M;
pii inter[MX];

bool works (int D) {
    int used = 1;
    int pos=inter[0].f;
    int cur = 0;
    while(pos<inter[M-1].s) {
        if(pos+D<=inter[cur].s&&pos+D>=inter[cur].f) {
            ++ used;
            pos += D;
        }
        else {
            while(pos+D>inter[cur].s) {
                ++ cur;
                if(cur==M) return used >= N;
            }
            if(pos+D<inter[cur].f)
              pos = inter[cur].f;
            else pos += D;
            ++ used;
        }
    }
    return used >= N;
}

int32_t main () {
  setIO("socdist");
  cin >> N >> M;
  FOR(i,M) cin>>inter[i].f>>inter[i].s;
  sort(inter,inter+M);
  int l=1,r=inter[M-1].s,ans=1;
  while(l <= r) {
    int m=l+(r-l)/2;
    if(works(m)) {
      ans=m;
      l=m+1;
    }
    else
      r=m-1;
  }
  cout<<ans<<"\n";
}
