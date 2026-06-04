# 14. C++ 응용 분야와 최신 표준의 발전

## 🎯 학습 목표

* DLib 얼굴 인식 알고리즘의 동작 원리를 이해한다.
* OpenCV와 DLib의 차이점을 이해한다.
* C++이 활용되는 대표 산업 분야를 이해한다.
* C++ 표준의 발전 과정을 이해한다.
* 효과적인 C++ 학습 방법을 이해한다.

---

# 📚 복습 : DLib 얼굴 인식 알고리즘

## DLib이란?

고성능 얼굴 인식(Face Recognition) 라이브러리

---

## 특징

```text
높은 정확도 (99% 이상)

C++ 기반

오픈소스

실시간 처리 가능
```

---

# 얼굴 인식 과정

## 1단계 : 얼굴 감지

### HOG

```text
Histogram of Oriented Gradients
```

사용

---

### 역할

```text
얼굴 위치 찾기
```

---

# 2단계 : 얼굴 정렬

## Face Alignment

```text
68개 랜드마크 검출
```

---

### 예

```text
눈

코

입

턱
```

위치 탐색

---

### 목적

```text
얼굴을 정면 기준으로 정렬
```

---

# 3단계 : 얼굴 인코딩

## CNN 사용

```text
Convolutional Neural Network
```

---

### 역할

얼굴을

```text
128차원 벡터
```

로 변환

---

# 4단계 : 비교

## 벡터 거리 계산

```text
128차원 벡터

↓

거리 계산

↓

같은 사람 여부 판단
```

---

# DLib 처리 과정

```text
이미지 입력
      ↓

얼굴 감지(HOG)
      ↓

얼굴 정렬
      ↓

CNN 인코딩
      ↓

128차원 벡터
      ↓

비교
      ↓

결과 출력
```

---

# 📚 DLib vs OpenCV

| 항목        | DLib  | OpenCV |
| --------- | ----- | ------ |
| 얼굴 인식 정확도 | 높음    | 보통     |
| 처리 속도     | 느림    | 빠름     |
| 활용 목적     | 얼굴 인식 | 영상 처리  |
| 난이도       | 높음    | 쉬움     |

---

## 한 줄 요약

```text
DLib = 더 정확

OpenCV = 더 빠름
```

---

# 📚 C++의 응용 분야

## 특징

C++은

```text
빠르고

강력하며

하드웨어 제어가 가능
```

한 언어이다.

---

# 1. 게임 개발

## 대표 분야

```text
Unreal Engine

Unity 내부 모듈
```

---

## 활용

```text
실시간 렌더링

물리 엔진

그래픽 처리
```

---

## 대표 사례

```text
배틀그라운드

포트나이트

AAA 게임
```

---

# 2. 운영체제 및 시스템 프로그램

## 활용

```text
Windows

Linux

드라이버

파일 시스템

컴파일러
```

---

## 특징

```text
메모리 직접 제어

매우 높은 성능
```

---

# 3. 임베디드 / 로봇 / IoT

## 활용

```text
자동차 ECU

드론

산업용 로봇

센서 제어
```

---

## 대표 예

```text
자율주행

스마트 기기
```

---

# 4. 인공지능 및 고속 연산

## 활용

```text
OpenCV

TensorFlow 내부

PyTorch 내부
```

---

## 특징

```text
GPU 연산

영상 처리

고속 수치 계산
```

---

# 5. 금융 및 서버

## 활용

```text
증권 거래 시스템

실시간 서버

네트워크 엔진
```

---

## 특징

```text
마이크로초 단위 성능 중요
```

---

# 6. 그래픽 / CAD / 시뮬레이션

## 활용

```text
3D 모델링

CAD

영상 편집기

과학 시뮬레이션
```

---

## 특징

```text
대규모 계산 처리
```

---

# 응용 분야 정리

```text
게임

운영체제

AI

로봇

금융

그래픽
```

---

# 📚 C++ 표준의 발전

## C++98

첫 공식 표준

---

### 특징

```text
STL 정착

vector

string
```

---

# C++11

## 가장 큰 변화

현대 C++ 시작

---

### 추가 기능

```cpp
auto

lambda

smart pointer

move semantics
```

---

# C++14

## 특징

```text
C++11 개선판
```

---

## 목적

```text
사용성 향상
```

---

# C++17

## 실무에서 많이 사용

---

### 추가 기능

```cpp
filesystem

structured binding

optional

variant
```

---

# C++20

## 혁신적인 변화

---

### 추가 기능

```cpp
concepts

ranges

coroutine

module
```

---

# C++23

## 특징

```text
표준 라이브러리 강화
```

---

## 목적

```text
더 편리한 개발
```

---

# C++26

## 개발 진행 중

---

### 방향

```text
성능 향상

안전성 강화

병렬 처리 강화
```

---

# 표준 발전 흐름

```text
C++98
   ↓

C++11
   ↓

C++14
   ↓

C++17
   ↓

C++20
   ↓

C++23
   ↓

C++26
```

---

# 📚 효율적인 C++ 학습 방법

## 1단계

### C 문법 기초

```cpp
변수

조건문

반복문

함수

배열
```

---

# 2단계

### C++ 핵심 문법

```cpp
class

object

reference

string

vector
```

---

# 3단계

### Modern C++

```cpp
auto

lambda

smart pointer

move semantics
```

---

# 4단계

### STL 학습

```cpp
vector

map

set

algorithm
```

---

# 5단계

### 프로젝트 제작

예

```text
계산기

콘솔 게임

파일 저장 프로그램
```

---

# 6단계

### 라이브러리 활용

```text
OpenCV

SQLite

Raylib

SFML

Unreal Engine
```

---

# 📌 핵심 정리

## DLib

```text
얼굴 인식 라이브러리
```

---

## 얼굴 인식 과정

```text
HOG
 ↓

랜드마크
 ↓

CNN
 ↓

128차원 벡터
 ↓

비교
```

---

## OpenCV

```text
영상 처리
```

---

## DLib

```text
얼굴 인식
```

---

## C++ 활용 분야

```text
게임

AI

로봇

운영체제

금융

그래픽
```

---

## 현대 C++ 시작

```text
C++11
```

---

## 실무 표준

```text
C++17
```

---

## 최신 표준

```text
C++20

C++23
```

---

# 🚨 시험 대비 암기 포인트

### DLib

```text
99% 이상 정확도
```

---

### 얼굴 인코딩

```text
128차원 벡터
```

---

### OpenCV

```text
빠름
```

---

### DLib

```text
정확함
```

---

### Modern C++

```cpp
auto

lambda

smart pointer

move semantics
```

---

### C++17

```cpp
filesystem

structured binding
```

---

### C++20

```cpp
concepts

ranges

coroutine

module
```

---

### C++ 핵심 응용 분야

```text
게임

AI

로봇

금융

시스템
```

---

# 📖 최종 한 줄 정리

```text
C++은 고성능을 유지하면서도
점점 더 안전하고 사용하기 쉬운 방향으로 발전하고 있으며,
게임, AI, 시스템, 로봇, 금융 등
성능이 중요한 거의 모든 분야에서 활용되는 핵심 언어이다.
```
