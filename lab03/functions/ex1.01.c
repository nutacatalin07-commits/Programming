#include <stdio.h>
void print_bar(int percent,int width);
int main(){
      int percent,width;
      if(scanf("%d",&percent)!=1){
        printf("Error: invalid input");
        return 1;
    }
    else if(percent<0 || percent>100){
        printf("Error: percent must be between 0 and 100");
        return 1;}
      scanf("%d",&width);
      print_bar(percent,width);
      return 0;
}
void print_bar(int percent,int width){
    if(0<=percent && percent<=100){
        printf("[");
        int i;
        for(i=1;i<=width;i++){
            if(i<=percent*width/100){
                printf("#");
            }
            else{
                printf("-");
            }
        }
        printf("]");
        printf(" ");
        printf("%3d%%",percent);
    }
}
 //am pus iar scanf de doua ori si nu mi lua inputul care trebuie