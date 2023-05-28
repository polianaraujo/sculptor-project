#include <iostream>
#include "sculptor.h"

int main(void){
    Sculptor trono(100,100,100);

    // 8 VÉRTICES - COORDENADAS

    //eixo x
    trono.setColor(0.0,1.0,0.0,1.0); //verde
    trono.putBox(0,99, 0,5, 0,5); 
    trono.cutBox(1,99, 1,4, 1,4);

    //eixo y
    trono.setColor(0.0,0.0,1.0,1.0); //azul
    trono.putBox(0,5, 0,99, 0,5);
    //trono.cutBox(1,4, 1,99, 1,4);

    //eixo z
    trono.setColor(1.0,0.0,1.0,1.0); //rosa
    trono.putBox(0,5, 0,5, 0,99);
    //trono.cutBox(1,4, 1,4, 1,99);

    
    //PORCO
    
    //olhos
    trono.setColor(1.0,0.0,0.0,1.0); //vermelho
    
    trono.putSphere(80,40,50,2); //olho esquerdo
    trono.putSphere(80,60,50,2); //olho direito


    //cabeça
    trono.setColor(0.8,0.3,0.3,1.0); //rosa claro [255][203][219]

    trono.putEllipsoid(75,50,55, 11, 18, 11);
    trono.cutEllipsoid(75,50,55, 10, 17, 10);
    

    //fucinho
    trono.putEllipsoid(89,50,55, 10, 10, 5);
    //trono.cutBox(94,99, 40,60, 45,65);


    //corpo do porco
    trono.setColor(0.8,0.3,0.3,1.0); //rosa claro [255][203][219]
    trono.putEllipsoid(50,50,50, 28, 25, 20);


    trono.writeOFF("pig.off");
}