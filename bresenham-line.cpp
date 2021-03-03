#include <iostream>
#include "GL/glut.h"
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>

using namespace std;
float x00, y01, x10, y11;
void DrawPoint()
{
    float x1 = x00, y1 = y01, x2 = x10, y2 = y11;
    float M, p, dx, dy, x, y, t;
    glClear(GL_COLOR_BUFFER_BIT);

    if ((x2 - x1) == 0)
        M = (y2 - y1);
    else
        M = (y2 - y1) / (x2 - x1);

    if (fabs(M) < 1)
    {
        if (x1 > x2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y1;
            y1 = y2;
            y2 = t;
        }

        dx = fabs(x2 - x1);
        dy = fabs(y2 - y1);

        p = 2 * dy - dx;

        x = x1;
        y = y1;

        glBegin(GL_POINTS);
        while (x <= x2)
        {
            glVertex2f(x, y);
            x = x + 1;

            if (p >= 0)
            {
                if (M < 1)
                    y = y + 1;
                else
                    y = y - 1;
                p = p + 2 * dy - 2 * dx;
            }
            else
            {
                y = y;
                p = p + 2 * dy;
            }
        }
        glEnd();
    }

    if (fabs(M) >= 1)
    {
        if (y1 > y2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y1;
            y1 = y2;
            y2 = t;
        }

        dx = fabs(x2 - x1);
        dy = fabs(y2 - y1);

        p = 2 * dx - dy;

        x = x1;
        y = y1;

        glBegin(GL_POINTS);
        while (y <= y2)
        {
            glVertex2f(x, y);
            y = y + 1;

            if (p >= 0)
            {
                if (M >= 1)
                    x = x + 1;
                else
                    x = x - 1;
                p = p + 2 * dx - 2 * dy;
            }
            else
            {
                x = x;
                p = p + 2 * dx;
            }
        }
        glEnd();
    }
    glFlush();
}
void InitDispaly()
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int args, char *argV[])
{
    printf("Enter two end points of the line to be drawn:\n");
    printf("\n************************************");
    printf("\nEnter Point1( X1 , Y1):\n");
    scanf("%f%f", &x00, &y01);
    printf("\n************************************");
    printf("\nEnter Point2( X2 , Y2):\n");
    scanf("%f%f", &x10, &y11);

    glutInit(&args, argV);

    glutInitWindowPosition(300, 50);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Bresenham Line Drawing");
    InitDispaly();

    glutDisplayFunc(DrawPoint);
    glutMainLoop();

    return 0;
}