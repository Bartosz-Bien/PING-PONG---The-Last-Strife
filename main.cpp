/* Win XP lub wincyj

ZASADY:
- gramy do 10 pkt
- pileczka odbija sie prostopadle jak na srodek
- pod katem 45 stopni jak od krawedzi
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <windows.h>

using namespace std;

int wysokosc () {
    al_init();
    ALLEGRO_DISPLAY_MODE    disp_data ;
    al_get_display_mode ( al_get_num_display_modes ()  -  1 ,  & disp_data );
    return disp_data.height;
}

int szerokosc () {
    al_init();
    ALLEGRO_DISPLAY_MODE    disp_data ;
    al_get_display_mode ( al_get_num_display_modes ()  -  1 ,  & disp_data );
    return disp_data.width;
}

const int WYS=wysokosc();
const int SZER=szerokosc();

bool powitanie (bool t) {
    t=true;
    bool pom=true;
    string wejscie;
    string wejscie2;
    cout << endl << endl << endl;
    cout << "                           *******************" << endl;
    cout << "                           Wpisz <<graj>> by zagrac w " << endl;
    cout << "                          PING PONG - The Last Strife" << endl;
    cout << "                           *******************" << endl;
    cout << "                           Wpisz <<wyjdz>> by wyjsc z " << endl;
    cout << "                          PING PONG - The Last Strife" << endl;
    cout << "                           *******************" << endl;

    cout << endl << "                           ";

    while (pom) {
        cin >> wejscie;
        wejscie2="";

        for (int i=0; i<wejscie.size(); i++)
            wejscie2.push_back(tolower(wejscie[i]));

        if (wejscie2=="wyjdz") {
            t=false;
            pom=false;
        }
        if (wejscie2=="graj")
            pom=false;
        if (wejscie2!="graj" && wejscie2!="wyjdz") {
            cout << endl << "                           *******************" << endl;
            cout << "                           Ups, wpisz ponownie, poprawnie: ";
        }
    }
    return t;
}

void odlicz () {
    al_init();

    al_init_primitives_addon();
    ALLEGRO_DISPLAY *okno;

    int SZERp=0.4*SZER; //to 300
    int WYSp=0.4*WYS; //to 100

    al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0));
    al_draw_filled_rectangle(SZERp, WYSp, SZERp+100, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
    al_draw_filled_rectangle(SZERp+90, WYSp+10, SZERp+100, WYSp+100, al_map_rgb_f(1.0, 1.0, 1.0));
    al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+100, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
    al_draw_filled_rectangle(SZERp+90, WYSp+110, SZERp+100, WYSp+200, al_map_rgb_f(1.0, 1.0, 1.0));
    al_draw_filled_rectangle(SZERp, WYSp+200, SZERp+100, WYSp+210, al_map_rgb_f(1.0, 1.0, 1.0));
    al_flip_display();
    Sleep(1000);

    al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0));
    al_draw_filled_rectangle(SZERp, WYSp, SZERp+100, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
    al_draw_filled_rectangle(SZERp+90, WYSp+10, SZERp+100, WYSp+100, al_map_rgb_f(1.0, 1.0, 1.0));
    al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+100, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
    al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+10, WYSp+200, al_map_rgb_f(1.0, 1.0, 1.0));
    al_draw_filled_rectangle(SZERp, WYSp+200, SZERp+100, WYSp+210, al_map_rgb_f(1.0, 1.0, 1.0));
    al_flip_display();
    Sleep(1000);

    al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0));
    al_draw_filled_rectangle(SZERp+90, WYSp+10, SZERp+100, WYSp+210, al_map_rgb_f(1.0, 1.0, 1.0));
    al_flip_display();
    Sleep(1000);
}

void licznik_lewy (int licznik) {
    al_init();
    al_init_primitives_addon();
    ALLEGRO_DISPLAY *okno;

    int SZERp=0.1*SZER;
    int WYSp=0.1*WYS;

     al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+110, al_map_rgb_f(0.0, 0.0, 0.0));

    switch (licznik) {

    case 0: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 1: {
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 2: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+10, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 3: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 4: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+50, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 5: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 6: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+10, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 7: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 8: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 9: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    }
}

void licznik_prawy (int licznik) {
    al_init();
    al_init_primitives_addon();
    ALLEGRO_DISPLAY *okno;

    int SZERp=0.9*SZER;
    int WYSp=0.1*WYS;

     al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+110, al_map_rgb_f(0.0, 0.0, 0.0));

    switch (licznik) {

    case 0: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 1: {
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 2: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+10, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 3: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 4: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+50, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 5: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 6: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+10, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 7: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 8: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    case 9: {
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+60, WYSp+10, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+50, SZERp+60, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp+50, WYSp+50, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp+100, SZERp+60, WYSp+110, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_filled_rectangle(SZERp, WYSp, SZERp+10, WYSp+60, al_map_rgb_f(1.0, 1.0, 1.0));
        break;
    }
    }
}

void piosnka () {

    Beep(195, 500);
    Beep(233, 250);
    Beep(293, 500);
    Beep(391, 750);
    Beep(391, 250);
    Beep(349, 250);
    Beep(293, 500);

    Beep(195, 500);
    Beep(233, 250);
    Beep(293, 500);
    Beep(391, 750);
    Beep(391, 250);
    Beep(349, 250);
    Beep(293, 500);

    Beep(195, 500);
    Beep(233, 250);
    Beep(293, 500);
    Beep(391, 750);
    Beep(391, 250);
    Beep(349, 250);
    Beep(293, 500);

    Beep(195, 500);
    Beep(233, 250);
    Beep(293, 500);
    Beep(391, 750);
    Beep(391, 250);
    Beep(349, 250);
    Beep(293, 500);

    Beep(783, 500);
    Beep(880, 250);
    Beep(932, 500);
    Beep(1174, 1750);
    Sleep(250);

    Sleep(500);
    Beep(1318, 500);
    Beep(1369, 250);
    Beep(1174, 500);
    Beep(1318, 250);
    Beep(1046, 500);
    Beep(1174, 250);
    Beep(880, 1750);

    Sleep(1000);

    Beep(783, 500);
    Beep(880, 250);
    Beep(932, 500);
    Beep(1174, 1750);
    Sleep(250);

    Sleep(500);
    Beep(1318, 500);
    Beep(1369, 250);
    Beep(1174, 500);
    Beep(1318, 250);
    Beep(1046, 500);
    Beep(1174, 250);
    Beep(880, 1750);

    Sleep(1000);

    Beep(880, 750);

    Beep(932, 3000);

    Beep(1174, 250);
    Beep(1046, 500);
    Beep(1174, 250);
    Beep(1046, 500);
    Beep(1174, 250);
    Beep(1046, 500);
    Beep(1174, 250);

    Beep(880, 750);
    Sleep(500);
    Beep(880, 500);
    Beep(880, 750);
    Sleep(250);
    Beep(880, 250);

    Beep(880, 1000);
    Sleep(250);
    Beep(1760, 1000);
    Beep(880, 250);

    Beep(783, 1500);
    Beep(587, 1500);

    Beep(659, 1000);
    Sleep(250);
    Beep(880, 250);
    Beep(1760, 500);
    Beep(1567, 500);
    Beep(1396, 500);

    Beep(1174, 250);

    Sleep(1000);

}

int main() {
    bool t;
    t=powitanie(t);

if (t) {
    int speed;

    srand(time(NULL));
    al_init();

    al_init_primitives_addon();
    ALLEGRO_DISPLAY *okno = NULL;
    ALLEGRO_DISPLAY_MODE    disp_data ;
    al_get_display_mode ( al_get_num_display_modes ()  -  1 ,  & disp_data );

    al_set_new_display_flags ( ALLEGRO_FULLSCREEN );
    okno  =  al_create_display ( disp_data . width ,  disp_data . height );

    al_install_keyboard();
    ALLEGRO_KEYBOARD_STATE klawiatura;

    odlicz();



    int sr_x=SZER/2;
    int k=SZER/500; // wspolczynnik, ktory zalezy od rozdzielczosci (szerokosci ekranu), jest poto, izby na duzych ekranach nie gralo sie zalatwo

    int y11=0.4*WYS, x11=0.2*SZER;// wspolrzedne x11 i x pierwszego prostokata (lewy gorny rog)
    int y12=0.6*WYS, x12=0.19*SZER; // wspolrzedne x11 i x pierwszego prostokata (prawy dolny rog)
    int y21=0.4*WYS, x21=0.8*SZER; // wspolrzedne x11 i x drugiego prostokata (lewy gorny rog)
    int y22=0.6*WYS, x22=0.81*SZER; // wspolrzedne x11 i x drugiego prostokata (prawy dolny rog)

    int r=0.02*WYS, px=SZER/2, py=WYS/2; // r to promien pileczki, px i py to kolejno wspolrzedna x i x11 pileczkiR

    int licznik1=0; //licznik punktow gracza po lewej
    int licznik2=0;// licznik punktow gracza po prawej
    int masny_pom=1; // do switcha


    do {

    switch (masny_pom) {// 1 to pileczka w lewo, 2 to pileczka w prawo, 3 to pileczka w prawy gorny rog, 4 to pileczka w prawy dolny rog, 5 to pileczka w lewy gorny rog,,
                        //6 to pileczka w lewy dolny rog, 7 to punkt dla gracza po lewej, 8 to punkt dla gracza po prawej,

    case 1: {
    do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));
         al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;


    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;


            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));

            speed=(rand()%4)*k;
            px-=speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(px>x11);

        if (py<y12-20 && py>y11+20)
            masny_pom=2;
        if (py>=y12-20 && py<=y12)
            masny_pom=4;
        if (py<=y11+20 && py>=y11)
            masny_pom=3;
       if (py>y12 || py<y11)
            masny_pom=8;

        break;
    }


     case 2: {
    do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));
         al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));


        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;

            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));

            speed=(rand()%4)*k;
            px+=speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(px<x21);

        if (py<y22-20 && py>y21+20)
            masny_pom=1;
        if (py>=y22-20 && py<=y22)
            masny_pom=6;
        if (py<=y21+20 && py>=y21)
            masny_pom=5;
        if (py>y22 || py<y21)
            masny_pom=7;

        break;
    }


     case 3: {
    do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));
         al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;

            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));

            speed=(rand()%3)*k;
            px+=speed;
            speed=(rand()%3)*k;
            py-speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(py>0);

         do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;

            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));

            px+=speed;
            py+=speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(px<x21);

        if (py<y22-20 && py>y21+20)
            masny_pom=1;
        if (py>=y22-20 && py<y22)
            masny_pom=6;
        if (py<=y21+20 && py>y21)
            masny_pom=5;
        if (py>y22 || py<y21)
            masny_pom=7;

        break;
    }



     case 4: {
    do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));
         al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;

            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));

            speed=(rand()%3)*k;
            px+=speed;
            speed=(rand()%3)*k;
            py+=speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(py<WYS);

        do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;

            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));

            px+=speed;
            py-=speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(px<x21);

        if (py<y22-20 && py>y21+20)
            masny_pom=1;
        if (py>=y22-20 && py<y22)
            masny_pom=6;
        if (py<=y21+20 && py>y21)
            masny_pom=5;
        if (py>y22 || py<y21)
            masny_pom=7;

        break;
    }

     case 5: {
    do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));
         al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    //al_draw_filled_rectangle(x11, x, x12, a, al_map_rgb_f(1.0, 1.0, 1.0));

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;

            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));

            speed=(rand()%3)*k;
            px-=speed;
            speed=(rand()%3)*k;
            py-=speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(py>0);

        do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));
        al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;

            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));

            px-=speed;
            py+=speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(px>x11);

        if (py<y12-20 && py>y11+20)
            masny_pom=2;
        if (py>=y12-20 && py<y12)
            masny_pom=4;
        if (py<=y11+20 && py>y11)
            masny_pom=3;
        if (py>y12 || py<y11)
            masny_pom=8;

        break;
    }




     case 6: {
    do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));
         al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;

            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));

            speed=(rand()%3)*k;
            px-=speed;
            speed=(rand()%3)*k;
            py+=speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(py<WYS);

        do {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        licznik_lewy(licznik1);
        licznik_prawy(licznik2);

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;

            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));
            al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

            px-=speed;
            py-=speed;
            al_rest(0.003);

            al_flip_display();

        al_get_keyboard_state(&klawiatura);
        } while(px>x11);

        if (py<y12-20 && py>y11+20)
            masny_pom=2;
        if (py>=y12-20 && py<y12)
            masny_pom=4;
        if (py<=y11+20 && py>y11)
            masny_pom=3;
        if (py>y12 || py<y11)
            masny_pom=8;

        break;
    }

    case 7: {
        licznik1++;

        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));
         al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;


        px=SZER/2, py=WYS/2;
            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));
            al_flip_display();
            al_rest(1.0);

             if (licznik2>10)
                break;

             else {
                odlicz();
                int los;
                los=rand()%10;

                if (los<5) {
                    masny_pom=1;
                    break;
                }
                else {
                    masny_pom=2;
                    break;
                }
            }

    }


    case 8: {
        licznik2++;

        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB

    //lewy
         al_draw_filled_rectangle(x11, y11, x12, y12, al_map_rgb_f(1.0, 1.0, 1.0));
         al_draw_line(sr_x, 0, sr_x, WYS, al_map_rgb_f(1.0, 1.0, 1.0), 5);

        if (al_key_down(&klawiatura, ALLEGRO_KEY_S)  && y12<WYS-10)  ++y11, ++y12;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_W)    &&  y11>10)    --y11, --y12;

    // drugi, prawy
        al_draw_filled_rectangle(x21, y21, x22, y22, al_map_rgb_f(1.0, 1.0, 1.0));

        if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN)  && y22<WYS-10)  ++y21, ++y22;
        if (al_key_down(&klawiatura, ALLEGRO_KEY_UP)    && y21>10)    --y21, --y22;


        px=SZER/2, py=WYS/2;
            al_draw_filled_circle(px, py, r, al_map_rgb_f(1.0, 1.0, 1.0));
            al_flip_display();
            al_rest(1.0);

             int los;
             los=rand()%10;

             if (licznik2>10)
                break;

            else {
                odlicz();
                if (los<5) {
                    masny_pom=1;
                    break;
                }
                else {
                    masny_pom=2;
                    break;
                }
            }

    }

    }
    } while(!al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE ) && licznik1<10 && licznik2<10);

    int masne_r=1;
    //al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
    //al_flip_display();
    while (masne_r<(SZER)) {
        al_clear_to_color(al_map_rgb_f(0.0, 0.0, 0.0)); // RGB
        al_draw_filled_circle(SZER/2, WYS/2, masne_r, al_map_rgb_f(1.0, 1.0, 1.0));
        al_flip_display();
        al_rest(0.01);
        masne_r++;
    }
    piosnka();
    al_destroy_display(okno);

    system("cls");
    cout << "                           *******************" << endl;
    cout << "                           Wynik gracza po lewej: " << licznik1 << endl;
    cout << "                           Wynik gracza po prawej: " << licznik2 << endl;
    cout << "                           *******************" << endl;
    Sleep(4000);
}
cout << endl << endl << endl;
cout << "                           *******************" << endl;
cout << "                           Dziekuje za gre w " << endl;
cout << "                       PING PONG - The Last Strife" << endl;
cout << "                           *******************" << endl;

Sleep(5000);
return 0;
}


