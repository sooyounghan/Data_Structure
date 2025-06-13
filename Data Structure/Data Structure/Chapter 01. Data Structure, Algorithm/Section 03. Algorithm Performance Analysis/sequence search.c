int seq_search(int list[], int key) {
    int i;
    // 배열의 길이는 n
    for (i = 0; i < n; i++)
    {
        if(list[i] == key) {
            return i; // 탐색에 성공하면 키 값 인덱스 반환
        }
        return -1; // 탐색에 실패하면 -1 반환
    }
    
}