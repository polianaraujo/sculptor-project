#include <iostream>
#include <fstream>
#include <cmath>
//#include <iomanip>
#include "sculptor.h"
#include "voxel.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    r = g = b = a = 0.0;
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
    
    for (int i=0; i<nx; i++)
    {
        v[i] = new Voxel*[ny];
        
        for (int j=0; j<ny; j++)
        {
            v[i][j] = new Voxel[nz];
        }
    }
}

Sculptor::~Sculptor()
{
    for (int i=0; i<nx; i++)
    {
        for (int j=0; j<ny; j++)
        {
            delete [] v[i][j];
        }

        delete [] v[i];
    }
    delete [] v;
}

void Sculptor::setColor(float r, float g, float b, float a)
{
    this->r = r*255;
    this->g = g*255;
    this->b = b*255;
    this->a = a*255;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    /* se x cor cositivo e está dentro da matriz
       no eixo x */
    /* se y cor cositivo e está dentro da matriz
       no eixo y */
    /* se z cor cositivo e está dentro da matriz
       no eixo z */
    /* mostre o voxel[x][y][z], com vermelho r,
       verde g, azul b e transcarência a */
    if ((x>=0 && x<nx) && (y>=0 && y<ny) && (z>=0 && z<nz))
    {
        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    /* remova o voxel[x][y][z], ele não será
       mais mostrado (show=false)*/
    v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i=x0; i<=x1; i++)
    {
        for(int j=y0; j<=y1; j++)
        {
            for (int k=z0; k<=z1; k++)
            {
                putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i=x0; i<=x1; i++)
    {
        for(int j=y0; j<=y1; j++)
        {
            for (int k=z0; k<=z1; k++)
            {
                cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename)
{
    //quantos voxels?
    int qts_voxels=0;
    
    for (int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            for (int k=0; k<nz; k++)
            {
                if (v[i][j][k].show) qts_voxels++;
            }
        }
    }

    //std::cout << "Quantidade de voxels da escultura = " << qts_voxels << std::endl;

    std::ofstream fout;

    fout.open(filename);

    //CRIANDO ARQUIVO OFF

    if(!fout.is_open()){
        std::cout << "Erro ao abrir o arquivo\n";
        exit(1);
    }
    //if(fout.is_open()){
        
        // primeira linha, tipo do arquivo:
        fout << "OFF" << std::endl;
        
        // segunda linha contém:
        fout << qts_voxels*8 << " "; //número de vértices (qts_voxels*8)
        fout << qts_voxels*6 << " "; //número de faces (qts_voxels*6)
        fout << 0 << std::endl;      //número de arestas (não é necessário)

        //fout << std::fixed;
        
        // COORDENADAS DOS VÉRTICES

        for (int i=0; i<nx; i++)
        {
            for (int j=0; j<ny; j++)
            {
                for (int k=0; k<nz; k++)
                {
                    if (v[i][j][k].show = true)
                    {
                        fout << -0.5 + i << " " << 0.5 + j << " " << -0.5 + k << std::endl;
                        fout << -0.5 + i << " " << -0.5 + j << " " << -0.5 + k << std::endl;
                        fout << 0.5 + i << " " << -0.5 + j << " " << -0.5 + k << std::endl;
                        fout << 0.5 + i << " " << 0.5 + j << " " << -0.5 + k << std::endl;
                        fout << -0.5 + i << " " << 0.5 + j << " " << 0.5 + k << std::endl;
                        fout << -0.5 + i << " " << -0.5 + j << " " << 0.5 + k << std::endl;
                        fout << 0.5 + i << " " << -0.5 + j << " " << 0.5 + k << std::endl;
                        fout << 0.5 + i << " " << 0.5 + j << " " << 0.5 + k << std::endl;
                    }
                }
            }
        }
    
    
        //DEFININDO AS FACES
    
        // Quantas faces?
        int qts_faces = 0;
        for (int i=0; i<nx; i++)
        {
            for (int j=0; j<ny; j++)
            {
                for (int k=0; k<nz; k++)
                {
                    if (v[i][j][k].show)
                    {

                        fout << 4 << " " << 0 + qts_faces << " " << 3 + qts_faces << " " << 2 + qts_faces << " " << 1 + qts_faces << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        fout << 4 << " " << 4 + qts_faces << " " << 5 + qts_faces << " " << 6 + qts_faces << " " << 7 + qts_faces << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        fout << 4 << " " << 0 + qts_faces << " " << 1 + qts_faces << " " << 5 + qts_faces << " " << 4 + qts_faces << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        fout << 4 << " " << 0 + qts_faces << " " << 4 + qts_faces << " " << 7 + qts_faces << " " << 3 + qts_faces << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        fout << 4 << " " << 3 + qts_faces << " " << 7 + qts_faces << " " << 6 + qts_faces << " " << 2 + qts_faces << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        fout << 4 << " " << 1 + qts_faces << " " << 2 + qts_faces << " " << 6 + qts_faces << " " << 5 + qts_faces << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                        qts_faces = qts_faces + 8;
                    }
                }
            }
        }

        //std::cout << filename << " EXPORTADO" << std::endl;

        fout.close();

    //}

}