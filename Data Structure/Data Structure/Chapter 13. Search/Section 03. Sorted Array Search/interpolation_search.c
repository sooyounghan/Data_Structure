int interpolation_search(int key, int n) {
    int low, high, j;

    low = 0; // 첫 번쨰 인덱스
    high = n - 1; // 마지막 인덱스

    while((list[high] >= key) && (key > list[low])) { // 리스트 내 범위에 존재 (key == list[low]인 경우 보간 위치 계산을 할 필요 없이 바로 low를 반환해도 되기 때문에 커야함)
        j = ((float) (key - list[low]) / (list[high] - list[low]) * (high - low) + low); // 보간 탐색 위치 값 계산
        
        if(key > list[j]) low = j + 1; // 보간 탐색으로 찾은 인덱스에 위치한 값보다 key 값이 크면, 오른쪽 부분 리스트 탐색
        else if (key < list[j]) high = j - 1; // 왼쪽 부분 리스트 탐색
        else low = j; // 같으면 low에 인덱스 저장
    }

    if(list[low] == key) {
        return low; // 탐색 성공
    }

    else {
        return -1; // 탐색 실패
    }
}