#include <stdio.h>
void start_service(void){
    printf("Starting service...\n");
}
void stop_service(void){
    printf("Stopping service...\n");
}
int run_command(char cmd){
    switch(cmd){
        case 's':
        case 'S':
            start_service();
            return 0;
        case 't':
        case 'T':
            stop_service();
            return 0;
        case 'q':
        case 'Q':
            printf("Bye\n");
            return 0;
        case 'r':
        case 'R':
            stop_service();
            start_service();
            return 0;
        case '?':
            return 0;

        default:
            return 1;
    }
}
int main(){
    char cmd;
    int nr=0,ok=1;
    while(ok==1 && scanf(" %c", &cmd)==1){
        int y=run_command(cmd);
        if(y==1){
            nr++;
           printf("Unknown command: %c\n", cmd);
        }
        if(cmd=='?'){
            printf("Commands: s start, t stop, r restart, q quit\n");
        }
        if(cmd=='q' || cmd=='Q'){
            ok=0;
        }
    }
        if(nr!=0){
        return 2;
    }
    else{
        return 0;
    }

}