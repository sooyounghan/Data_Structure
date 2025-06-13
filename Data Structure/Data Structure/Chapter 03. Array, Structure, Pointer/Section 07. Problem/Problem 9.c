void delete(int array[], int loc) {
    for(int i = n; i > loc; i--) {
        array[i - 1] = array[i];
    }

    items--;
}