/*
    n = 1 : 1 (= div(1))
    n = 2 : 1 + 1 / 2 = div(1) + 1 / 2)
    n = 3 : 1 + 1 / 2 + 1 / 3 = div(2) + 1 / 3
    ...
*/
double div(int n) {
    if (n == 1) return 1;
    else return ((double) 1 / n) + div(n - 1);
}