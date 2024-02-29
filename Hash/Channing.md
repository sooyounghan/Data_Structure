-----
### Channing
-----

<div align = "center">
<img width="1096" alt="1" src="https://github.com/sooyounghan/Web/assets/34672301/4951e2b1-b87a-43e4-be4d-f1b16aee1cba">
</div>

1.  기본적으로 연결 가능한 노드를 해시 테이블에 저장
2.  해시 테이블에 동일한 해시값이 존재하는 경우 노드와 노드를 연결하여 저장
3. 시간복잡도
<div align = "center">
<img src="https://github.com/sooyounghan/Web/assets/34672301/6c56a9fc-9cda-4ad4-b958-f822efbccb75">
</div>

-----
### Channing 특징
-----
1. 키의 개수가 해시 테이블의 크기보다 큰 경우 테이블의 적재율이 100%을 넘어갈 수 있음
2. Linear Probing 방식은 Bucket에서 키를 찾는 방식이면, Channing 방식은 Bucket에 먼저 접근 후 노드의 리스트에서 키를 찾음
3. 그러나 키의 충돌이 빈번해 Bucket의 특정 인덱스에 키가 몰리면 탐색의 시간 복잡도는 O(n)

-----
### Channing Hash Fuction
-----
1. 보조 함수 없이 하나의 해시 함수로 구성
2. 해시 함수 (m은 해시 테이블의 크기)

       h'(k) -> (0, 1, 2, 3, ... , m - 1)

-----
### Channing Hash Table Search
-----
<div align = "center">
<img width="1096" alt="3" src="https://github.com/sooyounghan/Web/assets/34672301/38626445-74b0-4d1c-87f3-b3dcd808ee17">
</div>

1. 해시값을 이용해 Bucket에 접근 후 노드 리스트에서 키를 찾음
2. Open-Addressing과 다르게 Bucket에서만 탐색하는 것이 아닌, Bucket 접근 후 노드 리스트에서 키를 찾음
3. 노드 간의 연결이 없으면 탐색 종료

-----
### Channing Hash Table Insert
-----
1. 해시값을 이용해 Bucket에 접근 후 키를 삽입
2. 이미 버킷에 키를 존재하면, 연결 리스트를 통해 다음 노드에 삽입
3. 예제
<div align = "center">
<img width="1096" alt="4" src="https://github.com/sooyounghan/Web/assets/34672301/701ac0c5-a835-4dfe-95e9-f7f480dfe8b8">
</div>   

  - key1의 해시값은 24, 버킷의 24번 위치에 저장 시 공간이 비어있으면, 해당 위치에 키 삽입

<div align = "center">
<img width="1097" alt="5" src="https://github.com/sooyounghan/Web/assets/34672301/1c502574-bc1f-4580-9eab-10f1a0d0efc7">
</div>   

  - key4의 해시값은 24이며, 버킷의 24번 위치에 저장 시 이미 키가 존재하므로 노드 리스트의 마지막 위치에 키를 추가

4. 키 삽입의 문제
   - 키의 충돌이 빈번할 수록, 노드 리스트에서 키를 찾아야하는 탐색 횟수 증가
   - 중복된 키 : 이미 해시 테이블에 동일한 키가 존재한다면, 값만 덮어씀

-----
### Channing Hash Table Remove
-----
<div align = "center">
<img width="1098" alt="6" src="https://github.com/sooyounghan/Web/assets/34672301/f7a130b8-7185-48a3-a2cf-088c58d2acb9">
</div>   

1. 삭제할 key4의 해시값이 24이며, Bucket의 24번 위치에 접근하여 동일한 키가 존재하는지  노드 탐색

<div align = "center">
<img width="1096" alt="7" src="https://github.com/sooyounghan/Web/assets/34672301/984e5d34-56fd-4882-af4b-f2e4fe8675c8">
</div>   

2. 삭제할 키를 발견하면 노드의 연결을 끊어주는 방식으로 제거

<div align = "center">
<img width="1098" alt="8" src="https://github.com/sooyounghan/Web/assets/34672301/d9b39673-0cf7-4b9c-aeb6-5a9aec79121e">
</div>

3. key4를 삭제하면 위와 같은 상태

-----
### Channing 방식의 충돌을 줄이기 위한 방법
-----
1. 해시 함수는 해시 테이블의 크기와 연관이 있음
2. 충돌을 줄이기 위해 해시 테이블의 크기를 늘리는 방법 존재
3. 예시로, 최초 해시 테이블의 크기가 16으로 시작하여, 해시 테이블의 적재율(Load Factor)이 임계치를 넘으면,
   해시 테이블의 크기를 증가시켜서 확률적으로 충돌을 줄이는 방법 존재

-----
### Channing 구현
-----
     Collection Library의 LinkedList 이용


