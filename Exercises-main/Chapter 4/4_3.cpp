#include <iostream>
#include <string>
#include <limits>
// TODO: adaugati clasele aici


//Clasa de Baza
class A{
    
    //Destructor A (simplu) - VIRTUAL PENTRU UNICITATEA FIECARUI DESTRUCTOR
    public:
        virtual ~A(){std::cout<<"Dtor A"<<std::endl;}
    
};

//Clasa B derivata din A
class B:public A{
    
    //Destructor B (care ia si ce are A in el)
    public:
        ~B(){std::cout<<"Dtor B"<<std::endl;}

};



//Clasa C derivata din A
class C:public A{
    
    //Destructor C (care ia si ce are A in el)
    public:
        ~C(){std::cout<<"Dtor C"<<std::endl;}

}; 


//Clasa D derivata din C
class D:public C{
    
    //Destructor D (care ia si ce are C in el)
    public:
        ~D(){std::cout<<"Dtor D"<<std::endl;}

}; 


//Clasa E derivata din D
class E:public D{
    
    //Destructor E (care ia si ce are D in el)
    public:
        ~E(){std::cout<<"Dtor E"<<std::endl;}

}; 



int main(){
    A *p_a[6] = {new A(), new D(), new A(), new C(), new E(), new B() /* TODO: completati cu restul initializarilor */};
    for (int i=0; i<6; ++i){
        delete p_a[i];
        std::cout << std::endl;
    }
    return 0;
}