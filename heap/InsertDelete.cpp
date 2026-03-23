#include <iostream>
using namespace std;
class MinHeap {
    int arr[100];  // fixed-size array
    int size;      // current number of elements
public:
    MinHeap() {
        arr[0] = -1; // index 0 unused
        size = 0;
    }
    void insert(int val) {
        if (size >= 99) {
            cout << "Heap is full!" << endl;
            return;
        }
        arr[++size] = val;  // insert at end
        int i = size;
        // Heapify up to maintain min-heap property node ko correct position pe le jana
        while (i > 1) {
            int parent = i / 2;
            if (arr[parent] > arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                break;
            }
        }
    }
    void deleteMin() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        arr[1] = arr[size]; // replace root with last element
        size--;
        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int parent = i;
            if (left <= size && arr[left] < arr[parent])  
                parent = left;
            if (right <= size && arr[right] < arr[parent])
                parent = right;
            if (parent != i) {
                swap(arr[i], arr[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }
    int getMin() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return arr[1];
    }
    void display() {
        cout << "Heap elements: ";
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    MinHeap h;
    h.insert(5);
    h.insert(3);
    h.insert(8);
    h.insert(1);
    h.insert(6);
    h.display();
    cout << "Min element: " << h.getMin() << endl;
    h.deleteMin();
    h.display();
    h.deleteMin();
    h.display();
    return 0;
}


// Max heap implementation
// #include <iostream>
// using namespace std;
// class MaxHeap {
//     int arr[100];  
//     int size;      // current number of elements

// public:
//     MaxHeap() {
//         arr[0] = -1; // index 0 unused
//         size = 0;
//     }
//     void insert(int val) {
//         if (size >= 99) {
//             cout << "Heap is full!" << endl;
//             return;
//         }
//         arr[++size] = val;
//         int i = size;
//         // Heapify up (maintain max-heap property) 
//         while (i > 1) {
//             int parent = i / 2;
//             if (arr[parent] < arr[i]) { 
//                 swap(arr[parent], arr[i]);
//                 i = parent;
//             } else {
//                 break;
//             }
//         }
//     }
//     void deleteMax() {
//         if (size == 0) {
//             cout << "Heap is empty!" << endl;
//             return;
//         }

//         arr[1] = arr[size]; // replace root with last element
//         size--;

//         int i = 1;
//         while (true) {
//             int left = 2 * i;
//             int right = 2 * i + 1;
//             int parent = i;
//             if (left <= size && arr[left] > arr[parent])
//                 parent = left;
//             if (right <= size && arr[right] > arr[parent])
//                 parent = right;

//             if (parent != i) {
//                 swap(arr[i], arr[parent]);
//                 i = parent;
//             } else {
//                 break;
//             }
//         }
//     }
//     int getMax() {
//         if (size == 0) {
//             cout << "Heap is empty!" << endl;
//             return -1;
//         }
//         return arr[1];
//     }
//     void display() {
//         cout << "Heap elements: ";
//         for (int i = 1; i <= size; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };
// int main() {
//     MaxHeap h;
//     h.insert(5);
//     h.insert(3);
//     h.insert(8);
//     h.insert(1);
//     h.insert(6);
//     h.display();
//     cout << "Max element: " << h.getMax() << endl;
//     h.deleteMax();
//     h.display();
//     h.deleteMax();
//     h.display();
//     return 0;
// }
