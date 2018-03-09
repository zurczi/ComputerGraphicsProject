#ifndef STATEK_H_INCLUDED
#define STATEK_H_INCLUDED

#include "model.h"

class Statek: public Model {
public:
    Statek();
    ~Statek();
    void drawSolid(GLuint &tex,glm::mat4 &V);
};

#endif // STATEK_H_INCLUDED
