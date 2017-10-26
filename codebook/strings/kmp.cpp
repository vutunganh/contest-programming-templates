#include "../template.cpp"

// Knuth-Morris algorithm
// Pattern matching in O(n) query, O(m) preprocess, O(m) space
// n=|txt|, m=|patt|
// - usefull for shortness, especially well for small abc, short patterns
// ===================
#define MAX 10007 // max length of patt
ll B[MAX]; 
// B[i]: length of longest common (own) prefix (strictly shorter)
//			-1 = sentinel
//	   0  1  2  3  4  5  6  7  8  9 10 11
//str: a  b  c  a  b  b  a  b  c  a  b  b
//brd:-1  0  0  0  1  2  0  1  2  3  4  5  6
void buildTable(string & patt) {
	CL(B, 0); B[0] = -1;
	REP(i,patt.size()) {
		int j=B[i];
		while(j!=-1&&patt[j]!=patt[i]) j = B[j]; // jump back while mismatch on i-th
		B[i+1]=j+1;
	}
}

// returns vector of positions of match in txt
vll kmp(string & txt, string & patt) {
	vll foundpos;
	buildTable(patt);
	ll pos = 0; // position in patt
	REP(i,txt.size()) {
		while (pos != -1 && patt[pos] != txt[i]) pos = B[pos]; // -||-
		pos++;
		ll ns = patt.size();
		if (pos==ns){
			foundpos.pb(i-ns+1);
			pos = B[ns];
		}
	}
	return foundpos;
}

int main() {
	string txt="aaabcabbabcabbabcabb";
	string patt="abcabbabcabb";
	//ret-> [2,8]   ^     ^		
	vll v = kmp(txt,patt);
	for(auto i:v)cout<<i<<' ';
		cout<<endl;
	return 0;
}