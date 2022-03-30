//Am folosit alocare dinamica

#include <iostream>
#include <limits>
#include <string>

//Clasa
class Pantof{
    
    //Date membre
    private:
        std::string stil;
        int marime;
        int numar_maxim;        //numar maxim obiecte
        
    public:
        // static int numar_maxim;        //numar maxim obiecte
        static int contor;
    
    //Constructor
    public:
        Pantof(std::string stil=" ", int marime=0, int numar_maxim=0): stil(stil), marime(marime), numar_maxim(numar_maxim){
        // Pantof(std::string stil=" ", int marime=0): stil(stil), marime(marime){
            
            //Creste mereu cand este creat un obiect
            contor++;
        }
    
    //Functii
    public:
        void afisare(){
            std::cout<<stil<<" "<< marime<<"\n";
            
        }

};

//Definim contor in fisier
int Pantof::contor = 0;


//Functia main
int main(){
    
    //Initializare Date
    int m;          //Numar maxim pantofi
    int n;          //Nr. Obiecte
    
    std::string p_stil;
    int p_marime;
    
    //Citim Date
    std::cin>>m;
    // std::cin>>Pantof::numar_maxim;
    std::cin>>n;
    
    //Alocare Dinamica Vector
    Pantof **pantof_array = nullptr;
    pantof_array = new Pantof*[n];
    
    //Facem Obiectele
    for (int i=0; i<n; i++){
        
        std::cin>>p_stil;
        std::cin>>p_marime;

        *(pantof_array + i) = new Pantof(p_stil, p_marime, m);
        // *(pantof_array + i) = new Pantof(p_stil, p_marime);
        
    }
    
    //Afisam
    for (int i=0; i<n; i++){
        if(i<m){
            (*(pantof_array + i))->afisare();
        }
        else
            std::cout<<"S-a atins pragul maxim din editia limitata!"<<"\n";
    }
    
    //Destructor Obiecte
    for(int i=0; i<n; i++){
        delete *(pantof_array + i);
    }
    
    delete pantof_array;
    
    return 0;
}

