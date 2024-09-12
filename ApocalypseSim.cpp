#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

string BarangRandom(int section) {
    string barang;
    srand(time(0));

    vector<string> barangdapur = {"kaleng sarden", "Pisau dapur", "Botol Air mineral", "Kaleng bekas", "Panci Teflon", "2,5 kg Beras"};
    vector<string> barangruangtamu = {"Senter", "Koran bekas", "Kotak P3K", "Remot TV", "sekotak tisu", "Korek api"};
    vector<string> barangruangtidur = {"Kemeja kotor", "Jaket hoodie", "Tas Ransel", "Tongkat bisbol", "Buku catatan Matematika"};

    switch (section) {
        case 1:
            barang = barangdapur[rand() % barangdapur.size()];
            break;
        case 2:
            barang = barangruangtamu[rand() % barangruangtamu.size()];
            break;
        case 3:
            barang = barangruangtidur[rand() % barangruangtidur.size()];
            break;
        default:
            barang = "Nothing";
            break;
    }

    return barang;
}

int main() {
    vector<string> BarangDiambil;
    int jumlahbarang = 0;
    int pilihan;
    bool menggeledah = true;


    cout << "Jadi ceritanya kamu sedang kabur dari gerombolan zombi! Kemudian kamu menemukan sebuah rumah terbengkalai dan memutuskan untuk bersembunyi sambil menggeledah isi rumah tersebut.\n";

    while (menggeledah) {
        cout << "\nBagian rumah mana yang akan kamu geledah:\n";
        cout << "1. Dapur\n";
        cout << "2. Ruang Tamu\n";
        cout << "3. Kamar tidur\n";
        cout << "(Pilih dalam angka 1, 2, atau 3): ";
        cin >> pilihan;

        string barangTemuan = BarangRandom(pilihan);
        cout << "Kamu menemukan: " << barangTemuan << "!\n";
        BarangDiambil.push_back(barangTemuan);

        cout << "\nSelanjutnya, apa yang akan kamu lakukan:\n";
        cout << "1. Melanjutkan Geledah rumah\n";
        cout << "2. Keluar dari rumah\n";
        cout << "(Pilih dalam angka 1 atau 2): ";
        cin >> pilihan;

        if (pilihan == 2) {
            menggeledah = false;
            cout << "\nKamu memutuskan untuk keluar dari rumah dan melanjutkan perjalananmu.\n";
        }
    }

    cout << "\nBarang yang kamu dapatkan dari rumah tersebut:\n";
    for (const string& barang : BarangDiambil) {
        cout << "- " << barang << endl;
    }
    
    cout << "\nJumlah barang yang diambil: " << jumlahbarang << endl;
    cout << "Semoga kamu selamat di luar sana!\n";
    return 0;
}