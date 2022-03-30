#include <iostream>
#include <string>
class Magazin;
class Prouds;
class Produs {
    friend Magazin;
private:
    std::string nume;
    float pret;
    float nr_produse;
public:
    Produs(std::string nume = "", float pret = 0, float nr_produse = 0) : nume(nume), pret(pret),nr_produse(nr_produse) {}

    void set_nume(std::string nume) {
        this->nume = nume;
    }

    std::string get_nume() {
        return nume;
    }

    void set_pret(float pret) {
        this->pret = pret;
    }

    float get_pret() {
        return pret;
    }

    void set_nr_produse(float nr_produse) {
        this->nr_produse = nr_produse;
    }

    float get_nr_produse() {
        return nr_produse;
    }


};

class Magazin {
private:
    Produs produse[10];
public:
   void set_produse(std::string nume, float pret, float nr_produse){

   }

};

int main() {
    std::string nume;
    float pret;
    float nr_produse;
    while (nume != "STOP") {
        std::getline(std::cin,nume);
        std::cin>>pret>>nr_produse;

    }
    return 0;
}
