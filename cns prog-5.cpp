#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main() {
    int a;
    printf("Values of 'a' not allowed in the affine Caesar cipher:\n");
    
    for (a = 1; a < 26; a++) {
        if (gcd(a, 26) != 1)
            printf("%d\n", a);
    }
    return 0;
}