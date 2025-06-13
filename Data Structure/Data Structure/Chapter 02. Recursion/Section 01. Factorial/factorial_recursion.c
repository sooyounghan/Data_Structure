int factorial(int n) {
    printf("factorial(%d)\n", n);

    if( n <= 1 ) return ;
    else return (n * factorial(n - 1));
}