#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct {
    int * array;
    int size;
} ArrayADT;


ArrayADT * create_array(int size){
    ArrayADT * arrayADT = (ArrayADT *) malloc(sizeof(ArrayADT));
    int * array_pointer = (int *) malloc(sizeof(int) * size);
    arrayADT->array = array_pointer;
    arrayADT->size = size;
    return arrayADT;
}

int insert(ArrayADT * arrayADT, int index, int value){
    if(index < 0 || index>=arrayADT->size ){
        printf("Such index is not there in Array\n");
        exit(1);
    }
    arrayADT->array[index] = value;
    return value;
}

void delete(ArrayADT *arrayADT, int index) {
    if (index < 0 || index >= arrayADT->size) {
        printf("Bad Index\n");
        return;
    }
    arrayADT->array[index] = 0; 
}

void traverse(ArrayADT * arrayADT){
    printf("Traversing Array\n");
    for(int i=0;i<arrayADT->size;i++){
        printf("%d\n",arrayADT->array[i]);
    }
}

ArrayADT* merge(ArrayADT *arrayADT1,ArrayADT *arrayADT2) {
    int newSize = arrayADT1->size + arrayADT2->size;
    ArrayADT *mergedArrayADT = create_array(newSize);

    int index = 0;
    for (int i = 0; i < arrayADT1->size; i++) {
        mergedArrayADT->array[index++] = arrayADT1->array[i];
    }

    for (int i = 0; i < arrayADT2->size; ++i) {
        mergedArrayADT->array[index++] = arrayADT2->array[i];
    }

    return mergedArrayADT;
}
void modify(ArrayADT *arrayADT, int index, int value) {
    if (index < 0 || index >= arrayADT->size) {
        printf("So Such Index \n");
        return;
    }
    arrayADT->array[index] = value;
}


int main(void){
    ArrayADT * array = create_array(3);
    insert(array,0,1);
    insert(array,1,3);
    insert(array,2,2);
    traverse(array);
    delete(array,2);
    modify(array,1,3);
    traverse(array);
    ArrayADT * array2 = create_array(3);
    insert(array2,0,5);
    insert(array2,1,2);
    insert(array2,2,4);
    ArrayADT *merged = merge(array,array2);
    traverse(merged);
}