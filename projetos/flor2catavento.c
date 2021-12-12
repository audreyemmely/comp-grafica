#include <GL/glut.h>

GLsizei winWidth = 500, winHeight = 400;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0);

	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

}

//criando as petalas para gerar o catavento
void catavento()
{
	glColor3f(1.0, 1.0, 1.0); //branco
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f, 250.0f);
	glVertex2f(230.0f, 200.0f);
	glVertex2f(270.0f, 200.0f);
	glEnd();

	glColor3f(1.0, 0.0, 0.0); //vermelho
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f, 250.0f);
	glVertex2f(300.0f, 230.0f);
	glVertex2f(300.0f, 270.0f);
	glEnd();

	glColor3f(0.0, 1.0, 0.0); //verde
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f, 250.0f);
	glVertex2f(230.0f, 300.0f);
	glVertex2f(270.0f, 300.0f);
	glEnd();

	glColor3f(0.0, 0.0, 1.0); //azul
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f, 250.0f);
	glVertex2f(200.0f, 230.0f);
	glVertex2f(200.0f, 270.0f);
	glEnd();
	
}

// pressionar 'd' para rotacionar para a direita, pressionar 'e' para rotacionar para esquerda 
void keyboard(unsigned char key, int x, int y) {
    switch (key){
        case 'd': 
       	    glTranslatef(250, 250, 0);
	    glRotatef(15, 0.0, 0.0, 1.0);
	    glTranslatef(-250, -250, 0);

    	    glPopMatrix();
            break;
        case 'e':
            glTranslatef(250, 250, 0);
	    glRotatef(-15, 0.0, 0.0, 1.0);
	    glTranslatef(-250, -250, 0);

    	    glPopMatrix();
            break;
		
	case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}

//deixa o caule fixo
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix(); 
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION); 
	glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0);
	glColor3f(1.0, 1.0, .0);
	glBegin(GL_POLYGON);
	glVertex3f(249.0f, 250.0f, -1.0f);
	glVertex3f(250.0f, 250.0f, -1.0f);
	glVertex3f(249.0f, 100.0f, -1.0f);
	glVertex3f(250.0f, 100.0f, -1.0f);
	glEnd();
	glPopMatrix(); 

	catavento();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Flor de Abril/Catavento");

	init();

	glutDisplayFunc(display);
    	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
