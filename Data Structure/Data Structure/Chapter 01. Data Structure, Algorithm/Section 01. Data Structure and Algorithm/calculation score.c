#define MAX_ELEMENTS 100
int score[MAX_ELEMENTS]; // 자료 구조

int get_max_score(int n) {
    int i, largest;
    
    // 알고리즘
    largest = score[0];

    // 알고리즘
    for(i = 0; i < n; i++) {
        if(score[i] > largest) {
            largest = score[i];
        }
    }

    return largest;
}