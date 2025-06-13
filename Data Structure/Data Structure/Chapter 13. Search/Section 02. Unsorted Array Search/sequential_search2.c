int seq_search2(int key, int low, int high) {
    int i;

    list[high + 1] = key; // 가장 마지막 인덱스에 key값 저장

    for(i = low; list[i] != key; i++) { // list[i]가 key값을 찾을 때까지 반복
        ;
    }

    if(i == (high + 1)) return -1; // high + 1, 즉 맨 끝 인덱스에 도달하면 탐색 실패한 것이므로 -1 반환
    return i; // 그렇지 않으면 탐색에 성공하여 해당 위치 반환
}