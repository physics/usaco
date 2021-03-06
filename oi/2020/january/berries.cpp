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
const int MX = 1001;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

int N, K, trees[MX];

int bes (int b) {
  // how much bessie gets if prioritizing b per basket
  int ans = 0;
  int cur = 0;
  int picked[MX];
  FOR(i,MX) picked[i] = 0;
  FOR(i,N) {
    if(cur>=K) break;
    int berries = trees[i];
    if(berries>=b) {
      while(berries>=b) {
        berries -= b;
        picked[cur] += b;
        ++ cur;
        if(cur>K-1) break;
      }
    }
    else {
      picked[cur]=berries;
      ++ cur;
    }
  }
  sort(picked,picked+K);
  FOR(i,K/2) {
    ans += picked[i];
  }
  return ans;
}

int32_t main () {
  setIO("berries");
  cin >> N >> K;
  int maxtree = -1;
  FOR(i,N) {
    int amt;
    cin >> amt;
    maxtree=max(maxtree,amt);
    trees[i]=amt;
  }
  sort(trees,trees+N,greater<int>());
  int ans = 0;
  FOR1(i,maxtree+1) {
    ans=max(ans,bes(i));
  }
  cout<<ans<<"\n";
}
