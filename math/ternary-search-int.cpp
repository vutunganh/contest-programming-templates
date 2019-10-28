// assumes f increases and then decreases
ll ter_search_int(ll lo, ll hi) {
  while (hi - lo > 1){
      int mid = (hi + lo)>>1;
      if (f(mid) > f(mid + 1)) 
           hi = mid;
      else 
           lo = mid; 
  }
  //lo + 1 is the answer
  return lo + 1;
}
