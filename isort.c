#include <stdio.h>

#define SIZE 100

int *find_place(int *arr, int *pos);    // find the place to insert the number
void insertion_sort(int *arr, int len); // sort the array
int get_arr(int *arr);                  // get the array from the user
void print_array(int *arr, int len);    // print the array
void shift_element(int *arr, int i);    // shift the array

int main()
{
    int arr[SIZE] = {0};
    int len = get_arr(arr);
    insertion_sort(arr, len);
    print_array(arr, len);
    return 0;
};

void print_array(int *arr, int len)
{
    int *p = arr;       // the first element
    int *r = arr + len; // the last element
    printf("%d", *p++);
    while (p != r)
    {
        printf(",%d", *p++);
    }
    printf("\n");
};

void shift_element(int *arr, int i)
{
    int *p = arr + i;
    int *q = arr + i - 1;
    while (p != arr)
    { // from the last element to the first element
        *p = *q;
        p--;
        q--;
    }
};

void insertion_sort(int *arr, int len)
{
    int *p = arr;       // the first element
    int *q = arr + 1;   // the second element
    int *r = arr + len; // the last element
    while (q != r)
    {
        if (*q < *p)
        {                                    // if the second element is smaller than the first element
            int *place = find_place(arr, q); // find the place to move it to
            int num = *q;                    // save the number
            shift_element(place, q - place); // shift the array
            *place = num;                    // insert the number
        }
        p++;
        q++;
    }
};

int *find_place(int *arr, int *pos)
{
    int *p = pos;                 // the position of the number
    int num = *p;                 // the number
    while (p >= arr && *p >= num) // while the number is smaller than the previous number
    {
        p--;
    }
    return p + 1; // return the place to insert the number
};

int get_arr(int *arr)
{
    int *p = arr;        // the first element
    int *q = arr + SIZE; // the last element
    int num;
    int i = 0;                               // the number of elements
    while (p != q && scanf("%d", &num) == 1) // get the array from the user
    {
        *p = num;
        i++;
        p++;
    }
    return i;
};
