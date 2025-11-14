#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char kataunik[MAX_WORDS][MAX_WORD_LEN]; 
int hitungkata = 0; 
char judul[1024] = "";

int pengecekan(const char* word) {
    for (int i = 0; i < hitungkata; i++) {
        if (strcmp(word, kataunik[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
FILE* lagu = fopen("lirik.txt", "r");
