#include <stdio.h>

#define MAX 10

int antrian[MAX];
int depan = -1;
int belakang = -1;

void enqueue(int data) {
    if (belakang == MAX - 1)
        puts("Antrian penuh");
    else {
        if (depan == -1)
            depan = 0;
        belakang++;
        antrian[belakang] = data;
    }
}

void dequeue() {
    if (depan == -1 || depan > belakang)
        puts("Antrian kosong");
    else {
        if (antrian[depan] <= 5)
            printf("ditangani dokter umum\n");
        else
            printf("ditangani dokter spesialis\n");
        depan++;
    }
}

int main() {
    int i, pasien;
    char input[MAX * 2];
    
    printf("Masukkan tingkat keparahan pasien: ");
    fgets(input, sizeof(input), stdin); 
    
    int j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ') { 
            pasien = pasien * 10 + (input[i] - '0');
        } else {
            enqueue(pasien);
            pasien = 0; 
        }
    }
    enqueue(pasien);
    
    printf("\n");
    for (i = 0; i < MAX; i++) {
        dequeue();
    }

    return 0;
}