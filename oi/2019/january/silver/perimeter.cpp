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

int N, blob;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int visited[MX][MX];
bool grid[MX][MX];
char space;

int per (int x, int y) {
	int sum = 0;
	FOR(i,4) {
		if(x+dx[i]==N||x+dx[i]<0||y+dy[i]==N||y+dy[i]<0)
			++ sum;
		else if(!grid[x+dx[i]][y+dy[i]])
			++ sum;
	}
	return sum;
}

vpii near (int x, int y) {
  vpii n;
  for(int i=0;i<4;i++)
  	if(x+dx[i]>=0&&x+dx[i]<N)
  		if(y+dy[i]>=0&&y+dy[i]<N)
  			n.pb(mp(x+dx[i],y+dy[i]));
  return n;
}

void dfs (int x, int y) {
  if(visited[x][y])
  	return;
  visited[x][y] = blob;
  for (pii a : near(x,y))
  	if(!visited[a.f][a.s]&&grid[a.f][a.s])
  		dfs(a.f, a.s);
}

int32_t main () {
	setIO("perimeter");
	cin >> N;
	FOR(i,N) {
		FOR(j, N) {
			cin >> space;
			if(space=='#')
				grid[i][j]=true;
			else
				grid[i][j]=false;
		}
	}
	FOR(i,N) {
		FOR(j,N) {
			if(!visited[i][j]&&grid[i][j]) {
				++ blob;
				dfs(i,j);
			}
		}
	}
	pii blobs[blob];
	// first element is area of blob
	// second element is perimeter of blob
	FOR(i,blob) blobs[i]=mp(0,0);
	FOR(i,N) {
		FOR(j,N) {
			if(!grid[i][j])
				continue;
			int cur = visited[i][j]-1;
			++ blobs[cur].f;
			blobs[cur].s -= per(i,j);
		}
	}
	sort(blobs,blobs+blob);
	cout<<blobs[blob-1].f<<' '<<-1*blobs[blob-1].s<<"\n";
}