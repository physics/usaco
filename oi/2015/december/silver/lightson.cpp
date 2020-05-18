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
const int MX = 101;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

int N,M;
int x,y,a,b;
int ans;
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
bool barn[MX][MX];
bool visited[MX][MX];
vpii used;
map<pii,vpii> lights;

void reach (pii x) {
	if(!sz(lights[x]))
		return;
	if(visited[x.f][x.s])
		return;
	visited[x.f][x.s] = true;
	FOR(i,sz(lights[x])) {
		barn[lights[x][i].f][lights[x][i].s]=true;
		bool able = false;
		FOR(e,4) {
			pii next = mp(lights[x][i].f+dx[e],lights[x][i].s+dy[e]);
			if(count(all(used),next)) {
				able = true;
				break;
			}
		}
		used.pb(lights[x][i]);
		if(!visited[lights[x][i].f][lights[x][i].s]&&able) {
			reach(lights[x][i]);
		}
	}
}

int32_t main () {
	setIO("lightson");
	cin >> N >> M;
	LOOP(M) {
		cin>>x>>y>>a>>b;
		pii from = mp(x,y);
		pii to = mp(a,b);
		lights[from].pb(to);
	}
	barn[1][1] = true;
	used.pb(mp(1,1));
	reach(mp(1,1));
	FOR1(i,N+1)
		FOR1(j,N+1)
			if(barn[i][j])
				++ ans;
	cout << ans << "\n";
}