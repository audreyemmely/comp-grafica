#include <GL/glut.h>

GLsizei winWidth = 1000;
GLsizei winHeight = 700;
 
static int mercurio, venus, terra, marte, ceres, luas = 0;

void init(void)
{
    glClearColor(0, 0, 0, 0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
     
//  Sol
    glColor3f(1, 1, 0); //Cor amarela
     
    glPushMatrix();
    glRotatef((GLfloat) 90, 1, 0, 0); //Rotacionar o sol
    glRotatef((GLfloat) terra, 0, 0, 1); //Rotacionar o sol de acordo com o movimento dos planetas
    glutWireSphere(1, 20, 16); //Desenha o sol
    glPopMatrix();

//  Mercurio (planeta 1)
    glColor3f(0.0, 1.0, 1.0); //Cor ciano
     
    glPushMatrix();
    glRotatef((GLfloat) mercurio, 0, 1, 0.15); //Rotacionar planeta mercurio ao redor do sol
    glTranslatef(1.2, 0, 0); //Transladar planeta mais perto do sol
    glutWireSphere(0.05, 12, 10); //Desenha planeta
    glPopMatrix();

//  Venus (planeta 2)
    glColor3f(1.0, 0.5, 0.0); //Cor laranja
     
    glPushMatrix();
    glRotatef((GLfloat) venus, 0, 1, 0.1); //Rotacionar planeta venus ao redor do sol
    glTranslatef(1.5, -0.3, 0); //Transladar planeta entre mercurio e terra
    glutWireSphere(0.07, 12, 10); //Desenha planeta
    glPopMatrix();

//  Terra (planeta 3)
    glColor3f(0, 0, 1); //Cor azul
     
    glPushMatrix();
    glRotatef((GLfloat) (terra/2), 0, 1, 0); //Rotacionar a terra mais devagar ao redor do sol
    glTranslatef(2, 0, 0); //Transladar a terra para que ela possa rotacionar ao redor do sol
    glutWireSphere(0.2, 10, 8); //Desenha a terra
    glPopMatrix();

//  Primeira lua
    glColor3f(1, 1, 1); //Cor branca
     
    glPushMatrix();
    glRotatef((GLfloat) (terra/2), 0, 1, 0); //Rotacionar a lua para que ela gire junto com a Terra
    glTranslatef(2, 0, 0); //Transladar a lua para que ela fique junto com a Terra
    glRotatef((GLfloat) luas, 0, 1, 0); //Rotacionar a lua para que ela gire ao redor do eixo X da Terra
    glTranslatef(0.5, 0, 0); //Transladar a lua para ficar a 0.5 de distância da Terra
    glutWireSphere(0.05, 8, 6); //Desenha a lua
    glPopMatrix();

//  Segunda lua
    glColor3f(0, 1, 0); //Cor verde
     
    glPushMatrix();
    glRotatef((GLfloat) (terra/2), 0, 1, 0); //Rotacionar a lua para que ela gire junto com o planeta
    glTranslatef(2, 0, 0); //Transladar a lua para que ela fique junto com o planeta
    glRotatef((GLfloat) luas, 1, 1, 0); //Rotacionar a lua para que ela gire ao redor do eixo x e y da Terra
    glTranslatef(0, 0, 0.5); //Transladar a lua para ficar a 0.5 de distância do centro do planeta
    glutWireSphere(0.05, 8, 6); //Desenha a lua
    glPopMatrix();

//  Marte (planeta 4)
    glColor3f(1, 0, 0); //Cor vermelha
     
    glPushMatrix();
    glRotatef((GLfloat) (marte/3), 0, 1, 0); //Rotacionar planeta marte ao redor do sol
    glTranslatef(-2.5, 0.4, 0); //Transladar planeta para o outro lado do sol entre venus e ceres
    glutWireSphere(0.1, 10, 8); //Desenha o planeta
    glPopMatrix();

// Ceres (planeta-anão 5)
    glColor3f(1.0, 0.0, 1.0); //Cor rosa
     
    glPushMatrix();
    glRotatef((GLfloat) (ceres/8), 0, 1, 0.35); //Rotacionar planeta ceres ao redor do sol
    glTranslatef(-3, 0, 0); //Transladar planeta mais longe do sol
    glutWireSphere(0.05, 5, 5); //Desenha planeta
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
            mercurio = ((mercurio+10) % 360);
            venus = ((venus+10) % 360);
            terra = (terra-10) % 720;
            luas = (luas-10) % 360;
            marte = ((marte-10) % 1080);
            ceres = ((ceres-10) % 2880);
            
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