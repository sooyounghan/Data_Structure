package Rercursion;

public class Sigma {
	public static void main(String[] args) {
		System.out.println(sigma(1, 1)); // n = 1, sum = 1으로 시작해 5까지의 합을 재귀방식으로 구현
	}
	
    public static int f (int n) { // f(n)
    	return n;
    }
    
    public static int sigma(int n, int sum) { 
    	if(n > 5) return sum; // n이 5보다 크면 합인 sum 값 return
    	
    	int nextSum = (n == 1) ? f(n) : sum + f(n); 
        /*
         * 다음 값의 합에 대해
         *  1. n = 1이면, 그 값은 f(1)
         *  2. n > 1이면, sum + f(n) [ sum은 수의 합]
    	 */
         
    	return sigma(n + 1, nextSum); // 현재는 n이었으므로, 다음 수인 sum과 현재까지 더해진 nextSum에 대해 재귀
    }
}