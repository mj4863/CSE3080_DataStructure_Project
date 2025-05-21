# CSE3080 과제

이 저장소에는 Data Structures 과목(CSE3080) 과제 1(문자열 패턴 매칭)과 과제 2(최소 신장 트리) 구현 코드가 포함되어 있다.

## 프로젝트 구조

```
├── cse3080_hw1_학번
│   ├── problem1
│   │   ├── Makefile
│   │   ├── probgen.c
│   │   ├── hw1_naive.c
│   │   ├── hw1_kmp.c
│   └── problem2
│       ├── Makefile
│       ├── hw1_problem2.c
└── cse3080_hw2_학번
    ├── fp1.c
    ├── Makefile
    └── input_large.txt
```

## 과제 1: 문자열 패턴 매칭

* **문제**: 두 개의 문자열(str, pat)에서 `pat`의 모든 등장 위치와 횟수 출력
* **구현**:

  * `hw1_naive` (O(mn) 나이브 알고리즘)
  * `hw1_kmp` (O(m+n) KMP 알고리즘)
  * `hw1_problem2` (문자열 최대 제곱 반복 수 계산)
* **빌드 및 실행**:

  ```bash
  cd cse3080_hw1_학번/problem1
  make
  ./hw1_naive < string.txt pattern.txt
  ./hw1_kmp  < string.txt pattern.txt

  cd ../problem2
  make
  ./hw1_problem2 < input.txt
  ```

## 과제 2: 최소 신장 트리 (MST)

* **문제**: 가중 무향 그래프의 최소 신장 트리를 Kruskal 알고리즘으로 계산
* **구현**: `fp1.c` (Kruskal + 힙 + Disjoint Set)
* **빌드 및 실행**:

  ```bash
  cd cse3080_hw2_학번
  make
  ./fp1 input.txt
  ```

