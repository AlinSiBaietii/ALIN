#include <iostream>
#include <string>
#include <utility>
#include <fstream>

class Profil;

class Card;

class Cont_economii;

class Card {
    friend Profil;
private:
    float sold_card;
public:
    Card(float sold_card = 0) : sold_card(sold_card) {}

    void set_sold_card(float sold_card) {
        this->sold_card = sold_card;
    }

    float get_sold_card() {
        return sold_card;
    }


};

class Cont_economii {
    friend Profil;
private:
    float cont_economii;
    float dobanda;
public:
    Cont_economii(float cont_economii = 0, float dobanda = 0) : cont_economii(cont_economii), dobanda(dobanda) {}

    void set_cont_economii(float cont_economii) {
        this->cont_economii = cont_economii;
    }

    float get_cont_economii() {
        return cont_economii;
    }

    void set_dobanda(float dobanda) {
        this->dobanda = dobanda;
    }

    float get_dobanda() {
        return dobanda;
    }

};

class Profil {
private:
    std::string nume;
    Card card;
    Cont_economii cont_economii;
public:
    Profil(std::string nume, Card &card, Cont_economii &cont_economii) : nume(nume) {
        this->card.sold_card = card.sold_card;
        this->cont_economii.cont_economii = cont_economii.cont_economii;
        this->cont_economii.dobanda = cont_economii.dobanda;
    }

    void dobanda() {
        cont_economii.cont_economii =
                cont_economii.cont_economii + cont_economii.cont_economii * cont_economii.dobanda / 100;
    }

    void set_nume(std::string nume) {
        this->nume = nume;
    }

    std::string get_nume() { return nume; }

    Card get_card() {
        return card;
    }

    Cont_economii get_cont_economii() {
        return cont_economii;
    }

    void depunere(float suma) {
        if (suma >= 0) {
            std::cout<<"card bancar:"<<"\n";
            card.sold_card += suma;
        } else
            std::cout << "EROARE: depunere suma negativa";
    }

    void extragere(float suma) {
        if (suma <= card.sold_card)
            std::cout<<"card bancar:"<<"\n";
            card.sold_card -= suma;
        else
            std::cout << "EROARE: fonduri insuficiente";
    }

    void transfer(float suma) {
        if (suma > card.get_sold_card())
            std::cout << "EROARE: fonduri insuficiente";
        else {
            card.sold_card -= suma;
            cont_economii.cont_economii += suma;
        }
        dobanda();
    }

    void acumulare(float suma) {
        int i = 0;
        while (cont_economii.cont_economii < suma) {
            dobanda();
            i++;
        }
        std::cout << i;

    }
};


int main() {
    std::ifstream f("input.in");
    std::string nume;
    float suma;
    float sold_card;
    float economii;
    float dobanda;
    int comanda;
    std::getline(std::cin, nume);
    std::cin >> sold_card >> economii >> dobanda;
    std::cin >> comanda;
    Card card;
    Cont_economii cont_economii;
    card.set_sold_card(sold_card);
    cont_economii.set_cont_economii(economii);
    cont_economii.set_dobanda(dobanda);
    Profil p(nume, card, cont_economii);
    switch (comanda) {
        case 1: {
            std::cout << p.get_nume() << "\n";
            std::cout << "card_bancar:" << "\n";
            std::cout << "cont_economii:" << "\n";
            break;
        }
        case 2: {
            std::cin >> suma;
            p.depunere(suma);
            break;
        }
        case 3: {
            std::cin >> suma;
            p.extragere(suma);
            break;
        }
        case 4: {
            std::cin >> suma;
            p.transfer(suma);
            break;
        }
        case 5: {
            std::cin >> suma;
            p.acumulare(suma);
            break;
        }


    }

    return 0;

}

