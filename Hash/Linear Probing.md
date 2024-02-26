------
### Linear Probing
------

<div align = "center">
<img width="1097" alt="1" src="https://github.com/sooyounghan/Web/assets/34672301/0830bba4-064c-43cc-9969-082eba4d71d1">
</div>

<div align = "center">
<img width="277" alt="2" src="https://github.com/sooyounghan/Web/assets/34672301/0bcb2f01-3d31-4e4e-a6db-794229ac4834">
</div>   

1. open-addressing 중 하나로서, 간단하지만 군집 문제가 가장 심함
2. 버킷의 크기가 증가되지 않는 이상 키의 적재율은 100%를 넘을 수 없음
3. 최대로 저장할 수 있는 키의 개수 : 버킷의 크기
4. 충돌로 인한 키의 군집 문제가 빈번히 발생해 탐색 시간이 O(1)의 경우보다 O(N)의 경우가 많음

------
### Hash Fuction
------   

1. Linear Probing의 해시 함수는 보조 해시 함수와 추가적인 연산을 통해 탐색할 키의 위치나 삽입될 키의 위치, 삭제할 키의 위치 조사(Probing)
2. 보조 해시 함수 값의 범위 (m은 해시 테이블의 크기)
```jsp
h'(k) -> {0, 1, 2, 3, ... m - 1}
```
3. 해시 함수 (m은 해시 테이블의 크기)
```jsp
h(k, i) = (h'(k) + i) mod m
```

------
### Linear Probing 탐색
------   

1. 해시 테이블에 접근해 동일한 키를 발견할 때까지 T[h'(k)] 부터 T[m-1]까지 탐색
2. 키가 존재하지 않으면 다시 T[0]부터 T[h'(k) - 1]을 조사
3. 탐색 시 빈 공간을 만나면 탐색을 종료
4. 동일한 키가 존재하면 값을 반환

< 예제 >   
<div align = "center">
<img width="1098" alt="3" src="https://github.com/sooyounghan/Web/assets/34672301/d1a6cb8f-5ce4-4e8f-823a-b6fe6e7397ba">
</div>  

- 탐색할 키가 key 6이고, hash 값이 2일 때, 먼저 버킷의 2번 인덱스에서 시작
- 버킷의 2번 인덱스에서 시작해 해당 키가 존재하는지 확인
- 동일한 키가 아니면 i를 1씩 증가하며, 동일한 키를 발견할 때 까지 찾음

< 예제 2 >
<div align = "center">
<img width="1098" alt="0" src="https://github.com/sooyounghan/Web/assets/34672301/0cedbce0-f6e1-49ff-9c8a-e07df7264204">
</div>  

- 탐색할 키가 key 10이고, 해시 값이 3이면, 먼저 버킷의 3번 인덱스에서 시작
- 버킷의 3번 인덱스에서 시작해 해당 키가 존재하는지 확인
- 동일한 키가 아니면 i를 1씩 증가시키며 동일한 키를 발견할 때 까지 찾음
- 전체를 조사할 때 키가 발견되지 않으면, 키가 존재하지 않음

------
### Linear Probing 삽입
------   

1. 해시 테이블 인덱스에 동일한 키가 저장 되어 있으면, 값을 덮어씀
2. 동일한 키가 존재하지 않으면, 빈 공간을 발견할 때까지 조사 후 키와 값을 저장
3. 빈 공간이 나올 때 까지 T[h'(k)]부터 T[m-1]까지 탐색
4. 빈 공간이 나올 때 까지 T[0]부터 T[h'(k) - 1]까지 탐색
5. 빈 공간 발견 시 해당 위치에 삽입

< 예제 >
<div align = "center">
<img width="1097" alt="-1" src="https://github.com/sooyounghan/Web/assets/34672301/ac396425-8ff6-4240-a6d1-38cd51cf397a">
</div>

- key 1부터 key 6까지 순차적으로 키를 삽입한다고 가정
- 해시 함수에 의해 맨 처음 key 1의 해시값이 0이면 버킷의 0번 위치에 저장

<div align = "center">
<img width="1097" alt="5" src="https://github.com/sooyounghan/Web/assets/34672301/2eb1cafa-e26d-4e8a-bb54-88d7e6cea387">
</div>   

- 두 번째로 key2의 해시값이 1이면, 버킷의 1번 위치에 저장

<div align = "center">
<img width="1098" alt="6" src="https://github.com/sooyounghan/Web/assets/34672301/e7794234-27c5-47d2-b346-f64ea053faf1">
</div>   

- key3의 해시값이 0이며, 버킷의 0번 위치에 저장하려고 하나 이미 키가 존재
- 다음 위치로 넘어가 키가 존재하는지 확인
- 그러나 1번 위치에도 키가 존재하므로, 또 다음 위치로 넘어가 키가 존재하는지 확인
- 빈 공간이면 해당 위치에 키를 저장

<div align = "center">
<img width="1096" alt="7" src="https://github.com/sooyounghan/Web/assets/34672301/71b0ec49-c988-4913-b964-838d9b90a3d5">
</div>   

- key4의 해시값은 3이며, 버킷의 3번 위치에 저장

<div align = "center">
<img width="1096" alt="8" src="https://github.com/sooyounghan/Web/assets/34672301/230b97c2-79b9-4118-9fb7-380281845d2d">
</div>

- key5의 해시값이 1이며, 버킷의 1번 위치에 저장하려고 하나 이미 키가 존재
- 빈 공간을 찾을 때 까지 순차적으로 이동해 빈 공간에 키를 삽입

<div align = "center">
<img width="1097" alt="9" src="https://github.com/sooyounghan/Web/assets/34672301/43a837f8-d9e8-4fce-9e06-43dba1c894d0">
</div>

- key6의 해시값이 2이며, 버킷의 2번 위치에 저장하려고 하나 이미 키가 존재
- 빈 공간을 찾을 때까지 빈 공간에 키를 삽입


------
### Linear Probing 삽입의 문제
------   
1. 키의 충돌이 빈번할 수록 키의 분포가 특정 영역에 군집되는 현상 발생
2. 탐색 특성 상 키를 찾거나 빈 공간을 만날 때까지 탐색하는데 군집으로 인해
   빈 공간이 존재하지 않을 수 있기 때문에 탐색 횟수가 많아질 수 있음
3. 중복된 키 : 버킷에 이미 동일한 키가 존재한다면 값만 덮어씀

<div align = "center">
<img width="1097" alt="10" src="https://github.com/sooyounghan/Web/assets/34672301/f70e73cc-d61c-4d60-8873-4a57c2f930c6">
</div>
