/*
Niniejszy program jest wolnym oprogramowaniem; możesz go
rozprowadzać dalej i / lub modyfikować na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundację Wolnego
Oprogramowania - według wersji 2 tej Licencji lub(według twojego
wyboru) którejś z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on
użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej
gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH
ZASTOSOWAŃ.W celu uzyskania bliższych informacji sięgnij do
Powszechnej Licencji Publicznej GNU.

Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
jeśli nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <lodepng.h>
#include "constants.h"
#include "allmodels.h"
#include "loader.h"
#include <windows.h>
#include <time.h>
#define teksturaStatku "tekstury/statek.png"
#define teksturaNieba "tekstury/niebo3.png"
#define teksturaWody "tekstury/woda.png"
#define teksturaZagla "tekstury/zagiel.png"
#define teksturaWiosla "tekstury/wioslo.png"

#define PIERWSZY GLFW_KEY_1
#define DRUGI GLFW_KEY_2
#define TRZECI GLFW_KEY_3

using namespace glm;
Wioslo *wioslo1;
Wioslo *wioslo2;
Wioslo *wioslo3;
Wioslo *wioslo4;
Wioslo *wioslo5;
Wioslo *wioslo6;
Wioslo *wioslo7;
Wioslo *wioslo8;
Wioslo *wioslo9;
Wioslo *wioslo10;
///////////////
Wioslo2 *wioslo11;
Wioslo2 *wioslo22;
Wioslo2 *wioslo33;
Wioslo2 *wioslo44;
Wioslo2 *wioslo55;
Wioslo2 *wioslo66;
Wioslo2 *wioslo77;
Wioslo2 *wioslo88;
Wioslo2 *wioslo99;
Wioslo2 *wioslo101;
Statek *statek1;
Tlo *niebo1;
Woda *woda1;
GLuint texStatek;
GLuint texNiebo;
GLuint texWoda;
GLuint texWioslo;
float speed1=3.14;
int x=0;

float Xkam=0.0f;
float Ykam=0.0f;
float Zkam=10.0f;

float delta;
float a1,b1,c1,odp1,odp2;
int czy_wcisniety=0;


int iteracja=0;
float aspect=1.0f; //Aktualny stosunek szerokości do wysokości okna
float speed_x=0; //Szybkość kątowa obrotu obiektu w radianach na sekundę wokół osi x
float speed_y=0; //Szybkość kątowa obrotu obiektu w radianach na sekundę wokół osi y

//Procedura obsługi błędów
void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

//Procedura obługi zmiany rozmiaru bufora ramki
void windowResize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height); //Obraz ma być generowany w oknie o tej rozdzielczości
    aspect=(float)width/(float)height; //Stosunek szerokości do wysokości okna
}


//Procedura obsługi klawiatury
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        if (key == PIERWSZY)
        {
            Xkam=0.0f;
            Ykam=0.0f;
            Zkam=10.0f;
        }
        if (key == DRUGI)
        {
            Xkam=4.5f;
            Ykam=10.125f;
            Zkam=-3.5f;

        }
        if (key == TRZECI)
        {
            Xkam=0.0f;
            Ykam=0.0f;
            Zkam=-14.0f;
        }
    }
}

void ustaw()
{
    woda1=new Woda();
    statek1 = new Statek();
    niebo1 = new Tlo();
    niebo1->position = vec3(0.0,0.0,0.0);
    niebo1->scale = vec3(20.0,20.0,20.0);
    statek1->position=vec3(3.5,3.125,-3.0);
    woda1->position=vec3(0.0,-4.0,-4.0);
    woda1->scale = vec3(2.0,2.0,2.0);


    wioslo1=new Wioslo();
    wioslo2=new Wioslo();
    wioslo3=new Wioslo();
    wioslo4=new Wioslo();
    wioslo5=new Wioslo();
    wioslo6=new Wioslo();
    wioslo7=new Wioslo();
    wioslo8=new Wioslo();
    wioslo9=new Wioslo();
    wioslo10=new Wioslo();
///
    wioslo11=new Wioslo2();
    wioslo22=new Wioslo2();
    wioslo33=new Wioslo2();
    wioslo44=new Wioslo2();
    wioslo55=new Wioslo2();
    wioslo66=new Wioslo2();
    wioslo77=new Wioslo2();
    wioslo88=new Wioslo2();
    wioslo99=new Wioslo2();
    wioslo101=new Wioslo2();

    wioslo1->position=vec3(0.0,-1.95,3.75);
    wioslo2->position=vec3(0.2,-2.1,3.0);
    wioslo3->position=vec3(0.4,-2.25,2.25);
    wioslo4->position=vec3(0.6,-2.4,1.5);
    wioslo5->position=vec3(0.8,-2.55,0.75);
    wioslo6->position=vec3(1.0,-2.7,0.0);
    wioslo7->position=vec3(1.2,-2.85,-0.75);
    wioslo8->position=vec3(1.4,-3.0,-1.5);
    wioslo9->position=vec3(1.6,-3.15,-2.25);
    wioslo10->position=vec3(1.8,-3.3,-3.0);
///
    wioslo11->position=vec3(-1.6,-1.9,3.7);
    wioslo22->position=vec3(-1.4,-2.1,3.0);
    wioslo33->position=vec3(-1.2,-2.25,2.25);
    wioslo44->position=vec3(-1.0,-2.4,1.5);
    wioslo55->position=vec3(-0.8,-2.55,0.75);
    wioslo66->position=vec3(-0.6,-2.7,0.0);
    wioslo77->position=vec3(-0.4,-2.85,-0.75);
    wioslo88->position=vec3(-0.2,-3.0,-1.5);
    wioslo99->position=vec3(-0.0,-3.15,-2.25);
    wioslo101->position=vec3(0.2,-3.3,-3.0);
}

void cieniowanie()
{
    GLfloat ambientLight[] = { 0.1f, 0.1f, 0.1f, 1.0f }; // otoczenia
    GLfloat diffuseLight[] = { 0.5f, 0.5f, 0.5, 1.0f }; // rozproszenia
    GLfloat specularLight[] = { 0.9f, 0.9f, 0.9f, 1.0f }; // odbicia

    //GLfloat ambientLight[] = { 0.1f, 0.1f, 0.1f, 1.0f }; // otoczenia
    //GLfloat diffuseLight[] = { 0.5f, 0.5f, 0.5, 1.0f }; // rozproszenia
    //GLfloat specularLight[] = { 0.9f, 0.9f, 0.9f, 1.0f }; // odbicia


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);

}

// funckja ktora wczytuje textury do pamieci
void wczytajObraz(GLuint &tex, std::string path)
{
    std::vector<unsigned char> image; //Alokuj wektor do wczytania obrazka
    unsigned width, height; //Zmienne do których wczytamy wymiary obrazka
    unsigned error = lodepng::decode(image, width, height, path);
    if(error != 0)
    {
        fprintf(stderr,"%s\n",lodepng_error_text(error)); // wypisanie bledu jak cos nie pojdzie
        exit(1);
    }
    //Import do pamiêci karty graficznej
    glGenTextures(1,&tex); //Zainicjuj jeden uchwyt
    glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
    //Wczytaj obrazek do pamiêci KG skojarzonej z uchwytem
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*) image.data());
    //Bilinear filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_NORMALIZE);
}

///

//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window)
{
    //************Tutaj umieszczaj kod, który należy wykonać raz, na początku programu************
    glfwSetFramebufferSizeCallback(window, windowResize); //Zarejestruj procedurę obsługi zmiany rozdzielczości bufora ramki
    glfwSetKeyCallback(window, key_callback); //Zarejestruj procedurę obsługi klawiatury
    cieniowanie(); ///



    glEnable(GL_LIGHT0); //Włącz zerowe źródło światła
    glEnable(GL_COLOR_MATERIAL); //Włącz śledzenie kolorów przez materiał
    glEnable(GL_DEPTH_TEST); //Włącz używanie budora głębokości

    wczytajObraz(texStatek, teksturaStatku);
    wczytajObraz(texNiebo,teksturaNieba);
    wczytajObraz(texWoda,teksturaWody);
    wczytajObraz(texWioslo,teksturaWiosla);

}





//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window,float angle1,float angle2)
{
    //************Tutaj umieszczaj kod rysujący obraz******************l

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //Wyczyść bufor kolorów (czyli przygotuj "płótno" do rysowania)

    //***Przygotowanie do rysowania****
    mat4 P=perspective(50.0f*PI/180.0f,aspect,1.0f,50.0f); //Wylicz macierz rzutowania P
    mat4 V=lookAt( //Wylicz macierz widoku
               vec3(Xkam,Ykam,Zkam), //obserwator
               vec3(0.0f,0.0f,0.0f), //centrum
               vec3(0.0f,1.0f,0.0f)); //wektor nosa

    glMatrixMode(GL_PROJECTION); //Włącz tryb modyfikacji macierzy rzutowania
    glLoadMatrixf(value_ptr(P)); //Załaduj macierz rzutowania
    glMatrixMode(GL_MODELVIEW);  //Włącz tryb modyfikacji macierzy model-widok

    //1. Wyliczenie i załadowanie macierzy modelu
    //  mat4 M=mat4(1.0f);
    //  M=rotate(M,angle1,vec3(1.0f,0.0f,0.0f));
//  M=rotate(M,angle2,vec3(0.0f,1.0f,0.0f));//010
    // glLoadMatrixf(value_ptr(V*M));

    niebo1->drawSolid(texNiebo,V);
    statek1->drawSolid(texStatek,V);
    woda1->drawSolid(texWoda,V);

    //////////////
    wioslo1->drawSolid(texWioslo,V);
    wioslo2->drawSolid(texWioslo,V);
    wioslo3->drawSolid(texWioslo,V);
    wioslo4->drawSolid(texWioslo,V);
    wioslo5->drawSolid(texWioslo,V);
    wioslo6->drawSolid(texWioslo,V);
    wioslo7->drawSolid(texWioslo,V);
    wioslo8->drawSolid(texWioslo,V);
    wioslo9->drawSolid(texWioslo,V);
    wioslo10->drawSolid(texWioslo,V);

    wioslo1->speed=angle1;
    wioslo2->speed=angle1;
    wioslo3->speed=angle1;
    wioslo4->speed=angle1;
    wioslo5->speed=angle1;
    wioslo6->speed=angle1;
    wioslo7->speed=angle1;
    wioslo8->speed=angle1;
    wioslo9->speed=angle1;
    wioslo10->speed=angle1;

///
    wioslo11->drawSolid(texWioslo,V);
    wioslo22->drawSolid(texWioslo,V);
    wioslo33->drawSolid(texWioslo,V);
    wioslo44->drawSolid(texWioslo,V);
    wioslo55->drawSolid(texWioslo,V);
    wioslo66->drawSolid(texWioslo,V);
    wioslo77->drawSolid(texWioslo,V);
    wioslo88->drawSolid(texWioslo,V);
    wioslo99->drawSolid(texWioslo,V);
    wioslo101->drawSolid(texWioslo,V);

    wioslo11->speed=angle2;
    wioslo22->speed=angle2;
    wioslo33->speed=angle2;
    wioslo44->speed=angle2;
    wioslo55->speed=angle2;
    wioslo66->speed=angle2;
    wioslo77->speed=angle2;
    wioslo88->speed=angle2;
    wioslo99->speed=angle2;
    wioslo101->speed=angle2;



    //Posprzątaj po sobie
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    iteracja++;
//falowanie
    if(iteracja%12==0)
    {
        if(x==0)
        {
            woda1->position=woda1->position+vec3(1.25,0.0,0.0);

            x++;
        }
        else if(x=1)
        {
            woda1->position=woda1->position-vec3(1.25,0.0,0.0);

            x--;
        }
    }


    glfwSwapBuffers(window); //Przerzuć tylny bufor na przedni
}

int main(void)
{
    ustaw();
    GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

    glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

    if (!glfwInit())   //Zainicjuj bibliotekę GLFW
    {
        fprintf(stderr, "Nie można zainicjować GLFW.\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(700, 700, "Galera", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

    if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
    glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

    GLenum err;
    if ((err=glewInit()) != GLEW_OK)   //Zainicjuj bibliotekę GLEW
    {
        fprintf(stderr, "Nie można zainicjować GLEW: %s\n", glewGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    initOpenGLProgram(window); //Operacje inicjujące


    float angle1=0; //prawe
    float angle2=0;//lewe
    glfwSetTime(0);

    //Główna pętla
    while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
    {
        angle1+=speed1*glfwGetTime();
        angle2+=speed1*glfwGetTime();
        glfwSetTime(0);
        // angle_x+=speed_x*glfwGetTime(); //Oblicz przyrost kąta obrotu i zwiększ aktualny kąt
        // angle_y+=speed_y*glfwGetTime(); //Oblicz przyrost kąta obrotu i zwiększ aktualny kąt
        //glfwSetTime(0); //Wyzeruj timer
        drawScene(window,angle1,-angle2); //Wykonaj procedurę rysującą
        glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.

    }

    glDeleteTextures(1,&texStatek);
    glDeleteTextures(1,&texNiebo);
    glDeleteTextures(1,&texWioslo);
    glDeleteTextures(1,&texWoda);
    glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
    glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
    exit(EXIT_SUCCESS);
}
