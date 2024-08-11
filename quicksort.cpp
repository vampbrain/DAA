#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int l, int h, int arr[]) {
    int pivot = arr[l];
    int i = l, j = h+1;

    while (i < j) {
        do {
            i++;
        } while (i <= h && arr[i] <= pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[l], arr[j]);
    return j;
}

void quicksort(int arr[], int l, int h) {
    if (l < h) {
        int j = partition(l, h, arr);
        quicksort(arr, l, j - 1);  
        quicksort(arr, j + 1, h);  
    }
}

int main() {
    int arr[] = {3, 4, 5, 2, 6, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1); 

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
