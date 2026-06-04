# 07. 템플릿과 STL - 범용적이고 강력한 도구상자

## 🎯 학습 목표

* 클래스 템플릿(Class Template)을 이해한다.
* 템플릿 특수화(Template Specialization)를 학습한다.
* STL 연관 컨테이너(Map, Set)의 구조를 이해한다.
* Stack과 Queue의 동작 원리를 이해한다.
* STL 알고리즘을 활용하여 데이터를 효율적으로 처리한다.
* 반복자(Iterator)의 역할을 이해한다.

---

# 📚 템플릿 (Template)

## 템플릿이란?

템플릿은

자료형(Type)에 의존하지 않는

범용(Generic) 코드를 작성하기 위한 기능이다.

---

## 템플릿의 장점

### 코드 재사용

```cpp
int용 함수
double용 함수
string용 함수
```

를 따로 만들 필요가 없다.

---

### 타입 안전성

컴파일러가 타입을 검사해준다.

---

### 컴파일 타임 최적화

실행 중(Runtime)이 아니라

컴파일 시점에 코드가 생성된다.

---

# 📦 클래스 템플릿

## 기본 문법

```cpp
template <typename T>

class Box
{
};
```

---

# 🖥️ 클래스 템플릿 예제

```cpp
template <typename T>

class Box
{
private:

    T data;

public:

    void print()
    {
        cout
            << "데이터 : "
            << data
            << endl;
    }
};
```

---

## 사용 예

```cpp
Box<int> intBox;

Box<double> doubleBox;

Box<string> stringBox;
```

---

# 📚 템플릿 특수화 (Template Specialization)

## 개념

특정 자료형만

다르게 동작하도록 만드는 기능

---

## 일반 템플릿

```cpp
template <typename T>

class Box
{
};
```

---

## 특수화

```cpp
template <>

class Box<char*>
{
};
```

---

# 🖥️ 템플릿 특수화 예제

```cpp
template <typename T>

class Box
{
public:

    void print()
    {
        cout
            << "일반 데이터"
            << endl;
    }
};

template <>

class Box<char*>
{
public:

    void print()
    {
        cout
            << "문자열 전용 출력 모드"
            << endl;
    }
};
```

---

# 💡 템플릿 특수화의 목적

일반적인 경우

```cpp
Box<int>
Box<double>
```

---

특정 타입

```cpp
Box<char*>
```

만 별도로 처리

---

# 📚 STL (Standard Template Library)

## STL이란?

C++ 표준 라이브러리에서 제공하는

자료구조와 알고리즘 모음

---

## 구성 요소

```text
STL

├─ Container
├─ Iterator
├─ Algorithm
└─ Function Object
```

---

# 📚 연관 컨테이너 (Associative Container)

## 특징

데이터를 검색하기 쉽게 저장한다.

---

대표 컨테이너

```cpp
map
unordered_map
set
```

---

# 📚 std::map

## 특징

Key - Value 형태 저장

---

예

```cpp
map<string, int>
```

---

저장 형태

```text
이름 → 점수

Kim → 90
Lee → 85
Park → 100
```

---

## 내부 구조

```text
Red-Black Tree
```

---

## 특징

* 자동 정렬
* 중복 Key 불가
* 검색 가능

---

## 시간 복잡도

```text
O(log N)
```

---

# 🖥️ map 예제

```cpp
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> score;

    score["Kim"] = 90;
    score["Lee"] = 80;

    cout << score["Kim"];

    return 0;
}
```

---

# 📚 std::unordered_map

## 특징

해시 테이블(Hash Table) 기반

---

## 장점

검색 속도가 매우 빠름

---

## 시간 복잡도

평균

```text
O(1)
```

---

## 단점

정렬되지 않음

---

# 비교

| 컨테이너          | 내부 구조          | 정렬 | 검색       |
| ------------- | -------------- | -- | -------- |
| map           | Red-Black Tree | O  | O(log N) |
| unordered_map | Hash Table     | X  | O(1)     |

---

# 📚 std::set

## 특징

중복 없는 데이터 집합

---

예

```cpp
set<int>
```

---

저장

```cpp
1
3
2
3
```

---

결과

```cpp
1
2
3
```

중복 제거

---

## 시간 복잡도

```text
O(log N)
```

---

# 🖥️ set 예제

```cpp
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;

    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    for(auto n : s)
    {
        cout << n << " ";
    }

    return 0;
}
```

---

## 실행 결과

```text
1 2 3
```

---

# 📚 어댑터 컨테이너

## 개념

특정 규칙을 강제하는 자료구조

---

대표 컨테이너

```cpp
stack
queue
```

---

# 📚 Stack

## 구조

```text
Last In First Out
```

---

약어

```text
LIFO
```

---

예

```text
3
2
1
```

꺼내기

```text
3
2
1
```

---

비유

```text
접시 쌓기
```

---

# 🖥️ Stack 예제

```cpp
#include <stack>

stack<int> st;

st.push(10);
st.push(20);

cout << st.top();
```

---

## 출력

```text
20
```

---

# 📚 Queue

## 구조

```text
First In First Out
```

---

약어

```text
FIFO
```

---

예

```text
1
2
3
```

꺼내기

```text
1
2
3
```

---

비유

```text
줄 서기
```

---

# 🖥️ Queue 예제

```cpp
#include <queue>

queue<int> q;

q.push(10);
q.push(20);

cout << q.front();
```

---

## 출력

```text
10
```

---

# 📚 STL 알고리즘

## 알고리즘이란?

컨테이너 데이터를 처리하는 함수

---

대표 알고리즘

```cpp
sort
find
for_each
```

---

# 🖥️ Sort 예제

```cpp
#include <algorithm>
#include <vector>

vector<int> v =
{
    4, 2, 5, 1, 3
};

sort(
    v.begin(),
    v.end()
);
```

---

## 결과

```text
1 2 3 4 5
```

---

# 🖥️ Find 예제

```cpp
auto it =
find(
    v.begin(),
    v.end(),
    3
);
```

---

찾은 경우

```cpp
if(it != v.end())
{
    cout << "찾았다!";
}
```

---

## 출력

```text
찾았다!
```

---

# 📚 반복자 (Iterator)

## 개념

컨테이너와 알고리즘을 연결하는 다리

---

대표 함수

```cpp
begin()
end()
```

---

예

```cpp
v.begin()
v.end()
```

---

## 역할

```text
컨테이너
     ↓
 Iterator
     ↓
알고리즘
```

---

예

```cpp
sort(
    v.begin(),
    v.end()
);
```

---

# ⚡ 시간 복잡도 비교

| 자료구조          | 검색       |
| ------------- | -------- |
| vector        | O(N)     |
| map           | O(log N) |
| unordered_map | O(1)     |

---

# 💡 STL 선택 기준

## 순서대로 저장

```cpp
vector
```

---

## Key-Value 저장

```cpp
map
unordered_map
```

---

## 중복 제거

```cpp
set
```

---

## LIFO

```cpp
stack
```

---

## FIFO

```cpp
queue
```

---

# 📌 핵심 정리

## 클래스 템플릿

```cpp
template <typename T>
```

---

## 템플릿 특수화

```cpp
template <>
```

---

## map

```cpp
Key - Value
```

자동 정렬

---

## unordered_map

```cpp
Hash Table
```

고속 검색

---

## set

```cpp
중복 제거
```

---

## stack

```text
LIFO
```

---

## queue

```text
FIFO
```

---

## 알고리즘

```cpp
sort()
find()
for_each()
```

---

## 반복자

```cpp
begin()
end()
```

---

# 🚨 시험 대비 암기 포인트

### map

```text
O(log N)
자동 정렬
```

---

### unordered_map

```text
O(1)
정렬 없음
```

---

### set

```text
중복 제거
```

---

### stack

```text
LIFO
```

---

### queue

```text
FIFO
```

---

### 알고리즘

```cpp
sort()
find()
```

---

### 반복자

```cpp
v.begin()
v.end()
```

---

# 📖 다음 강의

## Modern C++ 핵심 기능

* enum class
* optional
* variant
* constexpr
* structured binding

현대 C++의 타입 안정성과 생산성을 높여주는 기능들을 학습한다.
