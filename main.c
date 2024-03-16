// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


void printElementsOfArray(int* arr, int size){
    
    printf("Elements in the array are as follows:\n");
    
    for(int i = 0; i < size; i++){
        printf("%d\n", *(arr+i));
    }
    
}

void pushToArray(int* dynamicArr, int* size, int newElement){
    
    dynamicArr = (int*) realloc(dynamicArr, sizeof(int)*(*size)+1);
    
    *(dynamicArr + *(size)) = newElement;
    
    *size = *size + 1;
    
}

void cloneArray(int* mainArr, int size, int* dynamicArr){
    
    for(int i = 0; i < size; i++){
        
        *(dynamicArr + i) = *(mainArr + i);
        
    }
    
}

int main() {
    
    int arr[] = {1, 2, 3};
    
    int arraySize = sizeof(arr)/sizeof(arr[0]);
    
    int *dynamicArr = (int*) malloc(sizeof(arr));
    
    cloneArray(arr, arraySize, dynamicArr);
    
    printElementsOfArray(dynamicArr, arraySize);
    
    int newIntegerUserInput = 0;
    
    printf("Enter a new element to be added to the array\n");
    
    scanf("%d", &newIntegerUserInput);
    
    pushToArray(dynamicArr, &arraySize, newIntegerUserInput);
    
    printElementsOfArray(dynamicArr, arraySize);
    
    printf("Enter a new element to be added to the array\n");
    
    scanf("%d", &newIntegerUserInput);
    
    pushToArray(dynamicArr, &arraySize, newIntegerUserInput);
    
    printElementsOfArray(dynamicArr, arraySize);
    
    
    
    free(dynamicArr);
    
    printf("Program ended. Memory freed.\n");


    return 0;
}
