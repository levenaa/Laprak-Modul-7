#include "stack.h"
#include <iostream>

using namespace std;

void tampilkanMenu() {
    cout << "\n=== MENU STACK POINTER (SOAL 2) ===" << endl;
    cout << "1. Tambah Terurut (pushAscending)" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Tampilkan Stack" << endl;
    cout << "4. Keluar" << endl;
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
                pushAscending(S, x);
                cout << "Berhasil menyisipkan " << x << " secara terurut." << endl;
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
                clearStack(S);
                cout << "Program selesai, memori dibersihkan." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}