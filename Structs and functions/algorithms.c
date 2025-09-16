#include <stdio.h>

void selectionSort(int *array, int size) {

    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[min]) {
                int temp = array[min];
                array[min] = array[j];
                array[j] = temp;
            }
        }
        printf ("%d ", array[min]);
    }
    printf("\n");
}


int algorithms() {

    int unsorted_array[] = {4, 2, 6, 9, 1, 3, 8, 7, 5, 10};

    printf("%s\n", "Unsorted array");
    for (int i = 0; i < sizeof(unsorted_array) / sizeof(unsorted_array[0]); i++) {
        printf("%d ", unsorted_array[i]);
    }
    printf("\n");

    printf("%s\n", "Selection Sort");
    selectionSort(unsorted_array, sizeof(unsorted_array)/sizeof(unsorted_array[0])); // this is the same as
                                                                                            // saying sizeof(unsorted_array) / 4
                                                                                            // in this case because the elements are int's which occupy 4 bytes each.

    return 0;

}