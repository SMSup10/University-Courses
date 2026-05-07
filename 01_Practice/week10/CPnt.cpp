#include<iostream>
using namespace std;


class CPnt {
	int x, y;
public:
	CPnt(int a, int b): x(a), y(b) {}
	void Pr();
};
inline void CPnt::Pr(){ 
	cout << x << " , " << y << endl; 
}
int main() {
	CPnt p1{ 2,3 }, p2(3, 4);
	p1.Pr();
	p2.Pr();
	return 0;
}
-------------------------------------------
// const 추가버전
#include<iostream>
using namespace std;


class CPnt {
	int x, y;
public:
	CPnt(int a, int b): x(a), y(b) {}
	void Pr()const;
};
inline void CPnt::Pr() const{ 
	cout << x << " , " << y << endl; 
}
int main() {
	CPnt p1{ 2,3 }, p2(3, 4);
	p1.Pr();
	p2.Pr();
	return 0;
}
-----------------------------------------
  #include<iostream>
using namespace std;


class CPnt {
	int x, y;
public:
	
	CPnt(int a=1, int b=1) : x(a), y(b) {}
	void Pr() const {
		cout << x << " , " << y << endl;
	}
	CPnt operator+(CPnt& p) {
		return CPnt(x + p.x, y + p.y);
	};
};
 
int main() {
	CPnt p1(1, 2), p2(3, 4), p3;
	p3 = p2 + p1;
	p3.Pr();
	return 0;
}
