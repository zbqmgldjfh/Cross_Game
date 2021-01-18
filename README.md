# Cross_Game
 
## 컴퓨터공학 포토폴리오 김지우

<img src = "https://user-images.githubusercontent.com/60593969/104873887-e2cc3e00-5994-11eb-8f2e-d3d871790a66.gif" width="700px">

**간단한 C++ 연습용 게임 만들기**

## Class 설계
______________________
|Name|State|Behavior|
|:--:|:--:|--|
|**cPlayer**|위치정보(X, Y)| 상단 중심을 시작위치로 |
|**cLane**|장애물정보, 방향정보| 장애물 bool값 반환, 장애물 이동, 장애물 방향변경|
|**cGame**|종료, numberOfLane, 점수, 너비와 폭| 점수계산, 출력문:Draw(), 이동:Input(), 게임논리:Logic(), 실행:Run()|

## mian 내부의 중요 함수 4가지
```C
Draw(); // 화면에 출력하는 함수
Input(); // user의 input을 받아들이고 작용하는
Logic(); // 공의방향지정, paddle의 움직임, 종료조건등 논리부분
Run(); // 실행
```

**cGame_Base설계**

<img src = "https://user-images.githubusercontent.com/60593969/104868766-ae05ba00-5987-11eb-9712-fafc6da34642.png" width="350px">

