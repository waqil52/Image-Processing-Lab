#include <iostream>
#include <math.h>
#include <GL/glut.h>

double X1, Y1, X2, Y2;

float RoundValue(float v)
{
    return floor(v + 0.5);
}
void LineDDA(void)
{
    double dx = (X2 - X1);
    double dy = (Y2 - Y1);
    double steps;
    float xInc, yInc, x = X1, y = Y1;

    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    xInc = dx / (float)steps;
    yInc = dy / (float)steps;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);

    glVertex2d(x, y);
    int k;

    for (k = 0; k < steps; k++)
    {
        x += xInc;
        y += yInc;

        glVertex2d(RoundValue(x), RoundValue(y));
    }
    glEnd();

    glFlush();
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

int main(int argc, char **argv)
{
    printf("Enter two end points of the line to be drawn:\n");
    printf("\n************************************");
    printf("\nEnter Point1( X1 , Y1):\n");
    scanf("%lf%lf", &X1, &Y1);
    printf("\n************************************");
    printf("\nEnter Point2( X2 , Y2):\n");
    scanf("%lf%lf", &X2, &Y2);

    /* Initialise GLUT library */
    glutInit(&argc, argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    /* Create the window */
    glutCreateWindow("DDA Line Drawing");
    /* Initialize drawing colors */
    Init();
    /* Call the displaying function */
    glutDisplayFunc(LineDDA);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}