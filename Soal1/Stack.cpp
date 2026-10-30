#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(Stack S) {
    return S.Top == 0;
}

bool isFull(Stack S) {
    return S.Top == MAX_ELM;
}

bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "TOP: ";
        for (int i = S.Top; i >= 1; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (isEmpty(S)) return;
    
    Stack S_bantu;
    createStack(S_bantu);
    
    int temp;
    // Pindahkan semua elemen dari S utama ke S bantu
    while (!isEmpty(S)) {
        pop(S, temp);
        push(S_bantu, temp);
    }
    
    // Pindahkan kembali ke S utama (urutan sekarang sudah terbalik)
    while (!isEmpty(S_bantu)) {
        pop(S_bantu, temp);
        push(S, temp);
    }
}