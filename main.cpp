#include <iostream>
#include "sculptor.h"

int main(void){
    Sculptor trono(100,100,100);

    // 8 VÉRTICES - COORDENADAS

    //origem
    //trono.setColor(1.0,0.0,0.0,1.0); //vermelho
    //trono.putBox(0,5, 0,5, 0,5);
    //trono.cutBox(1,4, 1,4, 1,4);

    //eixo x
    trono.setColor(0.0,1.0,0.0,1.0); //verde
    trono.putBox(0,100, 0,5, 0,5); 
    trono.cutBox(1,99, 1,4, 1,4);

    //eixo y
    trono.setColor(0.0,0.0,1.0,1.0); //azul
    trono.putBox(0,5, 0,100, 0,5);
    //trono.cutBox(1,4, 1,99, 1,4);

    //eixo z
    trono.setColor(1.0,0.0,1.0,1.0); //rosa
    trono.putBox(0,5, 0,5, 0,100);
    //trono.cutBox(1,4, 1,4, 1,99);

    //outros
    trono.setColor(0.0,1.0,1.0,1.0); //azul claro
    trono.putBox(95,100, 95,100, 0,5);
    //trono.cutBox(1,4, 1,4, 1,4);
    trono.putBox(0,5, 95,100, 95,100);
    //trono.cutBox(1,4, 1,4, 1,4);
    trono.putBox(95,100, 0,5, 95,100);
    //trono.cutBox(1,4, 1,4, 1,4);
    trono.putBox(95,100, 95,100, 95,100);
    //trono.cutBox(1,4, 1,4, 1,4);
    
    trono.putBox(50,51, 50,51, 0,0);

    //PORCO
    
    //olhos
    trono.setColor(1.0,0.3,0.3,1.0); //rosa claro [255][203][219]
    
    trono.putSphere(80,40,65,5); //olho esquerdo
    trono.putSphere(80,60,65,4); //olho direito
    trono.cutSphere(40,40,40,4);


    //cabeça
    trono.setColor(0.8,0.3,0.3,1.0); //rosa claro [255][203][219]

    trono.putEllipsoid(75,50,50, 15, 18, 15);
    trono.cutEllipsoid(75,50,50, 14, 17, 14);
    

    //fucinho
    //trono.putSphere(89,50,55,5);
    trono.putEllipsoid(89,50,55, 10, 10, 5);
    trono.cutBox(94,100, 40,60, 45,65);


    //corpo do porco
    trono.setColor(0.8,0.3,0.3,1.0); //rosa claro [255][203][219]
    trono.putEllipsoid(50,50,50, 28, 25, 20);
    //trono.cutEllipsoid(50,50,50, 27, 24, 19);
    trono.cutBox(0,80, 0,28, 30,70);


    trono.writeOFF("pig.off");
}