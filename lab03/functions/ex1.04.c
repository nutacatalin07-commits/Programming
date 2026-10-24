#include <stdio.h>
void print_menu(void){
    printf("1. Show balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("0. Exit\n");
}
int can_withdraw(int balance, int amount){
    if(amount<=balance){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int balance=100,choice,amount;
    print_menu();
    do{
        if(scanf("%d", &choice)!=1){
            return 1;
        };
        switch(choice){
            case 1:
                printf("Balance: %d\n", balance);
                break;
            case 2:
                if(scanf("%d", &amount)!=1){
                    return 1;
                }
                if(amount>0){
                    balance=balance+amount;
                    printf("Deposited: %d\n", amount);
                }
                else{
                    printf("Error: invalid amount\n");
                }
                break;
                case 3:
                if(scanf("%d", &amount)!=1){
                    return 1;
                }
                if(amount>0 && can_withdraw(balance,amount)==1){
                    balance=balance-amount;
                    printf("Withdrawn: %d\n", amount);
                }
                else if(amount>0){
                    printf("Error: insufficient funds\n");
                }
                else{
                    printf("Error: invalid amount\n");
                }
                break;
                case 0:
                printf("Bye\n");
                break;
                default:
                printf("Error: unknown option\n");

            
        } 
     } while(choice!=0);
    return 0;
}
//am avut probleme atunci cand compilam programu nu mergea compilat normal,am intrb
//de la vs si mi a spus sa i dau asa gcc -Wall -Wextra -g ex1.04.c -o ex1.04 si a functionat