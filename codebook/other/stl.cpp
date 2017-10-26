#include "../template.cpp"

struct Foo{
    Foo(){}
	Foo(int i):i(i){}
	int i;
};

struct Cmp {
	bool operator()(const Foo & a, const Foo & b) const { return a.i<b.i; }
};

struct cmpByStringLength {
    bool operator()(const string& a, const string& b) const {
        return a.length() < b.length();
    }
};


int main() {
	Foo one(1);

	priority_queue<Foo, vector<Foo>, Cmp> pq;
	pq.push(one); pq.top(); pq.pop();

	set<Foo, Cmp> s; s.insert(one); s.erase(one);

	map<Foo, Foo, Cmp> m;
    m[one]=one;
    dbg(m[one].i);


	vector<Foo> v; 
	lower_bound(all(v), one, [](const Foo& a, const Foo& b)->bool{return a.i<b.i;});
	sort(all(v), [](const Foo& a, const Foo& b)->bool{return a.i<b.i;});



	return 0;
}
