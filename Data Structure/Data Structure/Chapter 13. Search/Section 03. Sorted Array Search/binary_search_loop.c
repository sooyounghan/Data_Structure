int search_binary(int key, int low, int high) {
    int middle;

    while(low < high) { // 아직 숫자들이 남아있으면,
        middle = (low + high) / 2; // middle은 low와 high의 중간 인덱스

        if(key == list[middle]) {
            // 중간 인덱스의 위치한 값과 일치하면 탐색 성공
            return middle;
        }
        else if(key > list[middle]) { // 오른쪽 부분리스트 검색
            low = middle + 1;
        } else { // 왼왼쪽 부분 리스트 검색
            high = middle - 1;
        }
    }

    return -1; // 탐색 실패 경우 (발견되지 않음)
}