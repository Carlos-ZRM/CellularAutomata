//
//  main.cpp
//  Main
//
//  Created by Carlos Reyes on 26/12/17.
//  Copyright © 2017 Carlos Reyes. All rights reserved.
//


#include "ECA.hpp"
int rule;
int l;
int times;
int * x, *xi;


int fi(int x , int y, int z)
{
    int r = rule>>(4*x +2*y + z);

    return r&1;

}

string word(int ** matriz, int x, int y,  int block)
{
    string r = "";

    for (int i = x; i < (x + block) ; i++)
    {
        for (int j = y; j < (y + block) ; j++)
        {

            r.push_back((matriz[i][j]+48));
        }
    }
    return r;
}
/**
    Funcion de evolucion para encontrar la diversidad morfologia de matrices block X block

 */
void evolution (int ** matriz, int block)
{
    int   *x, *xi;
    cout << "\n";
    for (int i = 0; i < l; i++)
    {
        cout << matriz[0][i];

    }
    for (int i = 1; i < block; i++)
    {
        x = matriz[i-1];
        xi = matriz[i];
        cout << "\n";
        for (int j = 0; j < l; j++)
        {
            if (j == (l-1))
                xi[j] = fi( x[j-1] , x[j], x[0] );
            else if (j== 0)
                xi[j] = fi( x[l-1] , x[j], x[j+1] );
            else
                xi[j] = fi( x[j-1] , x[j], x[j+1] );
            cout << xi[j];
        }

        matriz[i]= xi;
       // x = xi;
       // xi = aux;
    }
     vector<string> lista;
    string s;

    for (int i = 0; i < (times-block); i++)
    {

        for (int j = 0; j < (l-block); j++)
        {

            //  cout << "\n" << word(matriz , 0, i, block);
            // checkVector(lista,word(matriz , 0, i, block) );
            // bloque que crea las palabras de cada posicion
            s = word ( matriz , 0, j, block );
            if(! (find(lista.begin(), lista.end() , s) != lista.end() ) )
            {
                lista.insert( lista.begin()+lista.size(), s );
            }
        }

        reglaGlobal(matriz[block-1],matriz[0]);
        recorrer(matriz,block);

    }

    //printVector(lista);

    //cout << "\n\n " << lista.size();

}
void reglaGlobal(int * x, int * xi)
{
    cout << "\n";
    for (int j = 0; j < l; j++)
    {
        if (j == (l-1) )
            xi[j] = fi( x[j-1] , x[j], x[0] );
        else if (j== 0)
            xi[j] = fi( x[l-1] , x[j], x[j+1] );
        else
            xi[j] = fi( x[j-1] , x[j], x[j+1] );
        cout << xi[j];
    }

}

void printVector(std::vector<string> lista)
{

    ofstream fs ("File.txt");
    if (fs.fail())
        cout << "\n Error \n\n";


    cout << "\nlista\n\n";
    fs << endl;
    for (int i = 0; i < lista.size(); i++)
    {
        for (int j = 0; j < 9; j++ )
        {
            cout << lista[i][j];
            fs << lista[i][j];
            if (j%3 == 2) {
                cout << "\n";
            }
        }
        fs << endl;
        cout << "\n";

    }
    fs.close();
}
void checkVector( std::vector<string> lista, string s )
{
    if(find(lista.begin(), lista.end(), s) != lista.end())
    {
      lista.insert( lista.begin()+lista.size(), s );
    }

}
void evolution (int * x, int * xi)
{
    int * aux;
    cout << "\n";
    for (int j = 0; j < l; j++)
    {
        cout << x[j];
    }
    for (int i = 0; i < times; i++)
    {
        cout << "\n";
        for (int j = 0; j < l; j++)
        {
            if (j == (l-1))
                xi[j] = fi( x[j-1] , x[j], x[0] );
            else if (j== 0 )
                xi[j] = fi( x[l-1] , x[j], x[j+1] );
            else
                xi[j] = fi( x[j-1] , x[j], x[j+1] );
            cout << xi[j];
        }
        aux = x;
        x = xi;
        xi = aux;
    }
}

void ECA(int ruless, int ls, int timess , string seedd, int block )
{
    rule = ruless;
    l = ls;
    times = timess;
    int **matriz;
    matriz = (int **)std::malloc(block*sizeof(int *));
    if (matriz == NULL)
    {
        printf( "No hay memoria disponible…\n" );
        return;
    }
    for ( int i = 0 ; i < block; i++)
    {
        matriz[i] = (int *)std::malloc( l * sizeof(int));;
        if (matriz[i] == NULL){
            printf( "No hay memoria disponible… \n" );
            return;
        }
        else
        {
            for (int j = 0; j < l ; j++)
            {
                matriz[i][j]=0;
            }
        }
    }

    seed(matriz[0], seedd, seedd.size());
    evolution(matriz, block);



}

void ECA(int rules, int ls, int timess, string seedd )
{
    rule = rules;
    l = ls;
    times = timess;
    x = (int *)std::malloc( l * sizeof(int));
    xi = (int *)std::malloc( l * sizeof(int));


    if( x == NULL || xi == NULL)
    {
        printf( "No hay memoria disponible…\n" );
        return;
    }
    else
    {
        for (int i = 0; i < l ; i++)
        {
            x[i] = 0 ;
        }        //x[l/2] = 1;
    }



    seed(x, seedd , seedd.size());

     evolution(x, xi);
  // int * h = evolutionH( x, xi );

}
void seed(int * x, string s, int t)
{


    for (int i = (l-t)/2 , j = 0; i< (l+t)/2;j++, i++) {
        if(s[i-(l-t)/2]=='1')
            x[i] = 1;

    }
}

void recorrer(int ** matriz, int block)
{
    int * x0 = matriz[0];
    int * aux;
    matriz[0] = matriz[1];
    for (int i = 1; i < (block - 1); i++)
    {
        aux = matriz [i + 1];
        matriz[i] = aux;
    }
    matriz [block - 1] = x0;
}
int main(int argc, const char * argv[])
{

    if(argc<5||argc>6)
    {
      cout << "el uso del programa es ./exe.exe rule anillo num evolucion semilla \n";
      cout << "                       ./exe.exe 90 128 64 1\n";
      return 1;
    }
    else
    {
      try
        {
          if (stoi(argv[1])<0 || stoi(argv[1])>255)
          {
            cout << "La regla es invalida, el intervalo debe ser  (0,256)";
            return 1;
          }

          if (stoi(argv[1])<0 || stoi(argv[1])>255)
          {
            cout << "La regla es invalida, el intervalo debe ser  (0,256)";
            return 1;
          }
          if (stoi(argv[2])<0)
          {
            cout << "La longitud del anillo debe ser positiva";
            return 1;
          }
          if (stoi(argv[3])<0)
          {
            cout << "El numero de evoluciones debe ser positivo";
          return 1;
          }

          if (argc==5)
            ECA (stoi(argv[1]) ,stoi(argv[2]), stoi(argv[3]), argv[4]);
          else if (argc==6)
            ECA (stoi(argv[1]) ,stoi(argv[2]), stoi(argv[3]), argv[4],3);

        }
      catch(const std::invalid_argument& e)
        {
          cout << "Las cadenas ingresados no corresponden a enteros";
          return 1;
        }
      catch(const std::out_of_range& e)
        {
          cout << "Numeros fuera de rango ";
          return 1;
        }
      catch(...)
       {
         cout << "Error desconocido";
         return 1;
       }


    }

    cout << "\n\n";

    return 0;
}
