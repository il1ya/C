switch ( /*variable*/ ) 
{
case const1:
  /*Тут находится код, который необходимо выполнить, если переменная  variable будет равна const1*/
  break;
case const2:
  /*этот код выполнится, если variable будет равна const2*/
  break;
/*...*/
default:
  /*Код, который выполнится, если ниодно из константых значению не соответствует значение в переменной variable*/
  break;
}

#include <stdio.h>
 
int main()
{
    printf( "Что бы сегодня посмотреть?\n" );
    printf( "1. Стрела(Arrow)\n" );
    printf( "2. Сверхъестественное(Supernatural)\n" );
    printf( "3. Ходячие мертвецы(Walking Dead)\n" );
    printf( "4. Выход\n" );
    printf( "Ваш выбор: " );
    int input;
    scanf( "%d", &input );
    switch ( input ) {
        case 1:            /* обратите внимание на двоеточие, точки сзапятой тут нет */
            printf("«His Death Was Just The Beginning»\n");
            break;
        case 2:
            printf("«Scary Just Got Sexy»\n");
            break;
        case 3:
            printf("«Fight the dead. Fear the living»\n");
            break;
        case 4:
            printf( "Сегодня смотреть ничего не будем :(\n" );
            break;
        default:
            printf( "Неправильный ввод.\n" );
    }
    getchar();
    return 0;
}