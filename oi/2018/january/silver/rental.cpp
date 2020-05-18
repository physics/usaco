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
#define D(x) greater<x>()

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
int N,M,R,CUR,SOLD,ANS;
int main () {
  //setIO("rental");
  cin>>N>>M>>R;
  int C[N], RENT[R];
  pair<int,int> S[M];
  FOR(CW,N) cin>>C[CW];
  sort(C,C+N,D(int));
  int CPS[N]; CPS[0] = C[0];
  FOR1(PRF, N) CPS[PRF] = CPS[PRF-1] + C[PRF];
  FOR(ST,M) {
    int q,p; cin>>q>>p;
    S[ST] = mp(p,q);
  } sort(S,S+M,D(pi));
  int SQ[M]; SQ[0] = S[0].s;
  int SV[M]; SV[0] = S[0].f * S[0].s;
  FOR1(PRF, M) SQ[PRF] = SQ[PRF-1] + S[PRF].s;
  FOR1(PRF, M) SV[PRF] = SV[PRF-1] + S[PRF].f * S[PRF].s;
  FOR(RNT, R) cin>>RENT[RNT];
  sort(RENT,RENT+R,D(int));
  FOR(COW,N) {
    int gal = C[COW];
    int store = lb(SQ,SQ+M,CPS[SOLD])-SQ;
    int sell = 0;
    if(SOLD>=M||CUR>=R) break;
    if(store == M) -- store;
    if(store == 0) { 
      sell += gal * S[0].f;
    } else {
      int rem = gal - SQ[store-1];
      sell += SV[store-1];
      sell += max(rem*S[store-1].f,S[store-1].s*S[store-1].f);
    }
    if(sell >= RENT[CUR]) {
      ANS += sell;
      ++ SOLD;
    } else {
      ANS += RENT[CUR];
      ++ CUR;
    }
    cout<<sell<<endl;
  }
  cout << ANS << endl;
  cout << endl << endl;
  
}


