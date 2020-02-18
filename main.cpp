// Author         : Ivan de Jesus May-Cen
// Email          : imaycen@hotmail.com, imay@itsprogreso.edu.mx
// Language       : C++
// Environment    : Linux
// Compiler       : g++
// Revisions      :
//        Initial : 16.02.2017
//           Last : 

// Este programa compila en la consola de linux mediante la orde
// g++ main.cpp -o complejo
// "complejo" es el nombre del ejecutable

//Inclusion de librerias
#include <iostream>
#include <cmath>

//Declaracion de funciones
double magnitud(double re, double im);
double argumento(double re, double im);
double conv_rad_deg( double rad );
void suma_complejos(double* z, double* w, double* sum);
void producto_complejos(double* z, double* w, double* prod);
void cociente_complejos(double* z, double* w, double* div);
void conjugado_complejos(double* z, double* conj);

using namespace std;

//Funcion principal
int main( )
{
double r, theta, angulo;
double z[2], w[2], aux[2]; 

z[0] = 1;
z[1] = 1;
w[0] = 1;
w[1] = 2;

//Determina cociente z/w
cociente_complejos(z, w, aux);

//Imprime resultados
cout << "Parte real       :" << aux[0] << endl;
cout << "Parte imaginaria :" << aux[1] << endl;

//Determina raices por T. de De Moivre
// 5 raices para z = 1+i
raices_de_moivre(z, aux, 5)

// 6 raices para w = 1+2i
raices_de_moivre(w, aux, 6)

return 0;
}
//********************************************************
// Funcion para efectuar magnitud de un numero complejo
//
// Input  : partes real e imaginaria (re, im)
// Output : magnitud
//********************************************************
double magnitud(double re, double im)
{
double r, aux;

aux = re*re+im*im;
r = sqrt(aux);

return r;
}
//********************************************************
// Funcion para determinar argumento principal 
// de un numero complejo
//
// Input  : partes real e imaginaria (re, im)
// Output : argumento principal
//********************************************************
double argumento(double re, double im)
{
double arg;

arg = atan2(im, re);

return arg;
}
//********************************************************
// Funcion para convertir radianes a degradientes
// de un numero complejo
//
// Input  : angulo en radianes
// Output : angulo en grados
//********************************************************
double conv_rad_deg( double rad )
{
double ang, fac;

fac = 180.0/M_PI; 
ang = fac * rad;

return ang;
}
//********************************************************
// Funcion para sumar numeros complejos
//
// Input  : z = z[0], z[1]; w = w[0], w[1]
// Output : z+w
//********************************************************
void suma_complejos(double* z, double* w, double* sum)
{

sum[0] = z[0]+w[0];
sum[1] = z[1]+w[1];

}
//********************************************************
// Funcion para multiplicar numeros complejos
//
// Input  : z = z[0], z[1]; w = w[0], w[1]
// Output : zw
//********************************************************
void producto_complejos(double* z, double* w, double* prod)
{
//Parte real
prod[0] = z[0]*w[0] - z[1]*w[1];
//Parte imaginaria
prod[1] = z[0]*w[1] + z[1]*w[0];

}
//********************************************************
// Funcion para dividir numeros complejos
//
// Input  : z = z[0], z[1]; w = w[0], w[1]
// Output : z/w
//********************************************************
void cociente_complejos(double* z, double* w, double* div)
{
double r;

//Calcula magnitud de w
r = magnitud(w[0],w[1]);

//Se efectua el conjugado de w
conjugado_complejos(w, w);

producto_complejos(z, w, div);
//Parte real
div[0] /= (r*r);
//Parte imaginaria
div[1] /= (r*r);

}
//********************************************************
// Funcion para efectuar el conjugado de un numero complejo
//
// Input  : z = z[0], z[1]
// Output : conjugado de z
//********************************************************
void conjugado_complejos(double* z, double* conj)
{

conj[0] = z[0];
conj[1] = -z[1];
}
//********************************************************
// Funcion para efectuar el calculo de n raices de z = re + i * im 
//
// Input  : z = z[0], z[1]
// Output : impresion de raices zk
//********************************************************
void raices_de_moivre(double* z, double* zk, unsigned n)
{
double r, theta;
unsigned k;
r = magnitud(z[0], z[1]);
theta = argumento(z[0], z[1])
//De Moivre
for(k=0; k<n; ++k)
   {
    zk[0] = pow(r, (1/n)) * cos( (theta - 2*M_PI*k)/n );
    zk[1] = pow(r, (1/n)) * sin( (theta - 2*M_PI*k)/n );
    //Imprime raiz calculada
    cout << "k = " << k << " : " << "Re = " << zk[0] << ", " << "Im = " <<zk[1] << endl;
   }
}

