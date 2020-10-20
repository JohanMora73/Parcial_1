#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;


int main()
{
    float xo0=0, yo0, Ho, d, Hd, xd0, yd0, pi=3.1415, ao, ad, vox, voy, x, y, g=9.8, vo, vdx, vdy, xo, yo;
    bool resp=false, riezgo;
    int cont=0, caso;
    //Condiciones iniciales ofensivo

    while(true){

    cout<<"ingrese la altura del cañon ofensivo: "<<endl;cin>>Ho;
    cout<<"ingrese la distancia que separa los cañones: "<<endl;cin>>d;
    cout<<"ingrese la altura del cañon defensivo: "<<endl;cin>>Hd;

    yo0=Ho;

    xd0=d;
    yd0=Hd;
    cout<<"digite una de las 4 opciones disponibles: "<<endl;cin>>caso;
    cont=0;
    switch(caso){


    //Genera tres disparos que comprometen la integridad del cañon defensivo
    case 1:
    while(cont<3){
        ao = rand () % (90-0+1) + 0;   // Este está entre M y N
        ao=ao*pi/180;
        for(int vo = 0;vo<100;vo+=2){
            vox=vo*cos(ao);
            voy=vo*sin(ao);
            for(int t =0;t<20;t+=1){
                x=xo0+vox*t;
                y=yo0+voy*t-0.5*g*t*t;
                if(sqrt(pow((x-d),2)+pow((y-Hd),2))<=0.05*d){
                    //cout<<x<<" "<<y<<" vox "<<vox<< " voy"<<voy<<" vo"<<vo<<endl;
                    cout<<"diatancia entre puntos"<<sqrt(pow((x-d),2)+pow((y-Hd),2))<<endl;
                    cout<<"angulo de riezgo "<<ao*180/pi<<" y velocidad: "<<vo<<"Tiempo de vuelo: "<<t<<endl;
                    cont++;
                    resp=true;
                    break;
                }
            }
            if(resp==true) {resp=false; break;}
        }

    }
    break;

    //Genera tres disparos que comprometen la integridad del cañon ofensivo
    case 2:
        while(cont<3){
            ad = rand () % (90-0+1) + 0;   // Este está entre M y N
            ad=ad*pi/180;
            for(int vd = 0;vd<100;vd+=2){
                vdx=-vd*cos(ad);
                vdy=vd*sin(ad);
                for(int t =0;t<20;t+=1){
                    x=xd0+vox*t;
                    y=yd0+voy*t-0.5*g*t*t;
                    if(sqrt(pow((x-0),2)+pow((y-Ho),2))<=0.025*d){
                        //cout<<x<<" "<<y<<" vox "<<vox<< " voy"<<voy<<" vo"<<vo<<endl;
                        cout<<"diatancia entre puntos"<<sqrt(pow((x-0),2)+pow((y-Ho),2))<<endl;
                        cout<<"angulo de riezgo "<<ad*180/pi<<" y velocidad: "<<vd<<"Tiempo de vuelo: "<<t<<endl;
                        cont++;
                        resp=true;
                        break;
                    }
                }
                if(resp==true) {resp=false; break;}
            }

        }
    break;

    //Dado un disparo ofensivo genera tres posibles disparos defensivos
    case 3:
        cout<<"ingrese los datos del disparo del caño ofensivo angulo y velocidad respectivamente: "<<endl;
        cin>>ao>>vo;
        ao=ao*pi/180;
        vox=vo*cos(ao);
        voy=vo*sin(ao);
        for(int t =0;t<20;t+=1){
            xo=xo0+vox*t;
            yo=yo0+voy*t-0.5*g*t*t;
            if(sqrt(pow((xo-d),2)+pow((yo-Hd),2))<=0.05*d){

                riezgo=true;
                break;
            }
            else{

                riezgo=false;
            }
        }
        if(riezgo==true){
            cout<<"El disparo representa un riezg0"<<endl;
        while(cont<3){
            ad = rand () % (90-0+1) + 0;
            ad=ad*pi/180;
            for(int vd = 0;vd<100;vd+=2){
                vdx=vd*cos(ad);
                vdy=vd*sin(ad);

                for(int t =0;t<20;t+=1){
                    x=xd0-vdx*(t+2.5);
                    y=yd0+vdy*(t+2.5)-0.5*g*(t+2.5)*(t+2.5);

                    xo=xo0+vox*t;
                    yo=yo0+voy*t-0.5*g*t*t;


                    if(sqrt(pow((x-xo),2)+pow((y-yo),2))<=0.025*d && sqrt(pow((xo-d),2)+pow((yo-Hd),2))>0.05*d){
                        cout<<"un disparo defensivo ceretero es: angulo"<<ad*180/pi<<", velovidad: "<<vd<<" tiempo de vuelo: "<<t<<endl;
                        cont++;
                        resp=true;
                        break;
                    }
                }
                if(resp==true) {resp=false; break;}
            }

        }
        }
        else{cout<<"el disparo no repesenta riezgo alguno"<<endl;}

    break;
    }

    }
    return 0;
}
