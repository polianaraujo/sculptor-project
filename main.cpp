#include <iostream>
#include "sculptor.h"

int main(void){
    Sculptor trono(30,30,30);
    trono.setColor(0,0,1.0,1.0); //azul
    trono.putBox(0,9,0,9,0,9);
    trono.cutBox(1,8,1,9,1,9);
    
    //putSphere(int xcenter, int ycenter, int zcenter, int radius);
    trono.setColor(0,1.0,0,1.0); //verde
    trono.putSphere(11,10,0,8);
    //trono.cutSphere(11,-10,0,6);
    
    trono.writeOFF("trono.off");
}