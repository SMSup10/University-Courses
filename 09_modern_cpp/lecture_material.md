# 09. 현대 C++ 문법 - 더 안전하고 간결한 코드

## 🎯 학습 목표

* enum class를 사용하여 타입 안전성을 높인다.
* std::optional을 활용하여 "값이 없을 수 있음"을 표현한다.
* std::variant를 이용하여 여러 타입을 안전하게 저장한다.
* std::function을 이용해 함수를 객체처럼 다룬다.
* 현대 C++의 핵심 철학인 안전성(Safety)과 가독성(Readability)을 이해한다.

---

# 📚 복습 : STL 알고리즘과 람다

## for_each 알고리즘

STL 알고리즘 중

모든 요소를 순회하며 특정 작업을 수행하는 함수

---

## 예제 1

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;

    v.push_back(4);
    v.push_back(5);

    for_each(
        v.begin(),
        v.end(),
        [](int n)
        {
            cout << n << " ";
        }
    );

    return 0;
}
```

---

## 실행 결과

```text
4 5
```

---

# 예제 2 : 객체와 for_each

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CRect
{
    int w, h;

public:

    CRect(int w, int h)
        : w(w), h(h)
    {
    }

    void Area()
    {
        cout << w * h << endl;
    }
};

int main()
{
    vector<CRect> v;

    v.push_back(CRect(1,2));
    v.push_back(CRect(2,3));

    for_each(
        v.begin(),
        v.end(),
        [](CRect r)
        {
            r.Area();
        }
    );

    return 0;
}
```

---

## 실행 결과

```text
2
6
```

---

# 예제 3 : 반복자 사용

```cpp
vector<CRect> v =
{
    CRect(1,2),
    CRect(2,3)
};

v.push_back(CRect(4,5));

for(auto it = v.begin();
    it != v.end();
    it++)
{
    it->Area();
}
```

---

# 📚 enum class (강타입 열거형)

## 기존 enum의 문제점

```cpp
enum Status
{
    OK,
    Error
};

enum Color
{
    Red,
    Green,
    Blue
};
```

---

## 문제 1 : 숫자 비교 가능

```cpp
Status s = OK;

if(s == 0)
{
}
```

가독성이 떨어진다.

---

## 문제 2 : 다른 enum과 비교 가능

```cpp
if(s == Red)
{
}
```

논리적으로 잘못된 비교

---

# 📚 enum class

## 개념

타입 안전성을 강화한 열거형

---

## 예제

```cpp
enum class Status
{
    OK,
    Error
};

enum class Color
{
    Red,
    Green,
    Blue
};
```

---

## 사용 방법

```cpp
Status s =
    Status::OK;
```

---

## 특징

다른 타입과 비교 불가

```cpp
if(s == 0)
{
}
```

컴파일 에러

---

```cpp
if(s == Color::Red)
{
}
```

컴파일 에러

---

# 💡 enum vs enum class

| 항목     | enum | enum class |
| ------ | ---- | ---------- |
| 타입 안전성 | 낮음   | 높음         |
| 정수 변환  | 가능   | 불가능        |
| 이름 충돌  | 가능   | 불가능        |
| 사용 권장  | X    | O          |

---

# 📚 std::optional

## 개념

값이 있을 수도 있고

없을 수도 있는 상황을 표현하는 클래스

---

기존 방식

```cpp
return -1;
```

---

```cpp
return nullptr;
```

---

문제점

```text
왜 -1인가?
왜 nullptr인가?
```

의도가 불명확

---

# 🖥️ optional 예제

```cpp
#include <optional>

std::optional<int>
GetScore(string name)
{
    if(name == "홍길동")
    {
        return 100;
    }

    return std::nullopt;
}
```

---

# 사용 예

```cpp
auto res =
    GetScore("심청");
```

---

값 존재 여부 확인

```cpp
if(res.has_value())
{
    cout << res.value();
}
else
{
    cout << "기록 없음";
}
```

---

## 실행 결과

```text
기록 없음
```

---

# optional 핵심 함수

## 값 존재 확인

```cpp
has_value()
```

---

## 값 가져오기

```cpp
value()
```

---

## 빈 값

```cpp
std::nullopt
```

---

# 📚 std::variant

## 개념

여러 타입 중 하나를 저장할 수 있는 클래스

---

## 기존 union 문제

```cpp
union
{
    int a;
    double b;
};
```

타입 안정성 부족

---

# 🖥️ variant 예제

```cpp
#include <variant>
#include <string>

using namespace std;

int main()
{
    variant<int,string> v = 10;

    cout << get<int>(v)
         << endl;

    v = "Hello World";

    if(
        holds_alternative<string>(v)
    )
    {
        cout
            << get<string>(v)
            << endl;
    }

    return 0;
}
```

---

## 실행 결과

```text
10
Hello World
```

---

# variant 핵심 함수

## 현재 타입 확인

```cpp
holds_alternative<T>()
```

---

## 값 꺼내기

```cpp
get<T>()
```

---

# 예시

```cpp
variant<int,string> v;
```

가능

```cpp
10
"Hello"
```

---

불가능

```cpp
int와 string 동시 저장
```

---

# 📚 std::function

## 개념

함수를 저장하는 객체

---

## 특징

다음 모두 저장 가능

* 일반 함수
* 람다 함수
* 멤버 함수
* 함수 객체(Functor)

---

# 🖥️ 기본 예제

```cpp
#include <functional>

void Hello()
{
    cout << "Hi!";
}

int main()
{
    std::function<void()>
        func = Hello;

    func();

    return 0;
}
```

---

## 실행 결과

```text
Hi!
```

---

# 람다 함수 저장

```cpp
func =
[]()
{
    cout
        << "Hello from Lambda!";
};
```

---

```cpp
func();
```

---

## 실행 결과

```text
Hello from Lambda!
```

---

# std::function 문법 분석

```cpp
std::function<void()>
```

의 의미

```text
반환형 : void

매개변수 : 없음
```

---

예

```cpp
std::function<int(int)>
```

의 의미

```text
정수 반환

정수 1개 입력
```

---

# 📚 현대 C++의 핵심 철학

## 1. Safety (안전성)

개발자의 실수를

컴파일 시점에 잡아낸다.

---

예

```cpp
enum class
optional
variant
```

---

## 2. Readability (가독성)

코드를 읽기 쉽게 만든다.

---

예

```cpp
auto
structured binding
```

---

## 3. Intent (의도 표현)

코드를 읽는 사람이

의도를 쉽게 이해할 수 있도록 만든다.

---

예

```cpp
optional
```

↓

```text
이 값은 없을 수도 있음
```

---

# 📌 핵심 정리

## enum class

```cpp
enum class Status
{
    OK,
    Error
};
```

타입 안전성 강화

---

## optional

```cpp
optional<int>
```

값이 없을 수 있음

---

## variant

```cpp
variant<int,string>
```

여러 타입 중 하나 저장

---

## function

```cpp
function<void()>
```

함수 저장 가능

---

## for_each

```cpp
for_each(
    begin,
    end,
    lambda
);
```

---

# 🚨 시험 대비 암기 포인트

### enum class

```cpp
Status::OK
```

---

### optional

```cpp
has_value()

value()

nullopt
```

---

### variant

```cpp
get<T>()

holds_alternative<T>()
```

---

### function

```cpp
function<void()>
```

---

### STL 알고리즘

```cpp
for_each()

sort()

find()
```

---

### 반복자

```cpp
begin()

end()
```

---

# 📖 다음 강의

## Modern C++ 심화

* constexpr
* structured binding
* RAII
* Move Semantics
* 스마트 포인터 심화

현대 C++의 성능 최적화와 자원 관리 기법을 학습한다.
