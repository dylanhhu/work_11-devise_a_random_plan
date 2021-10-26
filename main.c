#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int rand_nums[10];
    int read_nums[10];

    int file = open("/dev/random", O_RDONLY);

    if (file != -1) {
        ;
    }
    else return file;

    printf("Generating random numbers:\n");
    int i;
    for (i = 0; i < 10; i++) {
        printf("\trandom %d: %d\n", i, rand_nums[i]);
    }

    return 0;
}
