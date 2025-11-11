#include <iostream>
#include <algorithm> 
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int target, int& step) {
    if (left > right) {
        return -1; 
    }

    int mid = left + (right - left) / 2;

        cout << "Iterasi langkah:\n"<< step << " : ";
        cout << "Left = " << left << ", Right = " << right << ", mid = " << mid;
        cout << ", arr[mid] = " << arr[mid] << endl;

    if (arr[mid] == target) {
        return mid; 
    }
    else if (arr[mid] < target) {
        return binarySearchRecursive(arr, left, mid - 1, target, step); 
    }
    else {
        return binarySearchRecursive(arr, mid + 1, right, target, step); 
    }
}


int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[1000];
    int step = 0;
    cout << "Masukkan " << n << " angka (acak):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<int>());

    cout << "\nData setelah diurutkan (descending): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int target;
    cout << "\nMasukkan angka yang ingin dicari: ";
    cin >> target;

    int hasil = binarySearchRecursive(arr, 0, n - 1, target, step);

    if (hasil != -1)
        cout << "\nAngka " << target << " ditemukan di indeks ke-" << hasil << endl;
    else
        cout << "\nAngka " << target << " tidak ditemukan dalam array." << endl;

    return 0;
}