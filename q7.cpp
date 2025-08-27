#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left, inv_count = 0;
    while(i < mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += mid - i;
        }
    }
    while(i < mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    for(i = left; i <= right; i++) arr[i] = temp[i];
    return inv_count;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int inv_count = 0;
    if(left < right) {
        int mid = (left + right)/2;
        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid+1, right);
        inv_count += mergeAndCount(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n], temp[n];
    cout << "Enter elements:\n";
    for(int i=0; i<n; i++) cin >> arr[i];
    int result = mergeSortAndCount(arr, temp, 0, n-1);
    cout << "Number of inversions: " << result << endl;
    return 0;
}
