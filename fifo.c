#include <stdio.h>  
  
int main() {  
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};  
    int n = sizeof(pages)/sizeof(pages[0]);  
    int frames[3] = {-1, -1, -1};  
    int pageFaults = 0, pos = 0;  
  
    for (int i = 0; i < n; i++) {  
        int found = 0;  
        for (int j = 0; j < 3; j++) {  
            if (frames[j] == pages[i]) {  
                found = 1;  
                break;  
            }  
        }  
  
        if (!found) {  
            frames[pos] = pages[i];  
            pos = (pos + 1) % 3;  
            pageFaults++;  
        }  
  
        printf("Frames: ");  
        for (int j = 0; j < 3; j++) {  
            printf("%d ", frames[j]);  
        }  
        printf("\n");  
    }  
  
    printf("Total Page Faults: %d\n", pageFaults);  
  
    return 0;  
}  
