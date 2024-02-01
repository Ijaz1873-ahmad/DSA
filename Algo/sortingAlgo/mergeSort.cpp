#include <iostream>
using namespace std;
/**
 * p = start
 * q = mid
 * r = end
 * arr = array
*/
void mergeSort(int arr[], int p, int q, int r){
    int nl = q - p + 1;
    int nr = r - q;

    int* arrL = new int[nl];
    int* arrR = new int[nr];

    for(int i = 0; i <= (nl - 1); i++){
        arrL[i] = arr[p+i];
    }

    for(int j = 0; j <= (nr - 1); j++){
        arrR[j] = arr[q + j + 1];
    }

    int i = 0, j = 0, k = p;

    while (i < nl && j < nr)
    {
        /* code */
        if(arrL[i] <= arrR[j]){
            arr[k] = arrL[i];
            i += 1;
        }else{
            arr[k] = arrR[j];
            j += 1;
        }
        k = k + 1;
    }

    while (i < nl)
    {
        /* code */
        arr[k] = arrL[i];
        i = i+1;
        k = k + 1;
    }
    while (j < nr){
        arr[k] = arrR[j];
        j = j + 1;
        k = k + 1;
    }
    delete[] arrL;
    delete[] arrR;
}

void begenMergeSort(int arr[], int p, int r){
    if(p >= r){
        return;
    }
    //int middle_Point = p + (r - p) / 2;
    int middle_Point = (p + r) / 2;
    begenMergeSort(arr, p, middle_Point);
    begenMergeSort(arr, middle_Point+1, r);
    mergeSort(arr, p, middle_Point, r);
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    begenMergeSort(arr, 0, size-1);

    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}