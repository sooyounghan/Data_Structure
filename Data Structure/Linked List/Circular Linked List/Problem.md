-----
### 문제
-----
1. search() : 원형 연결 리스트에서 특정 값을 탐색하는 함수
```c
// 문제 3 : 원형 연결 리스트에서 특정 값을 탐색하는 함수
ListNode* search(ListNode *L, element data) {
    ListNode *p = L; // 포인터 p는 리스트 L을 가리킴

    if(L == NULL) return NULL; // 원형 연결 리스트가 공백 리스트일 때, NULL 반환

    do { // 무조건 처음 1번은 실행
        if(p->data == data) { // 특정 값을 찾으면,
            return p; // 해당 노드 반환
        } else { // 아니라면,
            p = p->link; // 다음 노드로 이동
        }
    } while(p != L); // 원형 연결 리스트이므로 다시 L로 돌아올 때까지 반복

    return NULL; // 없다면 NULL 반환
}
```

2. get_size() : 저장된 데이터의 개수를 반환하는 함수\
```c
// 문제 4 : 저장된 데이터의 개수를 반환하는 함수
int get_size(ListNode *L) {
    ListNode *p = L;
    int size = 0; // 초기 크기는 0 

    if(L == NULL) return 0; // 만약 공백 리스트라면 크기는 0 반환

    do { 
        size++; // 공백 리스트가 아니라면, 크기는 1씩 증가
        p = p->link; // 다음 노드 이동
    } while(p != L); // 원형 연결 리스트이므로 한 바퀴를 돌 떄까지 반복

    return size; // 크기 값 반환
}
```
