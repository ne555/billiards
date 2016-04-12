/*
 * main.cpp
 *
 *  Created on: 16/03/2016
 *      Author: Eduardo Gutiérrez
 *
 */

#include <vector>
#include <unistd.h>
#include <time.h>
#include <algorithm>
#include <GL/glut.h>
#include <jpeglib.h>

//#include "Particle.h"
#include "vector3.h"
#include "Ball.h"
#include "MyLoadTexture.h"
#include "DragForceGenerator.h"
#include "Plane.h"
#include "ParticleContact.h"
#include "BallPlaneColDetect.h"

void display();
void keyboard(unsigned char c,int x,int y);
void specialkeyboard(int key,int x,int y);
void PositionObserver(float alpha,float beta,int radi);
void idle();
void updateMovements();
void paintBilliadTable();
void LoadTexture(char *filename,int dim);
void background();

//float minimax( int mazeTemp[][COLUMNS], array<int,10> &CharactersLocationsMaze,int score, int direction, int depth, int jugador);

using namespace std;
using namespace MyBilliards;

#define WIDTH 1024
#define HEIGHT 585
#define WINDOW_X 100
#define WINDOW_Y 100
#define PI 3.141592
#define TRONERAS 0.30

//Definición de variables.
//Plano inferior
	vector3 normalBottom (0,1,0); // Vector normal apuntando hacia arriba

	//Un punto del plano seria
	Plane borderBottom (normalBottom,0.30,0.17,0); //17 cm es el borde la tabla...

	//Plano superior
	vector3 normalTop(0,-1,0); // Vector normal apuntando hacia abajo
	//Un punto del plano seria
	Plane borderTop (normalTop,0.30,1.55,0); //17 cm es el borde la tabla...

	//Plano izquierdo
	vector3 normalLeft (1,0,0); // Vector normal apuntando hacia arriba

	//Un punto del plano seria
	Plane borderLeft (normalLeft,0.17,1,0); //17 cm es el borde la tabla...

	//Plano derecho
	vector3 normalRight(-1,0,0); // Vector normal apuntando hacia abajo

	//Un punto del plano seria
	Plane borderRight(normalRight,2.85,1,0); //17 cm es el borde la tabla...
Ball myBall, myBall2;
long last_t=0;

int main (int argc, char *argv[])
{

	srand(time(NULL));




	/*Esta función es la que inicializa la GLUT y negocia con el sistema de ventanas para abrir una. Los parámetros deben ser los mismos argc y argv,
	 * sin modificar, de la función main(). Además, Glut entiende una serie de parámetros que pueden ser pasados por línea de comandos.*/
	glutInit(&argc, argv);

	/*En esta ocasión, utilizamos GLUT_DOUBLE en vez de GLUT_SIMPLE. Esto hace posible la utilización de la técnica de “double buffer”, con la utilizamos
	 * dos buffers para pintar en uno mientras se visualiza el otro. Con esto conseguimos una mayor fluidez en escenas.
	 */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

	//Posición x e y de la esquina superior izquierda de la nueva ventana, con respecto al escritorio en el que se trabaje.
	glutInitWindowPosition(WINDOW_X,WINDOW_Y);

	//Comprobamos que el ancho y alto de nuestra ventana es menor que los pixeles de la pantalla.
	//En ese caso no cabria nuestra ventana en la pantalla
	/*
	if ( glutGet(GLUT_SCREEN_WIDTH) == 0 || glutGet(GLUT_SCREEN_WIDTH) < WIDTH)
		throw out_of_range("Error: El ancho no puede ser cero. Error ancho pantalla");

	if (glutGet(GLUT_SCREEN_HEIGHT) == 0 || glutGet(GLUT_SCREEN_HEIGHT) < HEIGHT)
		throw std::out_of_range("Error: El alto no puede ser cero. Error alto pantalla");
*/
	//El ancho y alto de la nueva ventana.
	glutInitWindowSize(WIDTH,HEIGHT);

	// Esta función es la que propiamente crea la ventana y el parámetro es el nombre de la misma.
	glutCreateWindow("My Billiards");

	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard);

	glutSpecialFunc(specialkeyboard);

	glutIdleFunc(idle);

	/*Especifica la matriz actual para realizar la composición. En ogl las operaciones de rotación, translación, escalado, etc. se
	 * realizan a través de matrices de transformación. Dependiendo de lo que estemos tratando, hay tres tipos de matriz (que son
	 * los tres posibles flags que puede llevar de parámetro la función): matriz de proyección (GL_PROJECTION),
	 * matriz de modelo (GL_MODELVIEW) y matriz de textura (GL_TEXTURE). Con esta función indicamos a cual de estas tres deben
	 * afectar las operaciones. Concretamente, GL_PROJECTION afecta a las vistas o perspectivas o proyecciones.
	 */
	glMatrixMode(GL_PROJECTION);

	/*glOrtho() define una perspectiva ortonormal. Esto quiere decir que lo que se ves será una proyección paralela en uno de los
	 * planos definidos por los ejes. Los parámetros sirven para delimitar el volumen de vista y son, por este orden:
	 * x_mínima, x_máxima, y_mínima, ySon_máxima, */


	//gluOrtho2D: Son vertice inferior izquierdo, y superior derecho en unidades reales.
	//A partir de ahora todo ira en unidades reales y no pixeles. ex: 8x4 metros sera 0,7,0,3

	//Medidas oficiales: Mesa 1.4 alto -> 1.72 con bordes
	// 2.7 m de largo -> 3.02 con bordes
	//cada borde son 16 cm
	gluOrtho2D(0.0,3.02,0.0,1.72);


	//Esta función cede el control del flujo del programa a GLUT que, a partir de estos "eventos", irá llamando a las funciones que han sido pasadas como callbacks.
	glutMainLoop();


	return 0;

}

//la función display() al ser pasada a glutDisplayFunc(), será llamada cada vez que haya que redibujar la ventana

void display()
{


	/*Con esto se define el color con el que se borrara el buffer al hacer un glClear().
	 * Los 3 primeros parámetros son las componentes R, G y B, siguiendo un rango de [0..1]. La última es el valor alpha.
	 */
	//glClearColor(0.0,0.4,0.8,0.0);
	glClearColor(0.0,0.0,0.0,0.0);

	/* Borra un buffer o una combinación de varios. En este caso, borra el buffer de color (en realidad, cada componente
   	R G y B tienen un buffer distinto, pero aquí los trata como el mismo), el que se pinta después en pantalla.
   	Para borrarlos utiliza el color que ha sido previamente definido en init() mediante glClearColor(), en este caso,
   	el (0,0,0,0) es decir, pinta el buffer de negro.*/

	glClear(GL_COLOR_BUFFER_BIT);

	//paintBilliadTable();

	background();
	myBall.draw();
	myBall2.draw();



	updateMovements();

	//ShowInformation();
	//background();

	glutSwapBuffers();
}


//-----------------------------------------------
void keyboard(unsigned char c,int x,int y)
{

	switch(c)
	{
	case 27: // ESC
		exit (0);
		break;
	case 105 :  // Code 105 is 'i'
		//if ( anglebeta <= (90-4) ) anglebeta=(anglebeta+3);
		break;
	case 107: //Code 107 is k
		//if ( anglebeta >= (-90+4)) anglebeta=anglebeta-3;
		break;
	case 106: //Code 106 is j
		//anglealpha=(anglealpha+3)%360;
		break;
	case 108: //Code 108 is l
		//anglealpha=(anglealpha-3+360)%360;
		break;

	}


	myBall.setPosition(0.30,1.55,0);
	myBall2.setPosition(0.30,0.17,0);

	glutPostRedisplay();
}

void specialkeyboard(int key,int x,int y)
{


		glutPostRedisplay();//No ESTA LINEAAAA
}

//-----------------------------------------------
void idle()
{
	DragForceGenerator rozamiento;

	long t;

	t=glutGet(GLUT_ELAPSED_TIME);
	//t=t/1000.0;

	if(last_t==0)
		last_t=t;
	else
	{
		//moviment continuo bola
		//Primero el clearforceacumulator
		myBall.clearForceAccumulator();
		//Luego el updateforce
		rozamiento.updateForce(&myBall,0.01);
		//Luego el integrate
		 myBall.integrate((float)(t-last_t)/1000.0);

		// I luego resolver colisiones (
		//resolvecollisonplanes
		 BallPlaneColDetect p;
		 ParticleContact *contactResolve;
		 contactResolve = p.haveCollided(&myBall,&borderTop);
		 if (contactResolve != NULL) {
			 contactResolve->ResolveCollision();
			 cout "contacto con tacto";
		 }

		//resolvecollisionholes

		//resolvecollisionballs)

		last_t=t;
	}
	glutPostRedisplay();
}

void updateMovements()
{



}


void background()
{

	glColor3f(1,1,1);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D,0);
	//MyLoadTexture("pool-tables.jpg");
	MyLoadTexture("American(1024x585).jpg");

	// Draw a textured quad
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(0, 0);
	glTexCoord2f(0, 1); glVertex2f(0, 1.72);
	glTexCoord2f(1, 1); glVertex2f(3.02, 1.72);
	glTexCoord2f(1, 0); glVertex2f(3.02, 0);
	glEnd();


	glDisable(GL_TEXTURE_2D);

}

