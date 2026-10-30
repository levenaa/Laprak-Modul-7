#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(Stack S) {
    return S.Top == nullptr;
}

Node* alokasi(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void dealokasi(Node* &p) {
    delete p;
    p = nullptr;
}

bool push(Stack &S, int x) {
    Node* p = alokasi(x);
    if (p == nullptr) return false;
    
    p->next = S.Top;
    S.Top = p;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    Node* p = S.Top;
    x = p->info;
    S.Top = p->next;
    dealokasi(p);
    return true;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "TOP: ";
        Node* p = S.Top;
        while (p != nullptr) {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void pushAscending(Stack &S, int x) {
    Stack S_bantu;
    createStack(S_bantu);
    
    int temp;
    // Pindahkan elemen ke stack bantu sambil mencari posisi yang tepat
    // Aturan: Urutan menaik dari bawah ke TOP, artinya nilai terbesar di TOP.
    // Selama elemen di TOP stack utama lebih besar dari x, pindahkan ke stack bantu.
    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, temp);
        push(S_bantu, temp);
    }
    
    // Masukkan x ke stack utama
    push(S, x);
    
    // Kembalikan elemen dari stack bantu ke stack utama
    while (!isEmpty(S_bantu)) {
        pop(S_bantu, temp);
        push(S, temp);
    }
}

void clearStack(Stack &S) {
    int x;
    while (!isEmpty(S)) {
        pop(S, x);
    }
}