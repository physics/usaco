#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define vpii vector<pii>
#define mp make_pair
#define f first
#define s second
#define MX 101

int T,N,M;

int grid[MX][MX];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
bool visited[MX][MX];

vpii near (int x, int y) {
  vpii n;
  for(int i=0;i<4;i++)
  	if(x+dx[i]>=0&&x+dx[i]<M)
  		if(y+dy[i]>=0&&y+dy[i]<N)
  			n.pb(mp(x+dx[i],y+dy[i]));
  return n;
}

void dfs(int x, int y, int prev){
  if(visited[x][y])
  	return;
  visited[x][y] = true;
  int i = 0;
  //for(pii a:near(x,y)) cout<<a.f<<" "<<a.s<<" "<<++i<<"\n";
  for(pii a:near(x,y)){
  	if(!visited[a.f][a.s]&&grid[a.f][a.s]==prev) {
  	    dfs(a.f, a.s, prev);
  	}
  }
}

int main() {
    cin >> T;
    while(T--) {
        int x,y,K;
        cin>>N>>M;
        for(int i=0;i<M;i++) {
        	for(int j=0;j<N;j++) {
        		visited[i][j] = false;
        		cin >> grid[i][j];
        	}
        }
        cin>>y>>x>>K;
        dfs(x,y,grid[x][y]);
        for(int i=0;i<M;i++) {
            for(int j=0;j<N;j++) {
                if(visited[i][j]) grid[i][j]=K;
                if((i+1)*(j+1)==N*M) cout<<grid[i][j]<<"\n";
                else cout<<grid[i][j]<<" ";
            }
        }
    }
}