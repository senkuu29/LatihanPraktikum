# nama : deden ahmad jamil
# nim : 2501518

# list kosong
daftar_tugas = []

# menambahkan data list menggunakan append
daftar_tugas.append("Belajar Python")
daftar_tugas.append("Mengerjakan Tugas UPI")
daftar_tugas.append("Olahraga")

daftar_tugas.remove("Olahraga")     # menghapus list bernama olahraga
daftar_tugas.insert(1,"Beli Buku")  # menambahkan Beli Buku di index 1

daftar_tugas.sort()                # sort daftar tugas dari a-zj

print("Daftar Tugas Saya:")
i = 1  # deklarasi buat nomor
for data in daftar_tugas:
     print(f"{i}. {data}") 
     i += 1  # biarnambah iterasinya