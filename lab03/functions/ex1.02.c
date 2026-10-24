#include <stdio.h>
int is_client_error(int code){
    if(code/100==4){
        return 1;
    }
    else{
        return 0;
    }
}
int is_server_error(int code){
    if(code/100==5){
        return 1;
    }
    else{
        return 0;}
     }
int percent(int part, int whole){
    if(whole==0){
        return 0;
    }
    else{
        return part*100/whole;
    }
}
int main(){
    int part=0,whole=0,code,error1=0,error2=0,invalid=0;
    while(scanf("%d", &code)==1){
        if(is_client_error(code)==1){
            part++;
            error1++;;
        }
        if(is_server_error(code)==1){
            part++;
            error2++;
        }
        if(code<100 || code>599){
            invalid++;
            part++;
        }
        whole++;
    }
    printf("Total: %d\n",whole);
    printf("Client errors: %d\n",error1);
    printf("Server errors: %d\n",error2);
    printf("Invalid: %d\n",invalid);
    printf("Error rate: %d%%\n",percent(part,whole));
    return 0;

}