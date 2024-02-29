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
4. 빈 공간이 나올 때 까지 T[0]부터 T[h'(k - 1)]까지 탐색
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


------
### Linear Probing 삭제
------   
<div align = "center">
<img width="1097" alt="10" src="https://github.com/sooyounghan/Web/assets/34672301/ff82bd68-2c94-4913-bb09-f3442cb02f49">
</div>   

1. 삭제할 키는 key2이고, 해시 값은 1이라고 가정
2. 만약 삭제만 하고 키의 재배치에 대한 추가적 연산이 없다면, key 3을 탐색한다고 했을 때, 키가 존재하나 빈 공간을 만나 종료되는 문제 발생
3. null이 존재하는 인덱스를 기준으로 해시값이 인덱스보다 작거나 같은 키를 찾아 재배치 필요

<div align = "center">
<img width="1097" alt="11" src="https://github.com/sooyounghan/Web/assets/34672301/bd794567-a4b0-44e3-ab15-e883b9a6de89">
</div>   

4. null이 존재하는 인덱스는 1이고, moveIndex를 이용해 1보다 작거나 같은 해시값을 가진 키를 찾음
5. 2번 인덱스에 있던 키의 해시값이 0이므로 1번 위치로 이동

<div align = "center">
<img width="1096" alt="12" src="https://github.com/sooyounghan/Web/assets/34672301/67e58456-2662-4a29-bceb-5527c503d310">
</div>   

6. 키의 이동으로 인해 null이 존재하는 인덱스가 2가 됨
7. moveIndex를 이용해 2보다 작거나 같은 해시값을 찾음
8. 그러나 3번 인덱스에 있던 키의 해시값은 2보다 크므로 재배치 연산 종료

<div align = "center">
<img width="1096" alt="13" src="https://github.com/sooyounghan/Web/assets/34672301/3a647670-1287-4389-96cb-5feb195e3906">
</div>  

9. key4를 삭제한다고 가정하면, key의 해시값은 3
10. 해당 키를 삭제

<div align = "center">
<img width="1096" alt="14" src="https://github.com/sooyounghan/Web/assets/34672301/82f3a3cc-8082-4e7e-9bd3-e28a3b6a2da5">
</div>  

11. 해당 키 삭제로 인해 null 인덱스는 3이고, moveIndex를 이용해 3보다 작거나 같은 해시 값을 찾음
12. 4번 인덱스에 있던 키의 해시값이 1이므로 3번 위치로 이동

<div align = "center">
<img width="1097" alt="15" src="https://github.com/sooyounghan/Web/assets/34672301/f40d0763-9642-42da-a136-da2a91a9bd2b">
</div>  

13. null이 존재하는 index는 4이고 moveIndex를 이용해 4보다 작거나 같은 해시 값을 가진 키를 찾음
14. 5번 인덱스에 있던 키의 해시값이 2이므로 4번 위치로 이동

<div align = "center">
<img width="1099" alt="16" src="https://github.com/sooyounghan/Web/assets/34672301/080e755f-703f-4cde-9874-ab1474a8c859">
</div>  

15. null이 존재하는 index는 5이고, moveIndex를 이용해 5보다 작거나 같은 해시 값을 가진 키를 찾음
16. moveIndex가 가리키는 것은 null이므로 재배치 연산 종료

------
### Linear Probing 삭제 시 일반적 재배치 방식의 한계점
------   
<div align = "center">
<img width="1097" alt="17" src="https://github.com/sooyounghan/Web/assets/34672301/b359c99f-8389-41a3-aac4-378f3af66641">
</div>  

1. 일반적인 방식만으로는 예외적인 문제 발생 가능
2. 인덱스를 기준으로 해시값이 인덱스보다 작거나 같은 키를 찾아서 끌어 당기기 때문에
   그림과 같은 상황이라면 조사 방식의 한계점(빈 공간을 만나면서 조사 중지)때문에 key3을 찾을 수 없음

<div align = "center">
<img width="1096" alt="18" src="https://github.com/sooyounghan/Web/assets/34672301/9e9b5443-2d5f-4859-8197-8b25ef6dce6d">
</div>  

3. 그러므로 null대신 Dummy null Entry를 삽입하는 방식으로 조사를 진행
4. 더미 노드는 키 삽입 시 자연스럽게 제거되거나 또는 버킷의 크기를 늘릴 때 자연스럽게 제거
5. 이러한 방식을 Lazy Deletion

------
### Linear Probing 구현
------   
< Entry >
```jsp
public class Entry {
    Object key; // HashTable의 key
    Object value; // 저장할 값

    /*
     * remove 메서드의 내용 확인
     * 삭제되었다면, true
     */
    boolean isDeleted = false;

    Entry(Object key, Object value, boolean isDeleted) { // Entry 객체 생성자
        this.key = key;
        this.value = value;
        this.isDeleted = isDeleted;
    }
}
```

< Linear Probing >
```jsp
/*
 * Linear Probing Hash Table Class
 */
public class Linear_Probing {
    private static final int MAXIMUM_CAPACITY = 1 << 30;  // 버킷으로 할당할 수 있는 최대 크기
    private static final float ROAD_FACTOR_THRESHOLD = 0.75F;  // 버킷의 엔트리가 75%를 넘으면 버킷의 크기를 늘림

    private Entry[] bucket; // bucket 
    private int bucketSize; // bucket의 크기
    private final Entry dummyNull = new Entry(null, null, true); // Linear Probing 삭제 문제에서 끌어당기기에서 발생할 수 있는 문제에 대한 dummy null

    public Linear_Probing() { 
    /*
     * 생성자의 매개변수가 없으면 기본 테이블의 크기는 16
     */
        this(16);
    }

    public Linear_Probing(int capacity) {
    /*
     * 생성자 매개변수에 크기가 설정된 경우
     */
        if (capacity <= 0) { // 0이나 음수 입력 시 예외 발생
            throw new RuntimeException("정상적인 해시 테이블의 크기를 정해주세요.");
        }
        bucket = new Entry[tableSizeFor(capacity)]; // 양수의 경우 Entry 생성
    }

    private int tableSizeFor(int capacity) {
        /*
         * Hash Table 크기를 조정하는 메서드
         * 2의 제곱수로 bucket 사이즈를 상향식으로 보정한다.(예: 100 -> 128)
         */ 
        int n = capacity - 1;

        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 15;

        return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
    }

    private int secondaryHash(Object key) {
        /*
         * 보조 해시 함수 메서드
         * 보조 해시 함수 : h'(k) -> {0, 1, 2, .. m - 1}
         * 	 1. 해시값을 최대한 흩어놓기 위해 앞의 16비트를 옮겨 기존의 해시값과 XOR 연산을 먼저 한 후
         *      bucket 크기 만큼의 범위에 들어가게 하기 위해 비트 연산을 한다.
         *
         *   2. 만약에 최적화를 한다면 h = (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16)로
         *       연산된 값을 노드에 저장하여 재이용하면 된다.
         */

        int h; 

        h = (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16); // key가 null이면 해시값 0, 값이 있다면 key에 대해 hashCode화 후 16비트를 앞으로 옮기고 XOR 연산

        return h & (bucket.length - 1);
    }

    private int hash(Object key, int i) {
        /*
         * Hash 메서드
         * Linear Probing : (h(key, i) : h'(k)) + i mod m
         */
        int m = bucket.length;
        return (secondaryHash(key) + i) % m;
    }

    private int probing(Object key) {
        /*
         * 키 조사를 위한 메서드
         * 1. 키의 조사를 위해 Dummy null 엔트도 null로 판단하지 않는 조사 방식
         *
         * 2. T[h'(k)] 부터 T[m-1] 까지 동일한 키가 있거나 빈 공간이 있는지 탐색한다.
         *    T[h'(k)] 부터 T[m-1] 까지 찾지 못했으면 T[0] 부터 T[h'(k)-1] 까지 탐색한다.
         *
         * 3. return : 동일한 키의 인덱스 or 빈 공간의 인덱스 or 동일하지 않은 키의 인덱스
         */
        int m = bucket.length;

        int bucketIndex = -1;

        for (int i = 0; i < m; i++) {
            bucketIndex = hash(key, i); // key 값에 대한 hash 적용한 bucketIndex 도출

            if (bucket[bucketIndex]  != null && key.equals(bucket[bucketIndex].key)) {
                // 1. 동일한 키를 찾은 경우
                break;
            } else if (bucket[bucketIndex] == null) {
                // 2. bucket[bucketIndex]가 null인 경우
                break;
            }
	// 3. 동일하지 않은 키의 인덱스
        }
        return bucketIndex;
    }

    private int insertProbing(Object key) {
        /*
         * 키 삽입을 위한 메서드
         * 키의 삽입을 위해 Dummy null 엔트리도 null로 판단하는 조사 방식
         *
         * 	1. T[h'(k)] 부터 T[m-1] 까지 동일한 키가 있거나 빈 공간이 있는지 탐색한다.
         *     T[h'(k)] 부터 T[m-1] 까지 찾지 못했으면 T[0] 부터 T[h'(k)-1] 까지 탐색한다.
         *
         *  2. return 동일한 키의 인덱스 or 빈 공간의 인덱스 or 동일하지 않은 키의 인덱스
         */
        int m = bucket.length;

        int bucketIndex = -1;

        for (int i = 0; i < m; i++) {
            bucketIndex = hash(key, i); // key 값에 대한 hash 적용한 bucketIndex 도출

            if (bucket[bucketIndex] != null && key.equals(bucket[bucketIndex].key)) {
                 // 1. 동일한 키를 찾은 경우
                break;
            } else if (bucket[bucketIndex] == null ||
                    (bucket[bucketIndex] != null && bucket[bucketIndex].isDeleted)) {
                // 2. bucket[bucketIndex]가 null이거나 Dummy null 엔트리 존재 시
                break;
            }
        } // 3. 동일하지 않은 키의 인덱스
        return bucketIndex;
    }

    public void put(Object key, Object value) { // hashTable에 hash값에 일치하면 키, value 값 삽입
        putValue(key, value);
    }

    private void putValue(Object key, Object value) {
        /*
         * 키와 값을 HashTable에 삽입하기 위한 메서드
         * 1. 조사된 버킷의 위치에 저장된 값이 null이 아니고 이미 동일한 키가 존재하면 값을 덮어씀
         * 2. null이면 해당 자리에 키와 값을 저장한다.
         */

        int bucketIndex = insertProbing(key); // key에 대해 삽입해야 할 위치를 구함

        if (bucket[bucketIndex]  != null && key.equals(bucket[bucketIndex].key)) {
            // 1. 버킷에 동일한 키가 존재 시
            bucket[bucketIndex].value = value;
        } else if (bucket[bucketIndex] == null ||
                (bucket[bucketIndex] != null && bucket[bucketIndex].isDeleted)) {
            // 2. bucket[index]가 null이거나 Dummy null 엔트리 존재 시
            bucket[bucketIndex] = new Entry(key, value, false);
            ++bucketSize; // 추가하였으므로, 사이즈 1증가
        }
        resizeBucket();
    }

    public Object get(Object key) {
        /* 
         * 키에 해당하는 값을 가져오는 메서드
         */

        int bucketIndex = probing(key); // 우선 키에 대해 probing 시작
        Entry entry = null; // 값을 받아올 entry 객체 배열 생성

        if (bucket[bucketIndex]  != null && key.equals(bucket[bucketIndex].key)) {
	// bucket의 원래 인덱스의 값이 null 아니고, 키의 값과 bucket의 키의 값이 같다면,
            entry = bucket[bucketIndex]; // 그 때의 값을 entry로 이동하여 값 추출
        }
        return (entry != null) ? entry.value : null;
    }

    public void remove(Object key) {
        /*
         * 1. 삭제된 노드의 index를 기준으로 동일한 해시값이거나 또는 해시값보다 이전의 값을 가진 노드를 조사하여 가져옴
         * 2. 다만 충돌로 인해 삽입된 키의 해시값이 버킷의 인덱스보다 큰 경우가 있으므로 Lazy Deletion 방식을 택한다.
         *
         * 예) key21, key22, key23 순서대로 해시 테이블에 삽입 했을 경우 key21, key22, key23은 해시값이 5라고 가정한다.
         *  	| 0 | (hash : 5, key : key22)
         *	 	| 1 | (hash : 5, key : key23)
         * 		| 2 | null
         * 		| 3 | null
         * 		| 4 | null
         *		| 5 | (hash : 5, key : key21)
         *
         * 	   만약에 key21을 제거하면 이런 상황이 된다.
         * 		| 0 | (hash : 5, key : key22)
         * 		| 1 | (hash : 5, key : key23)
         * 		| 2 | null
         * 		| 3 | null
         * 		| 4 | null
         * 		| 5 | null
         *
         * 	   그리고 key23(hash 5)을 조사하는 경우 5번 인덱스가 null이기 때문에 조사를 멈춘다.
         *     그러면 key23을 못찾기 때문에 땡겨올 때 Dummy null 엔트리를 넣어주면 조사를 계속 진행 할 수 있다.
         * 		| 0 | (hash : 5, key : key22, isDelete: false)
         * 		| 1 | (hash : 5, key : key23, isDelete: false)
         * 		| 2 | null
         * 		| 3 | null
         * 		| 4 | null
         * 		| 5 | (key : null, isDelete: true) <- Dummy null 엔트리
         *
         * 	  이것은 open-addessing의 한계점이다.
         *
         */

        int index = probing(key); // key에 대한 probing을 통해 index 추출

        int removedIndex = -1; //  제거해야할 인덱스

        if (bucket[index] != null && key.equals(bucket[index].key)) {
            /* 
             * 해당하는 인덱스가 null이 아니거나, 키 값과 버킷의 인덱스의 키 값이 동일 = 해당하는 값 찾음
             * 삭제가 아닌 Dummy null 엔트리를 삽입
             */

            bucket[index] = this.dummyNull; // 그 인덱스에 dummyNull 삽입
            removedIndex = index; // 인덱스가 제거된 인덱스로 설정됨
            --bucketSize; // 사이즈는 1개 줄어듬
        }

        // 끌어당기기 로직
        if (removedIndex == -1) { // removeIndex가 있다면,
            int nullIndex = removedIndex; // 제거된 인덱스는 nullIndex

            for (int i = 0; i < bucket.length; i++) { // 버킷에 대해서
                int moveIndex = (i + removedIndex) % bucket.length; // 현재 해당하는 인덱스보다 작은 값을 순차적으로 확인해서

                if (bucket[moveIndex] != null &&
                        !bucket[moveIndex].isDeleted &&
                        secondaryHash(bucket[moveIndex].key) <= nullIndex) {
                    /*
                     * 1. bucket[moveIndex]가 null이 아니며
                     * 2. Dummy null 엔트리도 아니고
                     * 3. 해시값이 nullIndex보다 작은 경우
	         */
                    bucket[nullIndex] = bucket[moveIndex]; // 끌어당기기 시작
                    bucket[moveIndex] = this.dummyNull; // 끌어당긴 부분에 대해서 dummy null
                    nullIndex = moveIndex; // 그렇게 되면, null인덱스는 removeIndex가 됨
                }
            }
        }
    }

    private void resizeBucket() {
        /*
         * 적재율이 임계치를 넘으면 버킷의 크기를 늘리는 메서드.
         */ 

        int prevBucketSize = bucket.length; // 현재 버킷의 크기 확인

        if (MAXIMUM_CAPACITY <= prevBucketSize) { 
            // 이미 최대 버킷 크기이면 크기를 늘릴 수 없음.
            return;
        }

        if (bucketSize * 1.0F / prevBucketSize > ROAD_FACTOR_THRESHOLD) { // 아직 적재율이 임계치를 넘지 않았다면,

            int newBucketSize = tableSizeFor(prevBucketSize << 1); // 2배 증가
            Entry[] entries = bucket; // 현재 entry 임시 저장 후
            bucket = new Entry[newBucketSize]; // 새로운 크기의 entry 생성

            bucketSize = 0; // 새로운 버킷이 생성되었으므로 크기는 0
            
            for (Entry entry : entries) {
	// 새로운 버킷이 할당되면 노드의 해시를 재계산하여 다시 삽입
                if (entry != null && !entry.isDeleted) {
                    putValue(entry.key, entry.value);
                }
            }
        }
    }

    // print 부분은 생략
    public void printHashTable() {
        System.out.println("-----Linear----");
        for (int i = 0; i < bucket.length; i++) {
            if (null != bucket[i] && bucket[i].isDeleted) {
                System.out.printf("| %d | %s\n", i, "null(dummy)");
            } else if (null != bucket[i]) {
                System.out.printf("| %d | %s\n", i, printNode(bucket[i]));
            } else {
                System.out.printf("| %d | %s\n", i, "null");
            }
        }
        System.out.println("---------------");
    }

    private String printNode(Entry entry) {
        StringBuilder builder = new StringBuilder();
        int hash = secondaryHash(entry.key);
        builder.append("(").append(entry.key).append(",").append(entry.value)
                .append(",").append(hash).append(")");
        return builder.toString();
    }
}
```

1. 버킷의 사이즈를 상향식으로 보정하는 메서드
   - 기본적으로 버킷의 크기를 2의 제곱수를 설정
   - 그 이유는 secondaryHash 메서드에서 비트 연산을 통해 해시 값을 최대한 고르도록 정하게 함
   - 그러기 위해서는 먼저 버킷의 크기가 2의 제곱수를 가져야함
```java
int tableSizeFor(int capacity) {
    int n = capacity - 1;
    n |= n >>> 1;
    n |= n >>> 2;
    n |= n >>> 4;
    n |= n >>> 8;
    n |= n >>> 15;
    return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
}
```

2. 만약 capacity로 100의 값을 전달받으면 다음과 같은 과정을 거쳐 사이즈 계산
```java
int n = capacity - 1; // capacity 100

// n은 99
// 99의 비트구조
00000000 00000000 00000000 01100011
```
```java
n |= n >>> 1;

n
00000000 00000000 00000000 01100011
n >>> 1
00000000 00000000 00000000 00110001

n |= n >>> 1 연산
00000000 00000000 00000000 01100011
00000000 00000000 00000000 00110001
-----------------------------------
00000000 00000000 00000000 01110011
```
```java
n |= n >>> 2;

n
00000000 00000000 00000000 01110011
n >>> 2
00000000 00000000 00000000 00011100

n |= n >>> 2 연산
00000000 00000000 00000000 01110011
00000000 00000000 00000000 00011100
-----------------------------------
00000000 00000000 00000000 01111111
```
```java
n |= n >>> 4;

n
00000000 00000000 00000000 01111111
n >>> 4
00000000 00000000 00000000 00000111

n |= n >>> 4 연산
00000000 00000000 00000000 01111111
00000000 00000000 00000000 00000111
-----------------------------------
00000000 00000000 00000000 01111111
```
```java
n |= n >>> 8;

n
00000000 00000000 00000000 01111111
n >>> 8
00000000 00000000 00000000 00000000

n |= n >>> 8 연산
00000000 00000000 00000000 01111111
00000000 00000000 00000000 00000000
-----------------------------------
00000000 00000000 00000000 01111111
```
```java
n |= n >>> 15;

n
00000000 00000000 00000000 01111111
n >>> 15
00000000 00000000 00000000 00000000

n |= n >>> 15 연산
00000000 00000000 00000000 01111111
00000000 00000000 00000000 00000000
-----------------------------------
00000000 00000000 00000000 01111111
```
```java
return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;

n
00000000 00000000 00000000 01111111
1
00000000 00000000 00000000 00000001

n + 1
00000000 00000000 00000000 01111111
00000000 00000000 00000000 00000001
-----------------------------------
00000000 00000000 00000000 10000000
```

3. 연산의 방향은 하위 비트를 모두 1로 채우는 방향으로 진행
4. 마지막에 1을 더하면 2의 제곱수 비트가 완성되어, 2의 제곱수 비트의 특징을 이용해 보조 해시값을 구함

```java
비트 연산으로 인해 최대로 채워질수 있는 값
00111111 11111111 11111111 11111111

n + 1 연산을 통해 양의 정수 이며 2의 제곱수의 최댓값
01000000 00000000 00000000 00000000
```

5. 버킷의 사이즈를 이용한 해시값을 구하는 메서드
   - 2의 제곱수 크기를 가진 버킷을 이용하고 비트의 분포를 이용해 해시값을 구할 수 있음
```java
int secondaryHash(Object key) {
    int h;
    h = (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
    return h & (bucket.length - 1);
}
```
```java
int h;
h = (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);

key.hashCode()가 52123212인 경우

h = 52123212
00000011 00011011 01010110 01001100

h >>> 16
00000000 00000000 00000011 00011011

h ^ (h >>> 16)
(XOR 연산)
00000011 00011011 01010110 01001100
00000000 00000000 00000011 00011011
-----------------------------------
00000011 00011011 01010101 01010111
```

6. 버킷의 크기가 2진수의 제곱수 이므로 1을 빼면 하위 비트가 1로 꽉찬 비트 얻을 수 있음
7. 해당 비트와 h의 비트를 AND 연산하면 버킷의 크기보다 작은 해시값 도출 가능
8. 이러한 과정은 최대한 비트를 훑어놓으면서 버킷의 크기를 넘지 않도록 하는 것


```java
return h & (bucket.length - 1);
버킷의 크기가 128인 경우

128
00000000 00000000 00000000 10000000

128 - 1
00000000 00000000 00000000 01111111

h & 127
00000000 00000000 00000000 01111111
00000011 00011011 01010101 01010111
-----------------------------------
00000000 00000000 00000000 01010111 (10진수 87)
```

9. 버킷의 적재율에 따라 버킷의 크기를 늘리는 메서드
   - 버킷의 키의 적재율이 75%를 넘어가면 버킷의 크기를 2의 제곱수로 늘림

```java
void resizeBucket() {
    int prevBucketSize = bucket.length;
    if (MAXIMUM_CAPACITY <= prevBucketSize) {
        return;
    }
    if (bucketSize * 1.0F / prevBucketSize > ROAD_FACTOR_THRESHOLD) {
        int newBucketSize = tableSizeFor(prevBucketSize << 1);
        Node[] nodes = bucket;
        bucket = new Node[newBucketSize];
        bucketSize = 0;
        for (Node node :nodes) {
            if (null != node) {
                putValue(node.key, node.value);
            } 
        }
    }
}
```

10. 새로운 배열을 생성하고 버킷을 덮어씀
11. 버킷의 크기가 증가되었으므로 새로운 버킷의 크기에 맞는 새로운 해시값을 구해야함 (putValue 메서드)
```java
int newBucketSize = tableSizeFor(prevBucketSize << 1);

버킷의 크기가 128인 경우

128
00000000 00000000 00000000 10000000

128 << 1
00000000 00000000 00000001 00000000
```

------
### Quadratic Probing 구현
------   
< Quadratic Probing >
```jsp
public class Quadratic_Probing {
    private static final int MAXIMUM_CAPACITY = 1 << 30;  // 버킷으로 할당할 수 있는 최대 크기
    private static final float ROAD_FACTOR_THRESHOLD = 0.75F;  // 버킷의 엔트리가 75%를 넘으면 버킷의 크기를 늘림

    private Entry[] bucket; // bucket 
    private int bucketSize; // bucket의 크기
    private final Entry dummyNull = new Entry(null, null, true); // Linear Probing 삭제 문제에서 끌어당기기에서 발생할 수 있는 문제에 대한 dummy null

    public Quadratic_Probing() { 
    /*
     * 생성자의 매개변수가 없으면 기본 테이블의 크기는 16
     */
        this(16);
    }

    public Quadratic_Probing(int capacity) {
    /*
     * 생성자 매개변수에 크기가 설정된 경우
     */
        if (capacity <= 0) { // 0이나 음수 입력 시 예외 발생
            throw new RuntimeException("정상적인 해시 테이블의 크기를 정해주세요.");
        }
        bucket = new Entry[tableSizeFor(capacity)]; // 양수의 경우 Entry 생성
    }

    private int tableSizeFor(int capacity) {
        /*
         * Hash Table 크기를 조정하는 메서드
         * 2의 제곱수로 bucket 사이즈를 상향식으로 보정한다.(예: 100 -> 128)
         */ 
        int n = capacity - 1;

        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 15;

        return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
    }

    private int secondaryHash(Object key) {
        /*
         * 보조 해시 함수 메서드
         * 보조 해시 함수 : h'(k) -> {0, 1, 2, .. m - 1}
         * 	 1. 해시값을 최대한 흩어놓기 위해 앞의 16비트를 옮겨 기존의 해시값과 XOR 연산을 먼저 한 후
         *      bucket 크기 만큼의 범위에 들어가게 하기 위해 비트 연산을 한다.
         *
         *   2. 만약에 최적화를 한다면 h = (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16)로
         *       연산된 값을 노드에 저장하여 재이용하면 된다.
         */

        int h; 

        h = (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16); // key가 null이면 해시값 0, 값이 있다면 key에 대해 hashCode화 후 16비트를 앞으로 옮기고 XOR 연산

        return h & (bucket.length - 1);
    }

    private int hash(Object key, int i) {
        /*
         * Hash 메서드 (c1 = 2, c2= 2)
         * Quadratic Probing : (h(key, i) : h'(k) + (c1 * i) + (c2 * i^2)) mod m
         */
        int c1 = 2; 
        int c2 = 2;
        int m = bucket.length;
        return ((secondaryHash(key) + i) + (c1 * i) + (c2 * i * i)) % m;
    }

    private int probing(Object key) {
        /*
         * 키 조사를 위한 메서드
         * 1. 키의 조사를 위해 Dummy null 엔트도 null로 판단하지 않는 조사 방식
         *
         * 2. T[h'(k)] 부터 T[m-1] 까지 동일한 키가 있거나 빈 공간이 있는지 탐색한다.
         *    T[h'(k)] 부터 T[m-1] 까지 찾지 못했으면 T[0] 부터 T[h'(k)-1] 까지 탐색한다.
         *
         * 3. return : 동일한 키의 인덱스 or 빈 공간의 인덱스 or 동일하지 않은 키의 인덱스
         */
        int m = bucket.length;

        int bucketIndex = -1;

        for (int i = 0; i < m; i++) {
            bucketIndex = hash(key, i); // key 값에 대한 hash 적용한 bucketIndex 도출

            if (bucket[bucketIndex]  != null && key.equals(bucket[bucketIndex].key)) {
                // 1. 동일한 키를 찾은 경우
                break;
            } else if (bucket[bucketIndex] == null) {
                // 2. bucket[bucketIndex]가 null인 경우
                break;
            }
	// 3. 동일하지 않은 키의 인덱스
        }
        return bucketIndex;
    }

    private int insertProbing(Object key) {
        /*
         * 키 삽입을 위한 메서드
         * 키의 삽입을 위해 Dummy null 엔트리도 null로 판단하는 조사 방식
         *
         * 	1. T[h'(k)] 부터 T[m-1] 까지 동일한 키가 있거나 빈 공간이 있는지 탐색한다.
         *     T[h'(k)] 부터 T[m-1] 까지 찾지 못했으면 T[0] 부터 T[h'(k)-1] 까지 탐색한다.
         *
         *  2. return 동일한 키의 인덱스 or 빈 공간의 인덱스 or 동일하지 않은 키의 인덱스
         */
        int m = bucket.length;

        int bucketIndex = -1;

        for (int i = 0; i < m; i++) {
            bucketIndex = hash(key, i); // key 값에 대한 hash 적용한 bucketIndex 도출

            if (bucket[bucketIndex] != null && key.equals(bucket[bucketIndex].key)) {
                 // 1. 동일한 키를 찾은 경우
                break;
            } else if (bucket[bucketIndex] == null ||
                    (bucket[bucketIndex] != null && bucket[bucketIndex].isDeleted)) {
                // 2. bucket[bucketIndex]가 null이거나 Dummy null 엔트리 존재 시
                break;
            }
        } // 3. 동일하지 않은 키의 인덱스
        return bucketIndex;
    }

    public void put(Object key, Object value) { // hashTable에 hash값에 일치하면 키, value 값 삽입
        putValue(key, value);
    }

    private void putValue(Object key, Object value) {
        /*
         * 키와 값을 HashTable에 삽입하기 위한 메서드
         * 1. 조사된 버킷의 위치에 저장된 값이 null이 아니고 이미 동일한 키가 존재하면 값을 덮어씀
         * 2. null이면 해당 자리에 키와 값을 저장한다.
         */

        int bucketIndex = insertProbing(key); // key에 대해 삽입해야 할 위치를 구함

        if (bucket[bucketIndex]  != null && key.equals(bucket[bucketIndex].key)) {
            // 1. 버킷에 동일한 키가 존재 시
            bucket[bucketIndex].value = value;
        } else if (bucket[bucketIndex] == null ||
                (bucket[bucketIndex] != null && bucket[bucketIndex].isDeleted)) {
            // 2. bucket[index]가 null이거나 Dummy null 엔트리 존재 시
            bucket[bucketIndex] = new Entry(key, value, false);
            ++bucketSize; // 추가하였으므로, 사이즈 1증가
        }
        resizeBucket();
    }

    public Object get(Object key) {
        /* 
         * 키에 해당하는 값을 가져오는 메서드
         */

        int bucketIndex = probing(key); // 우선 키에 대해 probing 시작
        Entry entry = null; // 값을 받아올 entry 객체 배열 생성

        if (bucket[bucketIndex]  != null && key.equals(bucket[bucketIndex].key)) {
	// bucket의 원래 인덱스의 값이 null 아니고, 키의 값과 bucket의 키의 값이 같다면,
            entry = bucket[bucketIndex]; // 그 때의 값을 entry로 이동하여 값 추출
        }
        return (entry != null) ? entry.value : null;
    }

    public void remove(Object key) {
        /*
         * 1. 삭제된 노드의 index를 기준으로 동일한 해시값이거나 또는 해시값보다 이전의 값을 가진 노드를 조사하여 가져옴
         * 2. 다만 충돌로 인해 삽입된 키의 해시값이 버킷의 인덱스보다 큰 경우가 있으므로 Lazy Deletion 방식을 택한다.
         *
         * 예) key21, key22, key23 순서대로 해시 테이블에 삽입 했을 경우 key21, key22, key23은 해시값이 5라고 가정한다.
         *  	| 0 | (hash : 5, key : key22)
         *	 	| 1 | (hash : 5, key : key23)
         * 		| 2 | null
         * 		| 3 | null
         * 		| 4 | null
         *		| 5 | (hash : 5, key : key21)
         *
         * 	   만약에 key21을 제거하면 이런 상황이 된다.
         * 		| 0 | (hash : 5, key : key22)
         * 		| 1 | (hash : 5, key : key23)
         * 		| 2 | null
         * 		| 3 | null
         * 		| 4 | null
         * 		| 5 | null
         *
         * 	   그리고 key23(hash 5)을 조사하는 경우 5번 인덱스가 null이기 때문에 조사를 멈춘다.
         *     그러면 key23을 못찾기 때문에 땡겨올 때 Dummy null 엔트리를 넣어주면 조사를 계속 진행 할 수 있다.
         * 		| 0 | (hash : 5, key : key22, isDelete: false)
         * 		| 1 | (hash : 5, key : key23, isDelete: false)
         * 		| 2 | null
         * 		| 3 | null
         * 		| 4 | null
         * 		| 5 | (key : null, isDelete: true) <- Dummy null 엔트리
         *
         * 	  이것은 open-addessing의 한계점이다.
         *
         */

        int bucketIndex = probing(key); // key에 대한 probing을 통해 index 추출

        int removedIndex = -1; //  제거해야할 인덱스

        if (bucket[bucketIndex] != null && key.equals(bucket[bucketIndex].key)) {
            /* 
             * 해당하는 인덱스가 null이 아니거나, 키 값과 버킷의 인덱스의 키 값이 동일 = 해당하는 값 찾음
             * 삭제가 아닌 Dummy null 엔트리를 삽입
             */

            bucket[bucketIndex] = this.dummyNull; // 그 인덱스에 dummyNull 삽입
            removedIndex = bucketIndex; // 인덱스가 제거된 인덱스로 설정됨
            --bucketSize; // 사이즈는 1개 줄어듬
        }

        // 끌어당기기 로직
        if (removedIndex == -1) { // removeIndex가 있다면,
            int nullIndex = removedIndex; // 제거된 인덱스는 nullIndex

            for (int i = 0; i < bucket.length; i++) { // 버킷에 대해서
                int moveIndex = (i + removedIndex) % bucket.length; // 현재 해당하는 인덱스보다 작은 값을 순차적으로 확인해서

                if (bucket[moveIndex] != null &&
                        !bucket[moveIndex].isDeleted &&
                        secondaryHash(bucket[moveIndex].key) <= nullIndex) {
                    /*
                     * 1. bucket[moveIndex]가 null이 아니며
                     * 2. Dummy null 엔트리도 아니고
                     * 3. 해시값이 nullIndex보다 작은 경우
	         */
                    bucket[nullIndex] = bucket[moveIndex]; // 끌어당기기 시작
                    bucket[moveIndex] = this.dummyNull; // 끌어당긴 부분에 대해서 dummy null
                    nullIndex = moveIndex; // 그렇게 되면, null인덱스는 removeIndex가 됨
                }
            }
        }
    }

    private void resizeBucket() {
        /*
         * 적재율이 임계치를 넘으면 버킷의 크기를 늘리는 메서드.
         */ 

        int prevBucketSize = bucket.length; // 현재 버킷의 크기 확인

        if (MAXIMUM_CAPACITY <= prevBucketSize) { 
            // 이미 최대 버킷 크기이면 크기를 늘릴 수 없음.
            return;
        }

        if (bucketSize * 1.0F / prevBucketSize > ROAD_FACTOR_THRESHOLD) { // 아직 적재율이 임계치를 넘지 않았다면,

            int newBucketSize = tableSizeFor(prevBucketSize << 1); // 2배 증가
            Entry[] entries = bucket; // 현재 entry 임시 저장 후
            bucket = new Entry[newBucketSize]; // 새로운 크기의 entry 생성

            bucketSize = 0; // 새로운 버킷이 생성되었으므로 크기는 0
            
            for (Entry entry : entries) {
	// 새로운 버킷이 할당되면 노드의 해시를 재계산하여 다시 삽입
                if (entry != null && !entry.isDeleted) {
                    putValue(entry.key, entry.value);
                }
            }
        }
    }

    // print 부분은 생략
    public void printHashTable() {
        System.out.println("-----Linear----");
        for (int i = 0; i < bucket.length; i++) {
            if (null != bucket[i] && bucket[i].isDeleted) {
                System.out.printf("| %d | %s\n", i, "null(dummy)");
            } else if (null != bucket[i]) {
                System.out.printf("| %d | %s\n", i, printNode(bucket[i]));
            } else {
                System.out.printf("| %d | %s\n", i, "null");
            }
        }
        System.out.println("---------------");
    }

    private String printNode(Entry entry) {
        StringBuilder builder = new StringBuilder();
        int hash = secondaryHash(entry.key);
        builder.append("(").append(entry.key).append(",").append(entry.value)
                .append(",").append(hash).append(")");
        return builder.toString();
    }
}

```
1. 보조 해시 함수 값의 범위 (m은 해시 테이블의 크기)
```java
h'(key) -> {0, 1, 2, 3, .. m - 1}
```

2. 해시 함수 (m은 해시 테이블의 크기)
```java
h(key, i) = (h'(key) + (2 * i) + (2 * i^2)) mod m
```

3. Linear Probing과 해시 함수만 차이

< Main >
```jsp
package HashTable;

public class Main {
    public static void main(String[] args) {

        // Linear Probing이 적용된 해시 테이블
        System.out.println("Linear Probing");
        Linear_Probing Linear_Probing = new Linear_Probing(16);
        Linear_Probing.put("hi1", 1);
        Linear_Probing.put("hi2", 2);
        Linear_Probing.put("hi3", 3);
        Linear_Probing.put("hi10", 10);
        Linear_Probing.put("hi11", 11);
        Linear_Probing.put("hi12", 12);
        Linear_Probing.put("hi13", 13);
        Linear_Probing.put("hi14", 14);
        Linear_Probing.printHashTable();
        Linear_Probing.remove("hi12");
        Linear_Probing.printHashTable();
        System.out.printf("find key:%s value:%s\n\n", "hi11", Linear_Probing.get("hi11"));

        // Quadratic Probing이 적용된 해시 테이블
        System.out.println("Quadratic Probing");
        Quadratic_Probing Quadratic_Probing = new Quadratic_Probing(16);
        Quadratic_Probing.put("hi1", 1);
        Quadratic_Probing.put("hi2", 2);
        Quadratic_Probing.put("hi3", 3);
        Quadratic_Probing.put("hi10", 10);
        Quadratic_Probing.put("hi11", 11);
        Quadratic_Probing.put("hi12", 12);
        Quadratic_Probing.put("hi13", 13);
        Quadratic_Probing.put("hi14", 14);
        Quadratic_Probing.printHashTable();
        Quadratic_Probing.remove("hi12");
        Quadratic_Probing.printHashTable();
        System.out.printf("find key:%s value:%s\n", "hi10", Quadratic_Probing.get("hi10"));

    }
}
```
