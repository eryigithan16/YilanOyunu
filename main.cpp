#include <QCoreApplication>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;
using namespace std;

int N=40,M=30;
int boyut=16;
int w = boyut*N;
int h = boyut*M;

int uzunluk=4;
int yon=0;
struct Snake
{ int x,y;}  kobra[100];

struct Yem
{ int x,y;} yem;

float timer=0, delay=0.1;

RenderWindow window(VideoMode(w,h),"Yilan Oyunu");

void kuyruk()
 {
    for (int i=uzunluk;i>0;--i)
     {kobra[i].x=kobra[i-1].x;
     kobra[i].y=kobra[i-1].y;}

        if (yon==0) kobra[0].y+=1;
        else if (yon==1) kobra[0].x-=1;
        else if (yon==2) kobra[0].x+=1;
        else if (yon==3) kobra[0].y-=1;
        if((kobra[0].x==yem.x) && (kobra[0].y==yem.y)){
            uzunluk++;          
            if(delay>0.050){
            delay=delay-0.003f;
            }
            yem.x=rand()%N;
            yem.y=rand()%M;
        }

        if(kobra[0].x>N){
            kobra[0].x=0;
        }
        if(kobra[0].x<0){
            kobra[0].x=N;
        }
        if(kobra[0].y>M){
            kobra[0].y=0;
        }
        if(kobra[0].y<0){
            kobra[0].y=M;
        }

        for (int i=1;i<uzunluk;i++) {
            if(kobra[0].x==kobra[i].x && kobra[0].y==kobra[i].y){
                 system("cls");
              cout<< "Yandiniz... Puaniniz: " << uzunluk;
              delay=0.1f;
              uzunluk=4;
              cout<<"\nOyun Bastan basliyor..";

            }
        }

}


int main()

{
    kobra[0].x=0;
    kobra[0].y=0;


    Texture t1,t2;
    t1.loadFromFile("C:/Users/sony/Desktop/yilanimages/white.png");
    t2.loadFromFile("C:/Users/sony/Desktop/yilanimages/apple.png");
    Sprite yilan(t1);
    Sprite meyve(t2);
    Clock clock;
    yem.x=10;
    yem.y=10;




    while (window.isOpen()) {
        float time=clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        Event olayNesnesi;
        while (window.pollEvent(olayNesnesi)) {
            if(olayNesnesi.type==Event::Closed){
                window.close();}}
        if(Keyboard::isKeyPressed(Keyboard::Left)&& yon!=2) {

            yon=1;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right) && yon!=1) {

            yon=2;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Up) && yon!=0) {

            yon=3;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Down)&& yon!=3) {

            yon=0;
        }

        if(timer>delay){
            timer=0;
            kuyruk();
        }


    window.clear(Color(0,0,0));
    for (int i =0 ;i<uzunluk;i++) {
        yilan.setPosition(kobra[i].x*boyut,kobra[i].y*boyut);
        window.draw(yilan);
    }

    meyve.setPosition(yem.x*boyut, yem.y*boyut);
    window.draw(meyve);
    window.display();


    }

}
