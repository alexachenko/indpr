#include "главный.h"

int main(void)
{
    int prg=0;
    do{
        srand(time(NULL));
        struct test proga[20];//считать с файла вопросы и ответы к ним (должно быть 5 файлов)
        
        readf(proga);
        int n;
        
        int mass_ans[20]={0};//массив ответов
        
        do{
            printf("введите количество вопросов, на которое хотите ответить (от 1 до 20)\n"); scanf("%d", &n);
        }while (n<1 || n>20);
        
        int rezim;//выбор режима( тренировка или экзамен)
        do{
            printf("выберите режим\n1-тренировка\n2-экзамен\n");
            scanf("%d", &rezim);
        }while (rezim<1 || rezim>2);
        
        if (rezim==1){//тренировка
            tren(mass_ans, proga, n);}
        else{//экзамен
            exam(n, mass_ans, proga);}
        
        printf("Если хотите закончить выполнение программы, нажмите 0\nЕсли хотите пройти тест ещё раз, введите любое целое число\n");scanf("%d", &prg);
    }while (prg!=0);
}

