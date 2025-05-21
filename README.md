# CSE3080 과제 모음

이 저장소에는 Data Structures 과목(CSE3080)의 과제 1과 과제 2 구현 코드가 포함되어 있다.

## 프로젝트 구성

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
    └── input_large.txt (예시)
```

## 과제 1: 문자열 패턴 매칭

* **문제 설명**: 두 개의 문자열(str, pat)을 입력받아 `pat`이 `str`에 나타나는 모든 시작 위치와 등장 횟수를 출력한다.
* **프로그램**:

  * `hw1_naive`: O(mn) 나이브 알고리즘 기반
  * `hw1_kmp`: O(m+n) KMP 알고리즘 기반
  * `hw1_problem2`: 문자열의 최대 제곱 반복 수 계산 (KMP 활용)
* **입출력**:

  * 입력 파일: `string.txt`, `pattern.txt` (각각 단일 문자열 또는 여러 줄)
  * 출력 파일: `result_naive.txt`, `result_kmp.txt`, `result.txt`
* **빌드 및 실행**:

  ```bash
  cd cse3080_hw1_학번/problem1
  make
  # 실행 예시
  ./hw1_naive
  ./hw1_kmp

  cd ../problem2
  make
  ./hw1_problem2
  ```

## 과제 2: 최소 신장 트리 (MST)

* **문제 설명**: 가중 무향 그래프의 최소 신장 트리를 Kruskal 알고리즘으로 계산하고 결과를 파일로 출력한다.
* **프로그램**: `fp1` (Kruskal + 힙 + Disjoint Set)
* **입출력**:

  * 실행 인자: `./fp1 input_filename`
  * 입력 파일 형식: 첫 줄 정점 개수, 둘째 줄 간선 개수, 이후 `u v w` 형태 데이터
  * 출력 파일: `fp1_result.txt`
* **빌드 및 실행**:

  ```bash
  cd cse3080_hw2_학번
  make
  ./fp1 input.txt
  ```

## 요구사항

* C99 표준 준수
* Makefile 제공
* 최대 입력 크기 지원 (문자열 ≤ 10^7, 정점 ≤ 10,000, 간선 ≤ 5×10^7)
* 입력 파일 미존재 시 에러 메시지 출력 후 종료

## 디렉터리 구조 설명

* `cse3080_hw1_학번/problem1`: 문자열 패턴 매칭 과제 코드
* `cse3080_hw1_학번/problem2`: 문자열 제곱 반복 과제 코드
* `cse3080_hw2_학번`: MST 과제 코드

## 기여 방법

1. 이슈(issue) 등록 후 토론한다.
2. 풀 리퀘스트(PR)를 제출한다.
3. 코드 리뷰 후 병합한다.

## 라이선스

MIT License

## 연락처

* 이메일: [your\_email@example.com](mailto:your_email@example.com)
* GitHub: [https://github.com/your\_username](https://github.com/your_username)
