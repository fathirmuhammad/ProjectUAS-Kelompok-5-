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