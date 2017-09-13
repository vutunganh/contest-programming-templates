#define PAT_LEN 101
#define TXT_LEN 1000001
#define MAX_K   20
#define ALPHA   28
bitset<PAT_LEN> v, r[MAX_K+1], rp[MAX_K+1], d[ALPHA];
int levenshtein(string& txt, string& pat, int k) {
    int m = pat.size(), n = txt.size(), occ = 0;
    F(m) v[i] = (i == m-1);
    F(ALPHA) FF(m) d[i][j] = (pat[j] != i + 'a');
    F(k+1) FF(m) rp[i][j] = (j >= i);
    F(n) {
        r[0] = (rp[0] << 1) | d[txt[i]-'a'];
        FF(k) {
            r[j+1] = ((rp[j+1] << 1) | d[txt[i]-'a']) // subs
                & ((rp[j] & r[j]) << 1) // insert
                & (rp[j] | v); //remove
        }
        if (!r[k][m-1]) occ++;
        FF(k+1) rp[j] = r[j];
    }
    return occ;
}

