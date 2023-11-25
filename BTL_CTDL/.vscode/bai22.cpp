#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Xây d?ng vun d?ng (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // S?p x?p vun d?ng
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int minCostToConnectMetalBars(int n, vector<int>& lengths) {
    // S?p x?p dãy d? dài các thanh kim lo?i b?ng Heap Sort
    heapSort(lengths);

    int totalCost = 0;

    // Th?c hi?n n?i thanh kim lo?i d? gi?m thi?u chi phí
    for (int i = 1; i < n; ++i) {
        // Tính chi phí n?i và thêm vào t?ng chi phí
        int cost = lengths[i - 1] + lengths[i];
        totalCost += cost;

        // Thêm thanh n?i du?c vào dãy d? dài
        lengths[i] = cost;

        // S?p x?p l?i dãy d? duy trì tính ch?t heap
        heapify(lengths, i + 1, i);
    }

    return totalCost;
}

int main() {
    int n;
    cin >> n;

    vector<int> lengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
    }

    // Tính và in ra k?t qu?
    int result = minCostToConnectMetalBars(n, lengths);
    cout << result << endl;

    return 0;
}
