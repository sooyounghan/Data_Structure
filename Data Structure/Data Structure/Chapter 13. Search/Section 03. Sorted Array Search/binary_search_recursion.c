int search_binary(int key, int low, int high) {
    int middle;

    if(low < high) {
        middle = (low + high) / 2; // middle은 low와 high의 중간 인덱스

        if(key == list[middle]) {
            // 중간 인덱스의 위치한 값과 일치하면 탐색 성공
            return middle;
        }
        else if(key < list[middle]) { // 왼쪽 부분리스트 검색
            return search_binary(key, low, middle - 1);
        } else { // 오른쪽 부분 리스트 검색
            return search_binary(key, middle + 1, high);
        }
    }

    return -1; // 탐색 실패 경우
}