
#include "Функции.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "главный.h"

void readf(struct test proga[20]){
    int n1=20;
    FILE* f=fopen("f.quest.txt","r");
    for (int i=0; i<n1; i++){
        fgets(proga[i].quest, 1000, f);
    }
    fclose(f);
    
    //1 ответ (правильный)
    FILE* f0=fopen("f.ans0.txt","r");
    for (int i=0; i<n1; i++){
        fgets(proga[i].ans[0], 1000, f0);
    }
    fclose(f0);
    
    //2 ответ
    FILE* f1=fopen("f.ans1.txt","r");
    for (int i=0; i<n1; i++){
        fgets(proga[i].ans[1], 1000, f1);
    }
    fclose(f1);
    
    //3 ответ
    FILE* f2=fopen("f.ans2.txt","r");
    for (int i=0; i<n1; i++){
        fgets(proga[i].ans[2], 1000, f2);
        
    }
    fclose(f2);
    
    //4 ответ
    FILE* f3=fopen("f.ans3.txt","r");
    for (int i=0; i<n1; i++){
        fgets(proga[i].ans[3], 1000, f3);
    }
    fclose(f3);
}
void tren(int mass_ans[20], struct test proga[20], int n){
    for (int i=0; i<n; i++){
    int que;
    que=rand()%(20);
    
    do
    {
        if (mass_ans[que]==1) que=(que+1)%20;
    }while (mass_ans[que]==1);
    mass_ans[que]=1;
    
    printf("%d. %s\n", i+1, proga[que].quest);//выводим вопрос на экран
    
    int mass_anss[4]={0};
    int right = 0;//инициализировала, зачем?????
    
    for (int j=0; j<4;j++){
        int ans;
        ans=rand()%4;
        do
        {
            if (mass_anss[ans]==1) ans=(ans+1)%4;
        }while (mass_anss[ans]==1);
        mass_anss[ans]=1;
        printf("%d) %s\n", j+1,proga[que].ans[ans]);//выводим ответы по очереди на экран
        if (ans==0) right=j+1;//запоминаем индекс правильного ответа
    }
        
    //для экзамена нужна переменная с общей суммой, потом поделить на общее количество вопросов
    //тест
    int ot;
    do{
        scanf("%d", &ot);
        if (ot==right) printf("вы ответили верно\n");
        else{printf("вы ответили неверно\n");}
    }while(ot!=right);
}
}
void exam(int n, int mass_ans[20],struct test proga[20]){
    //для экзамена
    int rez=0, osh=0;
    char q_osh[n][1000];//массив вопросов с ошибками
    char a_osh[n][1000];//правильный ответ
    int n_osh[n];//номера вопросов с неправильными ответами
    for (int i=0; i<n; i++)
    {
        int que;
        que=rand()%(20);
        do
        {
            if (mass_ans[que]==1) que=(que+1)%20;
        }while (mass_ans[que]==1);
        mass_ans[que]=1;
        
        printf("%d. %s\n", i+1, proga[que].quest);//выводим вопрос на экран
        
        int mass_anss[4]={0};
        int right = 0;//инициализировала, зачем?????
        
        for (int j=0; j<4;j++)
        {
            int ans;
            ans=rand()%4;
            do
            {
                if (mass_anss[ans]==1) ans=(ans+1)%4;
            }while (mass_anss[ans]==1);
            mass_anss[ans]=1;
            printf("%d) %s\n", j+1,proga[que].ans[ans]);//выводим ответы по очереди на экран
            if (ans==0) right=j+1;//запоминаем индекс правильного ответа
        }
        //для экзамена нужна переменная с общей суммой, потом поделить на общее количество вопросов
        //тест
        int ot;
        do{
            printf("введите ответ (1, 2, 3 или 4)\n");
            scanf("%d", &ot);
            if (ot==right) rez++;
            else
            {
                strcpy(q_osh[osh], proga[que].quest);
                strcpy(a_osh[osh], proga[que].ans[0]);
                n_osh[osh]=que;//вводим номер вопроса, где была допущена ошибка.
                osh++;
            }
        }while(ot<1 || ot>4);
    }
    printf("Результат экзамена: %d из %d\nОценка: %d\nКоличество ошибок: %d\n", rez, n, ((rez*5)/n)+1, osh);
    for (int i=0; i<osh; i++){
        printf("Ошибка %d: %s\n", i+1, q_osh[i]);
        printf("    Правильный ответ: %s\n", a_osh[i]);
    }
    if (osh>0)
    {
    int prg1=0;
    printf("Хотите сделать работу над ошибками?\nДа: нажмите 1\n Нет: любое целое число\n");scanf("%d", &prg1);
        if (prg1==1){
            for (int i1=0; i1<osh; i1++)
            {
                printf("%d. %s\n", i1,proga[n_osh[i1]].quest);
                
                int mass_anss[4]={0};
                int right = 0;//инициализировала, зачем?????
                
                for (int j=0; j<4;j++){
                    int ans;
                    ans=rand()%4;
                    do
                    {
                        if (mass_anss[ans]==1) ans=(ans+1)%4;
                    }while (mass_anss[ans]==1);
                    mass_anss[ans]=1;
                    printf("%d) %s\n", j+1,proga[n_osh[i1]].ans[ans]);//выводим ответы по очереди на экран
                    if (ans==0) right=j+1;//запоминаем индекс правильного ответа
                }
                //для экзамена нужна переменная с общей суммой, потом поделить на общее количество вопросов
                //тест
                int ot;
                do{
                    scanf("%d", &ot);
                    if (ot==right) printf("вы ответили верно\n");
                    else{printf("вы ответили неверно\n");}
                }while(ot!=right);
            }
        }
    }
}
