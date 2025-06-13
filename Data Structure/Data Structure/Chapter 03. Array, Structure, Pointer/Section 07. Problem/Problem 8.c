// 시간 복잡도 : O(n)
void insert(int array[], int loc, int value) {
    for(int i = loc; i < n; i++) {
        array[i + 1] = array[i];
    }

    array[loc] = value;
    items++;
}