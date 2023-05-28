#include <iostream>
#include "sculptor.h"

int main(void){
    Sculptor trono(30,30,30);
    trono.setColor(0,0,1.0,1.0); //azul
    trono.putBox(0,29,0,29,0,29);
    trono.cutBox(1,28,1,29,1,29);
    
    //trono.setColor(0,1.0,0,1.0); //verde
    //trono.putSphere(15,15,15,15);
    //trono.cutSphere(15,15,15,14);

    //void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    trono.setColor(1.0,0,0,1.0); //vermelho
    trono.putEllipsoid(15,15,15, 15, 9, 5);
    trono.cutEllipsoid(15,15,15, 14, 8, 4);
    
    trono.writeOFF("trono.off");
}