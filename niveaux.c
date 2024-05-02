#include "types.h"

void div_niv(Hotte *hot){
  hot->x/=hot->niveaux;
  hot->y/=hot->niveaux;
  hot->z/=hot->niveaux;
}
