#include <fstream> 
#include "voxel.h"

//#ifndef VOXEL.H
#ifndef SCULPTOR.H
//#define VOXEL.H
#define SCULPTOR.H

class Sculptor {
private:
  Voxel ***v; // matriz 3D
  int nx,ny,nz; // dimensões
  float r,g,b,a; // cor do desenho
  std::ofstream fout;

public:
  Sculptor(int _nx, int _ny, int _nz);
  // Construtor da classe
  
  ~Sculptor();
  // Destrutor da classe
  
  void setColor(float r, float g, float b, float a);
  // Define a cor atual do desenho
  
  void putVoxel(int x, int y, int z);
  /* Ativa o voxel na posição (x,y,z) (fazendo show=true)
  e atribui ao mesmo a cor atual de desenho*/
  
  void cutVoxel(int x, int y, int z);
  // Desativa o voxel na posição (x,y,z) (fazendo show=false)
  
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /* Ativa todos os voxels no intervalo de
  x pertencente [x0,x1]
  y pertencente [y0,y1]
  z pertencente [z0,z1]
  e atribui aos mesmos a cor atual do desenho */
  
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /* Desativa todos os voxels no intervalo de
  x pertencente [x0,x1]
  y pertencente [y0,y1]
  z pertencente [z0,z1]
  */
  
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /* Ativa todos os voxel que satisfazem à equação da esfera
  e atribui aos mesmos a cor atual de desenho (r,g,b,a) */
  
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /* Desativa todos os voxels que satisfazem à equação da esfera */
  
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /* Ativa todos os voxels que satisfazem à equação do elipsóide
  e atribui aos mesmos a cor atual de desenho */
  
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /* Desativa todos os voxels que satisfazem à equação do elipsóide */
  
  void writeOFF(const char* filename);
  /* Grava a escultura no formato OFF no arquivo 'filename' */
};

#endif