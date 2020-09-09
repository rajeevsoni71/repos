#define io(v) cin>>v
#define FUNCTION(type,Operator) inline void type(int &out,int vec){!(out Operator vec)?out=vec:false;}
#define INF (int)((int)0)
#define toStr(st) #st
#define foreach(v,i) for(size_t i=0;i<v.size();i++)
#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, < )
FUNCTION(maximum, > )

	int main() {
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result = ) << ' ' << ans;
	return 0;

}