int seq_search(int key, int low, int high) {
    int i;

    for(i = low; i <= high; i++) { // 인덱스 low에서부터 high까지
        if(list[i] == key) {
            return i; // key와 일치하는 값을 찾으면, 탐색에 성공하므로 키 값의 해당 인덱스 반환
        }    
    }

    return -1; // 그렇지 않으면 탐색에 실패하여 -1 반환
}