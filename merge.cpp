#include <stdio.h>  
//#include <conio.h>  
#include <stdlib.h>  
  
void merge(int arr[], int l, int m, int end)  
{  
    int i, j, k;  
    int a1 = m - l + 1;  
    int a2 = end - m;  
      
    // create temp subarray  
    int sub1[a1], sub2[a2];  
      
    // Store data to temp subarray subArr1[] and subArr2[]  
    for (i = 0; i < a1; i++)  
        sub1[i] = arr[l + i];  
    for (j = 0; j < a2; j++)  
        sub2[j] = arr[m + 1 + j];  
      
    // Merge the temp array into the original array arr[]  
    i = 0;  
    j = 0;  
    k = l;  
    while (i < a1 && j < a2)  
    {  
        if (sub1[i] <= sub2[j])  
        {  
            arr[k] = sub1[i];  
            i++;  
        }  
        else  
        {  
            arr[k] = sub2[j];  
            j++;  
        }  
        k++;  
    }  
      
    // copry the rest element of subArr1[], if some element is left;  
while (i < a1)  
{  
    arr[k] = sub1[i];  
    i++;  
    k++;      
}  
  
    // copry the rest element of subArr2[], if some element is left;  
while (j < a2)  
{  
    arr[k] = sub2[j];  
    j++;  
    k++;      
  }  
}  
  
/* st represents the first index and end represents the right index of the subarray of arr[] to be sorted using merge sort. */  
void mergeSort(int arr[], int l, int end)  
{  
    if (l < end)  
    {     
        int m = l + (end - l) / 2;  
          
        mergeSort(arr, l, m);  
        mergeSort(arr, m + 1, end);  
          
        merge(arr, l, m, end);  
    }  
}  
  
// Function to print the merge sort.  
void mergePrint(int Ar[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d \t", Ar[i]);  
    printf("\n");  
}  
  
int main()  
{  
    int arr[] = { 70, 80, 40, 50, 60, 11, 35, 85, 2 };  
    int arr_size = sizeof(arr) / sizeof(arr[0]);  
      
    printf(" Predefined Array is \n");  
    mergePrint(arr, arr_size);  
      
    mergeSort(arr, 0, arr_size - 1);  
      
    printf("\n Sorted array using the Merge Sort algorithm \n");  
    mergePrint(arr, arr_size);  
    return 0;  
}  
