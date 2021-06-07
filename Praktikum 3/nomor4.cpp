//Nama : Bagas Dwi Sulistyo
//NIM  : 20051397076
//Kelas : 2020 MI B

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

class Parkir {

private :

    struct Node
    {
        int plat;
        Node* next;
    };

    Node* head;
    Node* tail;

    static int size;
    static int pendapatan;
    
    int getSize() const;
    int getPendapatan() const;
    bool isTrue(int) const;

public : 
    Parkir();
    bool isEmpty() const;
    void menu();
    void addPlat(int);
    void deletePlat(int);
    void displayPendapatan();
    void display();


};

int Parkir::pendapatan = 0;
int Parkir::size = 0;

Parkir::Parkir(){
    head = NULL;
    tail = NULL;
}

bool Parkir::isEmpty() const {
    return head == NULL;
}

int Parkir::getSize() const{
    return this->size;
}

int Parkir::getPendapatan() const{
    return this->pendapatan;
}

void Parkir::menu() {
    cout << "\n--------------------------------------------------------------------------------" << endl;
    cout << setw(51) << "PROGRAM ANTRIAN KENDARAAN" << endl;
    cout << "--------------------------------------------------------------------------------\n" << endl;
    cout << setw(48) << "1. Antrian Parkir Mobil" << endl;
    cout << setw(43) << "2. Keluarkan Mobil" << endl;
    cout << setw(51) << "3. Tampilkan Antrian Mobil" << endl;
    cout << setw(55) << "4. Menghitung Total Pendapatan" << endl;
    cout << setw(33) << "0. Exit\n" << endl;
    cout << "--------------------------------------------------------------------------------\n" << endl;
}

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

int main(){
    int pilihan, plat;
    char answer;
    bool isTrue = false;

    Parkir* parkir = new Parkir();

    do
    {
        parkir->menu();

        cout << "Masukkan Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
 
            case 0:
 
                exit(1);
 
            case 1:
 
                std::cout << "\nMasukkan Plat Nomor : ";
                std::cin >> plat;
 
                while (!std::cin) {
 
                    std::cout << "\nInput hanya angka!" << std::endl;
 
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 
                    std::cout << "\nMasukkan Plat Nomor : ";
                    std::cin >> plat;
                }
 
                parkir->addPlat(plat);
 
                BACK1:
                std::cout << "\nKembali ke menu? (y/N) : ";
                std::cin >> answer;
 
                if(answer == 'y' || answer == 'Y') {
 
                    isTrue = true;
 
                } else if(answer == 'n' || answer == 'N') {
 
                    isTrue = false;
 
                } else {
 
                    std::cout << "\nKode Salah!" << std::endl;
 
                    goto BACK1;
                }
 
                break;
 
            case 2:
 
                if(parkir->isEmpty()) {
 
                    parkir->display();
 
                    BACK2:
                    std::cout << "\nKembali ke menu? (y/N) : ";
                    std::cin >> answer;
 
                    if(answer == 'y' || answer == 'Y') {
 
                        isTrue = true;
 
                    } else if(answer == 'n' || answer == 'N') {
 
                        isTrue = false;
 
                    } else {
 
                        std::cout << "\nKode Salah!" << std::endl;
 
                        goto BACK2;
                    }
 
                } else {
 
                    parkir->display();
 
                    std::cout << "\nPlat yang dihapus : ";
                    std::cin >> plat;
 
                    while (!std::cin) {
 
                        std::cout << "\nInput hanya angka!" << std::endl;
 
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 
                        std::cout << "\nMasukkan Plat Nomor : ";
                        std::cin >> plat;
                    }
 
                    parkir->deletePlat(plat);
 
                    BACK3:
                    std::cout << "\nKembali ke menu? (y/N) : ";
                    std::cin >> answer;
 
                    if(answer == 'y' || answer == 'Y') {
 
                        isTrue = true;
 
                    } else if(answer == 'n' || answer == 'N') {
 
                        isTrue = false;
 
                    } else {
 
                        std::cout << "\nKode Salah!" << std::endl;
 
                        goto BACK3;
                    }
                }
 
                break;
 
            case 3:
 
                parkir->display();
 
                BACK4:
                std::cout << "\nKembali ke menu? (y/N) : ";
                std::cin >> answer;
 
                if(answer == 'y' || answer == 'Y') {
 
                    isTrue = true;
 
                } else if(answer == 'n' || answer == 'N') {
 
                    isTrue = false;
 
                } else {
 
                    std::cout << "\nKode Salah!" << std::endl;
 
                    goto BACK4;
                }
 
                break;
 
            case 4:
 
                parkir->displayPendapatan();
 
                BACK5:
                std::cout << "\nKembali ke menu? (y/N) : ";
                std::cin >> answer;
 
                if(answer == 'y' || answer == 'Y') {
 
                    isTrue = true;
 
                } else if(answer == 'n' || answer == 'N') {
 
                    isTrue = false;
 
                } else {
 
                    std::cout << "\nKode Salah!" << std::endl;
 
                    goto BACK5;
                }
 
                break;
 
            default:
 
                std::cout << "\nKode Salah!" << std::endl;
 
                BACK6:
                std::cout << "\nKembali ke menu? (y/N) : ";
                std::cin >> answer;
 
                if(answer == 'y' || answer == 'Y') {
 
                    isTrue = true;
 
                } else if(answer == 'n' || answer == 'N') {
 
                    isTrue = false;
 
                } else {
 
                    std::cout << "\nKode Salah!" << std::endl;
 
                    goto BACK6;
                }
 
                break;
        }
    } while (isTrue);

    delete parkir;

    return 0;
    
}