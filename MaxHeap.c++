#include <iostream>
using namespace std;
class MaxHeap
{
    int *arr;
    int size;
    int total_size;

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }
    void insert(int val)
    {
        if (size == total_size)
        {
            cout << "Heap is Overfolow" << endl;
            return;
        }
        arr[size] = val;
        int index = size;
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
        }
        size++;
    }
    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        while (left < size && arr[left] > arr[largest])
            largest = left;
        while (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }
    void deletion()
    {
        if (size == 0)
        {
            cout << "Heap Underfolow" << endl;
        }
        cout << arr[0] << "is deleted from Heap" << endl;
        arr[0] = arr[size - 1];
        size--;
        if (size == 0)
            return;
        heapify(0);
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    MaxHeap H1(10);
    H1.insert(10);
    H1.insert(18);
    H1.insert(100);
    H1.insert(50);
    H1.insert(60);
    H1.insert(70);
    H1.insert(65);
    H1.deletion();
    H1.insert(15);
    H1.insert(27);
    H1.print();
}