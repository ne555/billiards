/*#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400

//-----------------------------------------------
#define MOVE 1
#define QUIET 2
//-----------------------------------------------

void display();;
void keyboard(unsigned char c,int x,int y);
void idle();

//-----------------------------------------------

class particle {
  float x,y;   //-- Current position
  float vx,vy; //-- Velocity vector
  int state;

  long time_remaining;

public:

  particle();
  void set_position(int x,int y);
  void init_movement(int destination_x,int destination_y,int duration);
  void integrate(long t);
  void draw();
};


//-----------------------------------------------

particle::particle()
{
  state=QUIET;
}

//-----------------------------------------------

void particle::set_position(int x,int y)
{
  this->x = x;
  this->y = y;
}

//-----------------------------------------------

void particle::init_movement(int destination_x,int destination_y,int duration)
{
  vx = (destination_x - x)/duration;
  vy = (destination_y - y)/duration;

  state=MOVE;
  time_remaining=duration;
}

//-----------------------------------------------

void particle::integrate(long t)
{
  if(state==MOVE && t<time_remaining)
    {
      x = x + vx*t;
      y = y + vy*t;
      time_remaining-=t;
    }
  else if(state==MOVE && t>=time_remaining)
    {
      x = x + vx*time_remaining;
      y = y + vy*time_remaining;
      state=QUIET;
    }
}

//-----------------------------------------------

void particle::draw()
{
  glColor3f(1,1,1);
  glBegin(GL_QUADS);
  glVertex2i(x-6,y-6);
  glVertex2i(x+6,y-6);
  glVertex2i(x+6,y+6);
  glVertex2i(x-6,y+6);
  glEnd();
}



//-----------------------------------------------
// -- MAIN
//-----------------------------------------------

particle square;
long last_t=0;

int main(int argc,char *argv[])
{
  srand(time(NULL));
  square.set_position(50,50);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("Variable Frame Rate");

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);

  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,WIDTH-1,0.0,HEIGHT-1);

  glutMainLoop();
  return 0;
}


//-----------------------------------------------
//-----------------------------------------------
void display()
{
  glClearColor(0,0,0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  square.draw();

  glutSwapBuffers();
}

//-----------------------------------------------
//-----------------------------------------------
void keyboard(unsigned char c,int x,int y)
{
  square.set_position(50,50);
  square.init_movement(WIDTH-50,HEIGHT-50,1000);

  glutPostRedisplay();
};


//-----------------------------------------------
//-----------------------------------------------
void idle()
{
  long t;

  t=glutGet(GLUT_ELAPSED_TIME); 

  if(last_t==0)
    last_t=t;
  else
    {
      square.integrate(t-last_t);
      last_t=t;
    }


  glutPostRedisplay();
}
*/

/*
#include <fstream>
#include <vector>
#include <cassert>

using HighScoreEntry = int;

int main()
{
    std::vector<HighScoreEntry> highscores;
    std::ifstream ifile("example.txt");
    HighScoreEntry tentry;
    while(ifile) {
       ifile >> tentry;
       highscores.push_back(tentry);
    }

    assert(highscores.empty());
    assert(!ifile.good());
}

sobre el stick:

class setShotVelocity
{
public:
	int last_mx;
	int last_my;
	int cur_mx;
	int cur_my;
	int tracking;
	int ballID;
	glm::vec3 velocity;
	glm::vec3 angVel;

	void setVelocity();
};

	Main antes keyboard:
	glutMouseFunc(onMouse);
    glutMotionFunc(onMotion);

void processSelection(int x, int y)
{
  unsigned char res[4];
  renderSelection();
  glReadPixels(x, screen_height-y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &res);
  myShot.ballID = res[0]-1;
  myShot.setVelocity();
  if (myShot.ballID != -1)
  {
    myBallPhy.ballVel[myShot.ballID] = myShot.velocity;
    myBallPhy.ballAngVel[myShot.ballID] = myShot.angVel;
  }
  cout << "myBallPhy.ballVel[myShot.ballID]: " << myShot.velocity[0] << ", " << myShot.velocity[1] << endl;
  printf("Ball: %d\n", myShot.ballID);
}


void onMouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    myShot.last_mx = x;
    myShot.last_my = y;
    myShot.tracking = true;
  }
  else myShot.tracking = false;

  // if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  // {
  //   myQuater.last_mx = myQuater.cur_mx = x;
  //   myQuater.last_my = myQuater.cur_my = y;
  //   myQuater.trackball_on = true;
  // }
  // else myQuater.trackball_on = false;
}


void onMotion(int x, int y)
{
  if (myShot.tracking)
  {
    myShot.cur_mx = x;
    myShot.cur_my = y;
    processSelection(x,y);
    printf("cur_mx: %d, cur_my: %d\n", myShot.cur_mx, myShot.cur_my);
  }

  // if (myQuater.trackball_on)
  // {
  //   myQuater.cur_mx = x;
  //   myQuater.cur_my = y;
  // }

}

void setShotVelocity::setVelocity()
{
	if (ballID >= 0)
	{
		velocity[0] = cur_my - last_my;
		velocity[1] = 0.0;
		velocity[2] = -(cur_mx - last_mx);
		angVel = glm::cross(glm::vec3(0.0,1.0,0.0),velocity);
	}
	else
	{
		velocity = glm::vec3(0.0f);
		angVel = glm::vec3(0.0f);
	}
}


**/
