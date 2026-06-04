#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class CRect {
    int w, h;
public:
    CRect(int w, int h) : w(w), h(h) {}
    void Area() { cout << w * h << endl; }
};

int main() {
    vector<CRect> v = { CRect(1,2), CRect(2,3) };
    v.push_back(CRect(4, 5));
   
   
    return 0;
}
-----------------------------------------------
//auto 사용
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class CRect {
    int w, h;
public:
    CRect(int w, int h) : w(w), h(h) {}
    void Area() { cout << w * h << endl; }
};

int main() {
    vector<CRect> v = { CRect(1,2), CRect(2,3) };
    v.push_back(CRect(4, 5));
    for (auto it = v.begin(); it != v.end(); it++) {
        it->Area();
   }
   
    return 0;
}
