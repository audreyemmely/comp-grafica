#include <GL/glut.h>

static GLfloat arr[10] = {
    0, 2,
    0, 2,
    0, 2,
    0, 2,
    0, 2
};

void displayQuads()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    
    glColor3f(0.0, 1.0, 0.0); //verde
    glVertex2f(3, arr[0]);
    glVertex2f(2, arr[0]);
    glVertex2f(2, arr[1]);
    glVertex2f(3, arr[1]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0); //amarelo
    glVertex2f(1, arr[2]); 
    glVertex2f(0, arr[2]);
    glVertex2f(0, arr[3]);
    glVertex2f(1, arr[3]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0); //laranja
    glVertex2f(-1, arr[4]); 
    glVertex2f(-2, arr[4]);
    glVertex2f(-2, arr[5]);
    glVertex2f(-1, arr[5]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0); //vermelho
    glVertex2f(-3, arr[6]); 
    glVertex2f(-4, arr[6]);
    glVertex2f(-4, arr[7]);
    glVertex2f(-3, arr[7]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0); // rosa
    glVertex2f(-5, arr[8]); 
    glVertex2f(-6, arr[8]);
    glVertex2f(-6, arr[9]);
    glVertex2f(-5, arr[9]);
    glEnd();

    glFlush();
}

// é possível visualizar o efeito "ola" utilizando as letras 'q' 'w' 'e' 'r' 't' 'y' 'u' 'i' 'o' 'p' do teclado
void keyboard(unsigned char letter, int x, int y) 
{  
    switch (letter) {
        case 't':
            arr[0] += 2;
            arr[1] += 2;
            displayQuads();
            break;
        case 'r':
            arr[2] += 2;
            arr[3] += 2;
            displayQuads();
            break;
        case 'e':
            arr[4] += 2;
            arr[5] += 2;
            displayQuads();
            break;
        case 'w':
            arr[6] += 2;
            arr[7] += 2;
            displayQuads();
            break;
        case 'q':
            arr[8] += 2;
            arr[9] += 2;
            displayQuads();
            break;
        case 'p':
            arr[0] -= 2;
            arr[1] -= 2;
            displayQuads();
            break;
        case 'o':
            arr[2] -= 2;
            arr[3] -= 2;
            displayQuads();
            break;
        case 'i':
            arr[4] -= 2;
            arr[5] -= 2;
            displayQuads();
            break;
        case 'u':
            arr[6] -= 2;
            arr[7] -= 2;
            displayQuads();
            break;
        case 'y':
            arr[8] -= 2;
            arr[9] -= 2;
            displayQuads();
            break;
    }
}

int main(int argc, char **argv)
{   
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(400, 200);
    glutCreateWindow("Projeto Ola");

    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, -1.0);

    glutDisplayFunc(displayQuads);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
