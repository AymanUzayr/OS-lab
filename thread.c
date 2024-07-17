#include <pthread.h>
#include <stdio.h>
 
#define NUM_THREADS 3
#define MAX_ARR_SIZE 50
 
int evensum = 0, oddsum = 0, sumn = 0;
int evenarr[MAX_ARR_SIZE], oddarr[MAX_ARR_SIZE];
int je = 0, jo = 0;
 
void Even(int arg) {
    int n = arg;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            evenarr[je] = i;
            evensum += i;
            je++;
        }
    }
    pthread_exit(NULL);
}
 
void Odd(int arg) {
    int n = arg;
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            oddarr[jo] = i;
            oddsum += i;
            jo++;
        }
    }
    pthread_exit(NULL);
}
 
void SumN(int arg) {
    int n = arg;
    for (int i = 1; i <= n; i++) {
        sumn += i;
    }
    pthread_exit(NULL);
}
 
int main() {
    pthread_t threads[NUM_THREADS];
    int num;
 
    printf("Enter a number: ");
    scanf("%d", &num);
 
    pthread_create(&threads[0], NULL, (void *(*)(void *))Even, (void *)num);
    pthread_create(&threads[1], NULL, (void *(*)(void *))Odd, (void *)num);
    pthread_create(&threads[2], NULL, (void *(*)(void *))SumN, (void *) num);
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
 
    printf("The sum of first N natural numbers is %d\n", sumn);
    printf("The sum of first N even natural numbers is %d\n", evensum);
    printf("The sum of first N odd natural numbers is %d\n", oddsum);
 
    printf("\nThe first N even natural numbers are:\n");
    for (int i = 0; i < je; i++) {
        printf("%d\t", evenarr[i]);
    }
 
    printf("\nThe first N odd natural numbers are:\n");
    for (int i = 0; i < jo; i++) {
        printf("%d\t", oddarr[i]);
    }
 
    pthread_exit(NULL);
}
 
