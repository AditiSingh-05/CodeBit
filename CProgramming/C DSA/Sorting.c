//Bubble sort

#include <stdio.h>
int main(){
    
    int n;
    printf("Enter list size : ");
    scanf("%d\n",&n);
    int list[n];
    for(int i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    printf("Array before sorting : ");
    for(int i = 0;i<n;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(list[j]>list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    printf("Array after sorting : ");
    for(int i = 0;i<n;i++){
        printf("%d ",list[i]);
    }
}

//Insertion sort
#include <stdio.h>
int main(){
    
    int n;
    printf("Enter list size : ");
    scanf("%d\n",&n);
    int list[n];
    for(int i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    printf("Array before sorting : ");
    for(int i = 0;i<n;i++){
        printf("%d ",list[i]);
    }
    printf("\n");

    for(int i = 1;i<n;i++){
        int key = list[i];
        int j = i-1;
        while(j>=0 && list[j]>key){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
    }

    printf("Array after sorting : ");
    for(int i = 0;i<n;i++){
        printf("%d ",list[i]);
    }

}


//Selection sort


//Bubble sort
//take number of elements
//take array elements
// print before sorting
//sort the element
//print after sorted
#include <stdio.h>
void merge(int arr[],int low,int mid,int high){
    int n1 = mid-low+1;
    int n2 = high - mid;
    int L[n1],R[n2];
    
    for(int i=0;i<n1;i++){
        L[i] = arr[low+i];
    }
    for(int i=0;i<n2;i++){
        R[i] =arr[mid+1+i];
    }
    
    int l = 0,r = 0,k = low;
    while(l<n1 && r<n2){
        if(L[l]<R[r]){
            arr[k] = L[l];
            l++;
            k++;
        }else{
            arr[k] = R[r];
            r++;
            k++;
        }
    }
    
    while(l<n1){
        arr[k] = L[l];
        l++;
        k++;
    }
    
    while(r<n2){
        arr[k] = R[r];
        r++;
        k++;
    }
}


void mergeSort(int arr[],int low,int high){
    
    if(low>=high) return;
        int mid = low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        
        merge(arr,low,mid,high);
    
}


int main(){
    int n;
    int low = 0;
    
    //no of elements
    scanf("%d",&n);
    int high = n-1;
    int arr[n];
    //took array elements
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    //before sorting
    
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    mergeSort(arr,low,high);
    
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

//Quick sort

#include <stdio.h>
int partition(int arr[],int low,int high){
    int pivot  = arr[low];
    int start = low + 1;
    int end = high;
    while(start<=end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }else{
            int temp = arr[low];
            arr[low] = arr[end];
            arr[end] = temp;
        }
        
    }
    return end;
    
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}


int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Print before sorting
    for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
    }
        
    printf("\n");
    // Quick sort
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
    }
        
        
    return 0;
}

