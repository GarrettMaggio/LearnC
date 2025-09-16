#include <stdio.h>

void selectionSort(int *array, int size) {

    for (int i = 0; i < size; i++) {
        int min = i; // first iteration i = 0 first element in array
        for (int j = i+1; j < size; j++) { // loops through the array until it finds a value that is smaller
            if (array[j] < array[min]) {         // or the end of the array
                int temp = array[min];
                array[min] = array[j];
                array[j] = temp;
            }
        }
        printf ("%d ", array[min]);
    }
    printf("\n");
}

void insertionSort(int *array, int size) {

    for (int i = 1; i < size; i++) {
        int temp = array[i];
        int x = i - 1;

        while (array[x] > temp && x >= 0) {
            array[x] = temp;
            x = x - 1;
        }
    }

    for (int i = 0; i < size; i++) {
        printf ("%d ", array[i]);
    }
    printf("\n");

}


int algorithms() {

    int unsorted_array[] = {4, 2, 6, 9, 1, 3, 8, 7, 5, 10};

    int size = sizeof(unsorted_array) / sizeof(unsorted_array[0]); // this is the same as saying sizeof(array) / 4 because int's occupy 4 bytes of memory
                                                                    // so 4 bytes per element.

    printf("%s\n", "Unsorted array");
    for (int i = 0; i < sizeof(unsorted_array) / sizeof(unsorted_array[0]); i++) {
        printf("%d ", unsorted_array[i]);
    }
    printf("\n");

    printf("%s\n", "Selection Sort");
    selectionSort(unsorted_array, size);

    printf("%s\n", "Insertion Sort");
    insertionSort(unsorted_array, size);

    return 0;

}