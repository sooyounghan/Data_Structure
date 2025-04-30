package Rercursion;

/*
 * Combination (Divide and Conquer)
 */
public class Combination {
	public static void main(String[] args) {
		System.out.println(combination(5, 3));
	}
	
	public static int combination(int n, int r) {
		/*
		 * Combination
		 */
		
		/*
		 * 조합의 성질 : n = r, r = 0이면 그 때의 값은 1
		 */
		if(n == r || r == 0) return 1;
		
		/*
		 * 조합 공식에 따른 재귀
		 */
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}
}
