#include <iostream>
#include <string>
#include <limits>


//Clasa de Baza
class Echipament_electronic{
    
    //Date membre
    protected:
        float tensiune;
        float intensitate;
    
    //Constructor
    public:
        
        //Constructor Gol
        Echipament_electronic(){}
        
        //Constructor cu Lista de Initializare
        Echipament_electronic(float tensiune, float intensitate): tensiune(tensiune), intensitate(intensitate){}
    
    

};

//Daca este PROTECTED in cea de BAZA este PRIVATE in derivata 

//Clasa Derivata
class Telefon:private Echipament_electronic{
    
    //Date membre
    protected:
        std::string nr_tel;
        
    //Constructor
    public:
        
        //Constructor Gol
        Telefon(){}
        
        //Constructor cu Lista de Initializare
        Telefon(float tensiune, float intensitate, std::string nr_tel):Echipament_electronic(tensiune, intensitate), nr_tel(nr_tel){}
    
    //Functii
    public:
    
        //Functie cu parametru din main
        void suna(std::string nr_apelat){
            
            std::cout<<"Calling: "<<nr_apelat<<std::endl;

        }
    
    //Getteri
    float get_tensiune(){return this->tensiune;}
    float get_intensitate(){return this->intensitate;}
    
};


//Clasa Derivata din Prima Derivata
class Telefon_mobil:protected Telefon{
    
    //Date membre
    private:
        int baterie;
    
    //Constructor
    public:
        
        //Constructor Gol
        Telefon_mobil(){}
        
        //Constructor cu Lista de Initializare
        Telefon_mobil(float tensiune, float intensitate, std::string nr_tel, int baterie):Telefon(tensiune, intensitate, nr_tel), baterie(baterie){}
    
    
    //Functii
    public:
    
        //Functie cu parametru din main
        void suna(std::string nr_apelat, int minute){
            
            Telefon::suna(nr_apelat);
            std::cout<<"Outgoing number: "<<nr_tel<<std::endl;
            
            
            //Baterie ramasa
            int baterie_ramasa = baterie-((Telefon::get_tensiune()*Telefon::get_intensitate())/100)*minute;
            
            if(baterie_ramasa>0){
                std::cout<<baterie_ramasa<<std::endl;
            }
            else{
                std::cout<<"0"<<std::endl;
            }
            
                
        }
        
};


//Functia main
int main(){
    
    //Initializam Date
    float tensiune;
    float intensitate;
    std::string nr_tel;
    int baterie;
    std::string nr_apelat;
    int minute;
    
    //Citim Date
    std::cin>>tensiune;
    std::cin>>intensitate;
    std::cin>>nr_tel;
    std::cin>>baterie;
    std::cin>>nr_apelat;
    std::cin>>minute;
    
    //Initializam Obiecte
    Telefon_mobil tm(tensiune, intensitate, nr_tel, baterie);
    
    //Functii
    tm.suna(nr_apelat, minute);
    
    return 0;
    
}







