#ifndef MANAGMENT_H
#define MANAGMENT_H

#ifdef _WIN32
#include <windows.h>
#endif // WIN32

#include "Theme_Park.h"
#include "Zoo.h"

//information about how many and which facilities we have
enum state{zoo,amu,theme,zoo_amu,zoo_theme,amu_theme,zoo_amu_theme};
//information which facility wee are currently using
enum facility{z,a,t};

//OTHERS
void clean();                           //screen clearing compiling both on Linux and Windows
void sum_up_screen(int, int);           //results of the day(money earned,visitors refused)

//MAIN
char start_up();                        //menu showed at the start of the program
facility switching(state,facility);     //switching between  facilities
bool choose_theme();                    //choosing theme for thematic park(3 available)
char create_new(state&);                //creating new facility
void manage(Ent_Park*,facility);        //menu where user chooses what he wants to change in chosen facility

//MANAGE
void buying_resources(Ent_Park*, char); //menu for buying area,slots,workers
void buying_mascot(Theme_Park*);        //menu for buying mascot for thematic park
void buying_attractions(Ent_Park*, facility);
void buying_attraction(Ent_Park*,char);

#endif // MANAGMENT
