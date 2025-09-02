/* Task description:
There is a mistake in the code similar to those seen on the previous practice. 
Do you get any compiler message? What happens when you run the program and why? 
Is there any difference between the two versions? Discuss it with your lab conductor.
*/


#include <stdio.h>

int *f1(int i) {
    return &i;
}

int main(void) {
    int *p;
    p = f1(10);
    printf("%d\n", *p);
    printf("%d\n", *p);
    return 0;
}
/* //comment the other and uncomment this to run
int *f1(int i) {
    return &i;
}

int main(void) {
    int x = 10;
    int *p = f1(x);
    printf("%d\n", *p);
    printf("%d\n", *p);
    return 0;
}
*/
