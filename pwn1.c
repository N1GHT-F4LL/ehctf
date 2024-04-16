#include<stdio.h>
#include <stdlib.h>
#include <time.h>

// unsigned int inputInt(){
//     char buffer[10];
//     scanf("%8s", buffer);
//     for(int i = 0; i < 8; i++){
//         if((*buffer + i) == '+' & (*buffer + i) == '-'){
//             exit(0);
//         }
//     }
//     return atoi(buffer);
// }
void setup(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int add(int num1, int num2){
    return num1 + num2;
}
int sub(int num1, int num2){
    return (num1 > num2)? (num1 - num2):(num2 - num1);
}
int mul(int num1, int num2){
    return num1 * num2;
}
int divi(int num1, int num2){
    return num1 % num2;
}
void loadSecretFunction(){
    puts("Loading.....");
    system("/bin/sh;");
    exit(0);
}
int main(){
    time_t t;
    int n, choice;
    setup();
    // srand((unsigned) time(&t));
    // printf("Hello hacker. \nDo you want to hack this program?\n");
    // printf("Look good! First, Hack this time 🤖\n");
    // for(int i = 0; i < 10; i++){
    //     printf("Enter num[%d]: ", i);
    //     if(inputInt() != rand()%1337){
    //         exit(0);
    //     }
    //     printf("\n");
    // }
    // printf("Keep tracking...\n");
    do{
        int num1, num2;
        int result;
        puts("\n  ####      ##     ##        ####    ##  ##   ##         ##     ######    ####    #####           ");
        puts(" ##  ##    ####    ##       ##  ##   ##  ##   ##        ####      ##     ##  ##   ##  ##          ");
        puts(" ##       ##  ##   ##       ##       ##  ##   ##       ##  ##     ##     ##  ##   ##  ##          ");
        puts(" ##       ######   ##       ##       ##  ##   ##       ######     ##     ##  ##   #####           ");
        puts(" ##       ##  ##   ##       ##       ##  ##   ##       ##  ##     ##     ##  ##   ####            ");
        puts(" ##  ##   ##  ##   ##       ##  ##   ##  ##   ##       ##  ##     ##     ##  ##   ## ##           ");
        puts("  ####    ##  ##   ######    ####     ####    ######   ##  ##     ##      ####    ##  ##       v.1\n");
        puts("Enter 1st number: ");
        scanf("%d", &num1);
        puts("Enter 2nd number: ");
        scanf("%d", &num2);
        if(num1 <= 0 && num2 <= 0){
            printf("My calc can not perform negative number\n");
            exit(0);
        }
        puts("What do you want to perfrom?\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                result = add(num1, num2);
                break;
            }
            case 2: {
                result = sub(num1, num2);
                break;
            }
            case 3: {
                result = mul(num1, num2);
                break;
            }
            case 4: {
                result = divi(num1, num2);
                break;
            }
            default:{
                puts("Don't try to hack me, Hmmm !!!\n");
                exit(0);
            }
        }
        if(result >= 0){
            printf("Result = %d\n", result);
        }else{
            printf("Try to hack me ??\n");
        }
        if(result == 0xDEAD1337){
            loadSecretFunction();
        }
    } while(choice != 0);
    return 0;
}