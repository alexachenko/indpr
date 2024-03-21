
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct test{
    char quest[1000];//вопросы [256]
    char ans[4][1000];//ответы. 1- всегда правильный. [4][256]
};
void readf(struct test proga[20]);
void tren(int mass_ans[20], struct test proga[20], int n);
void exam(int n, int mass_ans[20],struct test proga[20]);

