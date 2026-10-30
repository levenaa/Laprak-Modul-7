#include "stack.h"
#include <iostream>

using namespace std;

void tampilkanMenu() {
    cout << "\n=== MENU STACK ARRAY (SOAL 1) ===" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Tampilkan Stack" << endl;
    cout << "4. Balik Stack" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan: ";
}

int main() {
    Stack S;
    createStack(S);
    int pilihan, x;

    do {
        tampilkanMenu();
        if (!(cin >> pilihan)) break;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai integer: ";
                cin >> x;
                if (push(S, x)) {
                    cout << "Berhasil push " << x << endl;
                } else {
                    cout << "Gagal! Stack penuh (Kapasitas maksimum 20 elemen)." << endl;
                }
                break;
            case 2:
                if (pop(S, x)) {
                    cout << "Nilai yang berhasil di-Pop: " << x << endl;
                } else {
                    cout << "Gagal! Stack kosong." << endl;
                }
                break;
            case 3:
                printInfo(S);
                break;
            case 4:
                balikStack(S);
                cout << "Stack berhasil dibalik." << endl;
                printInfo(S);
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}