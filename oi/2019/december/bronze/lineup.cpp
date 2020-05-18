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
int N;
vector<pair<string,string>> req;
string perm[40320][8]; // 40320 = 8! for all permutations of array of cows
string ans[8] = {"z", "z", "z", "z", "z", "z", "z", "z"};
int indexOf(string cows[], string cow, int n) {
	FOR(i,n) {
		if(cows[i]==cow) {
			return i;
		}
	}
	return -1;
}
bool works (string cows[], int n) {
	bool work = true;
	FOR(i,sz(req)) {
		int ioc1 = indexOf(cows, req[i].f, n);
		int ioc2 = indexOf(cows, req[i].s, n);
		if(abs(ioc1-ioc2)!=1) {
			work = false;
			break;
		}
	}
	return work;
}
void permutations (string a[], int n) {
	sort(a, a + n);
	int cntr = 0;
  do { 
  	FOR(i,n) perm[cntr][i] = a[i];
  	if(works(perm[cntr], 8)) {
			FOR(j,8) ans[j] = perm[cntr][j];
			break;
  	}
  	cntr++;
  } while (next_permutation(a, a + n)); 
}
int main () {
	setIO("lineup");
	cin >> N;
	FOR(i,N) {
		string c1, c2, a,b,c,d; // abcd are trash
		cin>>c1>>a>>b>>c>>d>>c2;
		req.pb(mp(c1,c2));
	}
	string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	permutations(cows, 8);
	FOR(i,8) {
		cout << ans[i] << "\n";
	}
}