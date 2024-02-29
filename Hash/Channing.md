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

< Entry >
```java
package HashTable_Channing;

class Entry {
    Object key; // key
    Object value; // value

    Entry(Object key, Object value) { // entry 객체 생성자로 key, value를 받으면 저장
        this.key = key;
        this.value = value;
    }
}
```

< Channing Hash Table >
```java
import java.util.LinkedList;

public class ChanningHashTable {
    private static final int MAXIMUM_CAPACITY = 1 << 30;  // 버킷으로 할당할 수 있는 최대 크기
    private static final float ROAD_FACTOR_THRESHOLD = 0.75F;  // 버킷의 엔트리가 75%를 넘으면 버킷의 크기를 늘림

    private LinkedList<Entry>[] bucket; // bucket은 LinkedList이용
    private int bucketSize; // bucket의 크기

    public ChanningHashTable() {
    /*
     * 생성자의 매개변수가 없으면 기본 테이블의 크기는 16
     */
        this(16);
    }

    @SuppressWarnings("unchecked")
    public ChanningHashTable(int capacity) {
    /*
     * 생성자 매개변수에 크기가 설정된 경우
     */
       if (capacity <= 0) { // 0이나 음수 입력 시 예외 발생
            throw new RuntimeException("정상적인 해시 테이블의 크기를 정해주세요.");
        }
        bucket = new LinkedList[tableSizeFor(capacity)]; // 양수의 경우 LinkedList 생성
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

    private int hash(Object key) {
        /*
         * 해시 함수 : h'(k) -> {0, 1, 2, .. m - 1}
         */
        int h;
        h = (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
        return h & (bucket.length - 1);
    }

    private int probing(Object key) {
    // key에 대한 HashTable Probing
        return hash(key);
    }

    public Object get(Object key) {
       /* 
         * 키에 해당하는 값을 가져오는 메서드
         */

        int index = probing(key); // key에 대해 probing를 시작하여 일치하는 값을 찾으면 index 반환
        if (bucket[index] == null) { // 해당 index의 값이 없다면 null 반환
            return null;
        }
        // 값이 있다면, 그 Entry 반환
        LinkedList<Entry> list = bucket[index];

        for (Entry entry : list) { // LinkedList로 연결되어 있으므로,
            if (entry.key.equals(key)) { // 해당하는 key를 찾고
                return entry.value; // 그 값을 return
            }
        }
        return null; // 없다면, null 반환
    }

    public void put(Object key, Object value) { // hashTable에 키, value 값 삽입
        putValue(key, value);
    }

    private void putValue(Object key, Object value) {
       /*
         * 키와 값을 HashTable에 삽입하기 위한 메서드
         * 1. 조사된 버킷의 위치에 저장된 값이 null이 아니고 이미 동일한 키가 존재하면 값을 덮어씀
         * 2. null이면 해당 자리에 키와 값을 저장한다.
         */

        int index = probing(key); // key에 대해 probing 

        if (bucket[index] == null) { // 그 index 값이 비어있다면,
            bucket[index] = new LinkedList<>(); // 새롭게 값을 넣어야 하므로, LinkedList 생성
            ++bucketSize; // 버킷은 1개 커지므로 증가
        }

        boolean isExistKey = false; // 키가 존재하지 않는다고 시작

        for (Entry entry : bucket[index]) { // bucket에 대해 Entry 객체를 추출하고
            // 키가 이미 존재하면 값만 덮어씀
            if (entry.key.equals(key)) {
                isExistKey = true; // 키가 존재하게 됐으므로 true
                entry.value = value;
                break; // 발견했으므로 탈출
            }
        }

        // 키가 존재하지 않으면 새롭게 추가
        if (!isExistKey) {
            bucket[index].add(new Entry(key, value));
        }
        resizeBucket(); // 키를 추가하였으며, 다시 한 번 bucket resize
    }

    public void remove(Object key) {
    /*
     * 해당하는 bucket의 key에 접근해 해당하는 요소를 제거하는 메서드
     */ 
        int index = probing(key); // key에 대해 probing
        if (bucket[index] != null) { // bucket의 해당 index에 값이 존재하면
            LinkedList<Entry> list = bucket[index]; // 그 Entry 객체를 가져오고

            for (Entry entry : list) { // 그 Entry List에 대해
                if (entry.key.equals(key)) { // 일치하는 키를 찾으면 
                    list.remove(entry); // 그 객체 제거
                    break; // 반복문 탈출
                }
            }
            // 엔트리 리스트에 엔트리가 비어있으면 버킷을 비워줌
            if (list.isEmpty()) {
                bucket[index] = null;
                --bucketSize;
            }
        }
    }

    @SuppressWarnings("unchecked")
    private void resizeBucket() {
       /*
         * 적재율이 임계치를 넘으면 버킷의 크기를 늘리는 메서드.
         */ 
        int prevBucketSize = bucket.length; ; // 현재 버킷의 크기 확인

        if (MAXIMUM_CAPACITY <= prevBucketSize) {
           // 이미 최대 버킷 크기이면 크기를 늘릴 수 없음.
            return;
        }
        if (bucketSize * 1.0F / bucket.length > ROAD_FACTOR_THRESHOLD) {  // 아직 적재율이 임계치를 넘지 않았다면,

            int newBucketSize = tableSizeFor(prevBucketSize << 1); // 2배 증가
            LinkedList<Entry>[] tempList = bucket; // 현재 객체를 entry list 임시 저장 후
            bucket = new LinkedList[newBucketSize]; // 새롭게 Bucket LinkedList 생성
            bucketSize = 0; // 크기는 다시 0부터 시작

            // 새로운 버킷이 할당되면 노드의 bucket 해시를 재계산하여 다시 할당
            for (LinkedList<Entry> list : tempList) {
                if (null != list) {
                    // 리스트에 있는 엔트리를 꺼내서 새롭게 삽입한다.
                    while (!list.isEmpty()) {
                        Entry entry = list.removeFirst();
                        putValue(entry.key, entry.value);
                    }
                }
            }
        }
    }
  
   // print 부분 생략
    public void printHashTable() {
        System.out.println("-------------");
        for (int i = 0; i < bucket.length; i++) {
            if (null != bucket[i]) {
                System.out.printf("| %d | %s %s\n", i, "List", printNode(bucket[i]));
            } else {
                System.out.printf("| %d | %s\n", i, "null");
            }
        }
        System.out.println("-------------");
    }

    private String printNode(LinkedList<Entry> list) {
        StringBuilder builder = new StringBuilder();
        builder.append("head -> ");
        for (Entry entry : list) {
            builder.append("(").append(entry.key).append(",").append(entry.value).append(") -> ");
        }
        builder.append("null");
        return builder.toString();
    }
}
```

< Main >
```java
public class Main {
    public static void main(String[] args) {
	    ChanningHashTable channingHashTable = new ChanningHashTable(4);
	    channingHashTable.put("hi", 1);
	    channingHashTable.put("hi2", 2);
	    channingHashTable.put("hi3", 3);
	    channingHashTable.put("hi4", 4);
	    channingHashTable.put("hi5", 5);
	    channingHashTable.put("hi6", 6);
	    channingHashTable.put("hi7", 7);
	    channingHashTable.put("hi8", 8);
	    channingHashTable.put("hi9", 9);
	    channingHashTable.put("hi10", 10);
	    channingHashTable.put("hi11", 11);
	    channingHashTable.put("hi12", 12);
	    channingHashTable.put("hi13", 13);
	    channingHashTable.put("hi14", 14);
	    channingHashTable.put("hi15", 15);
	    channingHashTable.put("hi16", 16);
	    channingHashTable.put("hi17", 17);
	    channingHashTable.put("hi18", 18);
	    channingHashTable.put("hi19", 19);
	    channingHashTable.put("hi20", 20);
	    channingHashTable.printHashTable();
	
	    System.out.println(channingHashTable.get("hi17"));
	    channingHashTable.remove("hi17");
	    channingHashTable.printHashTable();
    }
}
```
