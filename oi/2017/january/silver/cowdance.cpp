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

int N, T, sum, seq[MX];

bool works(int K) {
	vi stage(K);
	queue<int> line;
	int MIN;
	int time = 0;
	FOR(i,N) {
		if(i<K) stage[i] = seq[i];
		else line.push(seq[i]);
	}
	MIN = (int)*min_element(all(stage));
	while(sz(line)>0) {
		FOR(i,K) {
			stage[i] -= MIN;
			if(stage[i] == 0) {
				if(sz(line)>0) {
					stage[i] = front(line);
					pop(line);
				}
				else {
					break;
				}
			}
		}
		time += MIN;
		MIN = (int)*min_element(all(stage));
	}
	int MAX = (int)*max_element(all(stage));
	time += MAX;
	if(time > T) return false;
	else return true;
}

int solve () {
	int l = 1, r = N, least = N;
	while (l <= r) {
		int m = l + (r-l) / 2;
		if(works(m)) {
			least = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return least;
}

int main () {
	setIO("cowdance");
  cin >> N >> T;
  FOR(i,N) cin >> seq[i];
  cout << solve() << "\n";
}