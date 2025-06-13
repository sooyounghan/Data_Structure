typedef struct Complex {
    float real;
    float imaginary;
} Complex;
 

Complex complex_add (Complex a, Complex b) {
    Complex result;

    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;

    return result;
}