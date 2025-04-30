package Singly_Linked_List;

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
