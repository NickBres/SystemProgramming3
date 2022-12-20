#include <stdio.h>
int *find_place(int* arr,int *pos); // find the place to insert the number

void print_array(int* arr, int len){
    int* p = arr;
    int* r = arr + len;
    while (p != r){
        printf("%d ", *p);
        p++;
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
            print_array(arr, len);
        }
        
        p++;
        q++;
    }
};

int *find_place(int* arr,int *pos){
    int *p = pos;
    int num = *p;
    while(p != arr && *p >= num){
        p--;
    }
    if(p != arr)
        p++;
    return p;
};

int main(){
    int arr[15] = {10,9,8,7,6,5,4,3,2,1,0,11,12,13,14};
    print_array(arr, 15);
    insertion_sort(arr, 15);
    return 0;
};

