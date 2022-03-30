// Aceasta problema nu are baterie de teste, ci ofera doar input-ul in mod 
// automat. Output-ul va fi urmarit in caseta de dialog


#include <iostream>


class Punctaj{
    
    //Date membre
    private:
        int nr_note;
        int *note;
       
    
    //Constructori
    public:   
    
        //Constructor
        Punctaj(int nr_note, int *note){
            this->nr_note = nr_note;
            this->note = new int[nr_note];
            for(int i=0; i<nr_note; i++){
                *(this->note+i) = *(note+i);
            }
        }
        
        //Destructor
        ~Punctaj(){
            delete [] note;
        }
        
        //Constructor de Copiere
        Punctaj(const Punctaj &p){
            this->nr_note = p.nr_note;
            this->note = new int[this->nr_note];
            for(int i=0; i<nr_note; i++){
                *(this->note+i) = *(p.note+i);
            }
        }
    
    //Functii
    public:
    
        //Aifsare
        void afisare(){
            for(int i=0; i<nr_note; i++){
                std::cout << *(note+i) << " ";
            }
        }
        
        //Incrementare
        void schimb(int index){
            
            for(int i=0; i<nr_note; i++){
                
                if(i == index){
                    
                    std::cin >> *(note+i);
                }
            }
        }
   
};

//Functia main
int main(){
    
    //Initializare Date
    int nr_note;
    std::cin >> nr_note;
    
    int *note = new int[nr_note];
    for(int i=0; i<nr_note;i++){
        std::cin >> *(note+i);
    }
    
    
    //Initializare Obiecte
    Punctaj p1(nr_note, note);
    Punctaj p2(p1);
    
    p1.afisare();
    
    std::cout<<std::endl;
    p2.schimb(2);
    
    p2.afisare();
    
    return 0;
}

// Apelul explicit pentru destructorul obiectului p din clasa Punctaj 
// (coincide cu apelul oricarei alte functii membre):
// p.~Punctaj();
