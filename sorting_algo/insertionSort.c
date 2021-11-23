#include <stdio.h>


void insertionSort(int *arr, int n){

    for(int i = 1; i<=n-1; i++){

        int key = arr[i];
        int j = i-1;
        while(arr[j]>key && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void display(int *arr, int len){
    for(int i=0; i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {5,6,4,2,9,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr, n);
    insertionSort(arr, n);
    display(arr, n);

 return 0;
}