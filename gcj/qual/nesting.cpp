#include <bits/stdc++.h>
using namespace std;
int amountOfZero = 48;
int main(){
  int tests;
  cin>>tests;
  for(int x=1;x<=tests;x++) {
	string work;
	cin>>work;
	int firstChar = work[0];
	int firstQuantity = firstChar - amountOfZero;
	string ultimate="";
	for(int aksjdas = 0; aksjdas < firstQuantity; ++ aksjdas)
		ultimate = ultimate + "(" ;
	ultimate += firstChar;
  int qq = static_cast<int>(work.length()-1);
	for(int y=0;y<qq;y++) {
		int a=work[y+1]-work[y];
		if(a>0) while(a--) ultimate = ultimate + "(" ;
		else {
      int z = abs(a);
      while(z--)
        ultimate = ultimate + ")" ;
    }  
		ultimate+=work[y+1];
	}
	int secondQuantity = work[work.length()-1] - amountOfZero;
	while(secondQuantity--)
		ultimate = ultimate + ")";
	cout<<"Case #"<<x<<": "<<ultimate<<"\n";
  }
}
