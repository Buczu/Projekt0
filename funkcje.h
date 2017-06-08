#include <vector>
#include "teren.h"
#include "boisko.h"
#include "stadion.h"
#include "klub.h"

void clean();
void choice(int &x);
void buildField(boisko &field);
void buildStadium(stadium &stadion);
void manageTeams(std::vector<club> &kluby, int &iloscK, double cena,stadium st);
