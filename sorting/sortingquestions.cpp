// Count Inversions in an array using merge sort
// #include <bits/stdc++.h>
// using namespace std;
// long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
//     vector<int> temp;
//     int i = left, j = mid + 1;
//     long long invCount = 0;
//     while (i <= mid && j <= right) {
//         if (arr[i] <= arr[j]) {
//             temp.push_back(arr[i++]);
//         } else { // arr[i]>arr[j]
//             temp.push_back(arr[j++]);
//             invCount += (mid - i + 1); // inversions
//         }
//     }
//     while (i <= mid) temp.push_back(arr[i++]);
//     while (j <= right) temp.push_back(arr[j++]);
//     for (int k = left; k <= right; k++)
//         arr[k] = temp[k - left];
//     return invCount;
// }
// long long mergeSortCount(vector<int>& arr, int left, int right) {
//     if (left >= right) return 0;
//     int mid = (left + right) / 2;
//     long long inv = 0;
//     inv += mergeSortCount(arr, left, mid);
//     inv += mergeSortCount(arr, mid + 1, right);
//     inv += mergeAndCount(arr, left, mid, right);
//     return inv;
// }

// int main() {
//     vector<int> arr = {5,1,3,0,4,2,6};
//     cout << mergeSortCount(arr, 0, arr.size() - 1);
// }

// Kth smallest element in an array using quickselect 
#include <iostream>
#include <algorithm>   
using namespace std;
int partitionArr(int arr[], int st, int end) {
    int pivot = arr[st];
    int cnt = 0;

    for (int i = st + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            cnt++;
    }

    int pivotidx = st + cnt;
    swap(arr[st], arr[pivotidx]); 

    int i = st, j = end;

    while (i < pivotidx && j > pivotidx) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < pivotidx && j > pivotidx) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotidx;
}
void kthsmallest(int arr[], int st, int end,int k,int& ans) {
    if (st <= end){ 
    int pi = partitionArr(arr, st, end);
    if (pi +1 == k) {
        ans= arr[pi];
        return;
    }
    else if(pi+1<k)  kthsmallest(arr,pi + 1,end,k,ans);
    else if(pi+1>k)  kthsmallest(arr,st,pi-1,k,ans);
    }
}
int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<"Enter k : "; 
    int k; cin >> k;
    int ans = -1;
    kthsmallest(arr, 0, n - 1,k,ans); cout<<"Kth smallest element is : "<<ans;
    return 0;
}

