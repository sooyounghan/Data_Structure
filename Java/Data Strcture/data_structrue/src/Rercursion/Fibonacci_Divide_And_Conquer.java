package Rercursion;

/*
 * Fibonacci (Divide and Conquer)
 */
public class Fibonacci_Divide_And_Conquer {
	public static void main(String[] args) {
		System.out.println(fibonacci(5));
	}
	
	public static int fibonacci(int n) {
		/*
		 * Fibonacci : Divide and Conquer
		 */
		
		/*
		 * 더 이상 나눌 수 없다면 1을 반환
		 */
		if(n == 1 || n == 2) return 1;
		
		/*
		 * n은 계속 시작해, 가장 작게 나눠질 때까지, 2개 전항 / 1개 전항을 계속해서 나눈 후, 분할할 수 없는 크기에 도달하면 합병 시작
		 */
		return fibonacci(n - 2) + fibonacci(n - 1);
	}
}
