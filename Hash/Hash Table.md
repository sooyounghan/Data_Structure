------
### Hash Table = Associated Array, Dictionary, Symbol Table
------
<div align = "center">
<img width="1099" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/67c1e604-f7f3-422f-b532-80f79d4079c0">
</div>

1. 키와 값의 구조를 가진 데이터를 저장해 해시 함수를 이용해 키 값을 해시값으로 반환
2. 해시 값을 해시 테이블의 인덱스로 사용하는 자료구조
3. 해시 함수를 이용하므로 해시값의 충돌이 발생할 수 있음
4. 좋은 해시 함수란, 충돌 가능성을 낮추고, 최대한 고른 값을 가진 함수
5. 충돌 발생 시 어떻게 처리하냐에 따라 해시 테이블의 성능이 달라짐

------
### Hash Table을 사용하는 이유
------   
1. 키와 값을 이용하는 자료 구조가 필요할 시 사용
2. 평균적으로 시간 복잡도 O(1)의 탐색 성능을 가지므로 빠른 탐색이 필요할 때 사용

------
### Hash Table의 구성 
------    
1. Backet
  - 해시값을 인덱스로 하여 접근할 수 있는 배열
  - 배열 접근의 시간 복잡도는 O(1)로 인덱스 위치에 찾으려는 키가 존재하면 가장 빠르게 찾음

2. Entry
  : 해시 테이블은 키와 값을 저장하는 구조이므로 노드를 이용해 키와 값을 저장

3. Hash Fuction
   - 해시 함수와 보조 해시 함수를 이용해 해시 값을 구할 수 있음
   - 좋은 해시 함수는 충돌 가능성을 줄여줌
  
------
### Hash Table 충돌에 대응하기 위한 방법 
------
1. Channing 기법
2. Open-Addressing 기법

------
### Channing
------
<div align = "center">
<img width="1098" alt="kr60qbu5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/9a0a5998-0152-4b98-82bb-7ec8ce9cf42c">
</div>

1. 키와 데이터를 삽입 시 동일한 해시값의 키가 존재하는 경우 노드를 연결하는 방식으로 저장
2. 키와 개수와 버킷의 크기가 크면 해시 테이블의 적재율이 100% 초과
3. 노드 간 연결이 많을 경우 탐색 시간이 늘어날 수 있음

         예) 3번 인덱스에 100개의 노드가 연결, 찾으려는 키가 3번에 존재
             : 최악의 경우 시간 복잡도 O(100)이 될 수 있음
             - 이 문제 완화를 위해 적재율에 따라 버킷의 크기를 늘림
             - 노드 간의 연결을 선형적 방식이 아닌 비선형적 구조로 변경

------
### Open-Addressing
------
1. 버킷에 키가 1:1로 저장되는 방식
2. Channing과 달리 해시 테이블 외부에 연결된 노드가 존재하지 않음
3. 이미 동일한 해시값으로 해시 테이블에 키가 존재하면, 보조 해시 함수의 규칙에 의해 빈 공간을 조사(Probing)해 저장
4. 빈 공간이 존재하지 않으면 키를 저장할 수 없으므로 해시 테이블의 적재율을 체크하고 버킷의 크기 늘림
   
------
### Linear-Probing
------
<div align = "center">
<img width="1099" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/fd6e789b-5eeb-4b72-a636-2eab5aa2b038">
</div>    

  - 선형적 특성을 가지고 있는 해시 함수를 이용해 조사하는 방식
  - 키를 찾거나 삽입할 위치를 찾거나, 삭제할 키를 찾을 때 순차적 접근하는 방식

1. 보조 해시 함수 값의 범위 (m은 해시 테이블의 크기)
```java
h'(key) -> {0, 1, 2, 3, .. m - 1}
```

  - 보조 해시 함수 h'(key)는 키를 0부터 m-1까지의 범위의 해시값으로 변경
    
2. 해시 함수 (m은 해시 테이블의 크기)
```java
h(key, i) = (h'(key) + i) mod m
```
  - 해시 함수 h(key, i)를 이용해 해시값을 구함

3. 최초 조사 시 T[h'(key)]에서 탐색 후, i를 1씩 증가 시키며 조사하기 때문에 선형적 방법
4. 특정 영역에 키가 몰리는 군집 문제로 탐색 성능 저하 발생

------
### Quadratic-Probing
------
<div align = "center">
<img width="1098" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b0fa03a2-70dc-419f-bc52-7cb849038d94">
</div>    


  - Linear Probing과 유사하나 c1과 c2를 이용한 양의 보조 상수를 추가해 비선형적으로 조사

1. 보조 해시 함수 값의 범위 (m은 해시 테이블의 크기)
```java
h'(key) -> {0, 1, 2, 3, .. m - 1}
```

2. 해시 함수 (m은 해시 테이블의 크기)
```java
h(key, i) = (h'(key) + (c1 * i) + (c2 * i^2)) mod m
```

3. 최초 조사 시 T[h'(key)]에서 탐색 후 i를 1씩 증가 시키되, c1값과 c2값에 의해 두 번째 탐색 위치 달라짐
4. 적절한 c1과 c2의 값을 정해야함
5. Linear Probing 방식보다 좀 더 가벼운 군집 문제 발생

------
### Quadratic-Probing
------
<div align = "center">
<img width="1097" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/36898a5e-b614-41e1-a752-a973ac44e9d1">
</div>  

1. 해시 함수 (m은 해시 테이블의 크기)

```java
 h(key, i) = (h1(key) + (i * h2(key))) mod m
```

2. 군집 문제 완화하기 위해 두 개의 해시 보조 해시 함수를 이용해 최대한 균등하게 분포하도록 하는 방법
3. 최초 조사 시 T[h'(key)]에서 탐색 후 i를 1씩 증가시키되, h2(key) 보조 해시 함수에 의해 두 번째 탐색 위치 달라짐
4. Quadratic Probing 보다 좀 더 가벼운 군집 문제 발생
