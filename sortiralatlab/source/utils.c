#include "../include/utils.h"

void load_alat(alat_lab *arr, int *n, char *nama_file){
    FILE *fptr = fopen(nama_file, "r");
    if (fptr == NULL){
        printf("Program Gagal: file %s tidak ditemukan.\n", nama_file);
        *n = 0;
        return;
    }

    *n = 0; 

    while(fscanf(fptr, "%u;%[^;];%[^;];%[^;];%u;%u\n", 
                    &arr[*n].id_alat,
                    arr[*n].nama_alat,