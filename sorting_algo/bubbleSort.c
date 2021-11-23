#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int *arr,int len){

    for(int i=0; i<len-1; i++){                  //no.of passes
        for(int j=0; j<len-1-i; j++){            //no.of comparisons
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    int arr[] = {5,3,9,4,3,8};
    int len = 6;

    display(arr, len);
    bubbleSort(arr,len);
    display(arr, len);



 return 0;
}