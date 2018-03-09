#ifndef TLO_H_INCLUDED
#define TLO_H_INCLUDED

#include "model.h"

class Tlo: public Model {
public:
    Tlo();
    ~Tlo();
    void drawSolid(GLuint &tex,mat4 &V);
};


#endif // TLO_H_INCLUDED
