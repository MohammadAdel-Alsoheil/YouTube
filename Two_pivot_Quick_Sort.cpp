
#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

void print(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void swap(vector<int> &arr, int a, int b)
{

    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

vector<int> partition_lomuto_2_pivot(vector<int> &arr, int p, int r)
{

    if (arr[p] > arr[r])
    {
        swap(arr, r, p);
    }
    swap(arr, p, r - 1);

    int pivot1 = arr[r - 1];
    int pivot2 = arr[r];

    int i = p - 1;
    for (int l = p; l < r - 1; l++)
    {
        if (arr[l] <= pivot1)
        {
            ++i;
            swap(arr, i, l);
        }
    }

    ++i;
    int first_pivot_location = i;
    swap(arr, i, r - 1);

    for (int l = i + 1; l < r; l++)
    {
        if (arr[l] > pivot1 && arr[l] <= pivot2)
        {
            ++i;
            swap(arr, i, l);
        }
    }
    ++i;
    swap(arr, i, r);
    vector<int> res(2);

    res[0] = first_pivot_location;
    res[1] = i;

    return res;
}

void two_pivot_quick_sort(vector<int> &arr, int p, int r)
{
    if (p < r)
    {
        vector<int> PIVOTS = partition_lomuto_2_pivot(arr, p, r);
        int q1 = PIVOTS[0];
        int q2 = PIVOTS[1];
        two_pivot_quick_sort(arr, p, q1 - 1);
        two_pivot_quick_sort(arr, q1 + 1, q2 - 1);
        two_pivot_quick_sort(arr, q2 + 1, r);
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

    two_pivot_quick_sort(arr, 0, x - 1);

    cout << "The Sorted Array is: ";
    print(arr, x);

    return 0;
}