#include <stdio.h>
#include <stdlib.h>


void merge(int *leftarray, int leftSize, int *rightarray, int rightSize, int *array, int size) {
    int i = 0, l = 0, r = 0;

    while (r < rightSize && l < leftSize) {
        if (leftarray[l] < rightarray[r]) {
            array[i] = leftarray[l];
            i++;
            l++;
        }
        else {
            array[i] = rightarray[r];
            i++;
            r++;
        }
    }
    while (l < leftSize) {
        array[i] = leftarray[l];
        i++;
        l++;
    }
    while (r < rightSize) {
        array[i] = rightarray[r];
        i++;
        r++;
    }

}

// Merge sort is significantly faster than selection and insertion sort. However, merge sort requires the use of more memory.
// There are two reasons for this I can think of one is that merge sort uses recursion which builds up the stack memory.
// The other reason I could think of is that merge sort has to dynamically allocate memory to subarrays which pulls memory from the heap.
// Merge sort would typically be used to sort large list of data. If you had smaller list like this it would proably be best to use
// the other two algorithms.

// a fundamental limitation of C know as array decay will keep you from finding the length of an array passed
// as an argument. So just pass the length of the array.
void mergeSort(int *array, int size) {


    // best case
    if (size <= 1) {
        return;
    }

    int middle = size / 2;

    // malloc is used to dynamically allocate memory for the two subarrays.
   int *leftarray = malloc(sizeof(int) *  middle);
    int *rightarray = malloc(sizeof(int) * (size - middle));

    if (leftarray == NULL || rightarray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < middle; i++){
        leftarray[i] = array[i];
    }
    for ( int i = middle; i < size; i++) {
        rightarray[i - middle] = array[i];
    }
    // do not try to use size of to find the size of the right array and leftarray
    // these to are pointers and as such they point to the first element in the array.
    //int size_of_right = sizeof(rightarray) / sizeof(rightarray[0]); // this will cause errors
    //int size_of_left = sizeof(leftarray) / sizeof(leftarray[0]);

    // the size was already determined with middle and size - middle.
    mergeSort(leftarray, middle);
    mergeSort(rightarray, size - middle);
    merge(leftarray, middle, rightarray, size - middle, array, size);
}

// selection sort works by comparing two elements that are next to each other if the next element in the
// array is larger than the first element then their positions in the array are swapped.
// for a more detailed explanation look at the selection sort function.

void selectionSort(int *array, int size) {

    // if statement says element at j position is smaller than element at min position
    // the if statement will execute for every value that is smaller than
    // min. Essentially it will move the smallest value to the minimum index on each iteration.

    for (int i = 0; i < size; i++) {
        int min = i; // first iteration i = 0 first element in array
        for (int j = i+1; j < size; j++) { // loops through the array until it finds a value that is smaller
            if (array[j] < array[min]) { // change < to > if you want to sort in descending order.
                int temp = array[min];
                array[min] = array[j];
                array[j] = temp;
            }
        }
        printf ("%d ", array[min]);
    }
    printf("\n");
}

// insertion sort works by starting as the second element in the array and comparing it to the element before it.
// this pattern continues until the entire array is sorted.

void insertionSort(int *array, int size) {

    // i is assigned the second element in the array. Then the second value is assignment to a temp variable.
    // then x is a variable pointing to the first element in the array.

    for (int i = 1; i < size; i++) {
        int temp = array[i];
        int x = i - 1;

        // when the while loop executes the first value is assigned to the element at the next index. This patten continues
        // for every element until and element is found with a larger value than temp.
        while (array[x] > temp && x >= 0) { // reverse the first > to < for descending order.
            array[x + 1] = array[x];
            x = x - 1;
        }
        array[x + 1] = temp;
    }

    for (int i = 0; i < size; i++) {
        printf ("%d ", array[i]);
    }
    printf("\n");
}

void binarySearch( int *array, int size, int value_to_find) {

    printf("%s\n", "Enter a number from 1-10 to search for.");
    scanf("%d", &value_to_find);

    int low = 0;
    int high = size - 1;
    int counter = 0;


    while (low <= high && counter != 1) {
        int middle = (low + high)/2;

        if (array[middle] > value_to_find) { // search the bottom of the array
            high = middle - 1;
        }
        if (array[middle] < value_to_find) { // search the top of the array
            low = middle + 1;
        }
        if (array[middle] == value_to_find) {
            printf("%s", "Value found:\t");
	        printf("%d\n", array[middle]);
            counter++;
	    }
    }
    if (low > high) {
        printf("%s\n", "Value not found:\t");
    }

}


int algorithms() {

    int unsorted_array[] = {4, 2, 6, 9, 1, 3, 8, 7, 5, 10};
    char value_to_find;
    value_to_find = 0;

    int size = sizeof(unsorted_array) / sizeof(unsorted_array[0]); // this is the same as saying sizeof(array) / 4 because int's occupy 4 bytes of memory
                                                                    // so 4 bytes per element.

    printf("%s\n", "Unsorted array");
    for (int i = 0; i < sizeof(unsorted_array) / sizeof(unsorted_array[0]); i++) {
        printf("%d ", unsorted_array[i]);
    }
    printf("\n");

    // comment out one of the sorting algorithms to see the other working
   printf("%s\n", "Selection Sort");
   selectionSort(unsorted_array, size);

    printf("%s\n", "Insertion Sort");
    insertionSort(unsorted_array, size);

    printf("%s\n", "Merge Sort");
    mergeSort(unsorted_array, size);

    for (int i = 0; i < sizeof(unsorted_array) / sizeof(unsorted_array[0]); i++) {
        printf("%d ", unsorted_array[i]);
    }

    printf("%s\n", "Binary Search");
    binarySearch(unsorted_array, size, value_to_find);



    return 0;

}
