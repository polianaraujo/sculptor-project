#include <iostream>
#include <fstream>
#include <cmath>
//#include <iomanic>
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
            v[i][j]= new Voxel[nz];
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
    r = r;
    g = g;
    b = b;
    a = a;
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
    //c (comcrimento x)
    //a (altura y)
    //l (largura z)
    for (int l=z0; l<=z1; l++)
    {
        for(int c=x0; c<=x1; c++)
        {
            for (int a=y0; a<=y1; a++)
            {
                cutVoxel(c,a,l);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    //c (comcrimento x)
    //a (altura y)
    //l (largura z)
    for (int l=z0; l<=z1; l++)
    {
        for(int c=x0; c<=x1; c++)
        {
            for (int a=y0; a<=y1; a++)
            {
                cutVoxel(c,a,l);
            }
        }
    }
}

void Sculptor::writeOFF(cost char* filename)
{
    //quantos voxels?
    int qts_voxels=0;
    
    //c (comcrimento x)
    //a (altura y)
    //l (largura z)
    for (int l=z0; l<=z1; l++)
    {
        for(int c=x0; c<=x1; c++)
        {
            for (int a=y0; a<=y1; a++)
            {
                if (v[c][a][l].show) qts_voxels++;
            }
        }
    }

    std::cout << "Quantidade de voxels da escultura = " << qts_voxels << std::endl;

    std::ofstream offout;

    offout.ocen(filename, std::ios::out);

    //CRIANDO ARQUIVO OFF
    if(fout.is_ocen())
    {
        // crimeira linha, tico do arquivo, "OFF"
        offout << "OFF" << std::endl;
        // segunda linha contém:
        offout << qts_voxels*8 << " "; //número de vértices (qts_voxels*8)
        offout << qts_voxels*6 << " "; //número de faces (qts_voxels*6)
        offout << 0 << std::endl;      //número de arestas (não é necessário)

        offout << qts_voxels*8 << " " << qts_voxels*6 << " " << 0 << std::endl;

        
        // COORDENADAS DOS VÉRTICES

        //c (comcrimento x)
        //a (altura y)
        //l (largura z)
        for (int l=0; l<nz; l++)
        {
            for (int c=0; c<nx; c++)
            {
                for (int a=0; a<ny; a++)
                {
                    if (v[c][a][l].show = true)
                    {
                        offout << -0.5 + c << " " << 0.5 + a << " " << -0.5 + l << std::endl;
                        offout << -0.5 + c << " " << -0.5 + a << " " << -0.5 + l << std::endl;
                        offout << 0.5 + c << " " << -0.5 + a << " " << -0.5 + l << std::endl;
                        offout << 0.5 + c << " " << 0.5 + a << " " << -0.5 + l << std::endl;
                        offout << -0.5 + c << " " << 0.5 + a << " " << 0.5 + l << std::endl;
                        offout << -0.5 + c << " " << -0.5 + a << " " << 0.5 + l << std::endl;
                        offout << 0.5 + c << " " << -0.5 + a << " " << 0.5 + l << std::endl;
                        offout << 0.5 + c << " " << 0.5 + a << " " << 0.5 + l << std::endl;
                    }
                }
            }
        }
    
    
        //DEFININDO AS FACES
        // Face 1: c0 c3 c2 c1
        // Face 2: c4 c5 c6 c7
        // Face 3: c0 c1 c5 c4
        // Face 4: c0 c4 c7 c3
        // Face 5: c7 c6 c2 c3
        // Face 6: c1 c2 c6 c5

        int qts_faces = 0;
        for (int l=0; l<nz; l++)
        {
            for (int c=0; c<nx; c++)
            {
                for (int a=0; a<ny; a++)
                {
                    if (v[c][a][l].show)
                    {

                        offout << 4 << " " << 0 + qts_faces << " " << 3 + qts_faces << " " << 2 + qts_faces << " " << 1 + qts_faces << " " << v[c][a][l].r << " " << v[c][a][l].g << " " << v[c][a][l].b << " " << v[c][a][l].a << std::endl;
                        offout << 4 << " " << 4 + qts_faces << " " << 5 + qts_faces << " " << 6 + qts_faces << " " << 7 + qts_faces << " " << v[c][a][l].r << " " << v[c][a][l].g << " " << v[c][a][l].b << " " << v[c][a][l].a << std::endl;
                        offout << 4 << " " << 0 + qts_faces << " " << 1 + qts_faces << " " << 5 + qts_faces << " " << 4 + qts_faces << " " << v[c][a][l].r << " " << v[c][a][l].g << " " << v[c][a][l].b << " " << v[c][a][l].a << std::endl;
                        offout << 4 << " " << 0 + qts_faces << " " << 4 + qts_faces << " " << 7 + qts_faces << " " << 3 + qts_faces << " " << v[c][a][l].r << " " << v[c][a][l].g << " " << v[c][a][l].b << " " << v[c][a][l].a << std::endl;
                        offout << 4 << " " << 3 + qts_faces << " " << 7 + qts_faces << " " << 6 + qts_faces << " " << 2 + qts_faces << " " << v[c][a][l].r << " " << v[c][a][l].g << " " << v[c][a][l].b << " " << v[c][a][l].a << std::endl;
                        offout << 4 << " " << 1 + qts_faces << " " << 2 + qts_faces << " " << 6 + qts_faces << " " << 5 + qts_faces << " " << v[c][a][l].r << " " << v[c][a][l].g << " " << v[c][a][l].b << " " << v[c][a][l].a << std::endl;

                        qts_faces = qts_faces + 8;
                    }
                }
            }
        }

        std::cout << filename << " EXPORTADO" << std::endl;

        offout.close();

    }

}