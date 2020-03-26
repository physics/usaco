#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t;
int main(){
	cin>>t;
	for(ll i=0;i<t;i++){
		ll a,b;
		cin>>a>>b;
		cout<<b*((ll)ceil(a/(b*1.0)))-a<<"\n";
	}
}
