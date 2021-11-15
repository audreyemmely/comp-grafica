#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

void display(){
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("OpenGL");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
/// rodou com comando diferente do q foi mostrado pelo monitor, nao sei pq deu erro, mas achei outro jeito de rodar 
/// gcc test.c -o test.out -lglut -lGL -lGLU
/// ./test.out