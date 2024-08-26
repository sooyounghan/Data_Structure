package HashTable_Channing;

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