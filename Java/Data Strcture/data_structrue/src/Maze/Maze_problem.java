package Maze;

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
