// Linear time all nearest smaller values, standard stack-based algorithm.
// res[i] = index of nearest smallest value in interval <0,i-1>; -1 if not found
void ansv_left(vector<int>& v, vector<int>& res) {
	stack<pair<int, int> > stk; stk.push(make_pair(INT_MIN, v.size()));
	for (int i = v.size()-1; i >= 0; i--) {
		while (stk.top().first > v[i]) {
			res[stk.top().second] = i; stk.pop();
		}
		stk.push(make_pair(v[i], i));
	}
	while (stk.top().second < v.size()) {
		res[stk.top().second] = -1; stk.pop();
	}
}