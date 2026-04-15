# nama : deden ahmad jamil
# nim : 2501518

catatan_mang_dadang = {}

#input jumlah jenis sayur
jumlah_sayur = int(input("Berapa jenis sayur yang dipanen? "))

print("\n")

#perulangan
for i in range(1, jumlah_sayur + 1):
    #input nama dan berat sayur
    nama_sayur = input(f"Masukkan nama sayur ke-{i}: ")
    berat_sayur = int(input(f"Masukkan berat {nama_sayur} (kg): "))
    
    # Memasukkan data ke dalam dictionary
    catatan_mang_dadang[nama_sayur] = berat_sayur

# values itu buat manggil semua nilai (angkanya saja)di dalam directionary
total_berat = sum(catatan_mang_dadang.values()) #sum untuk menghitung semua berat

print("\n")

print(f"Total hasil panen Mang Dadang adalah: {total_berat} kg")