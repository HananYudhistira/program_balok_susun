#include <iostream>
using namespace std;

int KebutuhanKardus(int kebutuhanTingkat, int tingkat) {
    return kebutuhanTingkat = tingkat * (tingkat + 1) / 2;
}

int main()
{
    //var menu: 
    int pilihanmenu;

    //var kardus:
    int tingkat = 1; //tingkat tujuan
    int persediaanKardus = 0;
    int kebutuhanTingkat = 0;

    //var case 1:
    int kardusTambahan;

    //var case 2 & 3:
    int tingkatSekarang = 0; //tingkat sekarang
    int kardusKurang;
    int penambahanTingkat;

    //var case 4:
    int kebutuhanKardus;
    int kardusTerpakai = 0;

    do{
        cout << "\n=== MENARA KARDUS HENI ===";
        cout << "\n1. Tambah Persediaan Kardus";
        cout << "\n2. Bangun Satu Tingkat";
        cout << "\n3. Bangun Sebanyak Mungkin";
        cout << "\n4. Lihat Laporan Menara";
        cout << "\n0. Keluar";
        cout << "\nPilihan: ";
        cin >> pilihanmenu;
        cout << endl;

        switch (pilihanmenu){
        case 1: //Tambah Persediaan Kardus

        cout << "\nJumlah kardus tambahan: "; //tahap satu
        cin >> kardusTambahan;
        cout << endl;

        if (kardusTambahan <= 0){

            cout << "\nJumlah tambahan harus lebih besar dari 0." << endl;
            break;
        } else {

            persediaanKardus += kardusTambahan;

            cout << "\nKardus berhasil ditambahkan."; //setelah ditambahkan
            cout << "\nPersediaan sekarang: " << persediaanKardus << endl; //pake PersediaanKardus
            break;
        }
        break;

        case 2: //Bangun Satu Tingkat

        if (persediaanKardus < KebutuhanKardus(kebutuhanTingkat, tingkat)){

            kardusKurang = KebutuhanKardus(kebutuhanTingkat, tingkat) - persediaanKardus;

            cout << "\nKardus tidak cukup"; 
            cout << "\nKekurangan kardus: " << kardusKurang << endl; //pake kardusKurang
            break;
        } else {

            persediaanKardus -= KebutuhanKardus(kebutuhanTingkat, tingkat);
            
            cout << "\nTingkat " << tingkat << " berhasil dibangun."; //klo kardus cukup
            cout << "\nSisa Kardus: " << persediaanKardus << endl; //pake persediaanKardus
            
            kardusTerpakai += KebutuhanKardus(kebutuhanTingkat, tingkat);
            tingkat ++;
            tingkatSekarang ++;
            kardusKurang = KebutuhanKardus(kebutuhanTingkat, tingkat) - persediaanKardus;
            break;
        }
        break;

        case 3: //Bangun Sebanyak Mungkin

        penambahanTingkat = 0;

        while (persediaanKardus >= KebutuhanKardus(kebutuhanTingkat, tingkat)){

            persediaanKardus -= KebutuhanKardus(kebutuhanTingkat, tingkat);
            kardusTerpakai += KebutuhanKardus(kebutuhanTingkat, tingkat);
            tingkat ++;
            tingkatSekarang ++;
            penambahanTingkat ++;
        }

        kardusKurang = KebutuhanKardus(kebutuhanTingkat, tingkat) - persediaanKardus;

        cout << "\nTingkat berhasil ditambahkan: " << penambahanTingkat; //pake penambahanTingkat
        cout << "\nTinggi menara sekarang: " << tingkatSekarang; //pake tingkatSekarang
        cout << "\nSisa kardus:" << persediaanKardus << endl; //pake persediaanKardus

        break;

        case 4: //Laporan Menara

        cout << "\n=== LAPORAN MENARA ===";
        cout << "\nTinggi menara: " << tingkatSekarang; //pake tingkatSekarang
        cout << "\nTotal kardus terpakai: " << kardusTerpakai; //pake kardusTerpakai
        cout << "\nSisa kardus: " << persediaanKardus; //pake persediaanKardus
        cout << "\nKebutuhan tingkat berikutnya: " << KebutuhanKardus(kebutuhanTingkat, tingkat) << endl; //pake kardusKurang

        break;

        case 0: //keluar
        return 0;
        break;

        default: //Tidak Valid
        cout << "\nPilihan tidak tersedia." << endl;

        break;
    }
    } while (pilihanmenu != 0);
    return 0;
}