package Tree;

/*
 * Tree Main
 */
public class Tree_Main {
    public static void main(String[] args) {
        NormalTree normalTree = new NormalTree(); // 이진트리 객체 생성
        normalTree.add(1);
        normalTree.add(2);
        normalTree.add(3);
        normalTree.add(4);
        normalTree.add(5);
        normalTree.add(6);
        normalTree.add(7);
        normalTree.add(8);
        normalTree.add(9);
        normalTree.add(10);
        normalTree.add(11);
        normalTree.add(12); // 1 ~ 12부터 노드 삽입
        normalTree.printTree();
        System.out.println();
        System.out.println("traversal");
        normalTree.levelOrder(); // 순회 시작
        
        // 전위 순회
        System.out.println("전위 순회");
        normalTree.preOrderTraversal();
        
        // 중위 순회
        System.out.println("중위 순회");
        normalTree.inorderTraversal();
        
        // 후위 순회
        System.out.println("후위 순회");
        normalTree.postOrderTraversal();
    }
}
