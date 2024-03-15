#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//untuk panjang maksimum dan minimum teks.
#define MAX_LENGTH 2024
#define MIN_LENGTH 2023

// menerima pointer ke integer sebagai parameter
void lessThanRequired(int *length);
void equalThanRequired();
void moreThanRequired(int *length);

int checkLenghtRequirement(char* text);//menerima array karakter sebagai parameter.
//tidak ada yang di ubah(hanya di pindahkan)
int main() {
  int lengthOfText, selectOption;
  FILE *fptr = NULL;
  char text[MAX_LENGTH];
  
    // Membuka file untuk dibaca
  fptr = fopen("file.txt", "r");

  // Memeriksa apakah file berhasil dibuka
  if(fptr == NULL){
    printf("Error");
    exit(1);
  }

  // Membaca teks dari file
  fgets(text, MAX_LENGTH, fptr);

  // Menutup file setelah selesai membaca
  fclose(fptr);

  // Memeriksa panjang teks dan menentukan tindakan yang tepat
  selectOption = checkLenghtRequirement(text);
  
    // Menghitung panjang teks menggunakan strlen
  lengthOfText = strlen(text);

  // Memanggil fungsi berdasarkan nilai selectOption
  void (*functions[3])(int*) = {lessThanRequired, equalThanRequired, moreThanRequired};
  functions[selectOption](&lengthOfText);

  printf("\nThe Lenght is updated to %d", lengthOfText);// Menampilkan panjang teks setelah diupdate

  return 0;
}

// Fungsi utama dari program.
// Membuka file "file.txt" untuk dibaca.
// Membaca teks dari file ke dalam array text.
// Menutup file setelah selesai membaca.
// Memanggil checkLenghtRequirement untuk menentukan tindakan yang tepat berdasarkan panjang teks yang dibaca.
// Menghitung panjang teks menggunakan fungsi strlen().
// Memanggil fungsi yang sesuai berdasarkan nilai yang dikembalikan oleh checkLenghtRequirement.
// Menampilkan panjang teks setelah diperbarui.

//fungsi yang dipanggil untuk menangani tindakan yang sesuai berdasarkan panjang teks.
void lessThanRequired(int *length) {
  printf("\nThe length of your text is less than specified, please update your text");
  printf("\nLength Before : %d", *length);
  *length = MIN_LENGTH;
}

void equalThanRequired() {
  printf("\nThank you, Your text length is correct");
}

void moreThanRequired(int *length) {
  printf("\nYour text is too long, please reduce the text");
  *length = MIN_LENGTH;
}

// untuk menentukan apakah panjang teks sesuai dengan kebutuhan.
int checkLenghtRequirement(char* text){
  int length = strlen(text);
  return (length < MIN_LENGTH) ? 0 : ((length == MIN_LENGTH) ? 1 : 2);
}
