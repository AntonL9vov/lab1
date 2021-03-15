#include <stdio.h>
#include "menu.h"

int main() {
    int n;
    do {
        printMenu();
        printf("\n\nDo you want try again?\n"
               "1)Yes, one more time\n"
               "2)No, quit\n");
        scanf("%d", &n);
    } while (n==1);
    return 0;
}
