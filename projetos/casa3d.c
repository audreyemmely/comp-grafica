#include <GL/gl.h>
#include <GL/glut.h>

float rotate_y = 0; 

void display()
{
    // Limpa tela e z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reinicia transformações
    glLoadIdentity();

    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    
    // Criando estrutura casa
    glBegin(GL_QUADS);
    // FRENTE 
    glColor3f(1.0, 0.0, 1.0); // rosa
    glVertex3f( 0.5, -0.5, -0.5); // Inferior direito
    glVertex3f( 0.5,  0.5, -0.5); // Superior direito
    glVertex3f(-0.5,  0.5, -0.5); // Superior esquerdo
    glVertex3f(-0.5, -0.5, -0.5); // Inferior esquerdo
    // TRASEIRA
    glColor3f(1.0, 0.0, 0.0); //vermelho
    glVertex3f( 0.5, -0.5, 0.5); // Inferior direito
    glVertex3f( 0.5,  0.5, 0.5); // Superior direito
    glVertex3f(-0.5,  0.5, 0.5); // Superior esquerdo
    glVertex3f(-0.5, -0.5, 0.5); // Inferior esquerdo
    // DIREITA
    glColor3f(1.0, 0.5, 0.0); //laranja
    glVertex3f( 0.5, -0.5, -0.5); // Inferior direito
    glVertex3f( 0.5,  0.5, -0.5); // Superior direito
    glVertex3f( 0.5,  0.5,  0.5); // Superior esquerdo
    glVertex3f( 0.5, -0.5,  0.5); // Inferior esquerdo
    // ESQUERDA
    glColor3f(1.0, 1.0, 0.0); //amarelo
    glVertex3f(-0.5, -0.5,  0.5); // Inferior direito
    glVertex3f(-0.5,  0.5,  0.5); // Superior direito
    glVertex3f(-0.5,  0.5, -0.5); // Superior esquerdo
    glVertex3f(-0.5, -0.5, -0.5); // Inferior esquerdo
    // INFERIOR
    glColor3f(0.0,  0.0,  0.0); //preto
    glVertex3f( 0.5, -0.5, -0.5); // Inferior direito
    glVertex3f( 0.5, -0.5,  0.5); // Superior direito
    glVertex3f(-0.5, -0.5,  0.5); // Superior esquerdo
    glVertex3f(-0.5, -0.5, -0.5); // Inferior esquerdo
    glEnd();

    // Criando teto casa
    glBegin(GL_TRIANGLES);
    // Face direita do triângulo
    glColor3f(1.0,  1.0,  1.0); //branco
    glVertex3f( 0.5,  0.5,  0.5); 
    glVertex3f( 0.5,  0.5, -0.5); 
    glVertex3f( 0.0,  1.0,  0.0); 
    // Face esquerda do triângulo
    glVertex3f(-0.5,  0.5, -0.5); 
    glVertex3f(-0.5,  0.5,  0.5); 
    glVertex3f( 0.0,  1.0,  0.0); 
    // Face frontal do triângulo
    glVertex3f( 0.5,  0.5,  0.5); 
    glVertex3f(-0.5,  0.5,  0.5); 
    glVertex3f( 0.0,  1.0,  0.0); 
    // Face traseira do triângulo
    glVertex3f( 0.5,  0.5, -0.5); 
    glVertex3f(-0.5,  0.5, -0.5); 
    glVertex3f( 0.0,  1.0,  0.0); 
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'r') 
    {
        rotate_y += 5;
    }

    glutPostRedisplay();
}
 
int main(int argc, char** argv){
    
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutCreateWindow("Casa 3D");

    // Habilita o teste de profundidade do z-buffer
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}