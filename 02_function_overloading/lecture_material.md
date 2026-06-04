# 02. 함수 오버로딩 (Function Overloading)

## 🎯 학습 목표

* 함수 오버로딩의 개념을 이해한다.
* 같은 이름의 함수를 여러 형태로 정의하는 방법을 학습한다.
* 생성자 오버로딩을 이해한다.
* 클래스 멤버 함수 오버로딩을 구현할 수 있다.

---

# 📚 함수 오버로딩이란?

함수 오버로딩(Function Overloading)이란,

**같은 이름의 함수를 여러 개 정의하는 것**을 의미한다.

단, 아래 조건 중 하나 이상이 달라야 한다.

* 매개변수의 개수
* 매개변수의 타입
* 매개변수의 순서

---

## 가능한 예

```cpp
int Add(int a, int b);

double Add(double a, double b);

int Add(int a, int b, int c);
```

함수 이름은 모두 `Add`이지만

매개변수가 다르므로 컴파일러는 서로 다른 함수로 인식한다.

---

# ✅ 함수 오버로딩의 장점

## 1. 같은 기능을 하나의 이름으로 관리

```cpp
Set();
Set(width);
Set(width, height);
```

---

## 2. 코드 가독성 향상

함수 이름이 통일되어 코드를 읽기 쉽다.

---

## 3. 프로그램 설계가 자연스러움

동일한 기능을 다양한 방식으로 호출할 수 있다.

---

# 🖥️ 기본 함수 오버로딩 예제

```cpp
#include <iostream>
using namespace std;

int Add(int a, int b)
{
    return a + b;
}

double Add(double a, double b)
{
    return a + b;
}

int main()
{
    cout << Add(3, 4) << endl;
    cout << Add(2.5, 3.1) << endl;

    return 0;
}
```

---

## 실행 결과

```text
7
5.6
```

---

# 🏗️ 생성자(Constructor) 오버로딩

생성자도 함수이므로 오버로딩이 가능하다.

---

## 다양한 생성자 구성

### 기본 생성자

```cpp
Rect()
```

### 정사각형 생성자

```cpp
Rect(int w)
```

### 직사각형 생성자

```cpp
Rect(int w, int h)
```

---

# 생성자 오버로딩 예제

```cpp
#include <iostream>
using namespace std;

class Rect
{
private:
    int width;
    int height;

public:

    // 기본 생성자
    Rect()
    {
        width = 0;
        height = 0;
    }

    // 정사각형 생성자
    Rect(int w)
    {
        width = w;
        height = w;
    }

    // 직사각형 생성자
    Rect(int w, int h)
    {
        width = w;
        height = h;
    }

    int Area()
    {
        return width * height;
    }
};

int main()
{
    Rect r1;
    Rect r2(5);
    Rect r3(5, 4);

    cout << r1.Area() << endl;
    cout << r2.Area() << endl;
    cout << r3.Area() << endl;

    return 0;
}
```

---

## 실행 결과

```text
0
25
20
```

---

# 🔧 Set() 함수 오버로딩

같은 이름의 `Set()` 함수를 여러 형태로 사용할 수 있다.

---

## 지원 형태

```cpp
Set(w, h);
Set(w);
```

---

# Set() 오버로딩 예제

```cpp
#include <iostream>
using namespace std;

class Rect
{
private:
    int width;
    int height;

public:

    void Set(int w, int h)
    {
        width = w;
        height = h;
    }

    void Set(int w)
    {
        width = w;
        height = w;
    }

    int Area()
    {
        return width * height;
    }
};

int main()
{
    Rect r1, r2;

    r1.Set(5, 4);
    r2.Set(6);

    cout << "r1 area: " << r1.Area() << endl;
    cout << "r2 area: " << r2.Area() << endl;

    return 0;
}
```

---

## 실행 결과

```text
r1 area: 20
r2 area: 36
```

---

# 📝 학생 실습 문제

## 실습 1

### Perimeter() 함수 추가

기능

직사각형의 둘레 계산

공식

```cpp
2 * (width + height)
```

예

```cpp
cout << r.Perimeter();
```

---

## 실습 2

### Set() 함수 추가

다음 형태의 함수를 추가하시오.

```cpp
Set();
```

기능

```cpp
width = 1;
height = 1;
```

---

# 💡 함수 오버로딩과 생성자 오버로딩 비교

| 구분       | 예제                               |
| -------- | -------------------------------- |
| 함수 오버로딩  | Add(), Set()                     |
| 생성자 오버로딩 | Rect(), Rect(int), Rect(int,int) |

---

# 📌 핵심 정리

## 함수 오버로딩

같은 이름의 함수라도

* 매개변수 개수
* 매개변수 타입
* 매개변수 순서

가 다르면 여러 개 정의할 수 있다.

---

## 생성자 오버로딩

생성자도 함수이므로 오버로딩이 가능하다.

예

```cpp
Rect()
Rect(int w)
Rect(int w, int h)
```

---

## Set() 함수 오버로딩

```cpp
Set()
Set(int w)
Set(int w, int h)
```

---

# 🚨 주의 사항

다음은 오버로딩이 불가능하다.

```cpp
int Add(int a, int b);

double Add(int a, int b);
```

반환형(Return Type)만 다른 경우에는 오버로딩이 성립하지 않는다.

---

# 🔥 시험 대비 암기 포인트

### 함수 오버로딩

* 같은 이름 사용 가능
* 매개변수가 달라야 함
* 반환형만 다르면 불가능

### 생성자 오버로딩

```cpp
Rect()
Rect(int)
Rect(int, int)
```

### 대표 출제 유형

```cpp
Add(3, 4);
Add(3.5, 4.2);
```

어떤 함수가 호출되는지 묻는 문제

---

# 📖 다음 강의

## 연산자 오버로딩 (Operator Overloading)

예제

```cpp
Rect r3 = r1 + r2;
```

사용자 정의 클래스에서도 연산자를 사용할 수 있도록 구현하는 방법을 학습한다.
