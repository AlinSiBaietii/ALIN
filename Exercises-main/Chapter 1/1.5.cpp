#include <iostream>
#include <limits>
#include <string>


//Clasa
class Pisica{
    
    //Date membre
    private:
        std::string nume;
        int varsta;
        float greutate;
        
    
    //Constructori
    public:
        //0 parametri
        Pisica(){
            this->nume = "";
            this->varsta = 0;
            this->greutate = 0;
        
        }
    
        //1 parametru
        Pisica(std::string nume){
            this->nume = nume;
            this->varsta = 0;
            this->greutate = 0;
        
        }
    
        //2 parametri
        Pisica(std::string nume, int varsta){
            this->nume = nume;
            this->varsta = varsta;
            this->greutate = 0;
        
        }
    
        //3 parametri
        Pisica(std::string nume, int varsta, float greutate){
            this->nume = nume;
            this->varsta = varsta;
            this->greutate = greutate;
        
        }
    
    
    
    //Functii
    public:
        void afisare(){
            std::cout << nume << " ";
            std::cout << varsta << " ";
            std::cout << greutate << std::endl;
        }
    
    
};


//Functia main
int main(){
    
    //Initializam Date
    std::string b_nume;
    std::string c_nume;
    int c_varsta;
    std::string d_nume;
    int d_varsta;
    float d_greutate;
    
    //Citim Date
    std::getline(std::cin, b_nume);
    
    std::getline(std::cin, c_nume);
    std::cin>>c_varsta;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //CONDITIE PENTRU CUVINTE CU SPATIU
    std::getline(std::cin, d_nume);
    std::cin>>d_varsta;
    std::cin>>d_greutate;


    //Constructori Parametrizati
    
    //0 parametri
    Pisica a;
    a.afisare();
    
    //1 parametru
    Pisica b(b_nume);
    b.afisare();
    
    //2 parametrii
    Pisica c(c_nume, c_varsta);
    c.afisare();
    
    //3 parametrii
    Pisica d(d_nume, d_varsta, d_greutate);
    d.afisare();
    
    
    
    return 0;
    
}




// Pentru a citi string-uri formate din mai multe cuvinte (care includ caractere de tip whitespace):
// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <- ignora toate caracterele ramase in fluxul 'cin' pana la intalnirea caracterului '\n'