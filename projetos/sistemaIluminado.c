#include <GL/glut.h>

GLsizei winWidth = 1000, winHeight = 700;

static int mercurio, venus, terra, marte, ceres, luas = 0;

// Inicializa parâmetros de rendering
void init(void)
{
    	glClearColor(0, 0, 0, 0); // Define a cor de fundo da janela de visualização como preta
	glEnable(GL_DEPTH_TEST); // Habilita o depth-buffering
	glEnable(GL_LIGHTING); 	// Habilita o uso de iluminação
	glEnable(GL_COLOR_MATERIAL); // Habilita uso das cores
	glEnable(GL_LIGHT0); // Habilita a luz de número 0
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0);
	GLfloat lightPosition[] = {-5, 0, 0, 1};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}
 
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT); // Limpa a janela e o depth buffer

//  Sol
    glColor3f(1, 1, 0); // Cor amarela
     
    glPushMatrix(); // Armazena as transformações atuais em um pilha interna do OpenGL
    glRotatef((GLfloat) 90, 1, 0, 0); // Rotacionar o sol
    glRotatef((GLfloat) terra, 0, 0, 1); // Rotacionar o sol de acordo com o movimento dos planetas
    glutSolidSphere(1, 20, 16); // Desenha o sol
    glPopMatrix(); // Retira as transformações armazenadas 

//  Mercurio (planeta 1)
    glColor3f(0.0, 1.0, 1.0); //Cor ciano
     
    glPushMatrix();
    glRotatef((GLfloat) mercurio, 0, 1, 0.15); // Rotacionar planeta mercurio ao redor do sol
    glTranslatef(1.2, 0, 0); // Transladar planeta mais perto do sol
    glutSolidSphere(0.05, 12, 10); // Desenha planeta
    glPopMatrix();

//  Venus (planeta 2)
    glColor3f(1.0, 0.5, 0.0); // Cor laranja
     
    glPushMatrix();
    glRotatef((GLfloat) venus, 0, 1, 0.1); // Rotacionar planeta venus ao redor do sol
    glTranslatef(1.5, -0.3, 0); // Transladar planeta entre mercurio e terra
    glutSolidSphere(0.07, 12, 10); // Desenha planeta
    glPopMatrix();

//  Terra (planeta 3)
    glColor3f(0, 0, 1); // Cor azul
     
    glPushMatrix();
    glRotatef((GLfloat) (terra/2), 0, 1, 0); // Rotacionar a terra mais devagar ao redor do sol
    glTranslatef(2, 0, 0); // Transladar a terra para que ela possa rotacionar ao redor do sol
    glutSolidSphere(0.2, 10, 8); // Desenha a terra
    glPopMatrix();

//  Primeira lua
    glColor3f(1, 1, 1); //Cor branca
     
    glPushMatrix();
    glRotatef((GLfloat) (terra/2), 0, 1, 0); // Rotacionar a lua para que ela gire junto com a Terra
    glTranslatef(2, 0, 0); // Transladar a lua para que ela fique junto com a Terra
    glRotatef((GLfloat) luas, 0, 1, 0); // Rotacionar a lua para que ela gire ao redor do eixo X da Terra
    glTranslatef(0.5, 0, 0); // Transladar a lua para ficar a 0.5 de distância da Terra
    glutSolidSphere(0.05, 8, 6); // Desenha a lua
    glPopMatrix();

//  Segunda lua
    glColor3f(0, 1, 0); // Cor verde
     
    glPushMatrix();
    glRotatef((GLfloat) (terra/2), 0, 1, 0); // Rotacionar a lua para que ela gire junto com o planeta
    glTranslatef(2, 0, 0); // Transladar a lua para que ela fique junto com o planeta
    glRotatef((GLfloat) luas, 1, 1, 0); // Rotacionar a lua para que ela gire ao redor do eixo x e y da Terra
    glTranslatef(0, 0, 0.5); // Transladar a lua para ficar a 0.5 de distância do centro do planeta
    glutSolidSphere(0.05, 8, 6); // Desenha a lua
    glPopMatrix();

//  Marte (planeta 4)
    glColor3f(1, 0, 0); // Cor vermelha
     
    glPushMatrix();
    glRotatef((GLfloat) (marte/3), 0, 1, 0); // Rotacionar planeta marte ao redor do sol
    glTranslatef(-2.5, 0.4, 0); // Transladar planeta para o outro lado do sol entre venus e ceres
    glutSolidSphere(0.1, 10, 8); // Desenha o planeta
    glPopMatrix();

// Ceres (planeta-anão 5)
    glColor3f(1.0, 0.0, 1.0); // Cor rosa
     
    glPushMatrix();
    glRotatef((GLfloat) (ceres/8), 0, 1, 0.35); // Rotacionar planeta ceres ao redor do sol
    glTranslatef(-3, 0, 0); // Transladar planeta mais longe do sol
    glutSolidSphere(0.05, 5, 5); // Desenha planeta
    glPopMatrix();

    glutSwapBuffers(); // Realiza troca de buffers
}


void reshape(GLint w, GLint h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); // Especifica o tamanho da viewport
     
    glMatrixMode(GL_PROJECTION);  // Especifica sistema de coordenadas de projeção
    gluPerspective(60, (GLfloat) w/(GLfloat) h, 1, 20); // Especifica a projeção perspectiva

    glMatrixMode(GL_MODELVIEW);	// Especifica sistema de coordenadas do modelo
    glLoadIdentity(); // Inicializa sistema de coordenadas do modelo
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); // Especifica posição do observador e do alvo
}
 
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'y': // Move o sistema solar, +10 sentido anti-horário, -10 sentido horário
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
     
    glutInit(&argc, argv); // Inicializa a biblioteca GLUT
     
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Inicia o modo de exibição, GLUT_DOUBLE permite a exibição na janela de buffer duplo
							     //GLUT_RGB mostra as cores, GLUT_DEPTH permite buffer de profundidade
    glutInitWindowSize(winWidth, winHeight); // Especifica o tamanho em pixels da janela GLUT
    glutCreateWindow("Sistema Solar Iluminado"); // Cria a janela
     
    init(); // Nesta função são feitas as inicializações OpenGL que devem ser executadas antes do rendering
     		
    glutDisplayFunc(display); // Estabelece a função "display" previamente definida como a função callback de exibição, 
			      //isto significa que a GLUT chama a função sempre que a janela precisar ser redesenhada
    glutReshapeFunc(reshape); // Sempre que a janela é maximizada, minimizada, etc., a função "reshape" é executada para reinicializar o sistema de coordenadas
    glutKeyboardFunc(keyboard); // Estabelece a função callback que é chamada pela GLUT cada vez que uma tecla que gera código ASCII é pressionada. 
				//Além do valor ASCII da tecla, a posição (x,y) do mouse quando a tecla foi pressionada também é retornada.
     
    glutMainLoop(); // Inicia a execução da “máquina de estados” e processa todas as mensagens específicas do sistema operacional, 
		    //como teclas e botões do mouse pressionados, até que o programa termine
     
    return 0;
}
