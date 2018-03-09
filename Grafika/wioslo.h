#ifndef WIOSLO_H_INCLUDED
#define WIOSLO_H_INCLUDED

#include "model.h"

class Wioslo: public Model {
public:
    Wioslo();
    ~Wioslo();
    void drawSolid(GLuint &tex,glm::mat4 &V);
};

#endif // WIOSLO_H_INCLUDED
