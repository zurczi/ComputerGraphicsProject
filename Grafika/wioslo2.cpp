
#include <stdio.h>
#include <cstdlib>

#include "constants.h"
#include "wioslo2.h"
#include "loader.h"

#define model_statku "modeleBlend/wioslo_odbite4.obj"

using namespace glm;

Wioslo2::Wioslo2() {
    bool res = loadOBJ(model_statku, this->vertices, this->uvs, this->normals, this->vCount);
    if(!res) {
        fprintf(stderr,"Model nie zostal wczytany");
        exit(1);
    }
    position = vec3(0.0,0.6,0.0);
    rotation = vec3(0.0,0.0,0.0);
    scale = vec3(0.6,0.6,0.6);
    speed = 0.0;
}

Wioslo2::~Wioslo2() {
    vertices.clear();
    uvs.clear();
    normals.clear();
}

void Wioslo2::drawSolid(GLuint &tex,mat4 &V) {
    glEnable(GL_NORMALIZE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindTexture(GL_TEXTURE_2D,tex);
    mat4 M=mat4(1.0f);
    M=translate(M,this->position);
   M=rotate(M,speed,vec3(-1.0f,0.0f,0.4f));
M=glm::scale(M,this->scale);
    glLoadMatrixf(value_ptr(V*M));
    glVertexPointer(3,GL_FLOAT,0,&(this->vertices[0]));
    glNormalPointer(GL_FLOAT,sizeof(float)*3,&(this->normals[0]));
    glTexCoordPointer(2,GL_FLOAT,0,&(this->uvs[0]));
    float ambient[] = {0,0,0,1};
    float emision[] = {0,0,0,1};
    float diffuse[] = {0.5,0.5,0.5,1};
    float specular[] = {0.5,0.5,0.5,1};
    float shininess = 50;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glDrawArrays(GL_TRIANGLES,0,this->vCount);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}


