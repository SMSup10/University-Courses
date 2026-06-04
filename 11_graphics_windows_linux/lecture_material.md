# 11. C++ Graphics와 Windows 프로그래밍

## 🎯 학습 목표

* Windows 프로그래밍의 기본 구조를 이해한다.
* Win32 API를 이용하여 GUI 프로그램을 작성할 수 있다.
* GDI(Graphics Device Interface)를 활용한 그래픽 출력 방법을 학습한다.
* 더블 버퍼링(Double Buffering)의 개념을 이해한다.
* OpenGL, DirectX, Vulkan 등 그래픽 API의 차이를 이해한다.
* 게임 엔진 및 웹 그래픽 기술의 관계를 이해한다.

---

# 📚 복습

## C++ in Linux

### WSL 실행

```bash
wsl
```

---

### 컴파일

```bash
g++ test.cpp
```

---

### 실행

```bash
./a.out
```

---

## Prompt(명령행)

프로그램 실행 시

사용자로부터 인자를 전달받는 기능

예

```bash
program.exe 10 20
```

---

# 📚 Windows Programming

## Windows API

Windows 운영체제가 제공하는 함수 집합

---

## 가장 쉬운 GUI 프로그램

### MessageBox

```cpp
#include <windows.h>

int main()
{
    MessageBox(
        NULL,
        L"안녕하세요!",
        L"메시지",
        MB_OK
    );

    return 0;
}
```

---

## 실행 결과

```text
[메시지]

안녕하세요!

[확인]
```

---

# 📚 C++ Graphics

## 그래픽 프로그래밍 계층 구조

```text
게임 엔진
   ↑

프레임워크
   ↑

그래픽 API
   ↑

그래픽 하드웨어
```

---

# 1. 하드웨어 가속 API (저수준)

## 개념

그래픽 카드(GPU)를 직접 제어하는 API

---

## 대표 API

### OpenGL

```text
크로스 플랫폼
```

---

### DirectX (Direct3D)

```text
Windows 전용
```

---

### Vulkan

```text
차세대 고성능 API
```

---

### Metal

```text
Apple 전용
```

---

# API 비교

| API     | 플랫폼                   |
| ------- | --------------------- |
| OpenGL  | Windows / Linux / Mac |
| DirectX | Windows               |
| Vulkan  | Cross Platform        |
| Metal   | macOS / iOS           |

---

# 📚 2. Windows 표준 그래픽

## GDI (Graphics Device Interface)

Windows 기본 그래픽 라이브러리

---

## 주요 기능

* 선 그리기
* 도형 그리기
* 텍스트 출력
* 비트맵 출력

---

## 관련 기술

```text
GDI
GDI+
DirectX
```

---

# 🖥️ 실습 : 마우스로 펜 그리기

## 프로그램 동작

```text
마우스 왼쪽 버튼 클릭

↓

마우스 이동

↓

선 그리기
```

---

## 핵심 메시지

### WM_LBUTTONDOWN

```text
마우스 버튼 누름
```

---

### WM_MOUSEMOVE

```text
마우스 이동
```

---

### WM_PAINT

```text
화면 다시 그리기
```

---

### WM_DESTROY

```text
프로그램 종료
```

---

# 핵심 그래픽 함수

## 펜 생성

```cpp
CreatePen()
```

---

## 선 시작 위치

```cpp
MoveToEx()
```

---

## 선 그리기

```cpp
LineTo()
```

---

## 화면 갱신

```cpp
InvalidateRect()
```

---

## 비트맵 복사

```cpp
BitBlt()
```

---

# 📚 더블 버퍼링 (Double Buffering)

## 문제점

직접 화면에 그리면

```text
깜빡임(Flickering)
```

이 발생한다.

---

## 해결 방법

보이지 않는 메모리 화면에 먼저 그림

```text
Back Buffer
    ↓
화면 복사
    ↓
Screen
```

---

## 사용 함수

```cpp
CreateCompatibleDC()
```

---

```cpp
CreateCompatibleBitmap()
```

---

```cpp
BitBlt()
```

---

# 📚 Device Context (DC)

## 개념

Windows에서 그림을 그리는 도화지

---

## 타입

```cpp
HDC
```

---

## 생성

```cpp
GetDC()
```

---

## 해제

```cpp
ReleaseDC()
```

---

# 📚 Window Procedure

## WndProc

Windows 메시지를 처리하는 함수

---

## 기본 구조

```cpp
LRESULT CALLBACK
WndProc(
    HWND hwnd,
    UINT msg,
    WPARAM wp,
    LPARAM lp
)
{
}
```

---

## 역할

```text
마우스

키보드

창 크기 변경

종료
```

등의 이벤트 처리

---

# 📚 3. 프레임워크 및 라이브러리

## 개념

그래픽 API 사용을 쉽게 만들어주는 도구

---

## 대표 라이브러리

### Raylib

```text
학습용으로 매우 쉬움
```

---

### SFML

```text
2D 게임 개발
```

---

### SDL

```text
멀티 플랫폼
```

---

### ImGui

```text
개발용 UI
```

---

# 비교

| 라이브러리  | 특징     |
| ------ | ------ |
| Raylib | 쉬움     |
| SFML   | 2D 게임  |
| SDL    | 범용     |
| ImGui  | GUI 개발 |

---

# 📚 4. 게임 엔진

## Unreal Engine

대표적인 AAA 게임 엔진

---

## 특징

```text
C++ 기반
```

---

## 활용 분야

* 게임 개발
* 영화 제작
* 시뮬레이션
* 메타버스

---

# 게임 엔진 구조

```text
게임 코드
    ↓

Unreal Engine
    ↓

DirectX/OpenGL
    ↓

GPU
```

---

# 📚 OpenGL

## 특징

* 크로스 플랫폼
* 오래된 표준
* 교육용으로 많이 사용

---

## 활용

* CAD
* 시뮬레이션
* 게임
* 과학 시각화

---

# 📚 DirectX 11

## 특징

* Microsoft 제공
* Windows 전용
* 게임 개발 표준

---

## 구성

```text
Direct3D
DirectSound
DirectInput
```

---

# 📚 5. Web Graphics

## p5.js

JavaScript 기반 그래픽 라이브러리

---

## 내부 기술

```text
WebGL
```

---

## WebGL

```text
OpenGL ES 기반
```

---

# three.js

JavaScript 3D 라이브러리

---

## 내부 기술

```text
WebGPU
```

---

## WebGPU 지원 API

```text
Metal

Vulkan

DirectX 12
```

---

# 그래픽 기술 계층 구조

```text
three.js
     ↓
WebGPU
     ↓
Metal / Vulkan / D3D12

---------------------

p5.js
     ↓
WebGL
     ↓
OpenGL ES
```

---

# 📌 핵심 정리

## Windows API

```cpp
MessageBox()
```

---

## Device Context

```cpp
HDC
```

---

## Window Procedure

```cpp
WndProc()
```

---

## 더블 버퍼링

```cpp
CreateCompatibleDC()

CreateCompatibleBitmap()

BitBlt()
```

---

## GDI

```text
Windows 기본 그래픽
```

---

## OpenGL

```text
Cross Platform
```

---

## DirectX

```text
Windows 전용
```

---

## Unreal Engine

```text
C++ 기반 게임 엔진
```

---

## Web Graphics

```text
p5.js → WebGL

three.js → WebGPU
```

---

# 🚨 시험 대비 암기 포인트

### 메시지 박스

```cpp
MessageBox()
```

---

### 디바이스 컨텍스트

```cpp
HDC
```

---

### 마우스 이벤트

```cpp
WM_LBUTTONDOWN

WM_MOUSEMOVE
```

---

### 화면 그리기

```cpp
WM_PAINT
```

---

### 더블 버퍼링

```cpp
BitBlt()
```

---

### 그래픽 API

```text
OpenGL

DirectX

Vulkan

Metal
```

---

### 게임 엔진

```text
Unreal Engine
```

---

# 📖 다음 강의

## SQLite 데이터베이스 프로그래밍

* sqlite3_open()
* sqlite3_exec()
* sqlite3_prepare()
* sqlite3_close()
* CRUD 구현

C++ 프로그램과 데이터베이스를 연결하여 데이터를 저장하고 관리하는 방법을 학습한다.
