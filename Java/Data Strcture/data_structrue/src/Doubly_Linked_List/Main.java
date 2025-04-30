package Doubly_Linked_List;

public class Main {
    public static void main(String[] args) {
		/*
		 * Doubly_Linked_List list = new Doubly_Linked_List ();
		 * 
		 * list.add(0, "B"); System.out.println(list);
		 * 
		 * list.add(1, "A"); System.out.println(list);
		 * 
		 * list.add(0, "E"); System.out.println(list);
		 * 
		 * list.addLast( "D"); System.out.println(list);
		 * 
		 * list.remove(0); System.out.println(list);
		 * 
		 * list.remove(2); System.out.println(list);
		 * 
		 * list.removeFirst(); System.out.println(list);
		 * 
		 * list.removeLast(); System.out.println(list);
		 * 
		 * System.out.printf("노드의 개수:%d\n", list.size());
		 * 
		 * System.out.printf("1번 인덱스의 값:%s", list.getData(1));
		 */
        // TODO : head, tail 노드 있는 이중 연결 리스트
        System.out.println("\n---head, tail node 존재 이중 연결 리스트---");
        Node_Doubly_Linked_List nodeDoublyLinkedList = new Node_Doubly_Linked_List();
        nodeDoublyLinkedList.add(0, "A");
        System.out.println(nodeDoublyLinkedList);

        nodeDoublyLinkedList.add(1, "B");
        System.out.println(nodeDoublyLinkedList);

        nodeDoublyLinkedList.add(2, "C");
        System.out.println(nodeDoublyLinkedList);

        System.out.printf("노드의 개수:%d\n", nodeDoublyLinkedList.size());

    }
}