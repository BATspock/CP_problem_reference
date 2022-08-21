#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
	int team_size(vector<int>& v) {
		sort(v.begin(), v.end());
		unordered_set<float> s;
		for (int i = 0; i < v.size() / 2 - 1; i++) {
			int j = v.size() - 1 - i;
			float value = (1.0*v[i]+ 1.0*v[j])/2.0;
			s.insert(value);
		}
		return s.size();
	}
};

int main() {

	vector<int> v{ 1,4,1,3,5,6 };
	Solution *object1 = new Solution();
	cout << object1->team_size(v);
	return 0;

}