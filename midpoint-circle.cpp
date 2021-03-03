#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int xc, yc, r;

void Plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + xc, y + yc);
    glEnd();
}

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

void MidPointCircle()
{
    int x = 0;
    int y = r;
    float decision = 5 / 4 - r;
    Plot(x, y);

    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            decision += 2 * (x - y) + 1;
        }
        Plot(x, y);
        Plot(x, -y);
        Plot(-x, y);
        Plot(-x, -y);
        Plot(y, x);
        Plot(-y, x);
        Plot(y, -x);
        Plot(-y, -x);
    }
}

void DrawCircle(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);

    MidPointCircle();

    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter center and radius of the circle to be drawn:\n");
    printf("\n************************************");
    printf("\nEnter Center( xc , yc):\n");
    scanf("%d%d", &xc, &yc);
    printf("\n************************************");
    printf("\nEnter Radius:\n");
    scanf("%d", &r);
    /* Initialise GLUT library */
    glutInit(&argc, argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    /* Create the window with title */
    glutCreateWindow("Midpoint Circle Algorithm");
    /* Initialize drawing colors */
    Init();
    /* Call the displaying function */
    glutDisplayFunc(DrawCircle);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}