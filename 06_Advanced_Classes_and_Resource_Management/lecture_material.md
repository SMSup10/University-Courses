# 06. 클래스 심화 - 리소스의 효율적 관리

## 🎯 학습 목표

* 멤버 초기화 리스트(Member Initializer List)를 이해한다.
* 복사 생성자(Copy Constructor)의 역할을 이해한다.
* 대입 연산자 오버로딩을 구현할 수 있다.
* 이동 생성자(Move Constructor)의 개념을 이해한다.
* Move Semantics를 통해 성능을 향상시키는 방법을 학습한다.
* RAII와 이동 의미론의 관계를 이해한다.

---

# 📚 리소스(Resource)란?

리소스(Resource)란

프로그램이 사용하는 자원을 의미한다.

대표적인 리소스

* 동적 메모리(new)
* 파일(File)
* 소켓(Socket)
* 데이터베이스 연결(DB Connection)

---

## 왜 관리가 중요한가?

잘못 관리하면

* 메모리 누수(Memory Leak)
* 중복 해제(Double Delete)
* 프로그램 비정상 종료

등의 문제가 발생한다.

---

# 📚 멤버 초기화 리스트 (Member Initializer List)

## 개념

생성자 본문(`{}`)이 실행되기 전에

멤버 변수를 초기화하는 문법

---

## 기본 문법

```cpp
클래스명(매개변수)
    : 멤버1(값),
      멤버2(값)
{
}
```

---

## 예제

```cpp
class Player
{
    string name;
    const int id;

public:

    Player(string n, int i)
        : name(n), id(i)
    {
    }
};
```

---

# 💡 멤버 초기화 리스트를 사용하는 이유

## 효율적

기존 방식

```cpp
Player(string n, int i)
{
    name = n;
    id = i;
}
```

---

초기화 리스트 방식

```cpp
Player(string n, int i)
    : name(n), id(i)
{
}
```

불필요한 대입 과정이 사라진다.

---

## 반드시 필요한 경우

### const 멤버

```cpp
const int id;
```

---

### 참조자 멤버

```cpp
int& ref;
```

---

이들은 생성 시 반드시 초기화해야 한다.

---

# 📚 복사 생성자 (Copy Constructor)

## 개념

객체를 복사할 때 호출되는 생성자

---

## 기본 문법

```cpp
클래스명(const 클래스명& other)
{
}
```

---

## 호출되는 경우

```cpp
Buffer b1;

Buffer b2 = b1;
```

---

# 📚 깊은 복사 (Deep Copy)

## 문제점

포인터 멤버가 있는 객체를 단순 복사하면

두 객체가 같은 메모리를 가리키게 된다.

---

예

```cpp
data
 ↓
[100]
```

---

결과

```text
객체 A
   ↓
 메모리

객체 B
   ↑
```

---

소멸 시

```cpp
delete
delete
```

가 두 번 발생하여 오류가 발생한다.

---

# 🖥️ 복사 생성자 예제

```cpp
class Buffer
{
    int* data;

public:

    Buffer()
    {
        data = new int[10];
    }

    ~Buffer()
    {
        delete[] data;
    }

    Buffer(const Buffer& other)
    {
        data = new int[10];

        for(int i = 0; i < 10; i++)
        {
            data[i] = other.data[i];
        }
    }
};
```

---

# 💡 Deep Copy 결과

```text
원본 객체
   ↓
메모리 A

복사 객체
   ↓
메모리 B
```

서로 다른 메모리를 사용한다.

---

# 📚 대입 연산자 오버로딩

## 개념

이미 생성된 객체에

대입(`=`)이 발생할 때 호출된다.

---

## 기본 문법

```cpp
클래스명& operator=
(
    const 클래스명& other
)
{
}
```

---

# 🖥️ 예제

```cpp
Buffer& operator=
(
    const Buffer& other
)
{
    if(this != &other)
    {
        for(int i = 0; i < 10; i++)
        {
            data[i] =
                other.data[i];
        }
    }

    return *this;
}
```

---

# ⚡ 자기 자신 대입 방지

```cpp
if(this != &other)
```

예

```cpp
buffer = buffer;
```

같은 상황을 방지한다.

---

# 📚 이동 의미론 (Move Semantics)

## 개념

복사하지 않고

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
원본 자원 가져오기

원본 비우기
```

빠름

---

# 📚 std::move

## 역할

```cpp
std::move(obj)
```

의 의미

```text
이 객체는 이제 사용하지 않을 예정

자원을 가져가도 됨
```

---

# 📚 우값 참조 (Rvalue Reference)

## 문법

```cpp
&&
```

---

예

```cpp
MoveBox&& other
```

---

이동 생성자에서 사용된다.

---

# 🖥️ 이동 생성자 예제

```cpp
class MoveBox
{
    int* data;

public:

    MoveBox()
    {
        data = new int[100];
    }

    ~MoveBox()
    {
        delete data;
    }

    MoveBox
    (
        MoveBox&& other
    ) noexcept

        : data(other.data)
    {
        other.data = nullptr;

        cout
        << "자원 이동 완료!"
        << endl;
    }
};
```

---

# 사용 예제

```cpp
MoveBox a;

MoveBox b =
    std::move(a);
```

---

# 이동 과정

## Before

```text
a
 ↓
메모리
```

---

## Move

```text
b
 ↓
메모리

a
 ↓
nullptr
```

---

## 결과

메모리 복사 없음

주소만 이동

---

# 🚀 Copy vs Move 비교

| 구분  | Copy  | Move   |
| --- | ----- | ------ |
| 속도  | 느림    | 빠름     |
| 메모리 | 추가 생성 | 생성 안 함 |
| 원본  | 유지    | 비워짐    |
| 비용  | 큼     | 작음     |

---

# 📚 RAII와 Move Semantics

## RAII

```text
생성자
 ↓
자원 획득

소멸자
 ↓
자원 해제
```

---

## 스마트 포인터와 이동

```cpp
unique_ptr
```

은 복사할 수 없다.

---

가능

```cpp
unique_ptr<int> p2 =
    std::move(p1);
```

---

불가능

```cpp
unique_ptr<int> p2 = p1;
```

---

Move Semantics를 이용해

소유권을 이동한다.

---

# 📌 핵심 정리

## 멤버 초기화 리스트

```cpp
Player(string n, int i)
    : name(n),
      id(i)
{
}
```

---

## 복사 생성자

```cpp
Buffer(const Buffer& other)
```

객체 복사 시 호출

---

## 깊은 복사

새로운 메모리를 생성하여 복사

---

## 대입 연산자

```cpp
operator=
```

대입 시 호출

---

## 이동 생성자

```cpp
MoveBox(MoveBox&& other)
```

자원을 이동

---

## std::move

```cpp
std::move(obj)
```

이동 가능 상태로 변경

---

## 우값 참조

```cpp
&&
```

Move Semantics의 핵심

---

# 🚨 시험 대비 암기 포인트

### 멤버 초기화 리스트

```cpp
: member(value)
```

---

### 복사 생성자

```cpp
Class(const Class& other)
```

---

### 대입 연산자

```cpp
operator=
```

---

### 이동 생성자

```cpp
Class(Class&& other)
```

---

### 이동 의미론

```cpp
std::move()
```

---

### 우값 참조

```cpp
&&
```

---

### Copy vs Move

```text
Copy → 복사

Move → 소유권 이전
```

---

# 📖 다음 강의

## STL 심화와 알고리즘

* vector
* map
* set
* iterator
* sort
* find
* for_each

템플릿 기반 STL 컨테이너와 알고리즘 활용법을 학습한다.
