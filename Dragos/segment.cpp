#include <iomanip> // biblioteca necesara pentru std::setprecision
#include <iostream>
#include <cmath>
class Segment{
private:
    float x;
    float y;
    float z;
public:
    /*    Segment(float x=0, float y=0, float z=0)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }*/
    void set_x(float x){
        this->x=x;
    }
    float get_x(){
        return this->x;
    }
    void set_y(float y){
        this->y=y;
    }
    float get_y(){
        return this->y;
    }
    void set_z(float z){
        this->z=z;
    }
    float get_z(){
        return this->z;
    }
};
int main(){
    float  x,y,z;
    int x1,y1,z1, x2,y2,z2, a,b,c;
    Segment s1;
    std::cin>>x1>>y1>>z1;
    s1.set_x(x1);
    s1.set_y(y1);
    s1.set_z(z1);
    std::cin>>x2>>y2>>z2;
    Segment s2;
    s1.set_x(x2);
    s1.set_y(y2);
    s1.set_z(z2);
    a=s2.get_x()-s1.get_x();
    b=s2.get_y()-s1.get_y();
    c=s2.get_z()-s2.get_z();
    std::cout<<x*x + y*y + z*z;
    return 0;
}
// TODO: rezolvarea exercitiului

// Pentru afisarea cu 2 zecimale a unei valori, secventa de afisare se va prefixa cu:
// std::cout << std::fixed << std::setprecision(2);
