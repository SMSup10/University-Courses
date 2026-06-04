GitHub에 올릴 용도라면 **강의 자료 + 복습 노트** 느낌으로 정리하는 것이 가장 좋습니다. 아래 버전은 Markdown 형식으로 바로 붙여넣어 사용할 수 있게 구성했습니다.

# 01. 수업 소개 및 첫 예제

## 🎯 수업 목표

본 과목을 통해 다음 내용을 학습한다.

* C++ 핵심 문법을 이해하고 프로그램을 구현한다.
* 객체지향 프로그래밍(OOP) 개념을 익혀 구조적인 소프트웨어를 설계한다.
* STL(Standard Template Library)을 활용하여 효율적인 코드를 작성한다.
* 메모리 관리와 예외 처리를 이해하여 안정적인 프로그램을 개발한다.
* 실습 및 프로젝트를 통해 문제 해결 능력을 향상시킨다.

---

# 📚 수업 내용

* C++ 언어 개요 및 개발 환경 구축
* C와 C++의 차이점
* 기본 입출력과 프로그램 구조
* 클래스(Class)와 객체(Object)
* 캡슐화(Encapsulation)와 접근 지정자
* 상속(Inheritance)과 다형성(Polymorphism)
* STL(Standard Template Library)
* 파일 입출력(File I/O) 및 예외 처리(Exception)
* 메모리 관리와 포인터(Pointer)
* 팀 프로젝트 기반 C++ 응용 프로그램 개발

---

# 🚀 C++의 주요 특징

* 객체지향 프로그래밍(OOP) 지원
* C 언어와 높은 호환성
* 높은 성능과 효율성
* 풍부한 표준 라이브러리(STL) 제공
* 대규모 소프트웨어 개발에 적합

---

# ⚖️ C와 C++의 차이점

| 항목       | C       | C++   |
| -------- | ------- | ----- |
| 프로그래밍 방식 | 절차지향    | 객체지향  |
| 데이터 처리   | 함수 중심   | 객체 중심 |
| 캡슐화      | 지원하지 않음 | 지원    |
| 함수 오버로딩  | 불가능     | 가능    |
| 참조 변수    | 없음      | 있음    |
| 예외 처리    | 없음      | 있음    |

## 핵심 정리

C++는 C 언어의 기능을 포함하면서도 객체지향 프로그래밍과 다양한 현대적 기능을 제공한다.

주요 활용 분야

* 임베디드 시스템
* 게임 개발
* 금융 시스템
* AI 및 머신러닝
* 운영체제 개발

---

# 🖥️ 개발 환경

## 온라인 컴파일러

### W3Schools

[https://www.w3schools.com/cpp/cpp_compiler.asp](https://www.w3schools.com/cpp/cpp_compiler.asp)

### cpp.sh

[https://cpp.sh/](https://cpp.sh/)

---

## Visual Studio Community

[https://visualstudio.microsoft.com/ko/vs/community/](https://visualstudio.microsoft.com/ko/vs/community/)

---

# 컴파일러란?

소스 코드(Source Code)를 실행 가능한 프로그램(Executable File)으로 변환하는 프로그램

## 컴파일 과정

```text
Source Code
    ↓
 Compiler
    ↓
 Object File
    ↓
 Linker
    ↓
 Executable File (.exe)
    ↓
 Loader
    ↓
 Execution
```

---

# 첫 번째 예제 : Hello World

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!";
    return 0;
}
```

## 실행 결과

```text
Hello World!
```

---

# 구조체를 이용한 두 수의 합

```cpp
#include <iostream>
using namespace std;

struct Math
{
    int a, b;

    int Add()
    {
        return a + b;
    }
};

int main()
{
    Math me;

    me.a = 10;
    me.b = 20;

    cout << "a + b = " << me.Add();

    return 0;
}
```

## 실행 결과

```text
a + b = 30
```

---

# 클래스를 이용한 두 수의 합

```cpp
#include <iostream>
using namespace std;

class CMath
{
private:
    int a, b;

public:
    void Set(int x, int y)
    {
        a = x;
        b = y;
    }

    int Add()
    {
        return a + b;
    }
};

int main()
{
    CMath me;

    me.Set(10, 20);

    cout << "a + b = " << me.Add();

    return 0;
}
```

## 실행 결과

```text
a + b = 30
```

---

# 구조체와 클래스 비교

| 구조체(struct)        | 클래스(class)          |
| ------------------ | ------------------- |
| 기본 접근 지정자 : public | 기본 접근 지정자 : private |
| 데이터 저장 중심          | 데이터 + 기능 캡슐화        |
| 단순 데이터 표현          | 객체지향 설계             |

---

# 💡 객체지향 프로그래밍(OOP)

객체지향 프로그래밍의 핵심 요소

1. 캡슐화 (Encapsulation)
2. 상속 (Inheritance)
3. 다형성 (Polymorphism)
4. 추상화 (Abstraction)

이번 강의에서는 캡슐화의 기초 개념을 살펴보았다.

---

# 🌍 C++로 개발된 대표 프로그램

| 프로그램              | 설명            |
| ----------------- | ------------- |
| Microsoft Windows | 운영체제 핵심 구성 요소 |
| Google Chrome     | 웹 브라우저        |
| Mozilla Firefox   | 웹 브라우저        |
| Adobe Photoshop   | 이미지 편집        |
| AutoCAD           | CAD 설계        |
| Blender           | 3D 모델링        |
| Unreal Engine     | 게임 엔진         |
| MySQL             | 데이터베이스        |
| TensorFlow        | 머신러닝 프레임워크    |
| Telegram Desktop  | 데스크톱 메신저      |

## 특징

C++는 다음과 같은 분야에서 널리 사용된다.

* 운영체제
* 브라우저
* 그래픽스
* 게임 엔진
* 데이터베이스
* 인공지능(AI)

---

# 📝 핵심 요약

* C++는 객체지향 프로그래밍 언어이다.
* C 언어와 높은 호환성을 가진다.
* 클래스는 데이터와 함수를 하나로 묶는다.
* private 멤버를 통해 캡슐화를 구현한다.
* 컴파일러는 소스 코드를 실행 파일로 변환한다.
* C++는 성능이 중요한 대규모 소프트웨어 개발에 많이 사용된다.

---

# 📌 참고 자료

## 수업 GitHub

[https://github.com/jcshim/cpp](https://github.com/jcshim/cpp)

## C++ 응용

[https://github.com/jcshim/cpp/blob/main/cpp_applications.md](https://github.com/jcshim/cpp/blob/main/cpp_applications.md)

## Classes Tutorial

[https://cplusplus.com/doc/tutorial/classes/](https://cplusplus.com/doc/tutorial/classes/)

---

# 📋 과제

## 개별 과제 1

[https://github.com/jcshim/cpp/blob/main/2026/report/p1.md](https://github.com/jcshim/cpp/blob/main/2026/report/p1.md)

## 추가 학습

클래스(Class)의 개념을 학습하고 구조체(struct)와의 차이점을 정리해보기

이 정도 형태면 GitHub에서 `01_introduction/README.md`로 저장했을 때 가독성이 상당히 좋고, 시험 직전 복습용으로도 바로 활용할 수 있습니다.
