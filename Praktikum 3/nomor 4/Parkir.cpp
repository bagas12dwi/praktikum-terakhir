#include "parkir.h"
 
/* pendapatan = 0 */
 
int Parkir::pendapatan = 0;
 
/* size = 0 */
 
int Parkir::size = 0;
 
/* head and tail = null */
 
Parkir::Parkir() {
 
    head = nullptr;
    tail = nullptr;
}
 
/* is empty */
 
bool Parkir::isEmpty() const {
 
    return head == nullptr;
}
 
/* get size */
 
int Parkir::getSize() const {
 
    return this->size;
}
 
/* get pendapatan */
 
int Parkir::getPendapatan() const {
 
    return this->pendapatan;
}
 
/* menu */
 
void Parkir::menu() {
 
    std::cout << "\n--------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(51) << "PROGRAM ANTRIAN KENDARAAN" << std::endl;
    std::cout << "--------------------------------------------------------------------------------\n" << std::endl;
 
    std::cout << std::setw(48) << "1. Antrian Parkir Mobil" << std::endl;
    std::cout << std::setw(43) << "2. Keluarkan Mobil" << std::endl;
    std::cout << std::setw(51) << "3. Tampilkan Antrian Mobil" << std::endl;
    std::cout << std::setw(55) << "4. Menghitung Total Pendapatan" << std::endl;
    std::cout << std::setw(33) << "0. Exit\n" << std::endl;
 
    std::cout << "--------------------------------------------------------------------------------\n" << std::endl;
}
 
/* add plat */
 
void Parkir::addPlat(int n) {
 
    this->size++;
 
    Node* temp = new Node;
 
    temp->plat = n;
    temp->next = nullptr;
 
    if(isEmpty()) {
 
        head = temp;
        tail = temp;
 
    } else {
 
        tail->next = temp;
        tail = tail->next;
    }
 
    std::cout << "\n" << n << " berhasil ditambahkan" << std::endl;
}
 
/* is true, cek plat yang dicari ada / tidak */
 
bool Parkir::isTrue(int n) const {
 
    bool result = false;
 
    Node* temp = head;
 
    while (temp != nullptr) {
 
        if(temp->plat == n) {
 
            result = true;
        }
 
        temp = temp->next;
    }
 
    return result;
}
 
/* delete plat */
 
void Parkir::deletePlat(int n) {
 
    if(isTrue(n)) {
 
        Node* current = head;
        Node* prev = nullptr;
 
        if(current->next == nullptr) {
 
            std::cout << "\n" << current->plat << " sudah dikeluarkan!" << std::endl;
 
            delete current;
            head = nullptr;
 
            this->size--;
 
            this->pendapatan += 3500;
 
        } else {
 
            if(current->plat == n) {
 
                std::cout << "\n" << current->plat << " sudah dikeluarkan!" << std::endl;
 
                head = head->next;
                delete current;
 
                this->size--;
 
                this->pendapatan += 3500;
 
            } else {
 
                int pos = 0;
 
                current = head;
 
                while (current != nullptr) {
 
                    if(current->plat == n) {
 
                        pos++;
                        break;
                    }
 
                    pos++;
 
                    current = current->next;
                }
 
                current = head;
 
                for(int i = 0; i < pos; i++) {
 
                    std::cout << "\n" << current->plat << " sudah dikeluarkan!";
 
                    prev = current;
                    delete current;
 
                    current = current->next;
 
                    this->size--;
 
                    this->pendapatan += 3500;
                }
 
                head = prev->next;
 
                std::cout << std::endl;
            }
        }
 
    } else {
 
        std::cout << "\nPlat nomor yang diinputkan tidak ada!" << std::endl;
    }
}
 
/* display pendapatan */
 
void Parkir::displayPendapatan() {
 
    std::cout << "\nPendapatan : " << getPendapatan() << std::endl;
}
 
/* display */
 
void Parkir::display() {
 
    if(isEmpty()) {
 
        std::cout << "\nParkiran Kosong!" << std::endl;
 
    } else {
 
        std::cout << "\nDaftar Plat Kendaraan : \n" << std::endl;
 
        int nomor = 1;
 
        Node* temp = head;
 
        while (temp != nullptr) {
 
            std::cout << (nomor++) << ". " << temp->plat << std::endl;
 
            temp = temp->next;
        }
 
        std::cout << "\nTotal Kendaraan : " << getSize() << std::endl;
    }
}