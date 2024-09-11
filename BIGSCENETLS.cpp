#include <iostream>
#include <vector>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For time

using namespace std;

// Function to get random item based on the section
string BarangRandom(int section) {
    string barang;
    srand(time(0));  // Seed for random number generation

    // Define barangs for each section
    vector<string> barangdapur = {"kaleng sarden", "Pisau dapur", "Botol Air mineral", "Kaleng bekas", "Panci Teflon", "2,5 kg Beras"};
    vector<string> barangruangtamu = {"Senter", "Koran bekas", "Kotak P3K", "Remot TV", "sekotak tisu", "Korek api"};
    vector<string> barangruangtidur = {"Kemeja kotor", "Jaket hoodie", "Tas Ransel", "Tongkat bisbol", "Buku catatan Matematika"};

    // Choose a random barang based on the section
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
    vector<string> BarangDiambil;  // Stores all the items collected
    int jumlahbarang = 0;
    int pilihan;  // To store the user's choice
    bool menggeledah = true;  // To control the scavenging loop

    cout << "Jadi ceritanya kamu sedang kabur dari gerombolan zombi! Kemudian kamu menemukan sebuah rumah terbengkalai dan memutuskan untuk bersembunyi sambil menggeledah isi rumah tersebut.\n";

    // Start scavenging loop
    while (menggeledah) {
        // Present choices of sections to search
        cout << "\nBagian rumah mana yang akan kamu geledah:\n";
        cout << "1. Dapur\n";
        cout << "2. Ruang Tamu\n";
        cout << "3. Kamar tidur\n";
        cout << "(Pilih dalam angka 1, 2, atau 3): ";
        cin >> pilihan;

        // Get a random item from the chosen section
        string barangTemuan = BarangRandom(pilihan);
        cout << "Kamu menemukan: " << barangTemuan << "!\n";
        BarangDiambil.push_back(barangTemuan);  // Add item to the collected items
        jumlahbarang++;

        // Ask if the user wants to search another section or leave
        cout << "\nSelanjutnya, apa yang akan kamu lakukan:\n";
        cout << "1. Melanjutkan Geledah rumah\n";
        cout << "2. Keluar dari rumah\n";
        cout << "(Pilih dalam angka 1 atau 2): ";
        cin >> pilihan;

        // If user chooses to leave, end the scavenging loop
        if (pilihan == 2) {
            menggeledah = false;
            cout << "\nKamu memutuskan untuk keluar dari rumah dan melanjutkan perjalananmu.\n";
        }
    }

    // Output the items collected
    cout << "\nBarang yang kamu dapatkan dari rumah tersebut:\n";
    for (const string& barang : BarangDiambil) {
        cout << "- " << barang << endl;
    }

    cout << "\nJumlah barang yang diambil: " << jumlahbarang << endl;

    cout << "Semoga kamu selamat di luar sana!\n";
    return 0;
}
