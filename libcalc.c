double calc_add(double a, double b) {
    return a + b;
}

double calc_sub(double a, double b) {
    return a - b;
}

double calc_mul(double a, double b) {
    return a * b;
}

double calc_div(double a, double b) {
    if (b == 0) {
        // division by zero error
        return 0;
    }
    return a / b;
}
