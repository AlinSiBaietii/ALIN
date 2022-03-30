#include <iostream>
#include <string>

//Clasa
class Cutie{
    
    //Date membre
    private:
        float lungime;
        float latime;
        float inaltime;
    
    //Setters si Getters
    public:
        void set_lungime(float lungime){
            this->lungime = lungime;
        }
        float get_lungime(){
            return this->lungime;
        }
        void set_latime(float latime){
            this->latime = latime;
        }
        float get_latime(){
            return this->latime;
        }
        void set_inaltime(float inaltime){
            this->inaltime = inaltime;
        }
        float get_inaltime(){
            return this->inaltime;
        }
        
    
};

//Functia main
int main(){
    
    //Initializam Obiect
    Cutie c;
    
    //Initializam Date
    float c_lungime;
    float c_latime;
    float c_inaltime;
    
    //Citim Date
    std::cin>>c_lungime;
    std::cin>>c_latime;
    std::cin>>c_inaltime;
    
    //Stabilim valori cu Setter
    c.set_lungime(c_lungime);
    c.set_latime(c_latime);
    c.set_inaltime(c_inaltime);
    
    //Afisam valori cu Getter
    std::cout<<c.get_lungime()<<'\n';
    std::cout<<c.get_latime()<<'\n';
    std::cout<<c.get_inaltime()<<'\n';
    
    
    return 0;
    
    
    
    
}