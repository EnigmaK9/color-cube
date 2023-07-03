#include <GL/glew.h>
#include <GL/freeglut.h>

GLfloat angle = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);

    glRotatef(angle, 1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();

    glutSwapBuffers();
}

void update(int value)
{
    angle += 1.0f;

    if (angle > 360)
        angle -= 360;

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

int main(int argc, char** argv)
{
    glutInitContextVersion(3, 3);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Cube");

    glewInit(); // Inicializar GLEW

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutTimerFunc(10, update, 0);

    glutMainLoop();

    return 0;
}

