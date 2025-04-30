package Rercursion;

/*
 * Array Max (배열의 최대값 구하기) : Divide
 */
public class Array_Max {
	public static void main(String[] args) {
		int[] arr = new int[] {2, 1, 6, 7, 5, 8, 3, 4};
		System.out.println(max(arr, 0, arr.length - 1));
	}
	
	public static int max(int[] arr, int startIndex, int endIndex) {
		/*
		 * Array Max (배열의 최댓값 구하기)
		 */
		
		/*
		 * 종단 조건 : startIndex = endIndex (배열의 크기가 하나일 때 생각)
		 */
		if(startIndex == endIndex)
			return arr[startIndex];
		
		int middleIndex = (startIndex + endIndex) / 2; // 중앙값은 (처음 인덱스 + 마지막 인덱스) / 2
		int leftValue = max(arr, startIndex, middleIndex); // 좌편에서 가장 큰 값은 처음 인덱스에서부터 중앙값 인덱스 중 최댓값
		int rightValue = max(arr, middleIndex + 1, endIndex); // 우편에서 가장 큰 값은 중앙값 + 1 인덱스에서부터 마지막 인덱스 중 최댓값
		
		return Math.max(leftValue, rightValue); // 좌편 큰 값과 우 편 큰 값 중 가장 큰 값 출력
	}
}
