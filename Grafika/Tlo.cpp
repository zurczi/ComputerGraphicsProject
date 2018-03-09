#include <stdio.h>
#include <cstdlib>

#include "tlo.h"
#include "loader.h"

#define modelNieba "modeleBlend/dobra_kula2.obj"

using namespace glm;

Tlo::Tlo() {
    bool res = loadOBJ(modelNieba, this->vertices, this->uvs, this->normals,this->vCount);
    if(!res) {
        fprintf(stderr,"Model nie zostal wczytany");
        exit(1);
    }
    position = vec3(1.0,1.0,1.0);
    rotation = vec3(0.0,0.0,0.0);
    scale = vec3(1.0,1.0,1.0);
    speed = 0.0;
}

Tlo::~Tlo() {
    vertices.clear();
    uvs.clear();
    normals.clear();
}

void Tlo::drawSolid(GLuint &tex,mat4 &V) {
    glEnable(GL_NORMALIZE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindTexture(GL_TEXTURE_2D,tex);
    glShadeModel(GL_SMOOTH);
    mat4 M=mat4(1.0f);
    M=translate(M,this->position);
    M=glm::scale(M,this->scale);
    M=rotate(M,this->rotation.z,vec3(0.0,0.0,1.0));
    glLoadMatrixf(value_ptr(V*M));
    glVertexPointer(3,GL_FLOAT,0,&(this->vertices[0]));
    glNormalPointer(GL_FLOAT,sizeof(float)*3,&(this->normals[0]));
    glTexCoordPointer(2,GL_FLOAT,0,&(this->uvs[0]));
    float ambient[] = {0,0,0,1};//otoczenie
    float emision[] = {0.25,0.25,0.25,1};
    float diffuse[] = {1,1,1,1};//rozproszenie
    float specular[] = {0.1,0.1,0.1,1};//odbicie
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

