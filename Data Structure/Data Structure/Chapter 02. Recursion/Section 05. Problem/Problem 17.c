int binomal_coefficient_recursion(int n, int k) {
        if (n == 0 || n == k) return 1; 
    else binomal_coefficient_recursion(n - 1, k - 1) + binomal_coefficient_recursion(n - 1, k);
}