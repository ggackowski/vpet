//
// Created by grzegorz on 5/30/21.
//

#include "PetDb.h"


tama::PetDb::PetDb()
{
    initDb();
}

void tama::PetDb::initDb()
{
    db.insert({
      {first, BABY, MASCULINE},
      {
              &firstMale::baby::frontOne,
              &firstMale::baby::frontTwo,
              &firstMale::baby::sideStandard,
              &firstMale::baby::sideEating,
              &firstMale::baby::frontOne,
         }
    });
}

tama::PetTextures tama::PetDb::getPetTextures(tama::PetIdentifier petIdentifier)
{
    return db.at(petIdentifier);
}
