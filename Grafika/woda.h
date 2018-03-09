#ifndef WODA_H_INCLUDED
#define WODA_H_INCLUDED

#include "model.h"

class Woda: public Model {
public:
    Woda();
    ~Woda();
    void drawSolid(GLuint &tex,mat4 &V);
};

#endif // FLOOR_H_INCLUDED

