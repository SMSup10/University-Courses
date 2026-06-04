# 04-1. Modern C++ 기초 (Vector, Range-based For, Lambda, Smart Pointer, Reference, Auto)

## 🎯 학습 목표

* STL의 대표 컨테이너인 vector를 사용할 수 있다.
* 범위 기반 for문(Range-based For)을 이해한다.
* 람다 함수(Lambda Function)의 기본 구조를 학습한다.
* 스마트 포인터(Smart Pointer)를 이해한다.
* 참조자(Reference)의 개념을 이해한다.
* auto 키워드를 활용하여 타입 추론을 사용할 수 있다.

---

# 📚 STL Vector (동적 배열)

## Vector란?

Vector는

**필요에 따라 크기가 자동으로 증가하는 동적 배열(Dynamic Array)** 이다.

일반 배열과 달리 크기를 미리 정할 필요가 없다.

---

## 특징

* 크기가 자동으로 증가
* 배열처럼 `[ ]` 사용 가능
* STL에서 가장 많이 사용되는 컨테이너
* 데이터를 순서대로 저장

---

## 주요 함수

### 데이터 추가

```cpp
v.push_back(10);
```

배열 맨 뒤에 데이터를 추가한다.

---

# 🖥️ Vector 기본 예제

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);

    cout << v[0] << endl;
    cout << v[1] << endl;

    return 0;
}
```

---

## 실행 결과

```text
10
20
```

---

# 🔄 범위 기반 For문 (Range-based For)

## 개념

컨테이너의 처음부터 끝까지

자동으로 하나씩 꺼내주는 반복문이다.

---

## 기본 문법

```cpp
for (자료형 변수 : 컨테이너)
{
}
```

---

## 예제

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);

    for (int n : v)
    {
        cout << n << " ";
    }

    return 0;
}
```

---

## 실행 결과

```text
10 20
```

---

# 💡 범위 기반 For문의 장점

기존 방식

```cpp
for(int i = 0; i < v.size(); i++)
{
    cout << v[i];
}
```

---

현대적 방식

```cpp
for(int n : v)
{
    cout << n;
}
```

---

장점

* 코드가 짧음
* 인덱스 실수 감소
* 가독성 향상

---

# 📚 람다 함수 (Lambda Function)

## 람다 함수란?

람다 함수는

**이름 없는 익명 함수(Anonymous Function)** 를

필요한 위치에서 즉석으로 만드는 현대 C++ 문법이다.

---

# 람다 함수의 핵심 구조

```cpp
[capture](parameter)
{
    body
};
```

---

## 3가지 핵심 요소

### 1. 캡처 (Capture)

```cpp
[z]
```

함수 외부의 지역 변수를 내부로 가져온다.

---

### 2. 매개변수 (Parameter)

```cpp
(int a, int b)
```

외부에서 값을 전달받는다.

---

### 3. 함수 본문 (Body)

```cpp
{
    return a + b + z;
}
```

실제 수행할 로직

---

# 🖥️ 람다 함수 예제

```cpp
#include <iostream>

using namespace std;

int main()
{
    int z(1);

    int x(2);
    int y(3);

    cout << [z](int a, int b)
    {
        return a + b + z;
    }(x, y);

    return 0;
}
```

---

## 실행 결과

```text
6
```

---

## 코드 분석

```cpp
[z](int a, int b)
{
    return a + b + z;
}(x, y);
```

구성

```text
[z]           → 캡처
(int a, int b) → 인자
{ ... }       → 본문
(x, y)        → 즉시 실행
```

---

# ⚡ 캡처 방식

## 값 복사

```cpp
[=]
```

모든 변수를 값으로 복사

---

## 참조 캡처

```cpp
[&]
```

모든 변수를 참조로 전달

---

## 특정 변수 캡처

```cpp
[x]
```

특정 변수만 사용

---

# 📚 스마트 포인터 (Smart Pointer)

## 스마트 포인터란?

포인터를 객체로 감싸서

메모리를 자동으로 관리하는 도구이다.

---

## 기존 방식

```cpp
Dog* p = new Dog();

delete p;
```

문제점

* delete 누락 가능
* 메모리 누수 발생
* 중복 해제 위험

---

## 스마트 포인터 방식

```cpp
auto p = make_unique<Dog>();
```

delete를 직접 작성할 필요가 없다.

---

# 주요 종류

## unique_ptr

독점 소유

```cpp
unique_ptr<Dog>
```

가장 많이 사용

---

## shared_ptr

공동 소유

```cpp
shared_ptr<Dog>
```

여러 객체가 공유 가능

---

# 🖥️ Smart Pointer 예제

```cpp
#include <iostream>
#include <memory>

using namespace std;

class Dog
{
public:

    Dog()
    {
        cout << "강아지 입양\n";
    }

    ~Dog()
    {
        cout << "강아지 무지개다리\n";
    }

    void bark()
    {
        cout << "멍멍!\n";
    }
};

int main()
{
    {
        unique_ptr<Dog> myDog =
            make_unique<Dog>();

        myDog->bark();
    }

    return 0;
}
```

---

## 실행 결과

```text
강아지 입양
멍멍!
강아지 무지개다리
```

---

# 💡 스마트 포인터 핵심 정리

현대 C++에서는

```cpp
new
delete
```

보다

```cpp
make_unique
make_shared
```

사용을 권장한다.

---

# 📚 참조자 (Reference)

## 참조자란?

기존 변수에 새로운 이름(별명)을 붙이는 기능

---

## 기본 문법

```cpp
int a = 10;

int& ref = a;
```

---

## 관계

```text
a
↑
ref
```

같은 메모리를 가리킨다.

---

# 🖥️ 참조자 예제

```cpp
#include <iostream>

using namespace std;

int main()
{
    int a = 10;

    int& ref = a;

    ref = 20;

    cout << a << endl;
    cout << ref << endl;

    return 0;
}
```

---

## 실행 결과

```text
20
20
```

---

# 참조자의 특징

### 반드시 초기화

```cpp
int& ref = a;
```

가능

---

```cpp
int& ref;
```

불가능

---

### 변경 불가

```cpp
int a = 10;
int b = 20;

int& ref = a;
```

참조 대상 변경 불가

---

# 📚 Auto

## Auto란?

컴파일러가 우변 값을 보고

자동으로 타입을 결정하는 키워드

---

# 기본 문법

```cpp
auto 변수 = 값;
```

---

## 예제

```cpp
auto a = 10;
auto b = 3.14;
auto c = "Hello";
```

---

## 컴파일러 해석

```cpp
int a = 10;

double b = 3.14;

const char* c = "Hello";
```

---

# 🖥️ Auto 활용 예제

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    auto a = 10;

    auto b = 3.14;

    vector<int> v = {1,2,3};

    auto it = v.begin();

    cout << a << endl;
    cout << b << endl;

    return 0;
}
```

---

# Auto + Range For

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    auto v = {10,20,30};

    for(auto n : v)
    {
        cout << n << " ";
    }

    return 0;
}
```

---

## 실행 결과

```text
10 20 30
```

---

# 📌 핵심 정리

## Vector

```cpp
vector<int> v;
v.push_back(10);
```

동적 배열

---

## Range-based For

```cpp
for(auto n : v)
```

자동 순회

---

## Lambda

```cpp
[capture](parameter)
{
}
```

익명 함수

---

## Smart Pointer

```cpp
make_unique
make_shared
```

자동 메모리 관리

---

## Reference

```cpp
int& ref = a;
```

변수의 별명

---

## Auto

```cpp
auto x = 10;
```

자동 타입 추론

---

# 🚨 시험 대비 암기 포인트

### Vector

```cpp
push_back()
```

---

### Lambda

```cpp
[z](int a, int b)
{
}
```

---

### Smart Pointer

```cpp
unique_ptr
shared_ptr
```

---

### Reference

```cpp
int& ref = a;
```

---

### Auto

```cpp
auto x = 10;
```

---

# 📖 다음 강의

## 예외 처리(Exception)와 파일 입출력(File I/O)

* try
* catch
* throw
* 파일 읽기
* 파일 쓰기

프로그램의 안정성과 데이터 저장 방법을 학습한다.
