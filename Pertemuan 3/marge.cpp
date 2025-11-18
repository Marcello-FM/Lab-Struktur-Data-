#include <iostream>
#include <vector>
using namespace std;

// fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {

    int n1 = mid - left + 1;  // jumlah elemen di bagian kiri
    int n2 = right - mid;     // jumlah elemen di bagian kanan

    // bikin array sementara untuk nyimpen elemen kiri & kanan
    vector<int> L(n1), R(n2);

    // copy data ke array sementara L dan R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // i buat index L, j buat index R, k buat index di arr utama
    int i = 0;    
    int j = 0;      
    int k = left;

    // gabungin lagi L dan R ke dalam arr sesuai urutan
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // kalau masih ada sisa di L, masukin ke arr
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // kalau masih ada sisa di R, masukin ke arr
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// fungsi utama merge sort (rekursif)
void mergeSort(vector<int>& arr, int left, int right) {
    // kalau cuma 1 elemen, langsung balik (udah pasti terurut)
    if (left >= right)
        return;

    // cari titik tengah
    int mid = left + (right - left) / 2;

    // rekursif ke kiri dan kanan
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // gabungkan hasilnya
    merge(arr, left, mid, right);
}

// buat nampilin isi array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Array sebelum diurutkan: ";
    printArray(data);

    // panggil merge sort
    mergeSort(data, 0, n - 1);

    cout << "Array setelah diurutkan: ";
    printArray(data);

    return 0;
}
