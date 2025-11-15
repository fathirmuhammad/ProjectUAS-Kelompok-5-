#include "../include/utils.h"

void menu_admin(){
    int pilihan;
    do{
        printf("=================== Menu Admin ===================\n");
        printf("1. Tampilkan List Alat Lab Yang Tersedia\n");
        printf("2. Tampilkan List Alat Lab Yang Sedang Dipinjam\n");
        printf("3. Edit List Alab Lab\n");
        printf("4. Keluar\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        switch(pilihan){
        case 1:
        view_list();
        break;

        case 2:
        view_list_pinjam();
        break;

        case 3:
        edit_list();
        break;
        
        default:
        printf("Input invalid\n");
        break;
        }
    }while(pilihan != 4);
}

void edit_list() {
    int pilihan;
    printf("\n========== Menu Edit Alat Lab ==========\n");
    printf("1. Tambah Alat Lab Baru\n");
    printf("2. Hapus Alat Lab\n");
    printf("3. Update Data Alat Lab\n");
    printf("4. Kembali ke Menu Utama\n");
    printf("Pilih Menu: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            add_alat();
            break;
        case 2:
            delete_alat();
            break;