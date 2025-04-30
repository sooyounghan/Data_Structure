-----
### LinkedList의 get(int index) 메서드와 반복문
-----
: LinkedList는 Index라는 개념이 존재하지 않음 (가상의 노드 순서로 index를 지칭)
```java
int sum = 0;

for (int i = 0; i < 100000; i++) {
    sum += linkedList.get(i);
}
```
<div align = "center">
<img width="640" alt="다운로드 (2)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a0c585b1-4bc4-4c0b-b012-7d611fbc9d42">
</div>   
: LinkedList는 이중 연결리스트로 되어 있으므로 head부터 시작해 앞에서부터 N번째 노드를 찾음   

  -> 즉, 항상 앞에서부터 n번째 노드를 찾기 때문에 반복문을 사용하면 순간 탐색 횟수가 제곱수에 가까워짐   

-----
### LinkedList의 get(int index) 메서드와 반복문의 실행시간
-----
<div align = "center">
<img width="321" alt="다운로드 (3)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/42aebeba-83d4-4798-b604-261c1385cfd9">
</div>
: 약 평균 4초에 가까운 시간으로 최악의 시간에 가까움

-----
### Iterator
-----
1. 컬렉션에 저장된 요소를 순차적으로 접근(탐색)하는 데 사용되는 인터페이스
2. 컬렉션에 저장된 요소들을 읽어오는 방법을 표준화 -> Iterator인터페이스
3. Collection 인터페이스를 상속받는 List와 Set 인터페이스에서도 iterator() 사용 가능

       * boolean hasNext()//읽어올 요소가 남아있는지 확인한다. 있으면 true, 없으면 false
       * Object next() : 다음 요소를 읽어옴, next() 호출 전, hasNext()를 호출해서 확인하는것이 안전
       * void remove()  : next()로 읽어온 요소를 삭제

<동일 조건에서 실행 시간>
<div align = "center">
<img width="321" alt="다운로드 (4)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/e7dd1be5-5dce-49ab-8619-3c1a4bd43692">
</div>   

-----
### 배열과 연결리스트의 차이
-----
<div align = "center">
<img width="640" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f235caac-a087-4ad8-8954-67d2fb86e0ea">
</div>   

1. ArrayList(배열 기반) : 배열을 사용하므로 특정 데이터를 index로 접근하기 쉬움
   > 메모리에 올라갈 때부터 배열 공간은 붙어서 메모리에 적재
3. LinkedList : Heap 메모리 공간의 어느 위치에 저장될지 모름, 단순히 참조값을 이용해 연결되어 저장

