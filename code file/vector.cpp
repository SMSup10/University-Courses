#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	vector <int> v = { 4, 2, 5, 1, 3 };
	auto it = find(v.begin(), v.end(), 1);
	if (it != v.end()) cout << *it << " 찾았다!";
}
