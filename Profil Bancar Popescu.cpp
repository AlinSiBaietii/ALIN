#include<iostream>
#include<string>



class Profil;

class Card;

class Cont_economii;

class Card {
    friend Profil;
private:
    float sold_card;
public:
    //constructor care acopera tot
    Card(float sold_card = 0) : sold_card(sold_card){};

    //setter
    void set_sold_card(float sold_card) { this->sold_card = sold_card; }

    //getter
    float get_sold_card(){return this->sold_card;}


};
class Cont_economii{
    friend Profil;
private:
    float cont_economii;
    float dobanda;
public:
    //constructor
    Cont_economii(float cont_economii=0,float dobanda=0):cont_economii(cont_economii),dobanda(dobanda){};
    //setter
    void set_cont_economii(float cont_economii){this->cont_economii=cont_economii;}
    void set_dobanda(float dobanda){this->dobanda=dobanda;}
    //getter
    float get_cont_economii(){return this->cont_economii;}
    float get_dobanda(){return this->dobanda;}

};

class Profil {
private:
    std::string nume;
    Card card;
    Cont_economii cont_economii;

public:
    //constructor
    Profil(std::string nume,Card &card,Cont_economii &cont_economii) : nume(nume) {
        this->card.sold_card = card.sold_card;
        this->cont_economii.cont_economii = cont_economii.cont_economii;
        this->cont_economii.dobanda = cont_economii.dobanda;
    }
//functia pentru dobanda
    void dobanda(){
        cont_economii.cont_economii =
                cont_economii.cont_economii + cont_economii.cont_economii * cont_economii.dobanda / 100;

    }
    //setter pentru nume
    void set_nume(std::string nume){this->nume=nume;}
    //getter pentru nume
    std::string get_nume(){return nume;}
    //getteri pentru card si cont_economii
    Card get_card(){return card;}
    Cont_economii get_cont_economii(){return cont_economii;}
    //functia de depunere
    void depunere(float suma){
        if (suma>=0){
            std::cout<<"card_bancar:"<<"\n";
            card.sold_card=card.sold_card+suma;
            std::cout<<card.sold_card<<"\n";
        }else std::cout<<"EROARE: depunere suma negativa";
    }
    //functia de extragere
    void extragere(float suma){
        if(suma<=card.sold_card){
            std::cout<<"card_bancar:"<<"\n";
            card.sold_card=card.sold_card-suma;
            std::cout<<card.sold_card<<"\n";
        }else std::cout<<"EROARE: fonduri insuficiente";
    }
//functia pentru transfer
    void transfer(float suma){
        if(suma>card.get_sold_card()) std::cout <<"EROARE: fonduri insuficiente";
        else {
            card.sold_card-=suma;
            cont_economii.cont_economii+=suma;
            std::cout<<"card_bancar:"<<'\n';
            std::cout<<card.sold_card<<"\n";
            std::cout<<"cont_economii:"<<"\n";
            dobanda();
            std::cout<<cont_economii.cont_economii<<"\n";
            std::cout<<cont_economii.dobanda<<"\n";
        }
    }
//functia pentru acumulare
    void acumulare(float suma){
        int i=0;
        while(cont_economii.cont_economii<suma){
            dobanda();
            i++;
        }
        std::cout<<i;
    }
};
int main(){
    std::string nume;
    float suma;
    float sold_card;
    float economii;
    float dobanda;
    int optiune;
    std::getline(std::cin,nume);
    std::cin>>sold_card>>economii>>dobanda;
    std::cin>>optiune;
    Card card;
    Cont_economii cont_economii;
    card.set_sold_card(sold_card);
    cont_economii.set_cont_economii(economii);
    cont_economii.set_dobanda(dobanda);
    Profil p(nume,card,cont_economii);
    if(optiune==1){
        std::cout<<p.get_nume()<<"\n";
        std::cout << "card_bancar:" << "\n";
        std::cout<<p.get_card().get_sold_card()<<"\n";
        std::cout<< "cont_economii:" << "\n";
        std::cout<<p.get_cont_economii().get_cont_economii()<<"\n";
        std::cout<<p.get_cont_economii().get_dobanda()<<"\n";
    }
    if(optiune==2){
        std::cin>>suma;
        p.depunere(suma);
  }
if(optiune==3){
    std::cin>>suma;
    p.extragere(suma);
    
    
}
if(optiune==4){
    std::cin >> suma;
            p.transfer(suma);
    
}
if(optiune==5){
    
    std::cin >> suma;
            p.acumulare(suma);
}
















}
