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

void selectionSortMahasiswa() {
    if (jumlahMahasiswa == 0) {
        printf("Tidak ada data mahasiswa untuk diurutkan.\n");
        return;
    }

    for (int i = 0; i < jumlahMahasiswa - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < jumlahMahasiswa; j++) {
            if (strcmp(mahasiswa[j].npm, mahasiswa[minIndex].npm) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            Mahasiswa temp = mahasiswa[i];
            mahasiswa[i] = mahasiswa[minIndex];
            mahasiswa[minIndex] = temp;
        }
    }

    printf("Data mahasiswa berhasil diurutkan dengan Selection Sort berdasarkan NPM.\n");
}

int main() {
    inisialisasiDataMahasiswa();
    printf("Data mahasiswa sebelum sorting:\n");
    tampilkanMahasiswa();

    selectionSortMahasiswa();
    printf("Data mahasiswa setelah sorting:\n");
    tampilkanMahasiswa();

    return 0;
}

