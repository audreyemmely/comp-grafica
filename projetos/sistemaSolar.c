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
    
//  Desenhar a terra
    glColor3f(0, 0, 1); //Cor azul
     
    glPushMatrix();
    glRotatef((GLfloat) (terra/2), 0, 1, 0); //Rotacionar a terra mais devagar ao redor do sol
    glTranslatef(2, 0, 0); //Transladar a terra para que ela possa rotacionar ao redor do sol
    glutWireSphere(0.2, 10, 8); //Desenha a terra
    glPopMatrix();

//  Desenha a primeira lua
    glColor3f(1, 1, 1); //Cor branca
     
    glPushMatrix();
    glRotatef((GLfloat) (terra/2), 0, 1, 0); //Rotacionar a lua para que ela gire junto com a Terra
    glTranslatef(2, 0, 0); //Transladar a lua para que ela fique junto com a Terra
    glRotatef((GLfloat) luas, 0, 1, 0); //Rotacionar a lua para que ela gire ao redor do eixo X da Terra
    glTranslatef(0.5, 0, 0); //Transladar a lua para ficar a 0.5 de distância da Terra
    glutWireSphere(0.05, 8, 6); //Desenha a lua
    glPopMatrix();

//  Desenha a segunda lua
    glColor3f(0, 1, 0); //Cor verde
     
    glPushMatrix();
    glRotatef((GLfloat) terra/2, 0, 1, 0); //Rotacionar a lua para que ela gire junto com o planeta
    glTranslatef(2, 0, 0); //Transladar a lua para que ela fique junto com o planeta
    glRotatef((GLfloat) luas, 1, 1, 0); //Rotacionar a lua para que ela gire ao redor do eixo x e y da Terra
    glTranslatef(0, 0, 0.5); //Transladar a lua para ficar a 0.5 de distância do centro do planeta
    glutWireSphere(0.05, 8, 6); //Desenha a lua
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

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'y': // Move o sistema solar
            terra = (terra-10) % 720;
            luas = (luas-10) % 360;
            glutPostRedisplay();
            break;
             
        case 27:
            exit(0);
            break;
             
        default:
            break;
    }
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
    glutKeyboardFunc(keyboard);

    glutMainLoop();
     
    return 0;
}