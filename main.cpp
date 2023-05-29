#include <iostream>
#include "sculptor.h"

int main(void){
    Sculptor trono(100,100,100);

    // 8 VÉRTICES - COORDENADAS

    //eixo x
    trono.setColor(0.0,1.0,0.0,1.0); //verde
    trono.putBox(0,99, 0,5, 0,5); 

    //eixo y
    trono.setColor(0.0,0.0,1.0,1.0); //azul
    trono.putBox(0,5, 0,99, 0,5);

    //eixo z
    trono.setColor(1.0,0.0,1.0,1.0); //rosa
    trono.putBox(0,5, 0,5, 0,99);

    
    //PORCO
    
    //olhos
    trono.setColor(0.0,0.0,0.0,1.0); //preto
    
    trono.putSphere(87,43,60,2); //olho esquerdo
    trono.putSphere(87,57,60,2); //olho direito

    trono.setColor(1.0,0.86,1.0,1.0); //rosa claro [255][203][219]

    //orelhas
    trono.putSphere(81,43,64,5); //orelho esquerda
    trono.cutSphere(83,42,64,3);

    trono.putSphere(81,58,64,5); //orelha direita
    trono.cutSphere(83,60,64,5);


    //cabeça
    trono.setColor(0.8,0.3,0.3,1.0); //rosa claro [255][203][219]

    trono.putEllipsoid(75,50,55, 14, 18, 14);
    trono.cutEllipsoid(75,50,55, 13, 17, 13);
    

    //fucinho
    trono.putEllipsoid(85,50,55, 10, 7, 5);
    trono.cutBox(92,99, 40,60, 45,65);
    trono.cutBox(90,91, 47,47, 55,55); // narina esquerda
    trono.cutBox(90,91, 53,53, 55,55); // narina esquerda


    //corpo do porco
    trono.putEllipsoid(50,50,50, 28, 25, 20);
    trono.putEllipsoid(50,50,50, 27, 24, 19);

    //rabo
    trono.putBox(10,23, 50,51, 50,51);

    //pernas
    trono.putBox(60,65, 35,40, 10,45); // frente esquerda
    trono.putBox(60,65, 60,65, 10,45); // frente direita
    trono.putBox(30,35, 35,40, 10,50); // trás esquerda
    trono.putBox(30,35, 60,65, 10,50); // trás direita

    trono.setColor(0.0,0.0,0.0,1.0); //preto
    trono.putBox(60,65, 35,40, 5,10);  // frente esquerda
    trono.putBox(60,65, 60,65, 5,10); // frente direita
    trono.putBox(30,35, 35,40, 5,10); // trás esquerda
    trono.putBox(30,35, 60,65, 5,10); // trás direita

    trono.writeOFF("pig.off");
}