#include <stdio.h>

void fcfs(int arr[], int head, int size) {
    int seek_count = 0;
    int distance, cur_track;

    printf("Order of cylinder traversal is: ");
    for (int i = 0; i < size; i++) {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
        printf("%d ", cur_track);
    }

    printf("\nTotal seek time is %d\n", seek_count);
    printf("Average seek time is %f\n", (float)seek_count / size);
}

int main() {
    int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int size = sizeof(arr) / sizeof(arr[0]);

    fcfs(arr, head, size);

    return 0;
}
