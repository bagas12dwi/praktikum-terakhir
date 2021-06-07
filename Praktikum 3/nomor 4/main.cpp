#include <iostream>
#include <limits>
#include "parkir.h"
 
/* program parkir dengan implementasi queue */
 
int main() {
 
    int pilihan, plat;
    char answer;
    bool isTrue = false;
 
    Parkir* parkir = new Parkir();
 
    do {
 
        parkir->menu();
 
        std::cout << "Masukkan Pilihan : ";
        std::cin >> pilihan;
 
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