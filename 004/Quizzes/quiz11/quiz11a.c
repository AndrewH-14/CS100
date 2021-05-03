#include <stdio.h>

int fun1(int a, int b) {
        if (a == b) return a;

        if (a > b)
                return fun1(a-b, b);
        else
                return fun1(a, b-a);
}


// int fun1(int a, int b) {
//         //int val = 0;
//         while (a != b) {
//                 if (a > b) {
//                         a = a - b;
//                 }
//                 else {
//                         b = b - a;
//                 }
//         }
//         return a;
// }

int main(void) {
        printf("Enter two postitive integers: ");
        int num1, num2;
        scanf("%d%d", &num1, &num2);

        int result=fun1(num1, num2);

        printf("The result is %d\n", result);

        return 0;
}