#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int datosO[4], datosD[4], tf, g=9.8;
    cout<<"Ingresar datos ofensivos(altura(Yo), alfao, Vo): "<<endl;
    datosO[0]=0;
    cin>>datosO[1]>>datosO[2]>>datosO[3];
    datosO[2]=datosO[2];
    cout<<"Ingresar la distancia que separa los cañones, seuido de la altura(Yo) defensiva: "<<endl;
    cin>>datosD[0]>>datosD[1];

    tf=-g+sqrt(pow(g,2)-2*g*(-datosO[1]-datosO[3]));

    for(int i =0;i<4;i++){
        cout<<datosO[i]<<endl;
    }
    return 0;
}
