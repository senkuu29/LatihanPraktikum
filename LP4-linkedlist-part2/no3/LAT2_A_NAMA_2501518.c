// nama : deden ahamd jamil
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

  // jawaban no 3
    updatePenyakit(1, "Tipes");
    insertTengahSesudah(4, 5, "Aura", "Maag");
    hapusAwal();
    hapusAkhir();

  // Menampilkan hasil
  tampilkan();

  return 0;
}