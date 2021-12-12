#include <GL/glut.h>

GLsizei winWidth = 1000;
GLsizei winHeight = 700;
 
static int terra = 0;
static int planetas = 0;
static int luas = 0;

void init(void)
{
    glClearColor(0, 0, 0, 0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
     
//  Desenhar o sol
    glColor3f(1, 1, 0); //Cor amarela
     
    glPushMatrix();
    glRotatef((GLfloat) 90, 1, 0, 0); //Rotacionar o sol
    glRotatef((GLfloat) terra, 0, 0, 1); //Rotacionar o sol de acordo com o movimento dos planetas
    glutWireSphere(1, 20, 16); //Desenha o sol
    glPopMatrix();
    
    glutSwapBuffers();
}

void reshape(GLint w, GLint h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
     
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
     
    gluPerspective(60, (GLfloat) w/(GLfloat) h, 1, 20);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char *argv[])
{
     
    glutInit(&argc, argv);
     
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Sistema Solar");
     
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
     
    return 0;
}