package HashTable_Probing;

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