#ifndef PARKIR_H
#define PARKIR_H
 
#include <iostream>
#include <iomanip>
 
class Parkir {
 
private:
 
    struct Node {
 
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
 
public:
 
    Parkir();
    bool isEmpty() const;
    void menu();
    void addPlat(int);
    void deletePlat(int);
    void displayPendapatan();
    void display();
};
 
#endif // PARKIR_H