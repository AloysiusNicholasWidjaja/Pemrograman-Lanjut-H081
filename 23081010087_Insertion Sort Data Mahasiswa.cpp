#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAHASISWA 100

typedef struct {
    char npm[15];
    char nama[50];
    char prodi[50];
    float ipk;
} Mahasiswa;

Mahasiswa mahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void inisialisasiDataMahasiswa() {
    strcpy(mahasiswa[jumlahMahasiswa].npm, "23081010356");
    strcpy(mahasiswa[jumlahMahasiswa].nama, "Bagus");
    strcpy(mahasiswa[jumlahMahasiswa].prodi, "Informatika");
    mahasiswa[jumlahMahasiswa].ipk = 4.0;
    jumlahMahasiswa++;

    strcpy(mahasiswa[jumlahMahasiswa].npm, "23082010065");
    strcpy(mahasiswa[jumlahMahasiswa].nama, "Rangga");
    strcpy(mahasiswa[jumlahMahasiswa].prodi, "Sistem Informasi");
    mahasiswa[jumlahMahasiswa].ipk = 3.7;
    jumlahMahasiswa++;

    strcpy(mahasiswa[jumlahMahasiswa].npm, "23091010098");
    strcpy(mahasiswa[jumlahMahasiswa].nama, "Cathrine");
    strcpy(mahasiswa[jumlahMahasiswa].prodi, "Hukum");
    mahasiswa[jumlahMahasiswa].ipk = 3.8;
    jumlahMahasiswa++;

    strcpy(mahasiswa[jumlahMahasiswa].npm, "23031010149");
    strcpy(mahasiswa[jumlahMahasiswa].nama, "Ridho");
    strcpy(mahasiswa[jumlahMahasiswa].prodi, "Teknik Mesin");
    mahasiswa[jumlahMahasiswa].ipk = 3.3;
    jumlahMahasiswa++;

    strcpy(mahasiswa[jumlahMahasiswa].npm, "23011010001");
    strcpy(mahasiswa[jumlahMahasiswa].nama, "Raka");
    strcpy(mahasiswa[jumlahMahasiswa].prodi, "Manajemen");
    mahasiswa[jumlahMahasiswa].ipk = 3.7;
    jumlahMahasiswa++;
}

void tampilkanMahasiswa() {
    if (jumlahMahasiswa == 0) {
        printf("Tidak ada data mahasiswa.\n");
        return;
    }

    printf("\nData Mahasiswa:\n");
    printf("--------------------------------------------------\n");
    printf("| NPM          | Nama                     | Prodi           | IPK  |\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("| %-12s | %-23s | %-15s | %.2f |\n", mahasiswa[i].npm, mahasiswa[i].nama, mahasiswa[i].prodi, mahasiswa[i].ipk);
    }
    printf("--------------------------------------------------\n");
}

void insertionSortMahasiswa() {
    if (jumlahMahasiswa == 0) {
        printf("Tidak ada data mahasiswa untuk diurutkan.\n");
        return;
    }

    for (int i = 1; i < jumlahMahasiswa; i++) {
        Mahasiswa key = mahasiswa[i];
        int j = i - 1;

        while (j >= 0 && strcmp(mahasiswa[j].npm, key.npm) > 0) {
            mahasiswa[j + 1] = mahasiswa[j];
            j--;
        }

        mahasiswa[j + 1] = key;
    }

    printf("Data mahasiswa berhasil diurutkan dengan Insertion Sort berdasarkan NPM.\n");
}

int main() {
    inisialisasiDataMahasiswa();
    printf("Data mahasiswa sebelum sorting:\n");
    tampilkanMahasiswa();

    insertionSortMahasiswa();
    printf("Data mahasiswa setelah sorting:\n");
    tampilkanMahasiswa();

    return 0;
}

