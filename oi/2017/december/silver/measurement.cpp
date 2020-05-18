#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pii> vpi;
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

bool cmp (pii p, pii q) {
	return p.s < q.s;
}

tuple<int,int,int> cows[MX];
int N, G, ans;

int main () {
  setIO("measurement");
  cin >> N >> G;
  int max = G; // max
  set<int> winners; // max cows
  map<int,set<int>> output; // keeps track of milk output
  map<int, int> milk; // milk that each cow outputs
  FOR(i,N) {
    int day, id, delta;
    cin>>day>>id>>delta;
    winners.insert(id);
    output[G].insert(id);
    milk[id]=G;
    cows[i]=make_tuple(day,id,delta);
  }
  sort(cows,cows+N);
  FOR(i,N) {
  	int id = get<1>(cows[i]);
  	int delta = get<2>(cows[i]);
  	if(delta == 0) continue;
  	int out = milk[id] + delta;
  	output[milk[id]].erase(id);
  	output[out].insert(id);
  	milk[id] = out;
  	set<int> current;
  	current.insert(id);
  	if(out > max) {
  		if(winners != current) {
  			winners = current;
  			++ ans;
  		}
  		max = out;
  	}
  	else if(out == max) {
  		winners.insert(id);
  		++ ans;
  	}
  	else /*(out < max)*/ {
  		if(winners.count(id)) {
  			if(sz(winners)==1) {
  				pii bigMapValue = (pii)*max_element(all(milk),cmp);
  				int big = bigMapValue.s;
  				winners = output[big];
  				if(winners != current)
  					++ ans;
  				max = big;
  			}
  			else {
  				winners.erase(id);
  				++ ans;
  			}
  		}
  	}
  }	
  if(ans==0) cout<<1<<"\n";
  else cout<<ans<<"\n";
}


