#define MX 112345
typedef int T;
function<T(T,T)> mrg = [](T a,T b){return max(a,b);}; // merge two subtrees
function<T(int)> ini; // init element
T seg[MX*4];
void build(int sz=(MX)-1, int st=0, int en=(MX)-1, int p=1) {
	if (st == en)
		seg[p] = st < sz ? ini(st) : T();
	else {
		build(sz,st,(st+en)/2,p*2);
		build(sz,(st+en)/2+1,en,p*2+1);
		seg[p] = mrg(seg[p*2],seg[p*2+1]);
	}
}
T get(int st, int en, int sst=0,int sen=(MX)-1,int p=1) {
	if (st > sen or en < sst) return T();
	if (st <= sst and en >= sen) return seg[p];
	int mid = (sst+sen)/2;
	T lt = get(st,en,sst,mid,2*p);
	T rt = get(st,en,mid+1,sen,2*p+1);
	if (st <= mid and en > mid) return mrg(lt,rt);
	return st <= mid ? lt : rt;
}
T upd(int pos,T val, int sst=0,int sen=(MX)-1,int p=1) {
	if (sst == sen) return seg[p] = val;
	int mid = (sst+sen)/2;
	if (pos <= mid) return seg[p] = mrg(upd(pos,val,sst,mid,2*p),seg[2*p+1]);
	else return seg[p] = mrg(seg[2*p],upd(pos,val,mid+1,sen,2*p+1));
}

int a[MX];

int main(void) {
    ios_base::sync_with_stdio(false);
    int a[] = {1,2,3,4,5};
    ini = [&](int pt){return a[pt];};
    build(5);
    cout << st.get(0,4) << endl;
    return 0;
}
