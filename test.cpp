#include <string>
#include <GL/gl.h>
#include <GL/glut.h>

static void displayFunc(void){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glutSwapBuffers();
}

int main(int argc,char **argv){ 
std::string nimportequoi;

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

if(glutCreateWindow("") == 0) return 1;

glutDisplayFunc(displayFunc);
glutMainLoop();
return 0;
}
