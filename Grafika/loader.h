#ifndef LOADEROBJ_H_INCLUDED
#define LOADEROBJ_H_INCLUDED

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>

#include <vector>

bool loadOBJ(const char * path,
             std::vector < float > & out_vertices,
             std::vector < float > & out_uvs,
             std::vector < float > & out_normals,
             unsigned int &vCount
            );
void wypiszvector(std::vector <float> name,char c[],int modulo);

#endif

