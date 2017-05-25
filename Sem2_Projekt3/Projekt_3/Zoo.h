#ifndef ZOO_H
#define ZOO_H

#include "Ent_Park.h"
#include "Animal.h"
#include <vector>

class Zoo :public Ent_Park
{

private:

    std::vector < Animal > animals;

public:
    Zoo();

};

#endif// ZOO_H
