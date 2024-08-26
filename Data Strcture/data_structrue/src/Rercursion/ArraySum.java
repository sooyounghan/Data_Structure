package Rercursion;

/*
 * Array Sum (배열의 값 더하기)
 */
public class ArraySum {
	public static void main(String[] args) {
		int[] arr = new int[]{4, 2, 5, 1, 5, 3, 1, 2};
		
		int result = sum(arr, 0, arr.length - 1);
		
		System.out.println(result);
	}
	
	public static int sum(int[] arr, int startIndex, int endIndex) {
		/*
		 * 배열의 값 더하기
		 */
		
		/*
		 * 종단 조건 : startIndex와 endIndex가 동일할 때 (배열의 크기가 하나일 때)
		 */
		if(startIndex == endIndex) {
			return arr[startIndex]; 
		}
		
		/*
		 * 중앙값(middleIndex) 구하기
		 */
		int middleIndex = (startIndex + endIndex) / 2;
		
		/*
		 * 배열의 값을 Divide and Conquer로 구하기 위해, 배열에 대해 
		 *   startIndex ~ middleIndex / middleIndex + 1 ~ endIndex까지 지속적으로 분할
		 *   -> 가장 작게 나누게 되면, 그 때부터 병합하여 문제를 해결
		 */
		return sum(arr, startIndex, middleIndex) + sum(arr, middleIndex + 1, endIndex);
	}
}
