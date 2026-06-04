# 03. 상속(Inheritance)과 다형성(Polymorphism)

## 🎯 학습 목표

* 상속(Inheritance)의 개념을 이해한다.
* 부모 클래스와 자식 클래스의 관계를 이해한다.
* 상속을 이용한 코드 재사용 방법을 학습한다.
* 가상 함수(virtual)를 이용한 다형성을 이해한다.
* 업캐스팅(Upcasting)과 동적 바인딩(Dynamic Binding)의 개념을 이해한다.

---

# 📚 상속(Inheritance)이란?

상속(Inheritance)이란,

**기존 클래스의 기능을 물려받아 새로운 클래스를 만드는 객체지향 기술**이다.

즉,

이미 만들어진 클래스를 재사용하여

* 코드 중복을 줄이고
* 기능을 확장하며
* 유지보수를 쉽게 만드는 방법이다.

---

# 🏗️ 상속의 구조

| 구분                     | 의미                   |
| ---------------------- | -------------------- |
| 부모 클래스 (Base Class)    | 기존 클래스               |
| 자식 클래스 (Derived Class) | 부모 클래스를 상속받아 확장한 클래스 |

---

# ✅ 상속의 장점

### 1. 코드 재사용

이미 작성한 코드를 그대로 사용할 수 있다.

### 2. 구조 단순화

공통 기능을 부모 클래스에 모아둘 수 있다.

### 3. 기능 확장 용이

기존 코드를 수정하지 않고 새로운 기능을 추가할 수 있다.

---

# 📖 상속 기본 문법

```cpp
class Child : public Parent
{
};
```

예

```cpp
class CSquare : public CRect
{
};
```

---

# 🖥️ 상속 기본 예제

## CRect → CSquare 상속

### 클래스 구조

```text
CRect (부모 클래스)
    ↑
CSquare (자식 클래스)
```

---

## 예제 코드

```cpp
#include <iostream>
using namespace std;

class CRect
{
protected:
    int wid;
    int hig;

public:

    void Set(int w, int h)
    {
        wid = w;
        hig = h;
    }

    int Area()
    {
        return wid * hig;
    }
};

class CSquare : public CRect
{
public:

    void Set(int w)
    {
        wid = w;
        hig = w;
    }
};

int main()
{
    CSquare sq;

    sq.Set(5);

    cout << "Square Area: " << sq.Area() << endl;

    return 0;
}
```

---

## 실행 결과

```text
Square Area: 25
```

---

# 💡 핵심 포인트

상속 관계

```text
CRect
  ↑
CSquare
```

자식 클래스는 부모 클래스의 함수를 그대로 사용할 수 있다.

예

```cpp
sq.Area();
```

`Area()` 함수는 `CRect`에 정의되어 있지만

`CSquare`에서도 사용할 수 있다.

---

# 📌 상속의 핵심

상속이란

> 기존 클래스를 재사용하여 새로운 클래스를 만드는 것

이다.

---

# 🚀 상속 + 다형성

## 상속(Inheritance)

기존 클래스를 물려받아 새로운 클래스를 만드는 것

---

## 다형성(Polymorphism)

같은 함수가 객체에 따라 다르게 동작하는 것

---

즉,

```text
상속 → 클래스 확장

다형성 → 함수 동작 확장
```

---

# 🖥️ 상속과 다형성 예제

## 클래스 구조

```text
CRect
  ↑
CSquare
```

---

## 예제 코드

```cpp
#include <iostream>
using namespace std;

class CRect
{
protected:
    int wid;
    int hig;

public:

    CRect(int w, int h)
    {
        wid = w;
        hig = h;
    }

    virtual int Area()
    {
        return wid * hig;
    }
};

class CSquare : public CRect
{
public:

    CSquare(int w)
        : CRect(w, w)
    {
    }

    int Area()
    {
        return wid * wid;
    }
};

int main()
{
    CRect* p;

    CRect r(5, 4);
    CSquare s(5);

    p = &r;
    cout << "Rectangle Area : "
         << p->Area() << endl;

    p = &s;
    cout << "Square Area : "
         << p->Area() << endl;

    return 0;
}
```

---

## 실행 결과

```text
Rectangle Area : 20
Square Area : 25
```

---

# 🔍 다형성 분석

같은 함수

```cpp
Area()
```

를 호출했지만

객체에 따라 다른 함수가 실행된다.

---

## Rectangle

```cpp
wid * hig
```

결과

```text
20
```

---

## Square

```cpp
wid * wid
```

결과

```text
25
```

---

✔ 이것이 다형성(Polymorphism)이다.

---

# ⚡ 가상 함수(Virtual Function)

다형성을 사용하기 위해서는

부모 클래스 함수 앞에

```cpp
virtual
```

키워드를 붙여야 한다.

예

```cpp
virtual int Area()
{
    return wid * hig;
}
```

---

# ⚡ 동적 바인딩(Dynamic Binding)

가상 함수가 사용되면

어떤 함수를 호출할지

실행 시점(Runtime)에 결정된다.

이를

**동적 바인딩(Dynamic Binding)**

이라고 한다.

---

예

```cpp
CRect* p;
p = &s;

p->Area();
```

컴파일 시점에는

```cpp
CRect::Area()
```

를 호출할지 알 수 없다.

실행 시점에

```cpp
CSquare::Area()
```

가 호출된다.

---

# 🔄 업캐스팅(Upcasting)

자식 객체를 부모 타입으로 바라보는 것

---

예

```cpp
CSquare s(5);

CRect* p = &s;
```

자동 변환된다.

---

# 🔄 다운캐스팅(Downcasting)

부모 타입을 자식 타입으로 변환하는 것

---

예

```cpp
CRect* p;

CSquare* s =
    (CSquare*)p;
```

명시적 형변환이 필요하다.

---

# 🔐 protected 멤버

예제에서 사용한

```cpp
protected:
    int wid;
    int hig;
```

의 의미

---

## private

```cpp
부모 클래스 내부에서만 사용 가능
```

---

## protected

```cpp
부모 + 자식 클래스에서 사용 가능
```

---

## public

```cpp
어디서든 접근 가능
```

---

# 📌 상속에서 알아야 할 핵심 개념

* 상속(Inheritance)
* 부모 클래스(Base Class)
* 자식 클래스(Derived Class)
* 접근 지정자(public, protected, private)
* protected 멤버
* 코드 재사용
* 생성자와 소멸자 호출 순서
* 함수 오버라이딩(Overriding)
* 가상 함수(virtual)
* 동적 바인딩(Dynamic Binding)
* 다형성(Polymorphism)
* 업캐스팅(Upcasting)
* 다운캐스팅(Downcasting)
* 다중 상속(Multiple Inheritance)

---

# 📝 핵심 정리

## 상속

```cpp
class Child : public Parent
{
};
```

부모 클래스를 재사용하여 새로운 클래스를 만든다.

---

## 다형성

같은 함수라도 객체에 따라 다른 결과가 나온다.

---

## 가상 함수

```cpp
virtual
```

를 사용하면 실행 시점에 함수가 결정된다.

---

## 업캐스팅

```cpp
CSquare → CRect
```

자동 변환 가능

---

## 다운캐스팅

```cpp
CRect → CSquare
```

명시적 형변환 필요

---

# 🚨 시험 대비 암기 포인트

### 상속

```cpp
class B : public A
```

---

### 오버라이딩

부모 함수를 자식 클래스에서 재정의

```cpp
int Area()
{
}
```

---

### 다형성

```cpp
CRect* p = &s;
p->Area();
```

실행 결과가 객체에 따라 달라짐

---

### virtual

없으면

```cpp
부모 함수 호출
```

있으면

```cpp
실제 객체 함수 호출
```

---

# 📖 다음 강의

## 연산자 오버로딩 (Operator Overloading)

예제

```cpp
Rect r3 = r1 + r2;
```

사용자 정의 클래스에서도

`+`, `-`, `*`, `==` 등의 연산자를 사용할 수 있도록 구현하는 방법을 학습한다.
