package HashTable_Probing;

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

