# 10. 고급 C++ 기능과 Linux 개발 환경

## 🎯 학습 목표

* 람다 함수(Lambda Function)를 자유롭게 사용할 수 있다.
* 구조적 바인딩(Structured Binding)을 이해한다.
* RAII(Resource Acquisition Is Initialization)를 실전 코드에 적용할 수 있다.
* 이동 세만틱(Move Semantics)의 성능 향상 원리를 이해한다.
* 다중 상속(Multiple Inheritance)과 인터페이스를 활용할 수 있다.
* Linux 환경에서 C++ 프로그램을 컴파일하고 실행할 수 있다.

---

# 📚 복습

## 두 수 더하기

생성자를 이용하여 두 개의 정수를 저장하고

합계를 반환하는 프로그램 작성

---

## 명령행 매개변수

프로그램 실행 시 전달된 값을 사용할 수 있다.

예

```bash
program.exe 10 20
```

---

## 파일 저장

프로그램 결과를

```text
my.txt
```

파일에 저장

---

## 구현 목표

* 생성자 초기화 리스트 사용
* 명령행 인자 → 정수 변환
* 두 수 더하기
* 화면 출력
* 파일 저장

---

# 📚 RAII (Resource Acquisition Is Initialization)

## 개념

객체의 생성과 자원의 획득을 함께 수행하고

객체가 소멸될 때 자원도 자동 해제하는 기법

---

## 동작 과정

```text
객체 생성
    ↓
자원 획득

객체 소멸
    ↓
자원 해제
```

---

## 예제

```cpp
class Buffer
{
    int* data;

public:

    Buffer()
    {
        data = new int[100];
    }

    ~Buffer()
    {
        delete[] data;
    }
};
```

---

## 장점

* 메모리 누수 방지
* 예외 발생 시 안전
* 자원 관리 자동화

---

# 📚 연산자 오버로딩

## 개념

객체에서도

```cpp
+
-
*
=
==
```

등의 연산자를 사용할 수 있게 만드는 기능

---

## 더하기 연산자

```cpp
CPnt operator+
(
    const CPnt& o
)
{
    return CPnt(
        v[0] + o.v[0],
        v[1] + o.v[1]
    );
}
```

---

## 대입 연산자

```cpp
CPnt& operator=
(
    const CPnt& o
)
{
    return *this;
}
```

---

## 활용

STL 알고리즘

```cpp
sort()
```

에서 객체 교환 및 복사 시 사용된다.

---

# 📚 클래스 템플릿

## 개념

자료형과 관계없이 동일한 코드를 재사용하는 기능

---

## 기본 문법

```cpp
template <typename T>

class CPnt
{
};
```

---

## 사용 예

```cpp
CPnt<int>

CPnt<float>

CPnt<double>
```

---

## 장점

* 코드 재사용성 증가
* 유지보수 용이
* 타입 안전성 확보

---

# 📚 람다 함수 (Lambda Function)

## 개념

이름 없는 익명 함수

---

## 예제

```cpp
#include <iostream>

using namespace std;

int main()
{
    int a = 1;

    [a](int b, int c)
    {
        cout
            << "Hi "
            << a + b + c;
    }(2,3);
}
```

---

## 실행 결과

```text
Hi 6
```

---

## 구조

```cpp
[a](int b, int c)
{
    ...
}
```

| 구성            | 의미    |
| ------------- | ----- |
| [a]           | 캡처    |
| (int b,int c) | 매개변수  |
| { }           | 실행 코드 |

---

# 📚 구조적 바인딩 (Structured Binding)

## 개념

pair, tuple, map 등의 요소를

직접 변수로 분해하여 사용하는 기능

---

## 기존 방식

```cpp
u.first
u.second
```

---

## 예제

```cpp
pair<string,int> u =
{
    "John",
    25
};

cout
<< u.first
<< " "
<< u.second;
```

---

# Map과 구조적 바인딩

## 예제

```cpp
map<string,int> scores =
{
    {"Kim",90},
    {"Lee",80},
    {"Park",95}
};

for(auto const&
    [name, score]
    : scores)
{
    cout
    << name
    << ": "
    << score
    << endl;
}
```

---

## 실행 결과

```text
Kim : 90
Lee : 80
Park : 95
```

---

## 장점

기존

```cpp
it->first
it->second
```

---

구조적 바인딩

```cpp
[name, score]
```

---

가독성이 크게 향상된다.

---

# 📚 이동 세만틱 (Move Semantics)

## 개념

객체를 복사하지 않고

자원의 소유권만 이동시키는 기술

---

## 복사 방식

```text
원본 유지

새 메모리 생성

데이터 복사
```

느림

---

## 이동 방식

```text
원본 자원 이전

원본 비우기
```

빠름

---

# 이동 생성자

```cpp
CPnt(CPnt&& o)
    noexcept

    : v(o.v)
{
    o.v = nullptr;
}
```

---

## 동작 과정

```text
객체 A
 ↓
메모리
```

---

이동

```text
객체 B
 ↓
메모리

객체 A
 ↓
nullptr
```

---

## 장점

* 메모리 복사 없음
* 성능 향상
* STL 최적화

---

# 📚 다중 상속 (Multiple Inheritance)

## 개념

하나의 클래스가

여러 부모 클래스를 상속받는 것

---

## 기본 문법

```cpp
class Child
    : public A,
      public B
{
};
```

---

# 인터페이스

## 추상 클래스

```cpp
struct Drawable
{
    virtual void Draw() = 0;
};
```

---

## 구현 클래스

```cpp
struct ColoredPnt
    : public CPnt<float>,
      public Drawable
{
    using CPnt::CPnt;

    void Draw() override
    {
        cout << "Draw!";
    }
};
```

---

## 구조

```text
          Drawable
              ↑

CPnt<float> → ColoredPnt
```

---

## 특징

* 여러 기능 조합 가능
* 코드 재사용 증가
* 객체지향 설계 강화

---

# 📚 STL + Move Semantics

## Vector

```cpp
vector<CPnt<float>> pts;
```

---

## 데이터 추가

```cpp
pts.push_back(
    CPnt<float>(10,20)
);
```

---

## 정렬

```cpp
sort(
    pts.begin(),
    pts.end(),
    ...
);
```

---

## 내부 동작

```text
push_back()
 ↓
Move Constructor

sort()
 ↓
operator=
```

---

# 📚 C++ in Linux

## WSL 설치

PowerShell 관리자 실행

```powershell
wsl --install
```

---

## 설치 확인

```bash
wsl --list --verbose
```

---

## 실행

```bash
wsl
```

---

## 컴파일러 확인

```bash
g++ --version
```

---

# 패키지 업데이트

```bash
sudo apt update
```

```bash
sudo apt upgrade g++
```

---

# 🖥️ Linux 실습

## test.cpp

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a =
    {
        2,3,4
    };

    a.push_back(5);

    for(auto n : a)
    {
        cout << n;
    }
}
```

---

# 컴파일 방법 1

```bash
g++ test.cpp
```

실행

```bash
./a.out
```

---

# 컴파일 방법 2

실행 파일 이름 지정

```bash
g++ -o test test.cpp
```

실행

```bash
./test
```

---

# 📌 핵심 정리

## 람다 함수

```cpp
[capture]
(parameter)
{
}
```

---

## 구조적 바인딩

```cpp
auto [a,b]
```

---

## RAII

```text
생성자 → 자원 획득

소멸자 → 자원 해제
```

---

## 이동 세만틱

```cpp
Class(Class&& obj)
```

---

## 다중 상속

```cpp
class C
    : public A,
      public B
{
};
```

---

## Linux 컴파일

```bash
g++ test.cpp
```

```bash
./a.out
```

---

# 🚨 시험 대비 암기 포인트

### RAII

```text
생성자 → 획득

소멸자 → 해제
```

---

### 람다 함수

```cpp
[a](int b,int c)
{
}
```

---

### 구조적 바인딩

```cpp
auto [name, score]
```

---

### 이동 생성자

```cpp
Class(Class&& obj)
```

---

### 다중 상속

```cpp
class Child
: public A,
  public B
```

---

### Linux

```bash
wsl
```

```bash
g++
```

```bash
./a.out
```

---

# 📖 다음 강의

## SQLite 데이터베이스와 C++ 연동

* sqlite3_open()
* sqlite3_exec()
* sqlite3_prepare()
* sqlite3_close()
* CRUD(Create, Read, Update, Delete)

C++ 프로그램에서 SQLite 데이터베이스를 연동하고 데이터를 저장하는 방법을 학습한다.
