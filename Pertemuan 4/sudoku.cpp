/*
Nama: Marcello Frans Mardohae Pakpahan
NIM:  241401104
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << " ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Fungsi untuk ngecek apakah angka valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Cek baris dan kolom
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Cek kotak 3x3 tempat angka itu berada
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Fungsi utama buat nyelesain Sudoku pakai rekursi
bool solveSudoku(vector<vector<int>>& board) {
    // Loop buat cari sel kosong (yang nilainya 0)
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                // Kalau nemu sel kosong, coba isi angka dari 1 sampai 9
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num; // masukin angka
                        
                        // Rekursi buat lanjut ke sel berikutnya
                        if (solveSudoku(board)) {
                            return true; // kalau berhasil, langsung selesai
                        }

                        // Kalau gagal (nggak ada angka valid lanjutannya)
                        // balikin ke 0 alias kosongin lagi
                        board[row][col] = 0;
                    }
                }

                // Kalau semua angka 1–9 dicoba tapi nggak ada yang valid, backtrack
                return false;
            }
        }
    }

    // Kalau semua sel udah terisi (nggak nemu 0 lagi), berarti selesai
    return true;
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}
