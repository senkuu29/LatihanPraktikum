// nama : deden ahmad jamil
// nim : 2501518

#include "antrian_rs.h"

int main() {
  // jawaban no 1 
  insertAwal(1, "Ryan", "Demam");
  insertAkhir(2, "Reybano", "Batuk");
  insertAkhir(3, "Akbar", "Flu");

  // jawaban no 2
  insertAwal(0, "Radit", "Sesak Napas");
  insertTengahSebelum(3, 4, "Sasa", "Sakit Kepala");

  // Menampilkan hasil
  tampilkan();

  return 0;
}