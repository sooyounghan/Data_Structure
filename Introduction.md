-----
### 자료구조 (Data Structure)
-----
1. 한정된 메모리 공간 안에서 다양하면서도 수 많은 데이터를 어떻게 잘 활용할 것인가에 대한 원리를 배움
2. Array, List, Stack, Queue, Graph, Tree...

```java
ckage data_structure;

/*
 * Array Insert -> Search
 */
public class Array_Ex {
	public static void main(String[] args) {
		String[] array = new String[500000];
		System.out.println("Data Insert Start");
		
		// Data Insert.
		for(int i = 0; i < array.length; i++) {
			array[i] = i + "";
		}
		
		// Data Mixed.
		for(int i = 0; i < array.length; i++) {
			int x = (int)(Math.random() * array.length);
			int y = (int)(Math.random() * array.length);
			
			String temp = array[x];
			array[x] = array[y];
			array[y] = temp;
		}
		
		// Data Insert & Mixed Complete.
		System.out.println("Data Insert Complete");
		
		// Data Search
		System.out.println("Data Search Start");
		
		// Search Time 
		long startExecutionTime = System.currentTimeMillis();
		// Search Data & index
		String findValue = "482923";
		int foundIndex = -1;
		
		for(int i = 0; i < array.length; i++) {
			if(array[i].equals(findValue)) {
				foundIndex = i;
				break;
			}
		}		
		long endExecutionTime = System.currentTimeMillis();
		long periodTime = endExecutionTime - startExecutionTime;

		System.out.println("index : " + foundIndex + ", Value : " + findValue + ", Search Time : " + periodTime + "ms");
	}
}
```
<div align = "center">
<img src="https://github.com/sooyounghan/JAVA/assets/34672301/bad7fd48-d349-472a-ab78-db26910cb8f0">
</div>

-----
### 배열 (Array)
-----
1. 배열의 경우에는 원하는 데이터를 탐색하기 위해, 순차적 탐색 필요
2. 최악의 경우 : 배열의 가장 마지막 인덱스까지 순회
3. 배열의 단점

        - 데이터 양에 따라 검색 연산 시간이 비례적 증가
        - 데이터 양을 측정하기 힘들며, 많을 경우 큰 배열 공간을 할당해야하기 때문에 메모리 낭비 발생
