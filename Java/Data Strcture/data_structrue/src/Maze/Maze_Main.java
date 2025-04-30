package Maze;

public class Maze_Main {
	public static void main(String[] args) {
		Maze_problem maze = new Maze_problem(); // 미로 문제 객체 생성
		maze.escape(); // 탈출 시작
		System.out.println("Escape!"); // 탈출 완료되면 표시
	}
}
