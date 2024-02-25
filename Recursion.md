-----
### 재귀 (Recursion)
-----
<div align = "center">
<img width="203" alt="다운로드 (1)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/bd08ca5c-22e5-4d18-95a2-718ddbe487d6">
</div>   

: 자신을 정의할 때, 자기 자신을 재참조하는 방식 (재귀 호출(Recursive Call)의 형태)   

-----
### 재귀 (Recursion)의 구조
-----
<div align = "center">
<img width="346" alt="다운로드 (5)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/21c753aa-cee7-4f03-ba15-8df5d4cabd2b">
</div>  

1. 순환적 특성
<div align = "center">
<img width="300" alt="다운로드 (2)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3db597c0-5b62-4530-ac0e-5c6ba9eb2e5b">
</div>   

   - A method 내에 A method 자기 자신을 호출하는 것
   - 메서드를 호출 한다는 것은 메서드의  주소를 가지고 있는 주소값(참조값)을 이용하여 호출
     (즉 A라는 메서드를 호출하기 위해 A라는 메서드의 주소값을 호출하는 것)
   - 재귀는 순환적 특성을 가짐
     (A method에서 B method를 호출하고, B method는 A method 호출하는 것)
     
2. 중단 조건
<div align = "center">
<img width="342" alt="다운로드 (3)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f0d32ec2-2fd7-4db1-86ed-d06dac326bb9">
</div>   

  - 순환을 종료할 중단 조건이 항상 있어야 함 (두 개의 메서드의 재귀라면 반드시 한 부분에는 있어야함)
  - 중단 조건이 없다면, 끊임없이 재귀가 될 것이므로 Stack Overflow가 발생


<div align = "center">
<img width="338" alt="다운로드 (4)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/56088a2a-3561-42fd-91bf-d7fb46fdc488">
</div>     
: 재귀는 순환적 특성을 가지고 있으므로, 반복문을 재귀함수로 변경할 수 있음

-----
### 점화식 관점
-----   
1. 반복 순차 방식 : 재귀 호출 방식이 아닌 하나의 반복문으로도 해결이 가능한 문제
2. 분할 병합 방식 : 하나의 반복문으로 해결이 어려운 문제 (재귀 호출 시 스택 구조의 특성 이용해야함)

-----
### 시그마 (반복 순차 방식)
-----    
<div align = "center">
<img width="586" alt="다운로드" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f9d4d338-0352-4c41-b0e5-46ebf12c5e0e">
</div>      

1. 합 (n을 1부터 n까지 대입하여 모든 결과 값을 합하는 것)
2. 점화식으로 표현할 수 있는 것은 실행 흐름을 따라가는 것보다 점화식 그 자체를 코드로 옮기는 것이 중요
3. 중단 조건 (n이 5를 초과하면 중단)
<div align = "center">
<img width="417" alt="다운로드 (1)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8ced68a4-4eff-4651-94ec-cae59995935a">
</div>      

<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3f6d5c70-2608-41d9-b33f-d75524cdef1">
</div>      

```java
public class Sigma {
	public static void main(String[] args) {
		System.out.println(sigma(1, 1)); // n = 1, sum = 1으로 시작해 5까지의 합을 재귀방식으로 구현
	}
	
    public static int f (int n) { // f(n)
    	return n;
    }
    
    public static int sigma(int n, int sum) { 
    	if(n > 5) return sum; // n이 5보다 크면 합인 sum 값 return (종단 조건)
    	
    	int nextSum = (n == 1) ? f(n) : sum + f(n); 
        /*
         * 다음 값의 합에 대해
         *  1. n = 1이면, 그 값은 f(1)
         *  2. n > 1이면, sum + f(n) [ sum은 수의 합]
    	 */
         
    	return sigma(n + 1, nextSum); // 현재는 n이었으므로, 다음 수인 sum과 현재까지 더해진 nextSum에 대해 재귀
    }
}
```
<div align = "center">
<img width="458" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/eaabfb9b-66e0-49dd-b088-e467cb7b1ae6">
</div>      

-----
### 공의 이동 거리 (반복 순차 방식)
-----    
1. 위에서 공을 떨어트렸을 때 공의 높이가 1 미만이 될 때까지 공의 이동 거리의 총합을 구하는 문제
<div align = "center">
<img src = "https://github.com/sooyounghan/Data-Structure/assets/34672301/75c36ae8-1619-48fe-964d-288cbb8eb4aa">
</div>   
   
2. 중단 조건 (높이가 1 미만일 때)
<div align = "center">
<img width="429" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/74caf75d-f37a-4b82-98cb-5cc10702b2b3">
</div>   

```java
public class Sum {
	public static void main(String[] args) {
		System.out.println(sum(16, 0));
	}
	
    public static int sum(int h, int prevSum) { // h는 높이, prevSum는 이전까지의 합
    	if(h < 1) return prevSum; // h가 1보다 작으면, 합 return
    	
    	int an = (prevSum == 0) ? h : h * 2; // 이전합이 0이란 뜻은 최초값은 한 번만 튕기므로 h, 그 다음부터는 왔다가 다시 그 높이만큼 튕기므로 h * 2
    	int sum = prevSum + an; // 현재까지의 합은 이전합 + 현재 튀었다가 다시 오른 높이
    	
    	return sum(h / 2, sum); // 높이는 점점 h/2이 되므로, h/2이고, 합은 현재까지 sum을 재귀
    }
}
```

-----
### 피보나치 수열 (반복 순차 방식)
-----    
1. 피보나치 수열은 첫 번째 항과 두 번째 항이 1이며, 이전 항의 합이 다음 항이 되는 수열 (규칙을 통해 일반항 도출 가능)
<div align = "center">
<img src = "https://github.com/sooyounghan/Data-Structure/assets/34672301/ad6402d1-d256-4756-815d-a62ac331f7e0">
</div>   

2. 중단 조건 (n이 5를 초과할 때 중단)
<div align = "center">
<img width="486" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4bbec929-38ea-414d-88e8-c93d589b5c6c">
</div>  

```java
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
```

-----
### 피보나치 수열 (분할 병합 방식 // Divide and Conquer)
-----   
<div align = "center">
<img width="547" alt="img" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/82ddbad5-3205-4a54-b848-6a8fa7f5cea7">
</div>  

1. 분할 방식 : 큰 문제를 계속 작은 문제로 쪼개어 분할
2. 합병 방식 : 작은 문제로 쪼개어 분할한 것을 해결한 뒤, 해결된 문제들을 역순으로 합하는 방식
3. 점화식 문제도 가능

       ** Stack Frame에 Pop 성질을 이용하여, 재귀적 호출이 종단 조건을 만났을 때 병합

4. 중단 조건 (n = 1 또는 n = 2)
```java
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
```

-----
### 조합 (분할 병합 방식 // Divide and Conquer)
-----  
<div align = "center">
<img width="595" alt="img (1)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/eb0df596-8aa1-4c4f-91f3-74ce2510dcce">
</div>  
1. 조합을 구할 때, 점화식 관점에서 분할 합병 방식으로 해결 가능
2. 중단 조건 (r = 0 또는 n = r)   

```java
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
```

-----
### 재귀 - 백트래킹(Back Tracking)
-----  
1. 퇴각 검색
2. 재귀 호출 시, Stack Frame에 쌓이고 Pop 되는 스택의 특징을 이용 → 탐색 가능한 이전 경우로 돌아가서 다시 탐색
3. 조건이 만족하는 한 모든 경우의 수를 탐색

-----
### 백트래킹(Back Tracking) - 미로 탈출
-----  

<div align = "center">
<img src = "https://github.com/sooyounghan/Data-Structure/assets/34672301/d83d3129-d05f-493d-b97d-b15871880fa0">
</div>  

1. 구성   
   - 미로를 구성하는 배열은 0과 1의 값으로 저장
   - 1은 메이즈 헌터가 지나갈 수 없는 벽, 0은 지나갈 수 있는 길
   - 미로에는 입구와 출구가 있으며, 입구에서부터 시작해 출구로 찾아 나서면 끝

2. 메이즈 헌터의 중단 조건
   - 벽이 존재하는 곳에 이동할 수 없음
   - 미로를 넘어서 이동할 수 없음
   - 방문했던 곳으로 가지 않음

3. 좌로 이동 (중단 조건)
<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4cc41d68-bea4-4134-99f6-73d9c69fabb4">
</div>  

4. 우로 이동 (중단 조건)
<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b83c2a80-0e1f-4432-af42-ee7b627dcaf3">
</div>  

5. 위로 이동 (중단 조건)
<div align = "center">
<img width="640" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d05a20d0-6ef4-4de7-a894-03a47280a7b1">
</div>  

6. 아래로 이동 (중단 조건)
<div align = "center">
<img width="640" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/495cc518-8893-47c8-9b49-eb37ae5a197d">
</div>  

7. 미로 찾기
<div align = "center">
<img width="640" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b320b5f5-0ff0-4b69-a439-a28120e5ded2">
</div>  

    1. move 메서드의 재귀적 호출을 통해 Stack Frame에 쌓아 나가는 방식으로 이동
    2. 우로 이동하는 메서드가 계속 호출되다가 이동할 수 없는 상황
    3. 해당 메서드는 중단하며, 이전 메서드의 실행 흐름으로 돌아가 그 다음 구문인 아래로 이동하는 메서드 호출
    4. 아래로 이동할 수 없는 상황이 오면, 이전 메서드의 실행 흐름으로 돌아가 좌로 이동하는 메서드를 호출
    5. 이렇게 우, 아래, 좌, 위 이동 메서드를 호출하면서 중단 조건을 만나면 이전 실행 흐름 부터 시작
     → 백트래킹(BackTraking)

< 중단 조건 >   
   A. 출구를 찾음   
   B. 또는 이동할 수 없는 상황
   
<div align = "center">
<img width="640" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2274ce42-7f2d-4e45-aadf-91f6662e9827">
</div>  

```java
/*
 * Backtracking - Maze Problem(미로찾기)
 */
public final class Maze_problem {
	/*
	 * 미로 배열 생성
	 */
    private final int[][] mazeArray = {
    									{1, 1, 1, 1, 1, 1, 1, 1},
    									{0, 0, 0, 0, 0, 0, 0, 1},
    									{1, 1, 1, 0, 1, 1, 1, 1},
    									{1, 0, 0, 0, 0, 0, 0, 0},
    									{1, 1, 1, 1, 1, 1, 1, 1},
    								  };
    
    /*
     * 방문 체크 배열 생성
     */
    private final boolean[][] mazeVisitArray = {
    											{false, false, false, false, false, false, false, false},
    											{false, false, false, false, false, false, false, false},
    											{false, false, false, false, false, false, false, false},
    											{false, false, false, false, false, false, false, false},
    											{false, false, false, false, false, false, false, false}
    										   };
    
    private boolean isFinished = false; // 최종 지점 도착을 확인하기 위한 변수
    private final int DEST_X = 7; // 최종 도착 지점의 X좌표 지정
    private final int DEST_Y = 3; // 최종 도착 지점의 Y좌표 지정
    private final int START_X = 0; // 처음 시작 지점 X좌표 지정
    private final int START_Y = 1; // 처음 시작 지점 Y좌표 지정
    private final int WALL = 1; // 벽은 문제 조건에 따라 1로 지정
    
    public void escape() {
    	/*
    	 * 탈출을 시작하는 메서드
    	 */
    	System.out.println("Start!");
    	move(START_X, START_Y);
    }
    
    private void visit(int x, int y) {
    	/*
    	 * 미로 방문 메서드
    	 */
    	mazeVisitArray[y][x] = true; // 해당 좌표 값에 대해 방문 했으므로 true
    	System.out.print("("+ x + ", " + y + ")"); // 좌표값 표시
    	System.out.println();
    }
    
    private void move(int x, int y) {
    	if(isFinished) {
    		/*
    		 * 길을 찾았으면 더 이상 탐색하지 않아야 함
    		 * 미로를 찾더라도, 실행 흐름 상 모든 메서드가 pop되어질 때 까지
    		 * 재귀 메서드가 계속 호출되기 떄문에 미로를 찾으면 다른 메서드는
    		 * 더 이상 탐색하지 않도록 빠르게 중단해야함
    		 */
    		return; // 메서드 종료
    	}
    	
    	else if(x == DEST_X && y == DEST_Y) {
    		/*
    		 * 도착 지점에 도착하게 되면
    		 */
    		isFinished = true; // 최종 지점에 도착함을 알리는 변수는 true
    	}
    	
    	else if(x < 0 || y < 0 || x > mazeArray[y].length - 1 || y > mazeArray.length - 1) {
    		/*
    		 * 미로를 넘어서게 되면 메서드 종료
    		 */
    		
    		return; // 메서드 종료
    	}
    	
    	else if (mazeArray[y][x] == WALL) {
    		/*
    		 * 미로에서 벽을 넘으면 메서드 종료
    		 */
    		
    		return; // 메서드 종료
    	}
    	
    	else if(mazeVisitArray[y][x] == true) {
    		/*
    		 * 방문했던 곳을 다시 방문한다면 메서드 종료
    		 */
    		
    		return;
    	}
    	
    	visit(x, y); // 조건에 다 불일치하면, 길이 있는 뜻으로 방문
    	
    	move(x + 1, y); // 오른쪽으로 이동
    	move(x, y + 1); // 아래쪽으로 이동
    	move(x - 1, y); // 왼쪽으로 이동
    	move(x, y - 1); // 위쪽으로 이동
    }
}
```
```java
public class Maze_Main {
	public static void main(String[] args) {
		Maze_problem maze = new Maze_problem(); // 미로 문제 객체 생성
		maze.escape(); // 탈출 시작
		System.out.println("Escape!"); // 탈출 완료되면 표시
	}
}
```
