#include <iomanip>// biblioteca necesara pentru std::setprecision
#include<iostream>
#include<math.h>
class Segment;
class Punct;
class Punct {
    friend Segment;
    private:
    float x;
    float y;
    float z;
    public:
//contrusctor
Punct(float x=0,float y=0,float z=0):x(x),y(y),z(z){}
//seters
void set_x(float x){this->x=x;}
void set_y(float y){this->y=y;}
void set_z(float z){this->z=z;}
//getters
float get_x(){return this->x;}
float get_y(){return this->y;}
float get_z(){return this->z;}
};
class Segment{
    private:
Punct p1;
Punct p2;
public:
//constructor
    Segment(float x1=0,float y1=0,float z1=0,float x2=0,float y2=0,float z2=0):p1(x1,y1,z1),p2(x2,y2,z2){};
    //functia de segment
    void segment(){
        float lungime_seg;
        lungime_seg=sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)+(p2.z-p1.z)*(p2.z-p1.z));
        //afisare cu 2 zecimale
        std::cout<<std::fixed;
        std::cout<<std::setprecision(2);
        std::cout<<lungime_seg;
    }
};
int main(){
    float v_x1;
    float v_y1;
    float v_z1;
    float v_x2;
    float v_y2;
    float v_z2;
    //citim datele
    std::cin>>v_x1;
    std::cin>>v_y1;
    std::cin>>v_z1;
    std::cin>>v_x2;
    std::cin>>v_y2;
    std::cin>>v_z2;
    //intializare obiect de clasa respectiva
   Segment s(v_x1,v_y1,v_z1,v_x2,v_y2,v_z2);
   //apelam functia 
   s.segment();
   return 0;
   
}
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    



