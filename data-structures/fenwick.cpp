#define MAX 1000001
// v arrayi nesmi byt zaporna cisla
ll T[MAX]; // T[0] se nepouziva!!!

void build(){
  FOR(i,1,MAX){
    int nextindex=i+(i&-i);
    if(nextindex<=MAX)T[nextindex]+=T[i];
  }
}

void add(int i,ll delta){ while(i<=MAX)T[i]+=delta,i+=(i&-i); }

ll pref_sum(int i) {
  ll s=0;
  while(i>0)s+=T[i],i=i&(i-1);
  return s;
}
