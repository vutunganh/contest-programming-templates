#include "../template.cpp"

// -Manacher algorithm-
// Longest palindromic substring finder
// O(n) query, O(n) preprocess, O(n) space
// n = |string|

#define MAX 100007 // max length of string
// (preprocessed string -> ^#s#t#r#i#n#g#$ for odd lengths)
void preprocess(string & str) {
	string ret = "^";
	for (auto ch : str) { ret+="#"; ret += ch; }
	ret += "#$"; str = ret;
}

// Array P 
// 	on i-th position of P is placed length of palindrome
ll P[MAX*2];
// returns {position, length} of longest palindromic substring
pll manacher(string & str) {
	CL(P,0);
	preprocess(str);
	ll ret=0,retpos;
	ll center = 0, right = 0;
	for(ll i = 1; i < str.size(); i++) {
		ll mirr = center * 2 - i;
		if (i < right) { // !crutial enhancement: if for mirrored calculated, use it
			P[i] = min(P[mirr], right-i);
			ret=max(ret,P[mirr]);
		}
		// expanding palindrome:
		while (str[i - (1 + P[i])] ==  str[i + P[i] + 1]) P[i]++;
		if (i + P[i] > right) { // out of palindrome used for mirroring
			center = i;
			right = i + P[i];
		}
		if(ret<P[i]){ret=P[i]; retpos=i; }
	}
	return {retpos,ret};
}

int main() {
	string str="aba";
	pll r = manacher(str);
	cout<<str<<endl;
	cout<< r.x << ' ' << r.y <<endl;
	return 0;
}