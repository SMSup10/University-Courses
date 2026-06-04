# 04. 연산자 오버로딩(Operator Overloading)과 템플릿(Template)

## 🎯 학습 목표

* 연산자 오버로딩의 개념을 이해한다.
* 객체 간 연산을 구현하는 방법을 학습한다.
* 템플릿(Template)의 개념을 이해한다.
* 함수 템플릿과 클래스 템플릿을 구현할 수 있다.
* 제네릭 프로그래밍(Generic Programming)의 기초를 이해한다.

---

# 📚 연산자 오버로딩 (Operator Overloading)

## 연산자 오버로딩이란?

기존 연산자(`+`, `-`, `==`, `<` 등)를

사용자 정의 클래스 객체에서도 사용할 수 있도록 정의하는 기능이다.

즉,

객체끼리도 일반 변수처럼 연산할 수 있게 만드는 것이다.

---

## 기본 연산

```cpp
a + b
```

---

## 객체 연산

```cpp
r1 + r2
```

---

# ✅ 연산자 오버로딩의 장점

### 1. 객체 사용이 자연스러워짐

```cpp
r1 + r2
```

---

### 2. 코드 가독성 향상

함수 호출보다 직관적이다.

---

### 3. 객체 간 연산 표현 가능

복잡한 객체 연산을 쉽게 표현할 수 있다.

---

# 📖 기본 문법

```cpp
ReturnType operator연산자(매개변수)
{
    // 연산 정의
}
```

---

## 대표적인 연산자

```cpp
operator+
operator-
operator==
operator<
operator>
```

---

# 🖥️ 예제 : 사각형 객체 더하기

## 문제

두 개의 사각형 객체를 더하면

새로운 사각형 객체를 생성한다.

---

## 계산 방식

```text
가로 = 가로 + 가로
세로 = 세로 + 세로
```

---

## 예제 코드

```cpp
#include <iostream>
using namespace std;

class CRect
{
public:
    int wid;
    int hig;

    CRect(int w, int h)
    {
        wid = w;
        hig = h;
    }

    int Area()
    {
        return wid * hig;
    }

    // 연산자 오버로딩
    CRect operator+(CRect r)
    {
        return CRect(
            wid + r.wid,
            hig + r.hig
        );
    }
};

int main()
{
    CRect r1(3, 4);
    CRect r2(5, 2);

    CRect r3 = r1 + r2;

    cout << "Area : "
         << r3.Area() << endl;

    return 0;
}
```

---

## 실행 결과

```text
Area : 48
```

---

## 계산 과정

```text
r1 = 3 × 4

r2 = 5 × 2

r3 = (3 + 5) × (4 + 2)

    = 8 × 6

    = 48
```

---

# 💡 핵심 정리

연산자 오버로딩이란

객체에서도

```cpp
+
-
*
==
<
>
```

등의 연산자를 사용할 수 있게 만드는 기능이다.

---

## 예

```cpp
CRect r3 = r1 + r2;
```

---

# 🚨 주의 사항

새로운 연산자를 만들 수는 없다.

가능

```cpp
operator+
operator==
operator<
```

불가능

```cpp
operator@
operator##
operator^^
```

---

# 📚 템플릿 (Template)

## 템플릿이란?

템플릿(Template)은

자료형(Type)을 나중에 결정할 수 있도록 만드는 설계도이다.

---

### 붕어빵 틀 비유

```text
템플릿 = 붕어빵 틀

int = 팥 붕어빵

double = 슈크림 붕어빵
```

틀은 하나지만

내용물은 다양하게 바뀔 수 있다.

---

## 템플릿의 특징

### 1. 컴파일 타임 결정

실행 전 컴파일 단계에서 실제 코드가 생성된다.

---

### 2. 타입 안전성

컴파일러가 타입을 검사한다.

---

### 3. 코드 재사용성

자료형마다 함수를 따로 만들 필요가 없다.

---

# 🖥️ 함수 템플릿

## 기본 문법

```cpp
template <typename T>
반환형 함수명(...)
{
}
```

---

## 예제 : 두 수 더하기

```cpp
#include <iostream>

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    std::cout
        << "Integer : "
        << add<int>(3, 7)
        << std::endl;

    std::cout
        << "Double : "
        << add(3.5, 4.2)
        << std::endl;

    return 0;
}
```

---

## 실행 결과

```text
Integer : 10
Double : 7.7
```

---

# 🔍 함수 템플릿 분석

```cpp
template <typename T>
```

의 의미

```text
T는 나중에 결정될 자료형
```

---

호출

```cpp
add<int>(3, 7);
```

컴파일러가

```cpp
int add(int a, int b)
```

를 생성한다.

---

호출

```cpp
add(3.5, 4.2);
```

컴파일러가

```cpp
double add(double a, double b)
```

를 생성한다.

---

# 📦 클래스 템플릿

## 기본 문법

```cpp
template <typename T>
class 클래스명
{
};
```

---

# 🖥️ 예제 : Box 클래스

```cpp
#include <iostream>
#include <string>

template <typename T>
class Box
{
private:
    T data;

public:

    void set(T value)
    {
        data = value;
    }

    T get()
    {
        return data;
    }
};

int main()
{
    Box<int> intBox;

    intBox.set(100);

    Box<std::string> strBox;

    strBox.set("Hello Template!");

    std::cout
        << "Box 1 : "
        << intBox.get()
        << std::endl;

    std::cout
        << "Box 2 : "
        << strBox.get()
        << std::endl;

    return 0;
}
```

---

## 실행 결과

```text
Box 1 : 100
Box 2 : Hello Template!
```

---

# 🔍 클래스 템플릿 분석

정수 저장

```cpp
Box<int>
```

---

문자열 저장

```cpp
Box<std::string>
```

---

같은 클래스지만

자료형만 다르게 사용 가능하다.

---

# ⚡ 제네릭(Generic)과 템플릿

## 제네릭(Generic)

자료형에 독립적인 프로그래밍 기법

---

## C++의 제네릭 구현 방식

```text
제네릭 프로그래밍
        ↓
Template
```

즉,

C++에서는 템플릿이

제네릭 프로그래밍을 구현하는 수단이다.

---

# 📌 연산자 오버로딩 vs 함수 오버로딩

| 구분       | 의미                   |
| -------- | -------------------- |
| 함수 오버로딩  | 같은 이름의 함수를 여러 형태로 정의 |
| 연산자 오버로딩 | 연산자를 객체에 맞게 재정의      |

---

예

함수 오버로딩

```cpp
Add(int, int)
Add(double, double)
```

---

연산자 오버로딩

```cpp
r1 + r2
```

---

# 📝 핵심 정리

## 연산자 오버로딩

객체에서도 연산자를 사용할 수 있도록 만드는 기능

예

```cpp
CRect r3 = r1 + r2;
```

---

## 템플릿

자료형을 나중에 결정하는 설계도

예

```cpp
template <typename T>
```

---

## 함수 템플릿

```cpp
template <typename T>
T add(T a, T b)
```

---

## 클래스 템플릿

```cpp
template <typename T>
class Box
{
};
```

---

## 템플릿 장점

* 코드 재사용
* 타입 안전성
* 컴파일 타임 최적화

---

# 🚨 시험 대비 암기 포인트

### 연산자 오버로딩

```cpp
operator+
operator==
operator<
```

---

### 함수 템플릿

```cpp
template <typename T>
```

---

### 클래스 템플릿

```cpp
Box<int>

Box<double>

Box<string>
```

---

### 핵심 개념

```text
함수 오버로딩
    ↓
같은 이름

연산자 오버로딩
    ↓
같은 연산자

템플릿
    ↓
같은 코드
```

---

# 📖 다음 강의

## STL(Standard Template Library)

* vector
* list
* map
* set
* iterator
* algorithm

템플릿을 기반으로 만들어진 C++ 표준 라이브러리를 학습한다.
