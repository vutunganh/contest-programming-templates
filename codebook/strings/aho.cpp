#include "../template.cpp"

// -Aho-Corasick Algorithm-
// Multiple patterns matching

// |txt|=n, combined pattern length=m
// O(n+m) query, O(m) space

// optimize: by replacing unordered_map with static array (smaller alphabeths)

#define MAXN 1000007 // max num of states = maxNumOfpatterns * maxLenOfPattern
 
unordered_map<char,ll> go[MAXN];
int fail[MAXN],
	que[MAXN],
	patt[MAXN],
	cnt;
void init() {
    cnt=1; // reset state id
    CL(patt,-1);
}
// creates trie
void add_patt(string & str, int k) {
    int act=0;
    for(auto ch : str) {
        if (!go[act][ch]) go[act][ch]=cnt++; // new state
        act=go[act][ch];
    }
    patt[act]=k;
}
// calculates fail function for created trie
void push_fails() { 
    CL(fail,0);
    fail[0]=-1;
    int be=0, en=1; que[0]=0; // init queue
    while(be < en) {
        int act=que[be++];
        for(auto it : go[act]) {
            ll ch=it.first,
            	u=it.second,
            	j=fail[act];
            while(j != -1 && !go[j][ch])j=fail[j]; // if there is not a way from fail (prefix), jump back
            if(j != -1) fail[u]=go[j][ch];
            que[en++]=u;
        }
    }
}

// returns pair<index of found needle, pos of found needle in txt>
vpll aho(vector<string> patterns, string txt) {
    init();
	F(patterns.size()) add_patt(patterns[i],i);
	push_fails();
	int act=0;
	vpll found;
	int i=0;
    for(auto ch : txt) {
    	while (act != -1 && !go[act].count(ch)) act=fail[act]; // go back until can go with 'ch' or is -1
    	if (act != -1) { // if can follow
    		act=go[act][ch];
	    	int pos=act; // add all matched keywords in own suffix
	    	while (pos != -1) {
	    		if (patt[pos] != -1) found.push_back({patt[pos], i - (patterns[patt[pos]].size()-1)});
	    		pos=fail[pos];
	    	}
	    } else
	    	act=0;
    	i++;
    }
    return found;
}

int main()
{
    vector<string> patterns{"he", "she", "hers", "his"}; 
    string txt="ahishersblablablashe";
	vpll found=aho(patterns, txt);
    for (auto i : found)
    	cout << patterns[i.first] << " at " << i.second << endl;
	return 0;
}