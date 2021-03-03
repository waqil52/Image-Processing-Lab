#include <iostream>
#include <math.h>
#include <GL/glut.h>

// Center of the cicle = (320, 240)
int xc = 320, yc = 240, radius;

// Plot eight points using circle's symmetrical property
void PlotPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc - y, yc - x);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - y, yc + x);
    glEnd();
}

void BresenhamCircle(int r)
{
    int x = 0, y = r;
    float pk = (5.0 / 4.0) - r;

    /* Plot the points */
    /* Plot the first point */
    PlotPoint(x, y);
    int k;
    /* Find all vertices till x=y */
    while (x < y)
    {
        x = x + 1;
        if (pk < 0)
            pk = pk + 2 * x + 1;
        else
        {
            y = y - 1;
            pk = pk + 2 * (x - y) + 1;
        }
        PlotPoint(x, y);
    }
    glFlush();
}

void DrawCircle()
{
    /* Clears buffers to preset values */
    glClear(GL_COLOR_BUFFER_BIT);

    BresenhamCircle(radius);
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
    printf("Enter center and radius of the circle to be drawn:\n");
    printf("\n************************************");
    printf("\nEnter Center( xc , yc):\n");
    scanf("%d%d", &xc, &yc);
    printf("\n************************************");
    printf("\nEnter Radius:\n");
    scanf("%d", &radius);

    /* Initialise GLUT library */
    glutInit(&argc, argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    /* Create the window  */
    glutCreateWindow("Cohen-Sutherland Line Clipping Algorithm");
    /* Initialize drawing colors */
    Init();
    /* Call the displaying function */
    glutDisplayFunc(DrawCircle);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}
