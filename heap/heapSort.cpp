#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
    int largest = i;          // assume current index is largest
    int left = 2 * i + 1;     // left child (0-based indexing)
    int right = 2 * i + 2;    // right child
    // Compare with left child
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // Compare with right child
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);  // jaha jaha largest badla, waha waha heapify karo
    }
}
void heapSort(int arr[], int n) {
    // Step 1: Build max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {  // from last non-leaf node to root
        heapify(arr, n, i);
    }
    // Step 2: One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]); // root ko end pe bhej diya jho ki largest tha
        // Call heapify on the reduced heap
        heapify(arr, i, 0); 
    }
}
int main() {
    int arr[] = {5, 3, 8, 1, 6,5,7,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    heapSort(arr, n);
    cout << "Sorted array (Ascending): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
