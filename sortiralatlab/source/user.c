#include "../include/utils.h"

void menu_user() {
    int pilihan;
    do {
        printf("=================== Menu User ===================\n");
        printf("1. Tampilkan List Alat Lab Yang Tersedia\n");
        printf("2. Tampilkan List Alat Lab Yang Sedang Dipinjam\n");
        printf("3. Pinjam Alat Lab\n");
        printf("4. Kembalikan Alat Lab\n");
        printf("5. Keluar\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                view_list();
                break;
            case 2:
                view_list_pinjam();
                break;
            case 3:
                pinjam_alat();
                break;
            case 4:
                kembalikan_alat(); 
                break;
            case 5: 
                printf("Keluar dari menu user...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 5); // Loop berhenti jika pilihan = 5
}

void pinjam_alat() {
    alat_lab daftar_alat[maxSize];
    int jumlah_alat = 0;