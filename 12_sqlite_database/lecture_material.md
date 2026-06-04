# 12. SQLite 데이터베이스와 C++ 연동

## 🎯 학습 목표

* 데이터베이스(Database)의 기본 개념을 이해한다.
* 테이블(Table), 행(Row), 열(Column)의 구조를 이해한다.
* SQL의 기본 명령어를 학습한다.
* SQLite의 특징과 장점을 이해한다.
* C++ 프로그램에서 SQLite 데이터베이스를 생성하고 사용할 수 있다.
* sqlite3_open(), sqlite3_exec(), sqlite3_close() 함수의 역할을 이해한다.

---

# 📚 데이터베이스(Database)란?

## 개념

데이터를 체계적으로 저장하고 관리하는 시스템

---

## 활용 예

* 학생 관리 시스템
* 회원 관리 시스템
* 쇼핑몰
* 게임 서버
* 은행 시스템

---

# 📚 테이블(Table)

## 개념

행(Row)과 열(Column)로 이루어진 표 형태의 데이터 저장소

---

## 예시

### STUDENT 테이블

| ID | NAME  | AGE |
| -- | ----- | --- |
| 1  | Alice | 20  |
| 2  | Bob   | 21  |

---

## 구성 요소

### 열(Column)

```text
ID
NAME
AGE
```

데이터 종류 정의

---

### 행(Row)

```text
1 Alice 20
2 Bob 21
```

실제 데이터

---

# 📚 SQL (Structured Query Language)

## 개념

데이터베이스를 조작하는 언어

---

# 주요 명령어

## CREATE

테이블 생성

```sql
CREATE TABLE STUDENT
(
    ID INT,
    NAME TEXT
);
```

---

## INSERT

데이터 추가

```sql
INSERT INTO STUDENT
VALUES
(
    1,
    'Alice'
);
```

---

## SELECT

데이터 조회

```sql
SELECT *
FROM STUDENT;
```

---

## UPDATE

데이터 수정

```sql
UPDATE STUDENT
SET NAME = 'Kim'
WHERE ID = 1;
```

---

## DELETE

데이터 삭제

```sql
DELETE
FROM STUDENT
WHERE ID = 1;
```

---

# 📚 SQLite

## 개념

가볍고 간단한 파일 기반 데이터베이스

---

## 특징

### 서버 불필요

```text
MySQL
 ↓
서버 필요

SQLite
 ↓
서버 불필요
```

---

### 파일 기반

```text
test.db
```

하나의 파일에 데이터 저장

---

### 설치 간단

별도의 DB 서버 설치 필요 없음

---

### 학습용 최적

소규모 프로젝트에 적합

---

# SQLite 동작 과정

```text
DB 열기
    ↓

테이블 생성
    ↓

데이터 추가
    ↓

데이터 조회
    ↓

DB 닫기
```

---

# 📚 대표적인 데이터베이스

| DBMS       | 특징            |
| ---------- | ------------- |
| SQLite     | 학습 및 소규모 프로젝트 |
| MySQL      | 대표적인 오픈소스 DB  |
| MariaDB    | MySQL 기반      |
| SQL Server | Microsoft DB  |

---

# 비교

## SQLite

```text
파일 기반
```

---

## MySQL / MariaDB

```text
클라이언트 - 서버 구조
```

---

## SQL Server

```text
Windows 친화적
```

---

# 📚 SQLite with C++

## SQLite Amalgamation

SQLite 공식 홈페이지에서

```text
sqlite3.c
sqlite3.h
```

두 파일만 프로젝트에 추가하면 사용 가능

---

## 장점

```text
설치 과정 없음

즉시 사용 가능
```

---

# 📚 SQLite 소스 준비

## 다운로드

SQLite 공식 홈페이지

[SQLite Download Page](https://www.sqlite.org/download.html?utm_source=chatgpt.com)

---

## 다운로드 파일

```text
sqlite-amalgamation-xxxx.zip
```

---

## 필요한 파일

```text
sqlite3.c

sqlite3.h
```

---

# 📚 Visual Studio 프로젝트 설정

## 프로젝트 생성

```text
C++ Empty Project

또는

Console App
```

---

## 파일 추가

### 소스 파일

```text
sqlite3.c
```

---

### 헤더 파일

```text
sqlite3.h
```

---

## Visual Studio

```text
소스 파일

우클릭
 ↓

추가
 ↓

기존 항목
 ↓

sqlite3.c
```

---

```text
헤더 파일

우클릭
 ↓

추가
 ↓

기존 항목
 ↓

sqlite3.h
```

---

# 📚 SQLite 기본 API

## sqlite3_open()

데이터베이스 열기

---

## sqlite3_exec()

SQL 실행

---

## sqlite3_close()

데이터베이스 닫기

---

# SQLite 프로그램 흐름

```text
sqlite3_open()
      ↓

sqlite3_exec()
      ↓

sqlite3_close()
```

---

# 🖥️ 실습 : 데이터베이스 생성

## main.cpp

```cpp
#include <iostream>
#include "sqlite3.h"

int main()
{
    sqlite3* db;
    char* errMsg = nullptr;

    int rc =
        sqlite3_open(
            "test.db",
            &db
        );

    if(rc != SQLITE_OK)
    {
        std::cout
        << "DB 열기 실패 : "
        << sqlite3_errmsg(db)
        << std::endl;

        return 1;
    }
    else
    {
        std::cout
        << "DB 연결 성공!"
        << std::endl;
    }

    const char* sql =
        "CREATE TABLE IF NOT EXISTS STUDENT("
        "ID INT PRIMARY KEY NOT NULL,"
        "NAME TEXT NOT NULL);";

    rc =
        sqlite3_exec(
            db,
            sql,
            nullptr,
            nullptr,
            &errMsg
        );

    if(rc != SQLITE_OK)
    {
        std::cout
        << "SQL 에러 : "
        << errMsg
        << std::endl;

        sqlite3_free(errMsg);
    }
    else
    {
        std::cout
        << "STUDENT 테이블 생성 성공!"
        << std::endl;
    }

    sqlite3_close(db);

    return 0;
}
```

---

# 실행 결과

```text
DB 연결 성공!

STUDENT 테이블 생성 성공!
```

---

# 생성되는 파일

```text
test.db
```

---

# 📚 코드 분석

## 데이터베이스 열기

```cpp
sqlite3_open(
    "test.db",
    &db
);
```

---

파일이 없으면

자동 생성

---

## 테이블 생성

```sql
CREATE TABLE IF NOT EXISTS
```

---

이미 존재하면

재생성하지 않음

---

## SQL 실행

```cpp
sqlite3_exec()
```

---

## 데이터베이스 종료

```cpp
sqlite3_close()
```

---

# 📚 SQLite 핵심 함수

## DB 열기

```cpp
sqlite3_open()
```

---

## SQL 실행

```cpp
sqlite3_exec()
```

---

## 오류 메시지

```cpp
sqlite3_errmsg()
```

---

## 메모리 해제

```cpp
sqlite3_free()
```

---

## DB 닫기

```cpp
sqlite3_close()
```

---

# 📌 핵심 정리

## 데이터베이스

```text
데이터 저장 시스템
```

---

## 테이블

```text
행(Row)

열(Column)
```

---

## SQL

```sql
CREATE

INSERT

SELECT

UPDATE

DELETE
```

---

## SQLite

```text
파일 기반 DB
```

---

## 주요 파일

```text
sqlite3.c

sqlite3.h
```

---

## DB 생성

```cpp
sqlite3_open()
```

---

## SQL 실행

```cpp
sqlite3_exec()
```

---

## DB 종료

```cpp
sqlite3_close()
```

---

# 🚨 시험 대비 암기 포인트

### 테이블

```text
Row

Column
```

---

### SQL 5대 명령어

```sql
CREATE

INSERT

SELECT

UPDATE

DELETE
```

---

### SQLite 특징

```text
파일 기반

서버 불필요
```

---

### DB 열기

```cpp
sqlite3_open()
```

---

### SQL 실행

```cpp
sqlite3_exec()
```

---

### DB 닫기

```cpp
sqlite3_close()
```

---

### 생성 파일

```text
test.db
```

---

# 📖 기말고사 대비 최종 정리

## 핵심 주제

* 클래스와 객체
* 함수 오버로딩
* 상속과 다형성
* 연산자 오버로딩
* 템플릿
* STL
* 예외 처리
* 파일 입출력
* 스마트 포인터
* RAII
* Move Semantics
* Modern C++
* Graphics
* SQLite

이제 1강부터 12강까지의 핵심 개념을 종합적으로 정리하며 기말고사 대비를 진행한다.
