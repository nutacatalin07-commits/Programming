#include <stdio.h>

int try_connect(int attempt, int succeeds_at) {
    if (attempt>=succeeds_at)
        return 1;
    return 0;
}
int connect_with_retry(int attempt, int max_attempts, int delay, int waited, int succeeds_at){
    if (try_connect(attempt, succeeds_at)==1) {
        printf("Attempt %d: connected (waited %d s in total)\n", attempt, waited);
        return attempt;
    }
    if (attempt==max_attempts) {
        printf("Attempt %d: failed, giving up (waited %d s in total)\n", attempt, waited);
        return -1;
    }
    printf("Attempt %d: failed, retrying in %d s\n", attempt, delay);
    int next_delay=delay*2;
    if (next_delay>30){
        next_delay=30;
    }
    return connect_with_retry(attempt+1,max_attempts,next_delay,waited+delay,succeeds_at);
}

int main() {
    int max_attempts,succeeds_at;
    scanf("%d %d", &max_attempts, &succeeds_at);
    if (max_attempts<1){
        printf("Error: max_attempts must be at least 1\n");
        return 1;
    }
    int ok=connect_with_retry(1, max_attempts, 1, 0, succeeds_at);
    if (ok==-1)
        return 2;

    return 0;
}
