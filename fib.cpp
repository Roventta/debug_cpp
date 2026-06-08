#include <ostream>
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int a = fib(n-1);
    int b = fib(n-2); 
    return a + b;
}



int main() {
    // codes start to run from here

    // some meaningless lines here for tesing
    int one = 1;
    int two = 2;
    int three = one + two;

    int i = 3;
    printf("calculating fib %i\n", i);
    int result = fib(i);
    printf("%i", result);
    return 0;
}