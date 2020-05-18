#include <bits/stdc++.h>
using namespace std;
#define f0r(x,n) for(int x=0;x<n;x++)
#define pi pair<int,int>
#define pb push_back

int zephyrorz[1441];
int t;

int main () {
    cin >> t;
    int attempt = 1;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<pi,int>> intervals;
        vector<pair<int,char>> finalAnswer;
        intervals.resize(n);
        f0r(i,n) {
            int f,s;
            cin>>f>>s;
            intervals[i].first.first=f; // first of interval
            intervals[i].first.second=s; // second of interval
            intervals[i].second=i;
            for(int j=intervals[i].first.first+1;j<=intervals[i].first.second;j++) {
                zephyrorz[j]++;
            }
        }
        sort(intervals.begin(), intervals.end());
        //if(static_cast<int>(*max_element(zephyrorz,zephyrorz+1441))>2)
        //    cout<<"IMPOSSIBLE\n";
        bool imp = false;
        f0r(i,1441) {
          if(zephyrorz[i]>2) {
            imp = true;
            break;
          }
        }
        if(imp) cout<<"Case #"<<attempt<<": "<<"IMPOSSIBLE\n";
        else {
            finalAnswer.pb({intervals[0].second,'J'});
            int lastf = intervals[0].first.second;
            for(int i=1;i<n;i++) {
                if(lastf <= intervals[i].first.first) {
                    finalAnswer.pb({intervals[i].second,'J'});
                    lastf = intervals[i].first.second;
                }
                else if (lastf > intervals[i].first.first) {
                    finalAnswer.pb({intervals[i].second,'C'});
                }
            }
            sort(finalAnswer.begin(),finalAnswer.end());
            cout<<"Case #"<<attempt<<": ";
            for(auto x : finalAnswer)
                cout<<x.second;
            cout<<"\n";
        }
        f0r(i,1441) {
          zephyrorz[i]=0;
        }
        attempt++;
    }
}

