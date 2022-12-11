/*
Heap sort is a comparison-based sorting technique based on Binary Heap data structure. 
It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning. 
Repeat the same process for the remaining elements.

Advantages of heapsort:
•	Efficiency 
•	Memory Usage
•	Simplicity

Heap Sort Algorithm :
    To solve the problem follow the below idea:
    First convert the array into heap data structure using heapify, than one by one delete the root node of the Max-heap and replace it with the last node in the heap and then heapify the root of the heap. Repeat this process until size of heap is greater than 1.
    Follow the given steps to solve the problem:
    •	Build a max heap from the input data. 
    •	At this point, the maximum element is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of the heap by 1. Finally, heapify the root of the tree. 
    •	Repeat step 2 while the size of the heap is greater than 1.

Time complexity
    Since there are 'n' number of nodes, therefore, the total runtime of the algorithm turns out to be O(n(log(n)), and we use the max-heapify function for each node.
    Mathematically, we see that-
    •	The first remove of a node takes log(n) time
    •	The second remove takes log(n-1) time
    •	The third remove takes log(n-2) time
    •	and so on till the last node, which will take log(1) time
    So summing up all the terms, we get-
    log(n) + log(n-1) + log(n-2) + ....log(1)
    as log(x) + log(y) = log(x * y), we get
    =log(n∗(n−1)∗(n−2)∗…∗2∗1)
    =log(n!)
    Upon further simplification (using Stirling's approximation), log(n!) turns out to be
    => n∗log(n)−n+O(log(n))
    => O(n(log(n)).

Algorithm
    low  –> Starting index,  high  –> Ending index 
    Quick Sort(arr[], low, high) {
        if (low < high) {
            /* pi is partitioning index, arr[pi] is now at right place */
            pi = partition(arr, low, high);
            quick Sort(arr, low, pi – 1);  // Before pi
            quick Sort(arr, pi + 1, high); // After pi
        }
    }

    Partition (arr[], low, high){
    // pivot (Element to be placed at right position)
    pivot = arr[high];  

    i = (low – 1)  // Index of smaller element and indicates the 
    // right position of pivot found so far
    for (j = low; j <= high- 1; j++){

        // If current element is smaller than the pivot
        if (arr[j] < pivot){
            i++;    // increment index of smaller element
            swap arr[i] and arr[j]
        }
    }
    swap arr[i + 1] and arr[high])
    return (i + 1)
    }


*/

#include <iostream>
using namespace std;
// Making a heap class
class heap{
    public:
        int arr[100];
        int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    // Function to insert the value in heap
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1){
            int parent = index / 2;
            if (arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }
    // Function to delete
    void deleteNode(){
        if (size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }else{
            arr[1] = arr[size];
            size--;
            // Progagating node to its correct position
            int i = 1;
            while (i < size){
                int leftNode = 2 * i;
                int rightNode = 2 * i + 1;
                if (leftNode < size && arr[i] < arr[leftNode]){
                    swap(arr[i], arr[leftNode]);
                    i = leftNode; 
                }else if (rightNode < size && arr[i] < arr[rightNode]){
                    swap(arr[i], arr[rightNode]);
                    i = rightNode; 
                }else{
                    return;
                }
            }
        }
    }
    // Function to print
    void print(){
        for (int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
    }
};
// Heapify
void heapify(int arr[], int n, int i){
    int largest = i;
    int leftNode = 2 * i;
    int rightNode = 2 * i + 1;
    if (leftNode <= n && arr[largest] < arr[leftNode]){
        largest = leftNode;
    }
    if (rightNode <= n && arr[largest] < arr[rightNode]){
        largest = rightNode;
    }
    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
// Heap Sort Implementation
void heapSort(int arr[], int n){
    int size = n;
    while (size > 1){
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}
int main(){
    // Insertion and deletion in the heap
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54); 
    h.print();
    h.deleteNode();
    cout << endl;
    h.print();

    // Implying the heapify algorithm
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout << endl << "Printing the array:" << endl;
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    // Implying heap sort
    heapSort(arr, n);
    cout << endl << "Printing the array after sorting:" << endl;
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}