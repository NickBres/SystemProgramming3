#include <stdio.h>

#define SIZE 100

int *find_place(int* arr,int *pos); // find the place to insert the number
void insertion_sort(int* arr , int len); // sort the array
int get_arr(int *arr); // get the array from the user
void print_array(int* arr, int len); // print the array
void shift_element(int* arr, int i); // shift the array

int main(){
    int arr[SIZE] = {0};
    int len = get_arr(arr);
    insertion_sort(arr, len);
    print_array(arr, len);
    return 0;
};

void print_array(int* arr, int len){
    int* p = arr;
    int* r = arr + len;
    printf("%d", *p++);
    while (p != r){
        printf(",%d", *p++);
    }
    printf("\n");
};

void shift_element(int* arr, int i){
    int* p = arr + i;
    int* q = arr + i - 1;
    while (p != arr){
        *p = *q;
        p--;
        q--;
    }
};

void insertion_sort(int* arr , int len){
    int* p = arr;
    int* q = arr + 1;
    int* r = arr + len;
    while (q != r){
        if (*q < *p){
            int* place = find_place(arr,q);
            int num = *q;
            shift_element(place, q - place);
            *place = num;
           // print_array(arr, len);
        }
        
        p++;
        q++;
    }
};

int *find_place(int* arr,int *pos){
    int *p = pos;
    int num = *p;
    while(p >= arr && *p >= num){
        p--;
    }
    return p + 1;
};

int get_arr(int *arr){
    int *p = arr;
    int *q = arr + SIZE;
    int num;
    int i = 0;
    while (p != q && scanf("%d", &num) == 1){
        *p = num;
        i++;
        p++;
    }
    return i;
};


