#include <stdio.h>

int main() {

int userMonth, userDay;
scanf("%d %d", &userMonth, &userDay);

if (userMonth == 1) {
    printf("%d %d is January %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay);
}
else if (userMonth == 2) {
    printf("%d %d is February %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 31);
}
else if (userMonth == 3) {
    printf("%d %d is March %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 60);
}
else if (userMonth == 4) {
    printf("%d %d is April %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 91);
}
else if (userMonth == 5) {
    printf("%d %d is May %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 121);
}
else if (userMonth == 6) {
    printf("%d %d is June %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 152);
}
else if (userMonth == 7) {
    printf("%d %d is July %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 182);
}
else if (userMonth == 8) {
    printf("%d %d is August %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 213);
}
else if (userMonth == 9) {
    printf("%d %d is September %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 244);
}
else if (userMonth == 10) {
    printf("%d %d is October %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 274);
}
else if (userMonth == 11) {
    printf("%d %d is November %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 305);
}
else if (userMonth == 12) {
    printf("%d %d is December %d, 2020, day %d of the year\n", userMonth, userDay, userDay, userDay + 355);
}

    return 0;
}