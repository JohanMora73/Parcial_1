#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;


int main()
{
    float xo0=0, yo0, Ho, d, Hd, xd0, yd0, pi=3.1415, ao, ad, vox, voy, x, y, g=9.8;
    bool resp=false;
    int cont=0;
    //Condiciones iniciales ofensivo

    cout<<"ingrese la altura del cañon ofensivo: "<<endl;cin>>Ho;
    cout<<"ingrese la distancia que separa los cañones: "<<endl;cin>>d;
    cout<<"ingrese la altura del cañon defensivo: "<<endl;cin>>Hd;

    yo0=Ho;

    while(cont<3){
        ao = rand () % (800-30+1) + 30;   // Este está entre M y N
        ao=ao*pi/180;
        for(int vo = 0;vo<100;vo+=2){
            vox=vo*cos(ao);
            voy=vo*sin(ao);
            for(int t =0;t<20;t+=1){
                x=xo0+vox*t;
                y=yo0+voy*t-0.5*g*t*t;
                if(sqrt(pow((x-d),2)+pow((y-Hd),2))<=0.05*d){
                    cout<<x<<" "<<y<<" vox "<<vox<< " voy"<<voy<<" vo"<<vo<<endl;
                    cout<<"diatancia entre puntos"<<sqrt(pow((x-d),2)+pow((y-Hd),2))<<endl;
                    cout<<"angulo de riezgo "<<ao*180/pi<<" y velocidad: "<<vo<<endl;
                    cont++;
                    resp=true;
                    break;
                }
            }
            if(resp==true) {resp=false; break;}
        }

    }


    return 0;
}
