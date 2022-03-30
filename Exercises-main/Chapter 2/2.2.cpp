#include <iostream>
#include <limits>
#include <string>



//Clasa
class Parinte;


class Copil{
    
    friend class Parinte;
    
    //Date membre
    private:
        int varsta;
        std::string nume;
    
    //Constructor
    public:
        Copil(int varsta=0, std::string nume=" "): varsta(varsta), nume(nume){}
    
    //Functii
    public:
        void modifica_copil(int m, std::string new_s){
            if(m >= 18){
                nume = new_s;
                std::cout<<nume<< std::endl;
            }
            
            else
                std::cout<<"EROARE"<<std::endl;
            
            
        }
    
};


class Parinte{
    
    //Declaram obiectul copil pentru a folosi elementele din clasa Copil
    Copil obiect_copil;
    
    //Functii
    public:
        void modifica_parinte(int m, std::string new_s){
            if(m < 18){
                obiect_copil.nume = new_s;
                std::cout<<obiect_copil.nume<< std::endl;
            }
            
            else
                std::cout<<"EROARE"<<std::endl;
        }
    
};


int main(){
    
    //Initializam Date
    int m;                      //varsta copil
    std::string s;              //nume copil
    std::string new_s;          //nume nou copil
    int x;                      //persoana care solicita
    
    //Citim Date
    std::cin>>m;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, s);
    std::getline(std::cin, new_s);
  
    
    std::cin>>x;
    
    //Initializare Obiecte
    Copil c(m, s);              //Are 2 elemente
    Parinte p;                  //Nu are elemente
 
    //Conditie Parinte
    if(x == 0){
        p.modifica_parinte(m, new_s);
    }
    
    if(x == 1){
        c.modifica_copil(m, new_s);
    }
    
    return 0;
}