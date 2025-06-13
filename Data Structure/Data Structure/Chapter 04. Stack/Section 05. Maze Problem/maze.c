#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // 스택 최대 크기
#define MAZE_SIZE 6 // 미로의 크기기

typedef struct element {
    short r;
    short c;
} element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

element here = { 1, 0 }, entry = { 1, 0 }; // 현재 위치와 입구 위치 설정
char maze[MAZE_SIZE][MAZE_SIZE] = { // 미로 생성
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '1', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' },
};

// 스택 초기화 함수
void init_stack(StackType *s) {
    s->top = -1; // 스택 초기화는 스택 구조체 포인터의 변수의 값을 -1로 지정
}

// 공백 상태 확인 함수
int is_empty(StackType *s) {
    return (s->top == -1);
}

// 포화 상태 확인 함수
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE- 1));
}

// 삽입 함수
void push(StackType *s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    } 

    else s->data[++(s->top)] = item;
}

// 위치를 스택에 삽입
void push_loc(StackType *s, int r, int c) {
    if(r < 0 || c < 0) return; // 미로 외의 범위면 오류
    if(maze[r][c] != '1' && maze[r][c] != '.') { // 1(벽)이거나 .(이미 방문)인 경우에는 스택에 넣지 않음
        element temp; 
        temp.r = r;
        temp.c = c;
        push(s, temp); // 아닌 경우, 스택에 삽입
    }
}

// 미로를 화면에 출력
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");
    for(int r = 0; r < MAZE_SIZE; r++) {
        for(int c = 0; c < MAZE_SIZE; c++) {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

// 스택에서 좌표를 꺼내오는 함수
element pop(StackType *s) {
    if(is_empty(s)) {  
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } 
    
    else return s->data[(s->top)--];
}

// Peek 함수
element peek(StackType *s) {
    if(is_empty(s)) {  
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } 
    
    else return s->data[s->top];
}

int main(void) {
    int r, c;
    StackType s;

    init_stack(&s); // 스택 초기화

    here = entry; // 현재 위치 = 입구

    while(maze[here.r][here.c] != 'x') { // 출구를 찾을 때 까지 
        r = here.r; // 현재 위치의 행 저장
        c = here.c; // 현재 위치의 열 저장

        maze[r][c] = '.'; // 방문 표시

        maze_print(maze); 

        // 위, 아래, 왼쪽, 오른쪽 순으로 스택에 저장
        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);

        if(is_empty(&s)) { // 비어있다면, 찾지 못해서 실패
            printf("실패! \n");
            return 0;
        } else { 
            here = pop(&s); // 그렇지 않으면, 스택에서 가장 최상단의 좌표 추출
        }
    }

    printf("성공! \n");
    return 0;
}