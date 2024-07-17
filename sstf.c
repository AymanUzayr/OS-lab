#include <stdio.h>
#include <limits.h>
#include<stdlib.h>

void sstf(int arr[], int head, int size) {
    int seek_count = 0;
    int distance, cur_track;
    int visited[size];
    for(int i = 0; i<size ; i++)
    visited[i] = 0;

    printf("Order of cylinder traversal is: ");
    for (int i = 0; i < size; i++) {
        int min = INT_MAX, index = -1;

        for (int j = 0; j < size; j++) {
            if (visited[j] == 0) {
                distance = abs(arr[j] - head);
                if (min > distance) {
                    min = distance;
                    index = j;
                }
            }
        }

        cur_track = arr[index];
        seek_count += min;
        head = cur_track;
        visited[index] = 1;
        printf("%d ", cur_track);
    }

    printf("\nTotal seek time is %d\n", seek_count);
    printf("Average seek time is %f\n", (float)seek_count / size);
}

int main() {
    int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int size = sizeof(arr) / sizeof(arr[0]);

    sstf(arr, head, size);

    return 0;
}
