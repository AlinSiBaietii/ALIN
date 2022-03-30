#include <iostream>
#include <limits>
#include <string>

class Profil;
class Card;
class Cont_economii;

class Profil{


public:

    std::string nume;
    //constrcutor
    Profil(std::string nume=""):nume(nume){}
    //getter
    std::string get_nume(){return this->nume;}



};



class Card{

    friend class Profil;

public:
    float sold_card;

    Card(float sold_card=0): sold_card(sold_card){}

    void set_sold_card(float sold_card){
        this->sold_card = sold_card;
    }
    float get_sold_card(){
        return this->sold_card;
    }

};

class Cont_economii{
    friend class Profil;

private:
    float cont_economii;
    float dobanda;

public:
    Cont_economii(float cont_economii =0, float dobanda=0):cont_economii(cont_economii), dobanda(dobanda){}

    float get_cont_economii(){
        return this->cont_economii;
    }

    float get_dobanda(){
        return this->dobanda;
    }


};


int main(){

    std::string nume;
    float c_sold;
    float ce_sold;
    float ce_dobanda;
    float optiune;

    std::getline(std::cin,nume);
    std::cin>>c_sold;
    std::cin>>ce_sold;
    std::cin>>ce_dobanda;


    Profil p(nume);
    Card card(c_sold);
    Cont_economii cont_economii(ce_sold,ce_dobanda);
    std::cin>>optiune;

    if(optiune==1){
        std::cout<<p.get_nume()<<std::endl;
        std::cout<<"card_bancar:"<<std::endl;
        std::cout<<card.get_sold_card()<<std::endl;
        std::cout<<"cont_economii:"<<std::endl;
        std::cout<<cont_economii.get_cont_economii()<<std::endl;
        std::cout<<cont_economii.get_dobanda()<<std::endl;


    }

    if(optiune==2){

        float suma;

        std::cin>>suma;

        if(suma<0) {std::cout<<"EROARE: depunere suma negativa"<<std::endl;}


        else if(suma > 0){

            float variabila;
            variabila = card.get_sold_card() + suma;
            std::cout << "card_bancar:" << std::endl;
            std::cout << variabila << std::endl;

        }

    }

    if(optiune == 3){

        float suma, variabila;

        std::cin >> suma;

        if(suma > card.get_sold_card()){
            std::cout << "EROARE: fonduri insuficiente" << std::endl;
        }

        else if(suma < card.get_sold_card()){
            variabila = card.get_sold_card() - suma;
            std::cout << variabila << std::endl;
        }
    }

    if(optiune==4){





    }

    return 0;



}