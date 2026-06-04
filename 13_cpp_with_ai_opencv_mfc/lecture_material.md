# 13. C++ with AI - OpenCV와 얼굴 인식

## 🎯 학습 목표

* OpenCV의 역할과 활용 분야를 이해한다.
* OpenCV를 이용하여 이미지를 불러오고 출력할 수 있다.
* OpenCV를 활용한 얼굴 검출(Face Detection)을 구현할 수 있다.
* AI와 컴퓨터 비전(Computer Vision)의 관계를 이해한다.
* C++ 기반 GUI 프레임워크(MFC, WinUI3)를 이해한다.

---

# 📚 C++ with AI

## 개념

C++를 활용하여

인공지능(AI) 및 영상 처리 프로그램을 개발하는 분야

---

## 주요 기술

```text
OpenCV

MFC

WinUI3
```

---

# 📚 OpenCV란?

## 개념

OpenCV(Open Source Computer Vision)

영상 처리와 컴퓨터 비전을 위한 오픈소스 라이브러리

---

## 역할

AI가 이미지를 분석하기 전에

이미지를 가공하고 필요한 정보를 추출한다.

---

# OpenCV와 AI의 역할

## OpenCV

```text
카메라 연결

이미지 로드

이미지 크기 조정

노이즈 제거

얼굴 위치 검출
```

---

## AI

```text
사람 판별

고양이 분류

자동차 분류

행동 분석

얼굴 인식
```

---

# 처리 과정

```text
카메라 / 이미지
        ↓

      OpenCV
        ↓

      AI 모델
        ↓

      인식 결과
```

---

# 📚 OpenCV 설치

## Visual Studio

NuGet 패키지 관리자 사용

---

## 설치 패키지

```text
OpenCV 4.2
```

---

# 📚 OpenCV 기본 예제

## 이미지 출력

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img =
        imread("jcshim.jpg");

    if(img.empty())
    {
        cout
        << "Image load failed"
        << endl;

        return -1;
    }

    namedWindow(
        "Image",
        WINDOW_AUTOSIZE
    );

    imshow(
        "Image",
        img
    );

    waitKey(0);

    destroyAllWindows();

    return 0;
}
```

---

# 코드 분석

## 이미지 읽기

```cpp
imread()
```

---

## 이미지 저장 객체

```cpp
Mat
```

---

## 창 생성

```cpp
namedWindow()
```

---

## 이미지 출력

```cpp
imshow()
```

---

## 키 입력 대기

```cpp
waitKey()
```

---

## 창 종료

```cpp
destroyAllWindows()
```

---

# 실행 결과

```text
jcshim.jpg

↓

화면에 출력
```

---

# 📚 얼굴 검출 (Face Detection)

## 개념

이미지 속 얼굴의 위치를 찾는 기술

---

## 사용 기술

```text
Haar Cascade
```

---

## 동작 과정

```text
이미지 입력
      ↓

흑백 변환
      ↓

얼굴 검출
      ↓

사각형 표시
```

---

# Haar Cascade 파일 준비

## PowerShell 실행

```powershell
Invoke-WebRequest `
-Uri "https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_default.xml" `
-OutFile "haarcascade_frontalface_default.xml"
```

---

## 생성 파일

```text
haarcascade_frontalface_default.xml
```

---

# 📚 얼굴 검출 예제

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    CascadeClassifier
        face_cascade;

    if(
        !face_cascade.load(
            "haarcascade_frontalface_default.xml"
        )
    )
    {
        cerr
        << "ERROR: Cascade Load Failed"
        << endl;

        return -1;
    }

    Mat img =
        imread("jcshim.jpg");

    if(img.empty())
    {
        cerr
        << "ERROR: Image Load Failed"
        << endl;

        return -1;
    }

    Mat gray;

    cvtColor(
        img,
        gray,
        COLOR_BGR2GRAY
    );

    vector<Rect> faces;

    face_cascade.detectMultiScale(
        gray,
        faces,
        1.1,
        4
    );

    for(Rect face : faces)
    {
        rectangle(
            img,
            face,
            Scalar(0,255,0),
            2
        );
    }

    namedWindow(
        "Face Detection",
        WINDOW_AUTOSIZE
    );

    imshow(
        "Face Detection",
        img
    );

    waitKey(0);

    destroyAllWindows();

    return 0;
}
```

---

# 코드 분석

## CascadeClassifier

```cpp
CascadeClassifier
```

얼굴 검출기 객체

---

## Cascade 파일 로드

```cpp
load()
```

---

## 흑백 변환

```cpp
cvtColor()
```

---

## 얼굴 찾기

```cpp
detectMultiScale()
```

---

## 사각형 그리기

```cpp
rectangle()
```

---

# 얼굴 검출 과정

```text
이미지
   ↓

imread()
   ↓

cvtColor()
   ↓

detectMultiScale()
   ↓

rectangle()
   ↓

imshow()
```

---

# 📚 Face Detection vs Face Recognition

## Face Detection

얼굴 위치 찾기

```text
어디에 얼굴이 있는가?
```

---

## Face Recognition

누구의 얼굴인지 식별

```text
누구인가?
```

---

# 비교

| 기능               | 목적       |
| ---------------- | -------- |
| Face Detection   | 얼굴 위치 검출 |
| Face Recognition | 사람 식별    |

---

# 📚 고급 얼굴 인식

## Dlib

대표적인 얼굴 인식 라이브러리

---

## 기능

```text
얼굴 검출

얼굴 특징점 추출

얼굴 인식
```

---

# 얼굴 인식 과정

```text
이미지 입력
       ↓

얼굴 검출
       ↓

특징점 추출
       ↓

벡터 생성
       ↓

사람 식별
```

---

# 📚 MFC

## 개념

Microsoft Foundation Class

---

## 특징

```text
Win32 API 기반

C++ GUI 프레임워크
```

---

## 활용

* 업무 프로그램
* 산업용 소프트웨어
* 관리 시스템

---

# 📚 WinUI 3

## 개념

Microsoft 최신 UI 프레임워크

---

## 특징

```text
Modern UI

Windows 11 최적화
```

---

## 활용

* 데스크톱 앱
* Windows App SDK
* 최신 Windows 애플리케이션

---

# GUI 기술 비교

| 기술        | 특징       |
| --------- | -------- |
| Win32 API | 저수준      |
| MFC       | Win32 래퍼 |
| WinUI3    | 최신 UI    |
| OpenCV    | 영상 처리    |

---

# 📚 AI + OpenCV 활용 분야

## 컴퓨터 비전

```text
객체 인식

얼굴 검출

번호판 인식
```

---

## 자율주행

```text
차선 인식

보행자 검출
```

---

## 보안 시스템

```text
얼굴 인증

출입 통제
```

---

## 의료 영상

```text
X-Ray 분석

MRI 분석
```

---

# 📌 핵심 정리

## OpenCV

```text
영상 처리 라이브러리
```

---

## 이미지 객체

```cpp
Mat
```

---

## 이미지 읽기

```cpp
imread()
```

---

## 이미지 출력

```cpp
imshow()
```

---

## 얼굴 검출기

```cpp
CascadeClassifier
```

---

## 얼굴 검출

```cpp
detectMultiScale()
```

---

## 사각형 그리기

```cpp
rectangle()
```

---

## GUI

```text
MFC

WinUI3
```

---

# 🚨 시험 대비 암기 포인트

### OpenCV

```text
컴퓨터 비전 라이브러리
```

---

### 이미지 로드

```cpp
imread()
```

---

### 이미지 저장 객체

```cpp
Mat
```

---

### 얼굴 검출

```cpp
detectMultiScale()
```

---

### 얼굴 검출기

```cpp
CascadeClassifier
```

---

### 흑백 변환

```cpp
cvtColor()
```

---

### 얼굴 검출

```text
Face Detection
```

---

### 얼굴 인식

```text
Face Recognition
```

---

### GUI 프레임워크

```text
MFC

WinUI3
```

---

# 📖 최종 기말고사 범위 정리

## 객체지향 프로그래밍

* 클래스
* 객체
* 상속
* 다형성

---

## Modern C++

* 람다 함수
* 구조적 바인딩
* enum class
* optional
* variant
* function

---

## STL

* vector
* map
* set
* stack
* queue
* sort
* find

---

## 자원 관리

* RAII
* Smart Pointer
* Move Semantics

---

## 응용 분야

* Graphics
* SQLite
* OpenCV
* AI
* Linux

C++를 이용한 현대적인 응용 프로그램 개발의 전체 흐름을 이해한다.
