#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 10 // 탐색 키의 최대 길이
#define TABLE_SIZE 13 // 해시 테이블의 크기는 소수

typedef struct {
    char key[KEY_SIZE]; // 키 배열
    // 다른 필요 필드
} element;

element hash_table[TABLE_SIZE]; // 해시 테이블

// 해시 테이블 초기화
void init_table(element ht[]) {
    int i;
    
    for(i = 0; i < TABLE_SIZE; i++) {
        ht[i].key[0] = NULL; // 해시 테이블의 KEY 값의 첫 글자를 NULL로 정의
    }
}

// 해시 함수 : 문자로 된 키를 숫자로 변환
int transform(char *key) {
    int number = 0;

     while(*key) { // 문자열에 대해
        number = 31 * number + *key++;
    }

    return number;
}

// 제산 함수를 사용한 해싱 함수
int hash_function(char *key) {

    // 키를 자연수로 변환 한 후에 테이블 크기로 나누어 나머지 반환
    return transform(key) % TABLE_SIZE;
}

#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key)) // 0이면 같은 값이므로 FALSE로 인식하므로 ! 연산자 사용

// 선형 조사법을 이용해 테이블에 키를 삽입하며, 테이블이 가득 찬 경우는 종료
void hash_lp_add(element item, element ht[]) {
    int i, hash_value;

    hash_value = i = hash_function(item.key); // item의 키 값을 해시 함수를 적용하면, 해시 인덱스가 나오므로 이 값을 현재 위치인 i와 Hash Value에 저장

    // printf("Hash Address = %d\n", i); // 해시 주소 확인

    while(!empty(ht[i])) { // 해시 테이블이 비어있지 않는 동안,
        if(equal(item, ht[i])) { // 삽입하려는 item과 i번째 해시 인덱스에 존재하는 값이 같으면 중복된 값
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }    

        i = (i + 1) % TABLE_SIZE; // 현재 인덱스 i는 다음 인덱스로 이동

        if(i == hash_value) { // 한 바퀴를 돌아 시작 위치로 돌아오면, 가득 찬 것 의미
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
     }

     ht[i] = item; // item 값을 해시 테이블의 i번째 위치에 삽입
}

// 선형 조사법을 이용해 테이블에 저장된 키 검색
void hash_lp_search(element item, element ht[]) {
    int i, hash_value;

    hash_value = i = hash_function(item.key);

    while(!empty(ht[i])) { // 해시 테이블이 비어있지 않는 동안,
        if(equal(item, ht[i])) { // 삽입하려는 item과 i번째 해시 인덱스에 존재하는 값이 같으면 성공
            fprintf(stderr, "탐색 %s : 위치 %d\n", item.key, i);
            return;
        }    

        i = (i + 1) % TABLE_SIZE; // 현재 인덱스 i는 다음 인덱스로 이동

        if(i == hash_value) { // 한 바퀴를 돌아 시작 위치로 돌아오면, 없음을 의미
            fprintf(stderr, "찾는 값이 테이블에 없음.\n");
            return;
        }
    }

    fprintf(stderr, "찾는 값이 테이블에 없없음 \n"); // 위 경우 모두 실패하면 없음을 의미
}

// 해싱 테이블의 내용 출력
void hash_lp_print(element ht[]) {
    int i;

    printf("==============================\n");
    for(i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] %s\n", i, ht[i].key);
    }
    printf("==============================\n\n");
}

// 이차 조사법 구현
void hash_qp_add(element item, element ht[]) {
    int i, hash_value, inc = 0; // inc는 이차 조사법을 위한 변수

    hash_value = i = hash_function(item.key); // item의 키 값을 해시 함수를 적용하면, 해시 인덱스가 나오므로 이 값을 현재 위치인 i와 Hash Value에 저장

    // printf("Hash Address = %d\n", i); // 해시 주소 확인

    while(!empty(ht[i])) { // 해시 테이블이 비어있지 않는 동안,
        if(equal(item, ht[i])) { // 삽입하려는 item과 i번째 해시 인덱스에 존재하는 값이 같으면 중복된 값
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }    

        i = (hash_value + (inc * inc)) % TABLE_SIZE; // 현재 인덱스 i는 다음 인덱스로 이동하되, inc의 제곱을 더하여 진행
        inc = inc + 1; // 1 증가가

        if(i == hash_value) { // 한 바퀴를 돌아 시작 위치로 돌아오면, 가득 찬 것 의미
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
     }

     ht[i] = item; // item 값을 해시 테이블의 i번째 위치에 삽입
}

// 이중 해싱법
void hash_dh_add(element item, element ht[]) {
    int i, hash_value, inc; // inc는 이중 해싱법을 위한 변수

    hash_value = i = hash_function(item.key); // item의 키 값을 해시 함수를 적용하면, 해시 인덱스가 나오므로 이 값을 현재 위치인 i와 Hash Value에 저장

    inc = hash_function2(item.key); // inc는 다른 해시 함수 적용한 값

    // printf("Hash Address = %d\n", i); // 해시 주소 확인

    while(!empty(ht[i])) { // 해시 테이블이 비어있지 않는 동안,
        if(equal(item, ht[i])) { // 삽입하려는 item과 i번째 해시 인덱스에 존재하는 값이 같으면 중복된 값
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }    

        i = (i + inc) % TABLE_SIZE; // 현재 인덱스 i는 다음 인덱스로 이동하되, 다른 해시 함수를 적용한 값 inc과 합으로 구성

        if(i == hash_value) { // 한 바퀴를 돌아 시작 위치로 돌아오면, 가득 찬 것 의미
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
     }

     ht[i] = item; // item 값을 해시 테이블의 i번째 위치에 삽입
}

// 해싱 테이블 사용 예제
int main(void) {
    char *s[7] = { "do", "for", "if", "case", "else", "return", "function"};

    element e;

    for(int i = 0; i < 7; i++) {
        strcpy(e.key, s[i]);
        hash_lp_add(e, hash_table); // 해싱 테이블에 추가
        hash_lp_print(hash_table); // 해싱 테이블 출력
    }

    for(int i = 0; i < 7; i++) {
        strcpy(e.key, s[i]); // s[i] 값을 복사
        hash_lp_search(e, hash_table); // 해당 값 탐색
    }

    return 0;
}