package Rercursion;

public class Fibonacci {
	public static void main(String[] args) {
		System.out.println(fibonacci(1, 1, 1));
	}
	
    public static int fibonacci(int n, int twoprevValue, int oneprevValue) {
    	if(n > 5) return oneprevValue; // 5번쨰항을 넘어가면 현재까지 더한 값 출력 
    	
    	/*
    	 * n은 항의 순서, 첫 번쨰항과 두 번째항은 1이어야 하므로,
    	 * n = 1, 2는 1이어야하고, n > 2는 첫 번째항과 두 번째항을 더해야함
    	 */
    	int value = (n == 1 || n == 2) ? 1 : oneprevValue + twoprevValue;
    
    	/*
    	 * 다음 항과 두 번째 전 항과 첫 번째 전항에 대해 다음 항을 구하기 위해 재귀
    	 */
    	return fibonacci(n + 1, oneprevValue, value);
    }
}