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
        case 3:
            update_alat();
            break;
        case 4:
            printf("Kembali ke menu admin...\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
    }
}

void add_alat() {
    alat_lab alat_baru; 

    printf("\n--- Menambah Alat Lab Baru ---\n");
    printf("Masukkan ID Alat: ");
    scanf("%u", &alat_baru.id_alat); 

    printf("Masukkan Nama Alat: ");
    scanf(" %[^\n]", alat_baru.nama_alat); 

    printf("Masukkan Merek Alat: ");
    scanf(" %[^\n]", alat_baru.merk_alat);

    printf("Masukkan Model Alat: ");
    scanf(" %[^\n]", alat_baru.model_alat);

    printf("Masukkan Tahun Produksi: ");
    scanf("%u", &alat_baru.tahun_produksi_alat);

    printf("Masukkan Jumlah Stok: ");
    scanf("%u", &alat_baru.jumlah_alat);

    FILE *fptr = fopen("../data/listbarang.txt", "a");
    if (fptr == NULL) {
        printf("Program Gagal: Gagal membuka file listbarang.txt!\n");
        return;
    }

    fprintf(fptr, "\n%u;%s;%s;%s;%u;%u",
            alat_baru.id_alat,
            alat_baru.nama_alat,
            alat_baru.merk_alat,
            alat_baru.model_alat,
            alat_baru.tahun_produksi_alat,
            alat_baru.jumlah_alat);

    fclose(fptr);

    printf("\nProgram Berhasil: Alat baru telah ditambahkan ke listbarang.txt.\n");
}

void delete_alat() {
    alat_lab daftar_alat[maxSize];
    int jumlah_alat = 0;
    unsigned int id_hapus;
    int i, index_ditemukan = -1; 

    load_alat(daftar_alat, &jumlah_alat, "../data/listbarang.txt");

    if (jumlah_alat == 0) {
        printf("\nFile list_barang.txt kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    printf("\n--- Daftar Alat Saat Ini ---");
    view_list(); 

    printf("Masukkan ID Alat yang ingin Anda hapus: ");
    scanf("%u", &id_hapus);

    for (i = 0; i < jumlah_alat; i++) {
        if (daftar_alat[i].id_alat == id_hapus) {
            index_ditemukan = i; 
            break; 
        }
    }

    if (index_ditemukan == -1) {
        printf("\nProgram Gagal: ID Alat %u tidak ditemukan.\n", id_hapus);
        return; 
    }

    FILE *fptr = fopen("../data/listbarang.txt", "w");