#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int gen_rand_int();

int main() {
    int rand_nums[10];
    int read_nums[10];

    int i;
    for (i = 0; i < 10; i++) {
        rand_nums[i] = gen_rand_int();
    }

    printf("Generating random numbers:\n");
    for (i = 0; i < 10; i++) {
        printf("\trandom %d: %d\n", i, rand_nums[i]);
    }

    printf("\nWriting numbers to file...\n");
    int file = open("rand_nums.bruh", O_WRONLY | O_CREAT, 0644);
    write(file, rand_nums, sizeof(rand_nums));
    close(file);

    printf("\nReading numbers from file...\n");
    file = open("rand_nums.bruh", O_RDONLY);
    read(file, read_nums, sizeof(read_nums));
    close(file);

    printf("\nVerification that written values were the same:\n");
    for (i = 0; i < 10; i++) {
        printf("\trandom %d: %d\n", i, read_nums[i]);
    }

    return 0;
}


// Generates a random int by reading from
// /dev/random
int gen_rand_int() {
    int * buf = malloc(sizeof(int));

    int file = open("/dev/random", O_RDONLY);
    read(file, buf, sizeof(int));
    close(file);

    // free malloc'd memory, so that
    // we don't waste memory
    int temp = *buf;
    free(buf);

    return temp;
}
