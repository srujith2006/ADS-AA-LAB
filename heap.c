#include <stdio.h>
#define MAX 50
void swap(int *, int *);
void maxHeapifyUp(int);
void maxHeapifyDown(int);
void insertMaxHeap(int);
void deleteMaxHeap();
void displayMaxHeap();
void minHeapifyUp(int);
void minHeapifyDown(int);

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertMaxHeap(int value) {
    maxHeap[maxSize] = value;
    maxHeapifyUp(maxSize);
    maxSize++;
}
void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void deleteMaxHeap() {
    if (maxSize == 0) {
        printf("Max Heap is empty\n");
        return;
    }
    printf("Deleted element: %d\n", maxHeap[0]);
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapifyDown(0);
}
void maxHeapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < maxSize && maxHeap[left] > maxHeap[largest])
        largest = left;
    if (right < maxSize && maxHeap[right] > maxHeap[largest])
        largest = right;
    if (largest != i) {
        swap(&maxHeap[i], &maxHeap[largest]);
        maxHeapifyDown(largest);
    }
}
void displayMaxHeap() {
    printf("Max Heap: ");
    for (int i = 0; i < maxSize; i++)
        printf("%d ", maxHeap[i]);
    printf("\n");
}
void insertMinHeap(int value) {
    minHeap[minSize] = value;
    minHeapifyUp(minSize);
    minSize++;
}
void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void deleteMinHeap() {
    if (minSize == 0) {
        printf("Min Heap is empty\n");
        return;
    }
    printf("Deleted element: %d\n", minHeap[0]);
    minHeap[0] = minHeap[--minSize];
    minHeapifyDown(0);
}
void minHeapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < minSize && minHeap[left] < minHeap[smallest])
        smallest = left;
    if (right < minSize && minHeap[right] < minHeap[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        minHeapifyDown(smallest);
    }
}
void displayMinHeap() {
    printf("Min Heap: ");
    for (int i = 0; i < minSize; i++)
        printf("%d ", minHeap[i]);
    printf("\n");
}
int main() {
    int choice, value;
    do {
        printf("\n--- Heap Operations ---\n");
        printf("1. Insert into Max Heap\t");
        printf("2. Delete from Max Heap\t");
        printf("3. Display Max Heap\n");
        printf("4. Insert into Min Heap\t");
        printf("5. Delete from Min Heap\t");
        printf("6. Display Min Heap\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertMaxHeap(value);
                break;
            case 2:
                deleteMaxHeap();
                break;
            case 3:
                displayMaxHeap();
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                insertMinHeap(value);
                break;
            case 5:
                deleteMinHeap();
                break;
            case 6:
                displayMinHeap();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}
