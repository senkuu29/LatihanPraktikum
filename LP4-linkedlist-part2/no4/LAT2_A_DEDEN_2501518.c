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

  // jawaban no 3
  updatePenyakit(1, "Tipes");
  insertTengahSesudah(4, 5, "Aura", "Maag");
  hapusAwal();
  hapusAkhir();

  // jawaban no 4
  updateNama(4, "Sasha");
  updatePenyakit(2, "Radang Tenggorokan");
  insertAkhir(6, "Galuh", "Luka Bakar");
  hapusTengah("Aura");
  
  // tampilkan hasil
  tampilkan();

  return 0;
}