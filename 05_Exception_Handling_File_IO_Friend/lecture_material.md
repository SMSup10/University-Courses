# 05. 예외 처리(Exception Handling), 파일 입출력(File I/O), Friend 키워드

## 🎯 학습 목표

* C++ 예외 처리(Exception Handling)의 개념을 이해한다.
* try, throw, catch의 동작 원리를 학습한다.
* 표준 예외 클래스와 사용자 정의 예외를 사용할 수 있다.
* 파일 입출력(File I/O)을 구현할 수 있다.
* friend 키워드의 역할을 이해한다.

---

# 📚 C++ 예외 처리 (Exception Handling)

## 예외 처리란?

예외 처리(Exception Handling)란

프로그램 실행 중 발생하는 오류를 안전하게 처리하는 방법이다.

---

### 축구 경기 비유

```text
try   → 경기 진행

throw → 반칙 발생

catch → 심판이 조치
```

정상적으로 실행되다가 문제가 발생하면

프로그램이 즉시 예외 처리 코드로 이동한다.

---

# ⚡ 예외 처리의 3단계

## 1. try

문제가 발생할 수 있는 코드를 실행

```cpp
try
{
}
```

---

## 2. throw

오류 발생 신호 전송

```cpp
throw 값;
```

---

## 3. catch

예외를 받아서 처리

```cpp
catch(...)
{
}
```

---

# 🖥️ 실습 1 : 0으로 나누기 예외 처리

```cpp
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 0;

    try
    {
        if (b == 0)
        {
            throw "0으로 나눌 수 없어요!";
        }

        cout << a / b << endl;
    }
    catch (const char* msg)
    {
        cout << "에러 메시지 : "
             << msg << endl;
    }

    return 0;
}
```

---

## 실행 결과

```text
에러 메시지 : 0으로 나눌 수 없어요!
```

---

# 🔄 스택 풀기 (Stack Unwinding)

## 개념

함수 호출 도중 예외가 발생하면

현재 함수와 중간 함수들을 모두 종료하고

예외를 처리할 수 있는 catch 블록까지 이동하는 과정

---

### 예시

```text
A()
 ↓
B()
 ↓
C()
```

C에서 예외 발생

```text
C 종료
 ↓
B 종료
 ↓
A의 catch 이동
```

---

## 특징

스택이 정리되는 과정에서

객체의 소멸자가 자동 호출된다.

따라서 메모리 누수를 방지할 수 있다.

---

# 📚 표준 예외 클래스

## 개념

C++은 자주 발생하는 오류를

미리 클래스 형태로 제공한다.

---

## 대표 예외

```cpp
out_of_range
runtime_error
logic_error
invalid_argument
```

---

# 🖥️ 실습 2 : out_of_range

```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {
        throw out_of_range(
            "번호가 너무 커요!"
        );
    }
    catch(const out_of_range& e)
    {
        cout << "무슨 에러? : "
             << e.what()
             << endl;
    }

    return 0;
}
```

---

## 실행 결과

```text
무슨 에러? : 번호가 너무 커요!
```

---

# 🔍 what() 함수

```cpp
e.what()
```

예외 객체 내부에 저장된

에러 메시지를 반환한다.

---

# 📚 사용자 정의 예외

## 개념

기본 제공 예외로 부족할 경우

직접 예외 클래스를 만들 수 있다.

---

# 🖥️ 사용자 정의 예외 예제

```cpp
#include <iostream>
#include <exception>

using namespace std;

class MyError : public exception
{
public:

    const char* what() const noexcept override
    {
        return "나만의 특별한 에러 발생!";
    }
};

int main()
{
    try
    {
        throw MyError();
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }
}
```

---

## 실행 결과

```text
나만의 특별한 에러 발생!
```

---

# 💡 예외 처리 실무 팁

## 1. 참조로 받기

좋은 방법

```cpp
catch(const exception& e)
```

---

나쁜 방법

```cpp
catch(exception e)
```

객체 복사가 발생한다.

---

## 2. 소멸자에서 예외 금지

```cpp
~Class()
{
    throw ...;
}
```

권장하지 않는다.

프로그램이 비정상 종료될 수 있다.

---

## 3. RAII 사용

```cpp
unique_ptr
shared_ptr
```

예외 발생 시에도

자동으로 메모리를 정리한다.

---

# 📌 예외 처리 핵심 정리

```text
try
 ↓
throw
 ↓
catch
```

문제가 발생하면

catch 블록으로 즉시 이동한다.

---

# 📚 파일 입출력 (File I/O)

## 파일 입출력이란?

프로그램 데이터를 파일에 저장하거나

파일에서 데이터를 읽어오는 기능

---

## 필요한 헤더

```cpp
#include <fstream>
```

---

# 파일 스트림 종류

| 클래스      | 역할      |
| -------- | ------- |
| ofstream | 파일 쓰기   |
| ifstream | 파일 읽기   |
| fstream  | 읽기 + 쓰기 |

---

# 🖥️ 파일 쓰기 예제

```cpp
#include <fstream>

using namespace std;

int main()
{
    ofstream outFile("test.txt");

    if(outFile.is_open())
    {
        outFile << "Hello C++ File!"
                << endl;

        outFile << 2026
                << endl;

        outFile.close();
    }

    return 0;
}
```

---

# 🖥️ 파일 읽기 예제

```cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line;

    ifstream inFile("test.txt");

    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            cout << line
                 << endl;
        }

        inFile.close();
    }

    return 0;
}
```

---

## 실행 결과

```text
Hello C++ File!
2026
```

---

# ⚡ 파일 입출력 핵심 함수

## 파일 열기

```cpp
open()
```

---

## 파일 닫기

```cpp
close()
```

---

## 파일 확인

```cpp
is_open()
```

---

## 한 줄 읽기

```cpp
getline()
```

---

# 📌 파일 입출력 핵심 정리

쓰기

```cpp
ofstream
```

---

읽기

```cpp
ifstream
```

---

읽고 쓰기

```cpp
fstream
```

---

# 📚 Friend 키워드

## Friend란?

private 멤버에

특정 함수나 클래스가 직접 접근할 수 있도록 허용하는 기능

---

# 기본 문법

```cpp
friend 함수;
```

---

## 예제

```cpp
#include <iostream>

using namespace std;

class CMe
{
private:

    int x = 10;

    friend int main();
};

int main()
{
    CMe a;

    cout << a.x << endl;

    return 0;
}
```

---

## 실행 결과

```text
10
```

---

# 🔍 Friend 분석

원래는

```cpp
private:
    int x;
```

외부 접근 불가

---

하지만

```cpp
friend int main();
```

선언으로

main() 함수에게만 특별 권한을 부여

---

# ⚠️ Friend 사용 시 주의점

장점

* 특정 함수 접근 허용
* 연산자 오버로딩 구현 시 자주 사용

---

단점

* 캡슐화 약화
* private 보호 기능 감소

---

실무에서는 최소한으로 사용하는 것이 좋다.

---

# 📝 핵심 정리

## 예외 처리

```cpp
try
throw
catch
```

---

## 표준 예외

```cpp
out_of_range
runtime_error
invalid_argument
```

---

## 사용자 정의 예외

```cpp
class MyError
    : public exception
{
};
```

---

## 파일 입출력

```cpp
ofstream
ifstream
fstream
```

---

## Friend

```cpp
friend 함수명;
```

private 접근 허용

---

# 🚨 시험 대비 암기 포인트

### 예외 처리 순서

```text
try
 ↓
throw
 ↓
catch
```

---

### 표준 예외

```cpp
out_of_range
```

---

### 에러 메시지

```cpp
e.what()
```

---

### 파일 쓰기

```cpp
ofstream
```

---

### 파일 읽기

```cpp
ifstream
```

---

### Friend

```cpp
friend int main();
```

private 접근 허용

---

# 📖 다음 강의

## 복사 생성자(Copy Constructor)와 깊은 복사(Deep Copy)

* 얕은 복사(Shallow Copy)
* 깊은 복사(Deep Copy)
* 동적 메모리 관리
* 자원 관리(Resource Management)

객체 복사 시 발생하는 문제와 해결 방법을 학습한다.
