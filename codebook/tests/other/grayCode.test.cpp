#include "../../other/grayCode.cpp"

string bin(ll n) {
	string ret;
	while(n)ret+='0'+n%2,n>>=1;
	if(!ret.size()) ret="0";
	reverse(all(ret));
	return ret;
}

int main() {
	cout<<setfill('0');
	F(50) {
		assert(i==gInv(g(i)));
		cout<<setw(2)<<i<<" "<<setw(2)<<g(i)<<" "<<setw(6)<<bin(g(i))<<" "<<setw(2)<<gInv(g(i))<<endl;
	}
}