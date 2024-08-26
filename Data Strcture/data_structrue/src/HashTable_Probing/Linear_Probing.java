package HashTable_Probing;

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
