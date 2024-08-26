package Rercursion;

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