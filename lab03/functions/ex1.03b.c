#include <stdio.h>
int init(void) { return 1; }
int init_any() { return 1; }
int main(){
    init_any(5);
}
/*error: too many arguments to function ‘init’; expected 0, have 1
    5 |     init(5);
      |     ^~~~ ~
ex1.03b.c:2:5: note: declared here
    2 | int init(void) { return 1; }
      |     ^~~~
      compileaza cu al primul da la al doilea eroare*/
