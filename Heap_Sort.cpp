#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

void swap(vector<int> &arr, int a, int b)
{

    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void print(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int get_parent(int i)
{
    return floor(i - 1 / 2);
}
int get_left(int i)
{
    return (2 * i) + 1;
}
int get_right(int i)
{
    return (2 * i) + 2;
}

void MAX_Heapify(vector<int> &arr, int i, int n)
{

    int left = get_left(i);
    int right = get_right(i);
    int largest = i;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr, largest, i);
        MAX_Heapify(arr, largest, n);
    }
}
void Build_Max_Heap(vector<int> &arr, int n)
{
    int mid = floor(n / 2) - 1; // execlude leaf nodes
    for (int i = mid; i >= 0; i--)
    {
        MAX_Heapify(arr, i, n);
    }
}
void heap_sort(vector<int> &arr, int n)
{
    Build_Max_Heap(arr, n);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr, i, 0);

        MAX_Heapify(arr, 0, i);
    }
}

int main()
{
    int x;
    cin >> x;
    vector<int> arr(x);
    for (int i = 0; i < x; i++)
    {
        int y;
        cin >> y;
        arr[i] = y;
    }

    heap_sort(arr, x);
    print(arr, x);

    return 0;
}