
#ifndef WIOSLO2_H_INCLUDED
#define WIOSLO2_H_INCLUDED

#include "model.h"

class Wioslo2: public Model {
public:
    Wioslo2();
    ~Wioslo2();
    void drawSolid(GLuint &tex,glm::mat4 &V);
};

#endif // WIOSLO2_H_INCLUDED
