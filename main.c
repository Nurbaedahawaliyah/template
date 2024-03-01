/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : Overview of language
 *   Hari dan Tanggal    : jumat,1 maret 2024
 *   Nama (NIM)          : Nurbaedah Awaliyah (18322027)
 *   Nama File           : main.c
 *   Deskripsi           : Soal 1 
 */

#include <stdio.h>
#include <stdbool.h>

// Fungsi untuk memeriksa apakah sebuah subsequence merupakan palindrom
bool isp(int arr[], int awal, int akhir) {
    while (akhir > awal) {
        if (arr[awal] != arr[akhir]) {
            return false;
        }
        awal++;
        akhir--;
    }
    return true;
}

// Fungsi untuk mencari subsequence yang merupakan palindrom dalam deret angka
int hitungsp(int arr[], int n) {
    int jumlah = 0;

    // Iterasi melalui semua kemungkinan subsequence
    for (int x = 0; x < n; x++) {
        for (int y = x; y < n; y++) {
            // Jika panjang subsequence lebih dari atau sama dengan 3 dan merupakan palindrom, tambahkan ke jumlah
            if (y - x + 1 >= 3 && isp(arr, x, y)) {
                jumlah++;
            }
        }
    }

    return jumlah;
}

int main() {
    int panjang;
    printf("Masukkan panjang deret angka: ");
    scanf("%d", &panjang);

    int deret[panjang];
    printf("Masukkan deret angka pada artefak: ");
    for (int x = 0; x < panjang; x++) {
        scanf("%d", &deret[x]);
    }

    int jumlahsp = hitungsp(deret, panjang);
    printf("Terdapat %d subsequence palindrom\n", jumlahsp);

    return 0;
}
