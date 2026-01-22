#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1416

bool isNight = false;

// Draw circle for tree leafs
void drawCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        float x = r * cosf(angle);
        float y = r * sinf(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

// Draw triangle for tree leafs
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

//Basic Element Codes
void placeForSM(double r, double g, double b) {
    glColor3f(r,g,b); 
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(40, 0);
    glVertex2f(40, 20);
    glVertex2f(0, 20);
    glEnd();
}

void placeForForest(double r, double g, double b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(60, 0);
    glVertex2f(100, 0);
    glVertex2f(100, 20);
    glVertex2f(60, 20);
    glEnd();
}

void drawRoads() {
   
    //vertical road
    glColor3f(0.5f, 0.5f, 0.5f);   
    glBegin(GL_QUADS);
    glVertex2f(60, 0);
    glVertex2f(60, 20);
    glVertex2f(40, 20);
    glVertex2f(40, 0);
    glEnd();

    //horizontal road
    glBegin(GL_QUADS);
    glVertex2f(0, 20);
    glVertex2f(100, 20);
    glVertex2f(100, 45);
    glVertex2f(0, 45);
    glEnd();

    //road Horizontal divider
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 32);
    glVertex2f(100, 32);
    glVertex2f(100, 34);
    glVertex2f(0, 34);
    glEnd();

    //road verticla divider
    glBegin(GL_QUADS);
    glVertex2f(49, 0);
    glVertex2f(51, 0);
    glVertex2f(51, 20);
    glVertex2f(49, 20);
    glEnd();

    //upeer road sign
    for (int x = 10; x <= 100; x += 20) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x, 38);//10,38
        glVertex2f(x+10, 38);//20,38
        glVertex2f(x+10, 40);//20,40
        glVertex2f(x, 40);//10,40
        glEnd();

    }

    //lower road sign
    for (int x = 0; x <= 100; x += 20) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x, 26);//0,26
        glVertex2f(x + 10, 26);//10,28
        glVertex2f(x + 10, 28);//10,28
        glVertex2f(x, 28);//0,28
        glEnd();

    }

}

void roadBorder() {
    
    //left side Horizontal border for SM
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 20);
    glVertex2f(40, 20);
    glVertex2f(40, 22);
    glVertex2f(0, 22);
    glEnd();

    for (int x = 0; x < 40; x += 4) {
       
        glColor3f(0.647f, 0.165f, 0.165f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, 20);
        glVertex2f(x+4, 20);
        glVertex2f(x+4, 22);
        glVertex2f(x, 22);
        glEnd();
    }

    //Right side Horizontal border for forest
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(60, 20);
    glVertex2f(100, 20);
    glVertex2f(100, 22);
    glVertex2f(60, 22);
    glEnd();

    for (int x = 60; x < 100; x += 4) {

        glColor3f(0.647f, 0.165f, 0.165f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, 20);
        glVertex2f(x + 4, 20);
        glVertex2f(x + 4, 22);
        glVertex2f(x, 22);
        glEnd();
    }

    //left side Birtical border for SM
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(38, 0);
    glVertex2f(40, 0);
    glVertex2f(40, 20);
    glVertex2f(38, 20);
    glEnd();

    for (int y = 0; y < 20; y += 4) {

        glColor3f(0.647f, 0.165f, 0.165f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(38, y);//38,0
        glVertex2f(40, y);//40,0
        glVertex2f(40, y+4);//40,4
        glVertex2f(38, y+4);//38,4
        glEnd();
    }

    //Righ side Birtical border for Forest
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(60, 0);
    glVertex2f(62, 0);
    glVertex2f(62, 20);
    glVertex2f(60, 20);
    glEnd();

    for (int y = 0; y < 20; y += 4) {

        glColor3f(0.647f, 0.165f, 0.165f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(60, y);//60,0
        glVertex2f(62, y);//62,0
        glVertex2f(62, y + 4);//62,4
        glVertex2f(60, y + 4);//60,4
        glEnd();
    }

}

void drawRailRoad() {

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0, 44);
    glVertex2f(100, 44);
    glVertex2f(100, 50);
    glVertex2f(0, 50);
    glEnd();
}

void drawRailPath() {

    for (float x = 0.0f; x < 100.0f; x += 2.0f) {

        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.3f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, 46.0f);//2,46
        glVertex2f(x + 2.0f, 46.0f);//4,46
        glVertex2f(x + 2.0f, 48.0f);//4,48
        glVertex2f(x, 48.0f);//2,48
        glEnd();

    }
}

void drawSky(double r, double g, double b) {
    
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(0, 50);
    glVertex2f(100, 50);
    glVertex2f(100, 80);
    glVertex2f(0, 80);
    glEnd();
}

//Trees code
void drawTree(float trunkX, float trunkY, float X1, float Y1) {

    // Draw trunk
    glColor3f(0.55f, 0.27f, 0.07f); // Brown
    glBegin(GL_POLYGON);
    glVertex2f(trunkX, trunkY);//10, 50
    glVertex2f(trunkX + 3.0f, trunkY);//13, 50
    glVertex2f(X1 + 1.0f, Y1);//12,63
    glVertex2f(X1, Y1);//11,63
    glEnd();

    // Draw leaves as 3 circles
    glColor3f(0.0f, 0.6f, 0.0f); // Green
    drawCircle(X1 - 4.0f, Y1, 4.0f, 100);         // Left leaf
    drawCircle(X1 + 5.0f, Y1, 4.0f, 100);         // Right leaf
    drawCircle(X1 + 0.5f, Y1 + 3.0f, 4.0f, 100);    // Top leaf
}

void drawTree(float trunkX, float trunkY, double r, double g, double b) {
    // Trunk: width = 1, height = 6 (from 50 to 56)
    glColor3f(0.55f, 0.27f, 0.07f); // Brown
    glBegin(GL_QUADS);
    glVertex2f(trunkX, trunkY);
    glVertex2f(trunkX + 1.0f, trunkY);
    glVertex2f(trunkX + 1.0f, trunkY + 6.0f);
    glVertex2f(trunkX, trunkY + 6.0f);
    glEnd();

    glColor3f(r,g,b);

    // Triangle 1: relative to trunk
    drawTriangle(trunkX - 1.0f, trunkY + 3.0f,
        trunkX + 2.0f, trunkY + 3.0f,
        trunkX + 0.5f, trunkY + 15.0f);

    // Triangle 2
    drawTriangle(trunkX - 2.0f, trunkY + 4.0f,
        trunkX + 3.0f, trunkY + 4.0f,
        trunkX + 0.5f, trunkY + 12.0f);

    // Triangle 3
    drawTriangle(trunkX - 3.0f, trunkY + 5.0f,
        trunkX + 4.0f, trunkY + 5.0f,
        trunkX + 0.5f, trunkY + 9.0f);
}


//Buildings codes
void drawBuildingBody(double x1, double y1, double stepX, double stepY, double r, double g, double b) {

    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x1+stepX, y1);
    glVertex2f(x1+stepX, y1+stepY);
    glVertex2f(x1, y1 + stepY);
    glEnd();

    glLineWidth(2.0f);

    glColor3f(r + 0.15, g + 0.20, b - 0.10);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x1 + stepX, y1);
    glVertex2f(x1 + stepX, y1 + stepY);
    glVertex2f(x1, y1 + stepY);
    glEnd();

    glLineWidth(2.0f);

}

void deawBuildingSideBody(double x1, double y1, double stepX, double stepY, double r, double g, double b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x1 + stepX, y1);
    glVertex2f(x1 + stepX, y1 + stepY);
    glVertex2f(x1, y1 + stepY - 1);
    glEnd();

    glColor3f(r + 0.15, g + 0.20, b - 0.10);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x1 + stepX, y1);
    glVertex2f(x1 + stepX, y1 + stepY);
    glVertex2f(x1, y1 + stepY - 1);
    glEnd();

}

void drawBuildingTop(double x1, double y1, double stepX, double stepY, double r, double g, double b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x1 + stepX, y1);
    glVertex2f(x1 + stepX, y1 + stepY);
    glVertex2f(x1, y1 + stepY);
    glEnd();

    glColor3f(r + 0.15, g + 0.20, b - 0.10);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x1 + stepX, y1);
    glVertex2f(x1 + stepX, y1 + stepY);
    glVertex2f(x1, y1 + stepY);
    glEnd();
}

void deawSideBuildingTop(double x1, double y1, double stepX, double stepY, double r, double g, double b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);//31,74
    glVertex2f(x1 + stepX, y1 + 0.8);//35,75
    glVertex2f(x1 + stepX, y1 + stepY);//35,77
    glVertex2f(x1, y1 + stepY - 1);//31,76
    glEnd();

    glColor3f(r + 0.15, g + 0.20, b - 0.10);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x1 + stepX, y1+0.8);
    glVertex2f(x1 + stepX, y1 + stepY);
    glVertex2f(x1, y1 + stepY - 1);
    glEnd();

}

void drawWindow(double x1, double y1, double maxX, double maxY, double r, double g, double b) {

    for (int x = x1; x < maxX; x += 4) {
        
        for (int y = y1; y < maxY; y += 4) {
            glColor3f(r, g, b);
            glBegin(GL_QUADS);
            glVertex2f(x, y);//20,70
            glVertex2f(x + 2, y);//22,70
            glVertex2f(x + 2, y + 2);//22, 72
            glVertex2f(x, y + 2);//20,72
            glEnd();

            glColor3f(r + 0.15, g + 0.20, b - 0.10);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);//20,70
            glVertex2f(x + 2, y);//22,70
            glVertex2f(x + 2, y + 2);//22, 72
            glVertex2f(x, y + 2);//20,72
            glEnd();
        }
    }

}

void drawSideWindow(double x1, double y1, double maxX, double maxY, double r, double g, double b) {

    for (int x = x1; x < maxX; x += 4) {

        for (int y = y1; y < maxY; y += 4) {
            glColor3f(r, g, b);
            glBegin(GL_QUADS);
            glVertex2f(x, y);//33,54
            glVertex2f(x + 2, y+1);//35,55
            glVertex2f(x + 2, y + 3);//35, 56
            glVertex2f(x, y + 2);//35,55
            glEnd();

            glColor3f(r + 0.15, g + 0.20, b - 0.10);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);//33,54
            glVertex2f(x + 2, y + 1);//35,55
            glVertex2f(x + 2, y + 3);//35, 56
            glVertex2f(x, y + 2);//35,55
            glEnd();
        }
    }

}

void drawBuildingDoor(double x1, double y1, double maxX, double maxY, double r, double g, double b) {
    for (int x = x1; x < maxX; x += 2) {

        for (int y = y1; y < maxY; y += 2) {
            glColor3f(r, g, b);
            glBegin(GL_QUADS);
            glVertex2f(x, y);//20,70
            glVertex2f(x + 2, y);//22,70
            glVertex2f(x + 2, y + 3);//22, 72
            glVertex2f(x, y + 3);//20,72
            glEnd();

            glColor3f(r + 0.15, g + 0.20, b - 0.10);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);//20,70
            glVertex2f(x + 2, y);//22,70
            glVertex2f(x + 2, y + 3);//22, 72
            glVertex2f(x, y + 3);//20,72
            glEnd();
        }
    }
}


//------All sky element-------------
void drawStars() {
    glColor3f(1.0f, 1.0f, 1.0f); // White stars
    srand(42); 

    for (int i = 0; i < 100; i++) {
        float x = rand() % 100;
        float y = 60 + rand() % 40;
        drawCircle(x, y, 0.2, 100);
    }
}

void drawSun(float x, float y, float radius) {
    // Main sun body
    glColor3f(1.0f, 0.843f, 0.0f);
    drawCircle(x, y, radius, 100);

    // Sun glow effect 
    glColor4f(1.0f, 0.843f, 0.0f, 0.3f);
    drawCircle(x, y, radius * 1.5f, 100);
}

void drawCrescentMoon(float x, float y, float radius) {
    // Full moon base (bright)
    glColor3f(1.0f, 1.0f, 0.8f);  // pale yellow
    drawCircle(x, y, radius, 100);

    // Overlapping circle to form crescent
    glColor3f(0.05f, 0.05f, 0.2f); // night sky color (to "cut" moon)
    drawCircle(x + radius * 0.2f, y + radius * 0.1f, radius * 0.85f, 100);
}

//clouds global variable
double cloudX1 = 10;
double cloudX2 = 80;
double cloudX3 = 50;

void drawCloud(float x, float y, float scale, float r, float g, float b) {
    glColor3f(r, g, b); // Set cloud color

    drawCircle(x, y, 4.0f * scale, 100);
    drawCircle(x + 3.0f * scale, y + 1.0f * scale, 4.5f * scale, 100);
    drawCircle(x + 6.0f * scale, y, 4.0f * scale, 100);
    drawCircle(x + 3.0f * scale, y - 1.5f * scale, 4.0f * scale, 100);
}

void updateClouds(int value) {
    cloudX1 += 0.2;
    cloudX2 -= 0.4;
    cloudX3 += 0.3;

    // Reset positions further left so clouds enter smoothly
    if (cloudX1 > 110.0f) cloudX1 = -30.0f;
    if (cloudX2 < -20.0f) cloudX2 = +120.0f;
    if (cloudX3 > 110.0f) cloudX3 = -35.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateClouds, 0);
}


//Plans global variable
float planeX = -20.0f;
float planeSpeed = 0.2f;

float planeX2 = 120.0f;
float planeSpeed2 = 0.4f;

void drawPlane() {
    glPushMatrix();
    glTranslatef(planeX, 73.0f, 0.0f); // Bottom Y = 73
    glScalef(0.4, 0.4, 0);

    // --- MAIN BODY  ---

    // Fuselage - White
    glColor3f(1.0f, 1.0f, 1.0f); // Pure white
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(10.0f, 2.0f);
    glVertex2f(0.0f, 2.0f);
    glEnd();

    // Blue cheat line 
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 1.8f);
    glVertex2f(10.0f, 1.8f);
    glVertex2f(10.0f, 2.0f);
    glVertex2f(0.0f, 2.0f);
    glEnd();

    // Tail - Blue with red tip
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 2.0f);
    glVertex2f(2.0f, 2.0f);
    glVertex2f(1.0f, 4.0f);
    glVertex2f(0.0f, 4.0f);
    glEnd();

    // Tail tip - Red
    glColor3f(0.9f, 0.1f, 0.1f); // Red tip
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 3.5f);
    glVertex2f(0.5f, 3.5f);
    glVertex2f(0.25f, 4.0f);
    glEnd();

    // Tail logo area
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5f, 2.5f);
    glVertex2f(1.0f, 2.5f);
    glVertex2f(0.75f, 3.0f);
    glEnd();

    // Nose - Gray with blue tip
    glColor3f(0.7f, 0.7f, 0.7f); // Gray nose
    glBegin(GL_TRIANGLES);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(12.0f, 1.0f);
    glVertex2f(10.0f, 2.0f);
    glEnd();

    // Nose tip - Blue
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_TRIANGLES);
    glVertex2f(11.0f, 0.8f);
    glVertex2f(11.5f, 1.0f);
    glVertex2f(11.0f, 1.2f);
    glEnd();

    // Cockpit windows - Black
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(9.2f, 1.0f);
    glVertex2f(9.8f, 1.0f);
    glVertex2f(9.8f, 1.6f);
    glVertex2f(9.2f, 1.6f);
    glEnd();

    // Engine nacelles (under wings)
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray engines
    // Left engine
    glBegin(GL_POLYGON);
    glVertex2f(4.5f, -0.5f);
    glVertex2f(6.5f, -0.5f);
    glVertex2f(6.5f, 0.0f);
    glVertex2f(4.5f, 0.0f);
    glEnd();

    // Right engine
    glBegin(GL_POLYGON);
    glVertex2f(4.5f, 2.0f);
    glVertex2f(6.5f, 2.0f);
    glVertex2f(6.5f, 2.5f);
    glVertex2f(4.5f, 2.5f);
    glEnd();

    // Engine details - Silver rings
    glColor3f(0.8f, 0.8f, 0.9f); // Silver
    // Bottom engine ring
    glBegin(GL_POLYGON);
    glVertex2f(4.7f, -0.5f);
    glVertex2f(6.3f, -0.5f);
    glVertex2f(6.3f, -0.4f);
    glVertex2f(4.7f, -0.4f);
    glEnd();

    // Top engine ring
    glBegin(GL_POLYGON);
    glVertex2f(4.7f, 2.5f);
    glVertex2f(6.3f, 2.5f);
    glVertex2f(6.3f, 2.4f);
    glVertex2f(4.7f, 2.4f);
    glEnd();

    // Bottom Wing - Blue with white stripe
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_QUADS);
    glVertex2f(5.0f, 0.0f);
    glVertex2f(4.0f, -3.0f);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(7.0f, 0.0f);
    glEnd();

    // Bottom wing stripe - White
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(5.2f, -1.0f);
    glVertex2f(4.8f, -2.0f);
    glVertex2f(5.2f, -2.0f);
    glVertex2f(5.8f, -1.0f);
    glEnd();

    // Top Wing - Blue with white stripe
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_QUADS);
    glVertex2f(5.0f, 2.0f);
    glVertex2f(3.0f, 4.0f);
    glVertex2f(4.0f, 4.0f);
    glVertex2f(6.0f, 2.0f);
    glEnd();

    // Top wing stripe - White
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4.8f, 3.0f);
    glVertex2f(3.8f, 3.8f);
    glVertex2f(4.2f, 3.8f);
    glVertex2f(5.2f, 3.0f);
    glEnd();

    // Winglets (wing tips) - Blue
    // Bottom winglet
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_TRIANGLES);
    glVertex2f(4.0f, -3.0f);
    glVertex2f(3.5f, -3.5f);
    glVertex2f(4.0f, -3.5f);
    glEnd();

    // Top winglet
    glBegin(GL_TRIANGLES);
    glVertex2f(3.0f, 4.0f);
    glVertex2f(2.5f, 4.5f);
    glVertex2f(3.0f, 4.5f);
    glEnd();

    // Windows 
    glColor3f(0.2f, 0.5f, 0.8f); 

    // Window frames
    glColor3f(0.1f, 0.1f, 0.1f); // Black frames
    float windowSpacing = 1.5f;

    for (int i = 0; i < 6; i++) {
        float xPos = 2.0f + i * windowSpacing;
        if (xPos < 8.5f) { 
            glBegin(GL_LINE_LOOP);
            glVertex2f(xPos, 0.5f);
            glVertex2f(xPos + 0.8f, 0.5f);
            glVertex2f(xPos + 0.8f, 1.5f);
            glVertex2f(xPos, 1.5f);
            glEnd();

            // Window glass
            glColor3f(0.2f, 0.5f, 0.8f);
            glBegin(GL_POLYGON);
            glVertex2f(xPos + 0.1f, 0.6f);
            glVertex2f(xPos + 0.7f, 0.6f);
            glVertex2f(xPos + 0.7f, 1.4f);
            glVertex2f(xPos + 0.1f, 1.4f);
            glEnd();

            glColor3f(0.1f, 0.1f, 0.1f); // Reset to black for frames
        }
    }

    // Landing gear (simplified)
    glColor3f(0.4f, 0.4f, 0.4f); // Gray gear
    // Front gear
    glBegin(GL_POLYGON);
    glVertex2f(8.5f, -0.3f);
    glVertex2f(9.0f, -0.3f);
    glVertex2f(9.0f, 0.0f);
    glVertex2f(8.5f, 0.0f);
    glEnd();

    // Main gear (under wings)
    glBegin(GL_POLYGON);
    glVertex2f(4.5f, -0.3f);
    glVertex2f(5.5f, -0.3f);
    glVertex2f(5.5f, 0.0f);
    glVertex2f(4.5f, 0.0f);
    glEnd();

    // Logo/registration on fuselage
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_POLYGON);
    glVertex2f(3.0f, 1.9f);
    glVertex2f(4.0f, 1.9f);
    glVertex2f(4.0f, 1.95f);
    glVertex2f(3.0f, 1.95f);
    glEnd();

    glPopMatrix();
}

void drawPlane2(float axis_y) {
    glPushMatrix();
    glTranslatef(planeX2, axis_y, 0.0f);
    glScalef(-16.0, 30.0, 0);

    // Plane Body 
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214f, 0.2920f);
    glVertex2f(-0.8376f, 0.2912f);
    glVertex2f(-0.9320f, 0.2881f);
    glVertex2f(-0.9289f, 0.2556f);
    glVertex2f(-0.9041f, 0.2378f);
    glVertex2f(-0.8732f, 0.2278f);
    glVertex2f(-0.8453f, 0.2193f);
    glVertex2f(-0.8144f, 0.2108f);
    glVertex2f(-0.7842f, 0.2069f);
    glVertex2f(-0.7440f, 0.2077f);
    glVertex2f(-0.3897f, 0.2092f);
    glVertex2f(-0.3603f, 0.2131f);
    glEnd();

    // Plane Head
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.4214f, 0.2920f);
    glVertex2f(-0.4044f, 0.2893f);
    glVertex2f(-0.3832f, 0.2803f);
    glVertex2f(-0.3546f, 0.2671f);
    glVertex2f(-0.3381f, 0.2622f);
    glVertex2f(-0.3238f, 0.2573f);
    glVertex2f(-0.3177f, 0.2518f);
    glVertex2f(-0.3122f, 0.2463f);
    glVertex2f(-0.3100f, 0.2400f);
    glVertex2f(-0.3098f, 0.2357f);
    glVertex2f(-0.3100f, 0.2300f);
    glVertex2f(-0.3138f, 0.2259f);
    glVertex2f(-0.3204f, 0.2228f);
    glVertex2f(-0.3281f, 0.2191f);
    glVertex2f(-0.3379f, 0.2157f);
    glVertex2f(-0.3500f, 0.2128f);
    glVertex2f(-0.3603f, 0.2131f);
    glEnd();

    //Head Windows
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.3819f, 0.2759f);
    glVertex2f(-0.3881f, 0.2729f);
    glVertex2f(-0.3772f, 0.2609f);
    glVertex2f(-0.3705f, 0.2634f);
    glVertex2f(-0.3661f, 0.2658f);
    glVertex2f(-0.3609f, 0.2696f);
    glVertex2f(-0.3787f, 0.2782f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.3989f, 0.2687f);
    glVertex2f(-0.4099f, 0.2680f);
    glVertex2f(-0.4085f, 0.2627f);
    glVertex2f(-0.4031f, 0.2556f);
    glVertex2f(-0.3926f, 0.2562f);
    glVertex2f(-0.3805f, 0.2589f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4128f, 0.2603f);
    glVertex2f(-0.4148f, 0.2668f);
    glVertex2f(-0.4318f, 0.2669f);
    glVertex2f(-0.4323f, 0.2604f);
    glVertex2f(-0.4296f, 0.2515f);
    glVertex2f(-0.4078f, 0.2526f);
    glEnd();

    //  Front Door 
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4540f, 0.2650f);
    glVertex2f(-0.4772f, 0.2641f);
    glVertex2f(-0.4757f, 0.2159f);
    glVertex2f(-0.4517f, 0.2157f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.4540f, 0.2650f);
    glVertex2f(-0.4772f, 0.2641f);
    glVertex2f(-0.4757f, 0.2159f);
    glVertex2f(-0.4517f, 0.2157f);
    glEnd();

    // Door Handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4696f, 0.2426f);
    glVertex2f(-0.4728f, 0.2424f);
    glVertex2f(-0.4726f, 0.2379f);
    glVertex2f(-0.4693f, 0.2381f);
    glEnd();

    // Wings
    // Upper Wing
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.5498f, 0.2873f);
    glVertex2f(-0.6218f, 0.3771f);
    glVertex2f(-0.6566f, 0.3778f);
    glVertex2f(-0.6489f, 0.2916f);
    glEnd();

    // Lower Wing
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8513f, 0.1241f);
    glVertex2f(-0.8653f, 0.1246f);
    glVertex2f(-0.8522f, 0.1102f);
    glVertex2f(-0.8291f, 0.1111f);
    glVertex2f(-0.5056f, 0.2087f);
    glVertex2f(-0.7115f, 0.2078f);
    glEnd();

    // Lower Wing Back
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.8479f, 0.2812f);
    glVertex2f(-0.9293f, 0.2448f);
    glVertex2f(-0.9793f, 0.2453f);
    glVertex2f(-0.9320f, 0.2881f);
    glEnd();

    // Upper Wing Back
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8229f, 0.3036f);
    glVertex2f(-0.8415f, 0.3121f);
    glVertex2f(-0.8562f, 0.3283f);
    glVertex2f(-0.9057f, 0.3910f);
    glVertex2f(-0.9428f, 0.3894f);
    glVertex2f(-0.9320f, 0.2881f);
    glVertex2f(-0.7618f, 0.2914f);
    glVertex2f(-0.7935f, 0.2959f);
    glVertex2f(-0.8097f, 0.2989f);
    glEnd();

    //  Back Door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.7514f, 0.2701f);
    glVertex2f(-0.7756f, 0.2687f);
    glVertex2f(-0.7743f, 0.2286f);
    glVertex2f(-0.7496f, 0.2281f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.7514f, 0.2701f);
    glVertex2f(-0.7756f, 0.2687f);
    glVertex2f(-0.7743f, 0.2286f);
    glVertex2f(-0.7496f, 0.2281f);
    glEnd();

    // Back Door Handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7679f, 0.2511f);
    glVertex2f(-0.7709f, 0.2509f);
    glVertex2f(-0.7708f, 0.2474f);
    glVertex2f(-0.7677f, 0.2477f);
    glEnd();

    // ================= Windows =================
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);

    // Window 1
    glVertex2f(-0.7151f, 0.2669f);
    glVertex2f(-0.7145f, 0.2435f);
    glVertex2f(-0.6963f, 0.2435f);
    glVertex2f(-0.6976f, 0.2669f);

    // Window 2
    glVertex2f(-0.6820f, 0.2682f);
    glVertex2f(-0.6813f, 0.2441f);
    glVertex2f(-0.6638f, 0.2445f);
    glVertex2f(-0.6641f, 0.2678f);

    // Window 3
    glVertex2f(-0.6501f, 0.2669f);
    glVertex2f(-0.6492f, 0.2448f);
    glVertex2f(-0.6316f, 0.2445f);
    glVertex2f(-0.6329f, 0.2672f);

    // Window 4
    glVertex2f(-0.6196f, 0.2672f);
    glVertex2f(-0.6183f, 0.2451f);
    glVertex2f(-0.6014f, 0.2448f);
    glVertex2f(-0.6030f, 0.2669f);

    // Window 5
    glVertex2f(-0.5858f, 0.2662f);
    glVertex2f(-0.5852f, 0.2458f);
    glVertex2f(-0.5702f, 0.2454f);
    glVertex2f(-0.5712f, 0.2669f);

    // Window 6
    glVertex2f(-0.5533f, 0.2669f);
    glVertex2f(-0.5520f, 0.2454f);
    glVertex2f(-0.5371f, 0.2448f);
    glVertex2f(-0.5394f, 0.2669f);

    // Window 7
    glVertex2f(-0.5228f, 0.2665f);
    glVertex2f(-0.5208f, 0.2432f);
    glVertex2f(-0.5040f, 0.2435f);
    glVertex2f(-0.5056f, 0.2669f);

    glEnd();

    glPopMatrix();
}

void updatePlane(int value) {
    planeX += planeSpeed;
    if (planeX > 120.0f) planeX = -30.0f; // Reset if it goes off right side

    planeX2 -= planeSpeed2;
    if (planeX2 < -20.0f) planeX2 = 120.0f; // Reset if it goes off right side

    glutPostRedisplay();
    glutTimerFunc(30, updatePlane, 0);
}



//----all road elements----

//cars and bus global variable
float carX1 = -30.0f;   
float carSpeed1 = 0.5f;

float carX2 = 120.0f;    
float carSpeed2 = -0.4f; 

float carX3 = -40.0f;
float carSpeed3 = 0.6f;

float carX4 = 150.0f;
float carSpeed4 = -0.5f;

bool nightLight = false;


void drawRedCar() {
    glPushMatrix();
    glTranslatef(carX1, 26.0f, 0.0f); // Move car onto road
    glScalef(1.5f, 1.5f, 1.0f);

    //WHEELS
    drawCircle(-1.8f, -1.7f, 0.8f, 100);
    drawCircle(-3.8f, -1.7f, 0.8f, 100);
    drawCircle(-8.5f, -1.7f, 0.8f, 100);

    // HEADLIGHT (NIGHT ONLY)
    if (nightLight) {
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 200); 
        glVertex3f(4.5f, 0.5f, 0.0f);    
        glVertex3f(4.5f, -2.5f, 0.0f);  
        glVertex3f(-0.5f, -1.3f, 0.0f);  
        glVertex3f(-0.5f, -1.0f, 0.0f);
        glEnd();
    }

    // --- CAR BODY (RED PARTS) ---

    // Main chassis base
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(-9.2f, -1.95f, 0.0f);
    glVertex3f(-0.5f, -1.95f, 0.0f);
    glVertex3f(-0.5f, -0.8f, 0.0f);
    glVertex3f(-9.2f, -0.8f, 0.0f);
    glEnd();

    // Car roof
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-3.1f, 0.5f, 0.0f);
    glVertex3f(-9.2f, 0.5f, 0.0f);
    glVertex3f(-9.2f, 1.69f, 0.0f);
    glVertex3f(-3.1f, 1.69f, 0.0f);
    glEnd();

    // Center pillar (between middle and rear windows)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-6.05f, 0.5f, 0.0f);
    glVertex3f(-6.05f, -0.85f, 0.0f);
    glVertex3f(-6.0f, -0.85f, 0.0f);
    glVertex3f(-6.0f, 0.5f, 0.0f);
    glEnd();

    // Front pillar (between front and middle windows)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-3.1f, 0.5f, 0.0f);
    glVertex3f(-3.15f, 0.5f, 0.0f);
    glVertex3f(-3.15f, -1.95f, 0.0f);
    glVertex3f(-3.1f, -1.95f, 0.0f);
    glEnd();

    // Rear pillar
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-9.2f, 0.5f, 0.0f);
    glVertex3f(-9.15f, 0.5f, 0.0f);
    glVertex3f(-9.15f, -1.95f, 0.0f);
    glVertex3f(-9.2f, -1.95f, 0.0f);
    glEnd();

    // --- WINDOWS (LIGHT BLUE) ---

    // Front windshield (triangle)
    glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.8f, 1.0f); // Light blue
    glVertex3f(-3.1f, 0.9f, 0.0f);
    glVertex3f(-3.1f, -0.85f, 0.0f);
    glVertex3f(-0.5f, -0.85f, 0.0f);
    glEnd();

    // Middle side window
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex3f(-6.0f, 0.5f, 0.0f);
    glVertex3f(-3.15f, 0.5f, 0.0f);
    glVertex3f(-3.15f, -0.85f, 0.0f);
    glVertex3f(-6.0f, -0.85f, 0.0f);
    glEnd();

    // Rear side window
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex3f(-6.05f, 0.5f, 0.0f);
    glVertex3f(-9.15f, 0.5f, 0.0f);
    glVertex3f(-9.15f, -0.85f, 0.0f);
    glVertex3f(-6.05f, -0.85f, 0.0f);
    glEnd();

    glPopMatrix();
}

void drawMiniCar() {
    glPushMatrix();
    glTranslatef(carX4, 40.0f, 0.0f);
    glScalef(-7.5f, 7.5f, 1.0f);  // Flipped horizontally (-7.5) and scaled up

    //WHEELS
    float wheelY = -0.52f;
    float wheelRadius = 0.1f;
    drawCircle(0.1f, wheelY, wheelRadius, 100);   // Front wheel
    drawCircle(-0.4f, wheelY, wheelRadius, 100);  // Rear wheel

    //HEADLIGHT (NIGHT ONLY)
    if (nightLight) {
        glBegin(GL_POLYGON);
        glColor3ub(192, 192, 192);
        glVertex2f(0.3f, -0.45f);
        glVertex2f(0.8f, -0.6f);
        glVertex2f(0.8f, -0.1f);
        glVertex2f(0.3f, -0.3f);
        glEnd();
    }

    //CAR BODY (RED)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, -0.2f);   
    glVertex2f(0.3f, -0.5f);   
    glVertex2f(-0.6f, -0.5f);  
    glVertex2f(-0.6f, -0.2f);  
    glEnd();

    // --- WINDOW FRAMES (BLACK OUTLINE) ---

    // Front window frame
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f); 
    glVertex2f(0.0f, 0.02f);
    glVertex2f(-0.35f, 0.02f);
    glVertex2f(-0.35f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glEnd();

    // Windshield frame
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);  
    glVertex2f(0.15f, -0.2f);
    glVertex2f(0.0f, 0.02f);
    glVertex2f(-0.35f, 0.02f);
    glVertex2f(-0.45f, -0.2f);
    glEnd();

    // --- WINDOWS (LIGHT BLUE) ---
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.8f, 1.0f);  
    glVertex2f(0.15f, -0.2f);   
    glVertex2f(0.0f, 0.02f);    
    glVertex2f(-0.35f, 0.02f);   
    glVertex2f(-0.45f, -0.2f);
    glEnd();

    // Front bumper highlight
    glBegin(GL_LINES);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.3f, -0.25f);
    glVertex2f(0.3f, -0.45f);
    glEnd();

    // Wheel hubs
    glPushMatrix();
    glTranslatef(0.1f, -0.52f, 0.0f);
    glColor3f(0.3f, 0.3f, 0.3f); 
    drawCircle(0.0f, 0.0f, 0.03f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4f, -0.52f, 0.0f);
    glColor3f(0.3f, 0.3f, 0.3f);
    drawCircle(0.0f, 0.0f, 0.03f, 20);
    glPopMatrix();

    glPopMatrix();
}

void drawMegendaBus() {
    glPushMatrix();
    glTranslatef(carX2, 45.0f, 0.0f);
    glScalef(-1.5f, 1.5f, 1.0f);

    // WHEELS
    float wheelY = -2.0f;
    float wheelRadius = 0.8f;

    // Bus typically has 4 or 6 wheels - here's 4
    drawCircle(-2.0f, wheelY, wheelRadius, 100);  // Front wheel
    drawCircle(-5.0f, wheelY, wheelRadius, 100);  // Front-middle wheel
    drawCircle(-7.0f, wheelY, wheelRadius, 100);  // Rear-middle wheel  
    drawCircle(-10.0f, wheelY, wheelRadius, 100); // Rear wheel

    // HEADLIGHTS 
    if (nightLight) {
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 200);
        glVertex3f(3.0f, 0.0f, 0.0f);    
        glVertex3f(3.0f, -3.0f, 0.0f);   
        glVertex3f(-0.5f, -1.5f, 0.0f);  
        glVertex3f(-0.5f, 0.0f, 0.0f);   
        glEnd();
    }

    // --- MAIN BUS BODY ---
    glColor3f(0.5f, 0.0f, 0.5f); // Magenta

    // Lower body (below windows)
    glBegin(GL_POLYGON);
    glVertex3f(-12.0f, -2.0f, 0.0f);  
    glVertex3f(0.0f, -2.0f, 0.0f);    
    glVertex3f(0.0f, 0.5f, 0.0f);     
    glVertex3f(-12.0f, 0.5f, 0.0f);  
    glEnd();

    // Upper body/roof
    glBegin(GL_POLYGON);
    glVertex3f(-12.0f, 0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(0.0f, 3.0f, 0.0f);    
    glVertex3f(-12.0f, 3.0f, 0.0f);
    glEnd();

    // Front bumper
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f); 
    glVertex3f(0.0f, -2.5f, 0.0f);
    glVertex3f(0.5f, -2.5f, 0.0f);
    glVertex3f(0.5f, -2.0f, 0.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);
    glEnd();

    // --- WINDOWS ---
    glColor3f(0.7f, 0.9f, 1.0f); // Light blue windows

    // Front windshield
    glBegin(GL_POLYGON);
    glVertex3f(-1.0f, 2.5f, 0.0f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glEnd();

    // Side windows (multiple rectangular bus windows)
    // Window 1
    glBegin(GL_POLYGON);
    glVertex3f(-3.0f, 2.5f, 0.0f);
    glVertex3f(-1.5f, 2.5f, 0.0f);
    glVertex3f(-1.5f, 0.5f, 0.0f);
    glVertex3f(-3.0f, 0.5f, 0.0f);
    glEnd();

    // Window 2
    glBegin(GL_POLYGON);
    glVertex3f(-5.0f, 2.5f, 0.0f);
    glVertex3f(-3.5f, 2.5f, 0.0f);
    glVertex3f(-3.5f, 0.5f, 0.0f);
    glVertex3f(-5.0f, 0.5f, 0.0f);
    glEnd();

    // Window 3
    glBegin(GL_POLYGON);
    glVertex3f(-7.0f, 2.5f, 0.0f);
    glVertex3f(-5.5f, 2.5f, 0.0f);
    glVertex3f(-5.5f, 0.5f, 0.0f);
    glVertex3f(-7.0f, 0.5f, 0.0f);
    glEnd();

    // Window 4
    glBegin(GL_POLYGON);
    glVertex3f(-9.0f, 2.5f, 0.0f);
    glVertex3f(-7.5f, 2.5f, 0.0f);
    glVertex3f(-7.5f, 0.5f, 0.0f);
    glVertex3f(-9.0f, 0.5f, 0.0f);
    glEnd();

    // Window 5
    glBegin(GL_POLYGON);
    glVertex3f(-11.0f, 2.5f, 0.0f);
    glVertex3f(-9.5f, 2.5f, 0.0f);
    glVertex3f(-9.5f, 0.5f, 0.0f);
    glVertex3f(-11.0f, 0.5f, 0.0f);
    glEnd();

    // --- BUS DETAILS ---

    // Front grill
    glColor3f(0.2f, 0.2f, 0.2f); 
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, -0.5f, 0.0f);
    glVertex3f(-0.8f, -0.5f, 0.0f);
    glVertex3f(-0.8f, -1.5f, 0.0f);
    glVertex3f(0.0f, -1.5f, 0.0f);
    glEnd();


    // Side door (near front)
    glColor3f(0.6f, 0.6f, 0.6f); 
    glBegin(GL_POLYGON);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(-3.0f, 0.0f, 0.0f);
    glVertex3f(-3.0f, -2.0f, 0.0f);
    glVertex3f(-2.0f, -2.0f, 0.0f);
    glEnd();

    // Door handle
    glColor3f(0.3f, 0.3f, 0.3f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex3f(-2.5f, -1.0f, 0.0f);
    glVertex3f(-2.5f, -1.5f, 0.0f);
    glEnd();
    glLineWidth(1.0f);

    // Rear lights
    glColor3f(1.0f, 0.0f, 0.0f); 
    glBegin(GL_POLYGON);
    glVertex3f(-12.0f, 0.0f, 0.0f);
    glVertex3f(-12.5f, 0.0f, 0.0f);
    glVertex3f(-12.5f, -0.5f, 0.0f);
    glVertex3f(-12.0f, -0.5f, 0.0f);
    glEnd();

    // Rear light 2
    glBegin(GL_POLYGON);
    glVertex3f(-12.0f, -1.0f, 0.0f);
    glVertex3f(-12.5f, -1.0f, 0.0f);
    glVertex3f(-12.5f, -1.5f, 0.0f);
    glVertex3f(-12.0f, -1.5f, 0.0f);
    glEnd();

    glPopMatrix();
}

void drawBlueBus() {
    glPushMatrix();
    glTranslatef(carX3, 33.0f, 0.0f);
    glScalef(1.5f, 1.5f, 1.0f);

    // WHEELS
    float wheelY = -2.0f;
    float wheelRadius = 0.8f;

    // Bus wheels in left-to-right orientation
    drawCircle(2.0f, wheelY, wheelRadius, 100);   // Front wheel
    drawCircle(5.0f, wheelY, wheelRadius, 100);   // Front-middle wheel
    drawCircle(7.0f, wheelY, wheelRadius, 100);   // Rear-middle wheel  
    drawCircle(10.0f, wheelY, wheelRadius, 100);  // Rear wheel

    // --- MAIN BUS BODY (BLUE) ---
    glColor3f(0.0f, 0.0f, 0.8f);

    // Lower body
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, -2.0f, 0.0f);   
    glVertex3f(12.0f, -2.0f, 0.0f);  
    glVertex3f(12.0f, 0.5f, 0.0f);   
    glVertex3f(0.0f, 0.5f, 0.0f);   
    glEnd();

    // Upper body/roof
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(12.0f, 0.5f, 0.0f);
    glVertex3f(12.0f, 3.0f, 0.0f);
    glVertex3f(0.0f, 3.0f, 0.0f);
    glEnd();

    // Front bumper
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(12.0f, -2.5f, 0.0f);
    glVertex3f(12.5f, -2.5f, 0.0f);
    glVertex3f(12.5f, -2.0f, 0.0f);
    glVertex3f(12.0f, -2.0f, 0.0f);
    glEnd();

    // --- WINDOWS ---
    glColor3f(0.7f, 0.9f, 1.0f);

    // Front windshield 
    glBegin(GL_POLYGON);
    glVertex3f(11.0f, 2.5f, 0.0f);
    glVertex3f(12.0f, 2.5f, 0.0f);
    glVertex3f(12.0f, 0.5f, 0.0f);
    glVertex3f(11.0f, 0.5f, 0.0f);
    glEnd();

    // Side windows 
    // Window 1 (closest to front)
    glBegin(GL_POLYGON);
    glVertex3f(9.5f, 2.5f, 0.0f);
    glVertex3f(11.0f, 2.5f, 0.0f);
    glVertex3f(11.0f, 0.5f, 0.0f);
    glVertex3f(9.5f, 0.5f, 0.0f);
    glEnd();

    // Window 2
    glBegin(GL_POLYGON);
    glVertex3f(7.5f, 2.5f, 0.0f);
    glVertex3f(9.0f, 2.5f, 0.0f);
    glVertex3f(9.0f, 0.5f, 0.0f);
    glVertex3f(7.5f, 0.5f, 0.0f);
    glEnd();

    // Window 3
    glBegin(GL_POLYGON);
    glVertex3f(5.5f, 2.5f, 0.0f);
    glVertex3f(7.0f, 2.5f, 0.0f);
    glVertex3f(7.0f, 0.5f, 0.0f);
    glVertex3f(5.5f, 0.5f, 0.0f);
    glEnd();

    // Window 4
    glBegin(GL_POLYGON);
    glVertex3f(3.5f, 2.5f, 0.0f);
    glVertex3f(5.0f, 2.5f, 0.0f);
    glVertex3f(5.0f, 0.5f, 0.0f);
    glVertex3f(3.5f, 0.5f, 0.0f);
    glEnd();

    // Window 5 
    glBegin(GL_POLYGON);
    glVertex3f(1.5f, 2.5f, 0.0f);
    glVertex3f(3.0f, 2.5f, 0.0f);
    glVertex3f(3.0f, 0.5f, 0.0f);
    glVertex3f(1.5f, 0.5f, 0.0f);
    glEnd();

    // --- BUS DETAILS ---

    // Front grill 
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex3f(12.0f, -0.5f, 0.0f);
    glVertex3f(11.2f, -0.5f, 0.0f);
    glVertex3f(11.2f, -1.5f, 0.0f);
    glVertex3f(12.0f, -1.5f, 0.0f);
    glEnd();

    // HEADLIGHTS
    if (nightLight) {
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 200);
        glVertex3f(12.5f, -0.5f, 0.0f);  
        glVertex3f(12.5f, -1.5f, 0.0f);     
        glVertex3f(15.0f, -2.5f, 0.0f);     
        glVertex3f(15.0f, 0.5f, 0.0f);     
        glEnd();
    }

    // Side door 
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex3f(4.0f, 0.0f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.0f);
    glVertex3f(5.0f, -2.0f, 0.0f);   
    glVertex3f(4.0f, -2.0f, 0.0f);  
    glEnd();

    // Door handle
    glColor3f(0.3f, 0.3f, 0.3f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex3f(4.5f, -1.0f, 0.0f);   
    glVertex3f(4.5f, -1.5f, 0.0f);   
    glEnd();
    glLineWidth(1.0f);

    // Rear lights 
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 0.0f, 0.0f);    
    glVertex3f(-0.5f, 0.0f, 0.0f);   
    glVertex3f(-0.5f, -0.5f, 0.0f);  
    glVertex3f(0.0f, -0.5f, 0.0f);   
    glEnd();

    // Rear light 2
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, -1.0f, 0.0f);   
    glVertex3f(-0.5f, -1.0f, 0.0f);  
    glVertex3f(-0.5f, -1.5f, 0.0f);  
    glVertex3f(0.0f, -1.5f, 0.0f);   
    glEnd();

    glPopMatrix();
}

void updateCars(int value) {
    // Move first car right
    carX1 += carSpeed1;
    if (carX1 > 120.0f) carX1 = -30.0f; // Loop left to right

    // Move second car left
    carX2 += carSpeed2;
    if (carX2 < -30.0f) carX2 = 120.0f; // Loop right to left

    carX3 += carSpeed3;
    if (carX3 > 160.0f) carX3 = -40.0f; // Loop left to right

    carX4 += carSpeed4;
    if (carX4 < -50.0f) carX4 = 150.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateCars, 0);
}



//train global variable
float trainX = 240.0f;  //rigt to left
float trainSpeed = -0.15f * 2;

float trainX2 = -20.0f;   //left to right
float trainSpeed2 = 0.15f * 2;

void drawTrain(float x) {
    glPushMatrix();
    glTranslatef(x, 55.0f, 0.0f); // Set position on rail path
    glScalef(5.0f, 5.0f, 1.0f);   // Scale to fit the 2D world

    // --- LOCOMOTIVE ---

    // Main locomotive body - Dark Blue
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glColor3f(0.0f, 0.2f, 0.6f); // Dark blue
    glScalef(1.5, 0.8, 0.1);
    glutSolidCube(1.3);
    glPopMatrix();

    // Locomotive roof - Light Gray
    glPushMatrix();
    glTranslatef(0.28, -0.2, 0);
    glScalef(1.6, 1, 0.1);
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray
    glutSolidCube(0.8);
    glPopMatrix();

    // Front detail stripe - Yellow
    glPushMatrix();
    glTranslatef(0.8, -0.7, 0.05);
    glScalef(0.05, 0.3, 0.12);
    glColor3f(1.0f, 0.8f, 0.0f); // Yellow
    glutSolidCube(1.0);
    glPopMatrix();

    // Smoke pipe - Black
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black
    glTranslatef(-0.8, -0.28, 1);
    glScalef(0.9, 1.3, 0.01);
    glutSolidCube(0.35);
    glPopMatrix();

    // Top of smoke pipe - Dark Gray
    glPushMatrix();
    glTranslatef(-0.81, 0.06, 1);
    glScalef(1, 1, 0.01);
    glColor3f(0.4f, 0.4f, 0.4f); // Dark gray
    glRotatef(90, 1, 0, 0);
    glutSolidCone(0.26, 0.3, 20, 20);
    glPopMatrix();

    // Windows - Glass blue with black frame
    // Window 1
    glPushMatrix();
    glColor3f(0.6f, 0.8f, 1.0f); // Light blue glass
    glTranslatef(0, -0.12, 0.95);
    glScalef(0.4, 0.3, 0.05);
    glutSolidCube(1.0);

    // Window frame
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black frame
    glScalef(1.1, 1.1, 1.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Window 2
    glPushMatrix();
    glColor3f(0.6f, 0.8f, 1.0f); // Light blue glass
    glTranslatef(0.5, -0.12, 0.95);
    glScalef(0.4, 0.3, 0.05);
    glutSolidCube(1.0);

    // Window frame
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black frame
    glScalef(1.1, 1.1, 1.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Headlight - Yellow
    glPushMatrix();
    glTranslatef(0.8, -0.3, 0.05);
    glScalef(0.15, 0.15, 0.12);
    glColor3f(1.0f, 1.0f, 0.5f); // Bright yellow
    glutSolidSphere(1.0, 10, 10);
    glPopMatrix();

    // Wheels - Dark Gray with silver rims
    // Front wheel 1
    glPushMatrix();
    glTranslatef(0.5, -1.4, 1);
    // Rim
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.9f); // Silver
    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();
    // Tire
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray
    glutSolidTorus(0.1, 0.15, 20, 20);
    glPopMatrix();
    glPopMatrix();

    // Front wheel 2
    glPushMatrix();
    glTranslatef(-0.5, -1.4, 1);
    // Rim
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.9f); // Silver
    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();
    // Tire
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray
    glutSolidTorus(0.1, 0.15, 20, 20);
    glPopMatrix();
    glPopMatrix();

    // --- FIRST CARRIAGE ---

    // Connector - Black
    glPushMatrix();
    glTranslatef(1.1, -1.1, 0);
    glScalef(1, 3, 0.01);
    glColor3f(0.1f, 0.1f, 0.1f); // Black
    glutSolidCube(0.25);
    glPopMatrix();

    // Carriage body - Forest Green
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 0.2f); // Forest green
    glScalef(1.3, 0.75, 0.01);
    glTranslatef(1.65, -1.45, 0);
    glutSolidCube(1.5);
    glPopMatrix();

    // Carriage stripe - Yellow
    glPushMatrix();
    glTranslatef(2.2, -0.9, 0.05);
    glScalef(1.2, 0.05, 0.12);
    glColor3f(1.0f, 0.8f, 0.0f); // Yellow
    glutSolidCube(1.0);
    glPopMatrix();

    // Carriage windows
    glPushMatrix();
    glTranslatef(0.05, 0, 0);
    for (float wx = 1.5f; wx <= 2.5f; wx += 0.5f) {
        glPushMatrix();
        glTranslatef(wx, -0.9, 0.95);
        glScalef(0.4, 0.3, 0.05);
        // Glass
        glColor3f(0.6f, 0.8f, 1.0f); // Light blue glass
        glutSolidCube(1.0);

        // Frame
        glPushMatrix();
        glColor3f(0.1f, 0.1f, 0.1f); // Black frame
        glScalef(1.1, 1.1, 1.2);
        glutWireCube(1.0);
        glPopMatrix();
        glPopMatrix();
    }
    glPopMatrix();

    // Carriage wheels
    glPushMatrix();
    glTranslatef(1.5, -1.55, 1);
    glScalef(0.7, 0.7, 0.01);
    // Rim
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.9f); // Silver
    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();
    // Tire
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray
    glutSolidTorus(0.1, 0.15, 20, 20);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.6, -1.55, 1);
    glScalef(0.7, 0.7, 0.01);
    // Rim
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.9f); // Silver
    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();
    // Tire
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray
    glutSolidTorus(0.1, 0.15, 20, 20);
    glPopMatrix();
    glPopMatrix();

    // Carriage door - Red
    glPushMatrix();
    glTranslatef(1.8, -1.2, 0.05);
    glScalef(0.3, 0.5, 0.12);
    glColor3f(0.8f, 0.2f, 0.2f); // Red
    glutSolidCube(1.0);
    glPopMatrix();

    // --- SMOKE ---
    glPushMatrix();
    glTranslatef(-0.65, 0.2, 1);
    glScalef(1, 1, 0.01);
    glColor3f(0.7f, 0.7f, 0.7f); // Light gray smoke
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, 0.5, 1);
    glScalef(1.4, 1.4, 0.01);
    glColor3f(0.6f, 0.6f, 0.6f); // Medium gray smoke
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, 0.8, 1);
    glScalef(2, 2, 0.01);
    glColor3f(0.5f, 0.5f, 0.5f); // Dark gray smoke
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // Additional smoke puff
    glPushMatrix();
    glTranslatef(0.1, 1.0, 1);
    glScalef(1.8, 1.8, 0.01);
    glColor3f(0.4f, 0.4f, 0.4f); // Darker gray smoke
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();

    glPopMatrix();
}

void drawTrain2(float x) {
    glPushMatrix();
    glTranslatef(x, 55.0f, 0.0f); // Set position on rail path
    glScalef(-5.0f, 5.0f, 1.0f);   // Scale to fit the 2D world 

    // --- LOCOMOTIVE (MAROON COLOR SCHEME) ---

    // Main locomotive body - Maroon
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glColor3f(0.5f, 0.1f, 0.1f); // Maroon
    glScalef(1.5, 0.8, 0.1);
    glutSolidCube(1.3);
    glPopMatrix();

    // Locomotive roof - Cream
    glPushMatrix();
    glTranslatef(0.28, -0.2, 0);
    glScalef(1.6, 1, 0.1);
    glColor3f(0.95f, 0.95f, 0.85f); // Cream
    glutSolidCube(0.8);
    glPopMatrix();

    // Front detail stripe - Gold
    glPushMatrix();
    glTranslatef(0.8, -0.7, 0.05);
    glScalef(0.05, 0.3, 0.12);
    glColor3f(0.9f, 0.7f, 0.2f); // Gold
    glutSolidCube(1.0);
    glPopMatrix();

    // Smoke pipe - Charcoal
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Charcoal
    glTranslatef(-0.8, -0.28, 1);
    glScalef(0.9, 1.3, 0.01);
    glutSolidCube(0.35);
    glPopMatrix();

    // Top of smoke pipe - Steel
    glPushMatrix();
    glTranslatef(-0.81, 0.06, 1);
    glScalef(1, 1, 0.01);
    glColor3f(0.5f, 0.5f, 0.5f); // Steel
    glRotatef(90, 1, 0, 0);
    glutSolidCone(0.26, 0.3, 20, 20);
    glPopMatrix();

    // Windows - Tinted glass with chrome frame
    // Window 1
    glPushMatrix();
    glColor3f(0.4f, 0.6f, 0.7f); // Tinted blue glass
    glTranslatef(0, -0.12, 0.95);
    glScalef(0.4, 0.3, 0.05);
    glutSolidCube(1.0);

    // Window frame
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f); // Chrome frame
    glScalef(1.1, 1.1, 1.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Window 2
    glPushMatrix();
    glColor3f(0.4f, 0.6f, 0.7f); // Tinted blue glass
    glTranslatef(0.5, -0.12, 0.95);
    glScalef(0.4, 0.3, 0.05);
    glutSolidCube(1.0);

    // Window frame
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f); // Chrome frame
    glScalef(1.1, 1.1, 1.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Headlight - White
    glPushMatrix();
    glTranslatef(0.8, -0.3, 0.05);
    glScalef(0.15, 0.15, 0.12);
    glColor3f(1.0f, 1.0f, 0.9f); // White light
    glutSolidSphere(1.0, 10, 10);
    glPopMatrix();

    // Wheels - Black with chrome details
    // Front wheel 1
    glPushMatrix();
    glTranslatef(0.5, -1.4, 1);
    // Rim
    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f); // Bright chrome
    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();
    // Tire
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black
    glutSolidTorus(0.1, 0.15, 20, 20);
    glPopMatrix();
    // Hub
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f); // Steel hub
    glutSolidTorus(0.03, 0.08, 20, 20);
    glPopMatrix();
    glPopMatrix();

    // Front wheel 2
    glPushMatrix();
    glTranslatef(-0.5, -1.4, 1);
    // Rim
    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f); // Bright chrome
    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();
    // Tire
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black
    glutSolidTorus(0.1, 0.15, 20, 20);
    glPopMatrix();
    // Hub
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f); // Steel hub
    glutSolidTorus(0.03, 0.08, 20, 20);
    glPopMatrix();
    glPopMatrix();

    // --- FIRST CARRIAGE (BURGUNDY COLOR SCHEME) ---

    // Connector - Dark gray
    glPushMatrix();
    glTranslatef(1.1, -1.1, 0);
    glScalef(1, 3, 0.01);
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray
    glutSolidCube(0.25);
    glPopMatrix();

    // Carriage body - Burgundy
    glPushMatrix();
    glColor3f(0.4f, 0.1f, 0.2f); // Burgundy
    glScalef(1.3, 0.75, 0.01);
    glTranslatef(1.65, -1.45, 0);
    glutSolidCube(1.5);
    glPopMatrix();

    // Carriage stripe - Cream
    glPushMatrix();
    glTranslatef(2.2, -0.9, 0.05);
    glScalef(1.2, 0.05, 0.12);
    glColor3f(0.95f, 0.95f, 0.85f); // Cream
    glutSolidCube(1.0);
    glPopMatrix();

    // Carriage windows
    glPushMatrix();
    glTranslatef(0.05, 0, 0);
    for (float wx = 1.5f; wx <= 2.5f; wx += 0.5f) {
        glPushMatrix();
        glTranslatef(wx, -0.9, 0.95);
        glScalef(0.4, 0.3, 0.05);
        // Glass
        glColor3f(0.4f, 0.6f, 0.7f); // Tinted glass
        glutSolidCube(1.0);

        // Frame
        glPushMatrix();
        glColor3f(0.7f, 0.7f, 0.7f); // Chrome frame
        glScalef(1.1, 1.1, 1.2);
        glutWireCube(1.0);
        glPopMatrix();
        glPopMatrix();
    }
    glPopMatrix();

    // Carriage wheels
    glPushMatrix();
    glTranslatef(1.5, -1.55, 1);
    glScalef(0.7, 0.7, 0.01);
    // Rim
    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f); // Bright chrome
    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();
    // Tire
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black
    glutSolidTorus(0.1, 0.15, 20, 20);
    glPopMatrix();
    // Hub
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f); // Steel hub
    glutSolidTorus(0.03, 0.08, 20, 20);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.6, -1.55, 1);
    glScalef(0.7, 0.7, 0.01);
    // Rim
    glPushMatrix();
    glColor3f(0.9f, 0.9f, 0.9f); // Bright chrome
    glutSolidTorus(0.08, 0.2, 20, 20);
    glPopMatrix();
    // Tire
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); // Black
    glutSolidTorus(0.1, 0.15, 20, 20);
    glPopMatrix();
    // Hub
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f); // Steel hub
    glutSolidTorus(0.03, 0.08, 20, 20);
    glPopMatrix();
    glPopMatrix();

    // Carriage door - Dark wood
    glPushMatrix();
    glTranslatef(1.8, -1.2, 0.05);
    glScalef(0.3, 0.5, 0.12);
    glColor3f(0.3f, 0.2f, 0.1f); // Dark wood
    glutSolidCube(1.0);

    // Door handle
    glPushMatrix();
    glTranslatef(0, -0.2, 0.6);
    glScalef(0.1, 0.05, 0.2);
    glColor3f(0.8f, 0.8f, 0.8f); // Silver handle
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Carriage number plate
    glPushMatrix();
    glTranslatef(2.2, -1.1, 0.05);
    glScalef(0.2, 0.1, 0.12);
    glColor3f(0.9f, 0.9f, 0.7f); // Light yellow plate
    glutSolidCube(1.0);

    // Plate border
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f); // Dark border
    glScalef(1.1, 1.1, 1.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // --- SMOKE ---
    glPushMatrix();
    glTranslatef(-0.65, 0.2, 1);
    glScalef(1, 1, 0.01);
    glColor3f(0.8f, 0.8f, 0.8f); // White smoke
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, 0.5, 1);
    glScalef(1.4, 1.4, 0.01);
    glColor3f(0.7f, 0.7f, 0.7f); // Light gray smoke
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, 0.8, 1);
    glScalef(2, 2, 0.01);
    glColor3f(0.6f, 0.6f, 0.6f); // Medium gray smoke
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // Additional smoke puffs
    for (int i = 0; i < 2; i++) {
        glPushMatrix();
        glTranslatef(0.1 + i * 0.2, 1.0 + i * 0.1, 1);
        glScalef(1.5 - i * 0.3, 1.5 - i * 0.3, 0.01);
        glColor3f(0.5f - i * 0.1f, 0.5f - i * 0.1f, 0.5f - i * 0.1f);
        glutSolidSphere(0.08, 20, 20);
        glPopMatrix();
    }

    glPopMatrix();
}

void updateTrain(int value) {

    trainX += trainSpeed;
    if (trainX < -20.0f) trainX = 240.0f;

    trainX2 += trainSpeed2;
    if (trainX2 > 240.0f) trainX2 = -20.0f;


    glutPostRedisplay();
    glutTimerFunc(30, updateTrain, 0);
}

//element for  ShaheedMinar
void drawRect(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++) {
        float angle = 2 * 3.1416f * i / 100;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

void drawShaheedMinar() {

    //RED BASE
    glColor3f(0.85f, 0.0f, 0.0f);
    drawRect(6, 0, 34, 1.5);

    glColor3f(0.9f, 0.1f, 0.1f);
    drawRect(8, 1.5, 32, 3);


    // RED SUN
    glColor3f(0.9f, 0.0f, 0.0f);
    drawCircle(20, 16, 5.0);


    // GOLDEN COLOR 
    float gr = 0.85f, gg = 0.7f, gb = 0.2f;


    // CENTER PILLAR (BIGGEST)
    glColor3f(gr, gg, gb);
    drawRect(17, 3, 23, 28);

    // Inner vertical bars
    glColor3f(1, 1, 1);
    for (float x = 18; x <= 22; x += 0.8)
        drawRect(x, 4, x + 0.2, 26);


    //LEFT INNER PILLAR
    glColor3f(gr, gg, gb);
    drawRect(12.5, 3, 15.5, 22);

    glColor3f(1, 1, 1);
    for (float x = 13.2; x <= 15; x += 0.7)
        drawRect(x, 4, x + 0.15, 20);


    // RIGHT INNER PILLAR
    glColor3f(gr, gg, gb);
    drawRect(24.5, 3, 27.5, 22);

    glColor3f(1, 1, 1);
    for (float x = 25.2; x <= 27; x += 0.7)
        drawRect(x, 4, x + 0.15, 20);


    // FAR LEFT SMALL PILLAR 
    glColor3f(gr, gg, gb);
    drawRect(9, 3, 11, 18);

    glColor3f(1, 1, 1);
    for (float x = 9.5; x <= 10.5; x += 0.6)
        drawRect(x, 4, x + 0.12, 16);


    // FAR RIGHT SMALL PILLAR
    glColor3f(gr, gg, gb);
    drawRect(29, 3, 31, 18);

    glColor3f(1, 1, 1);
    for (float x = 29.5; x <= 30.5; x += 0.6)
        drawRect(x, 4, x + 0.12, 16);


    // TOP CAPS
    glColor3f(gr + 0.1f, gg + 0.1f, gb);
    drawRect(16.5, 28, 23.5, 29);
    drawRect(12, 22, 16, 23);
    drawRect(24, 22, 28, 23);
    drawRect(8.5, 18, 11.5, 19);
    drawRect(28.5, 18, 31.5, 19);
}



//all scenerio 
// Draw day scene
void drawDayScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //call base structure
    placeForSM(0.76f, 0.7f, 0.5f);
    placeForForest(0.4f, 0.6f, 0.2f);
    drawRoads();
    roadBorder();
    drawRailRoad();
    drawRailPath();
    drawSky(0.53f, 0.81f, 0.92f);
    drawSun(70,75, 2);


    //call clouds
    drawCloud(cloudX1, 75.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    drawCloud(cloudX2, 70.0f, 1.2f, 0.95f, 0.95f, 0.95f);
    drawCloud(cloudX3, 78.0f, 0.8f, 0.9f, 0.9f, 0.9f);


    //call plans
    drawPlane();
    drawPlane2(70.0f);
    
    //call building 1
    drawBuildingBody(18, 50, 14, 24, 0.55f, 0.27f, 0.07f);
    deawBuildingSideBody(32, 50, 4, 25, 0.56f, 0.26f, 0.06f);
    drawBuildingTop(20, 74, 11, 2, 0.55f, 0.27f, 0.07f);
    deawSideBuildingTop(31, 74, 4, 3, 0.56f, 0.26f, 0.06f);
    drawWindow(20, 54, 30, 72, 0.58f, 0.23f, 0.09f);
    drawSideWindow(33, 54, 36, 74, 0.58f, 0.23f, 0.09f);
    drawBuildingDoor(23,50,26,52, 0.60f, 0.27f, 0.09f);

    //call building 2
    drawBuildingBody(50, 50, 10, 20, 0.65f, 0.33f, 0.22f);
    deawBuildingSideBody(60, 50, 6, 21, 0.68f, 0.36f, 0.22f);
    drawBuildingTop(51, 70, 8, 2, 0.65f, 0.33f, 0.22f);
    deawSideBuildingTop(59, 70, 6, 3, 0.68f, 0.36f, 0.22f);
    drawWindow(52, 55, 58, 68, 0.63f, 0.35f, 0.25f);
    drawSideWindow(62, 54, 64, 70, 0.68f, 0.36f, 0.22f);
    drawBuildingDoor(53, 50, 56, 52, 0.65f, 0.37f, 0.27f);

    //call building 3
    drawBuildingBody(67, 50, 8, 15, 0.55f, 0.32f, 0.07f);
    deawBuildingSideBody(75, 50, 5, 16, 0.57f, 0.31f, 0.05f);
    drawBuildingTop(68, 65, 6, 2, 0.55f, 0.32f, 0.07f);
    deawSideBuildingTop(74, 65, 5, 3, 0.57f, 0.31f, 0.05f);
    drawWindow(68, 54, 74, 64, 0.63f, 0.35f, 0.25f);
    drawSideWindow(77, 54, 79, 64, 0.58f, 0.23f, 0.09f);
    drawBuildingDoor(70, 50, 72, 52, 0.66f, 0.37f, 0.26f);

    //building 4
    drawBuildingBody(82.5, 50, 15, 25, 0.22f, 0.4f, 0.6f);
    drawWindow(85, 55, 94, 74, 0.20f, 0.6f, 0.7f);
    drawBuildingDoor(87, 50, 93, 52, 0.25f, 0.65f, 0.73f);

    //call trees
    drawTree(10.0f, 50.0f, 11.0f, 63.0f); // 1st tree
    drawTree(38.0f, 50.0f, 39.0f, 60.0f); // 2nd tree
    drawTree(45.0f, 50.0f, 0.0f, 1.0f, 0.5f);               // 3rd tree
    drawTree(83.0f, 50.0f, 0.0f, 1.0f, 0.5f);               // 4th tree
    drawTree(89.0f, 50.0f, 0.0f, 1.0f, 0.5f);               // 4th tree


    //call trains
    drawTrain(trainX);
    drawTrain2(trainX2);


    //call cars and bus
    drawMiniCar();
    drawBlueBus();
    drawRedCar();
    drawMegendaBus();


    //call trees to make forest
    drawTree(73.0f, 13.0f, 0.0f, 1.0f, 0.5f);
    drawTree(75.0f, 0.0f, 76.0f, 8.0f);
    drawTree(62.0f, 0.0f, 63.0f, 12.0f);
    drawTree(80.0f, 0.0f, 81.0f, 20.0f);
    drawTree(89.0f, 5.0f, 0.0f, 1.0f, 0.5f);
    drawTree(93.0f, 13.0f, 0.75f, 1.0f, 0.0f);
    drawTree(98.0f, 0.0f, 99.0f, 10.0f);
    drawTree(70.0f, 0.0f, 0.6f, 0.9f, 0.2f);
    drawTree(84.0f, 4.0f, 0.6f, 0.9f, 0.2f);
    drawTree(86.0f, 0.0f, 0.0f, 1.0f, 0.5f);


    //call drawShaheedMinar
    drawShaheedMinar();


    


    glutSwapBuffers();
}

// Draw night scene
void drawNightScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //call base structure
    placeForSM(0.35f, 0.33f, 0.25f);
    placeForForest(0.05f, 0.15f, 0.1f);
    drawRoads();
    roadBorder();
    drawRailRoad();
    drawRailPath();
    drawSky(0.08f, 0.08f, 0.25f);
    drawStars();
    drawCrescentMoon(10, 77, 2);

    //clouds
    drawCloud(cloudX1, 75.0f, 1.0f, 0.3f, 0.3f, 0.4f);
    drawCloud(cloudX2, 70.0f, 1.2f, 0.35f, 0.35f, 0.45f);
    drawCloud(cloudX3, 78.0f, 0.9f, 0.25f, 0.25f, 0.35f);

    //call plans
    drawPlane();
    drawPlane2(70.0f);

    //call building 1
    drawBuildingBody(18, 50, 14, 24, 0.25f, 0.12f, 0.05f);
    deawBuildingSideBody(32, 50, 4, 25, 0.20f, 0.10f, 0.04f);
    drawBuildingTop(20, 74, 11, 2, 0.22f, 0.11f, 0.05f);
    deawSideBuildingTop(31, 74, 4, 3, 0.18f, 0.09f, 0.04f);
    drawWindow(20, 54, 30, 72, 0.90f, 0.85f, 0.40f);
    drawSideWindow(33, 54, 36, 74, 0.90f, 0.85f, 0.40f);
    drawBuildingDoor(23, 50, 26, 52, 0.93f, 0.87f, 0.43f);


    //call building 2
    drawBuildingBody(50, 50, 10, 20, 0.30f, 0.18f, 0.12f);
    deawBuildingSideBody(60, 50, 6, 21, 0.26f, 0.15f, 0.10f);
    drawBuildingTop(51, 70, 8, 2, 0.28f, 0.17f, 0.12f);
    deawSideBuildingTop(59, 70, 6, 3, 0.24f, 0.14f, 0.10f);
    drawWindow(52, 55, 58, 68, 0.95f, 0.80f, 0.35f); 
    drawSideWindow(62, 54, 64, 70, 0.95f, 0.80f, 0.35f);
    drawBuildingDoor(53, 50, 56, 52, 0.93f, 0.87f, 0.38f);


    //call building 3
    drawBuildingBody(67, 50, 8, 15, 0.20f, 0.22f, 0.08f);
    deawBuildingSideBody(75, 50, 5, 16, 0.17f, 0.18f, 0.06f);
    drawBuildingTop(68, 65, 6, 2, 0.18f, 0.20f, 0.07f);
    deawSideBuildingTop(74, 65, 5, 3, 0.15f, 0.17f, 0.05f);
    drawWindow(68, 54, 74, 64, 0.90f, 0.82f, 0.40f);
    drawSideWindow(77, 54, 79, 64, 0.90f, 0.82f, 0.40f);
    drawBuildingDoor(70, 50, 72, 52, 0.93f, 0.87f, 0.43f);


    //call building 4
    drawBuildingBody(82.5, 50, 15, 25, 0.08f, 0.15f, 0.30f);
    drawWindow(85, 55, 94, 74, 0.40f, 0.75f, 0.90f); 
    drawBuildingDoor(87, 50, 93, 52, 0.44f, 0.76f, 0.93f);

    //call trees
    drawTree(10.0f, 50.0f, 11.0f, 63.0f);                   // 1st tree
    drawTree(38.0f, 50.0f, 39.0f, 60.0f);                   // 2nd tree
    drawTree(45.0f, 50.0f, 0.0f, 1.0f, 0.5f);               // 3rd tree
    drawTree(83.0f, 50.0f, 0.6f, 0.9f, 0.2f);               // 4th tree
    drawTree(89.0f, 50.0f, 0.6f, 0.9f, 0.2f);               // 4th tree
    
    //call trains
    drawTrain(trainX);
    drawTrain2(trainX2);

    //call cars and bus
    drawMiniCar();
    drawBlueBus();
    drawRedCar();
    drawMegendaBus();


    //call trees to make forest
    drawTree(73.0f, 13.0f, 0.0f, 1.0f, 0.5f);
    drawTree(75.0f, 0.0f, 76.0f, 8.0f);
    drawTree(62.0f, 0.0f, 63.0f, 12.0f);
    drawTree(80.0f, 0.0f, 81.0f, 20.0f);
    drawTree(89.0f, 5.0f, 0.0f, 1.0f, 0.5f);
    drawTree(93.0f, 13.0f, 0.75f, 1.0f, 0.0f);
    drawTree(98.0f, 0.0f, 99.0f, 10.0f);
    drawTree(70.0f, 0.0f, 0.6f, 0.9f, 0.2f);
    drawTree(84.0f, 4.0f, 0.6f, 0.9f, 0.2f);
    drawTree(86.0f, 0.0f, 0.0f, 1.0f, 0.5f);

    //call drawShaheedMinar
    drawShaheedMinar();

    glutSwapBuffers();
}




// Display callback
void display() {
    if (!isNight) {
        drawDayScene();
    }
    else {
        drawNightScene();
    }
}

// Keyboard handler to toggle day/night
void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'n' || key == 'N') {
        isNight = true;
        nightLight = true;
        glutPostRedisplay(); 
    }
    if (key == 'd' || key == 'D') {
        isNight = false;
        nightLight = false;
        glutPostRedisplay();
    }
    if (key == '2') {
        // click 2 to - increase speed
        planeSpeed = planeSpeed * 2; 
        trainSpeed = trainSpeed * 2;
        trainSpeed2 = trainSpeed2 * 2;
        planeSpeed2 = planeSpeed2 * 2;
        carSpeed1 = 0.5 * 5;
        carSpeed2 = -0.4f * 2;
        carSpeed3 = 0.6f * 3;
        carSpeed4 = -0.5f * 4;
    }
    if (key == '3') {
        // click 3 to  - decrease speed
        planeSpeed = planeSpeed / 2;
        trainSpeed = trainSpeed / 2;
        trainSpeed2 = trainSpeed2 / 2;
        planeSpeed2 = planeSpeed2 / 2;
        carSpeed1 = 0.5 / 5;
        carSpeed2 = -0.4f / 2;
        carSpeed3 = 0.6f / 3;
        carSpeed4 = -0.5f / 4;
    }

    if (key == '4') {
        //Click 3 - reset to normal speed 
        planeSpeed = 0.2f * 2;
        trainSpeed = -0.15f * 2;
        trainSpeed2 = 0.15f * 2;
        planeSpeed2 = 0.4;
        carSpeed1 = 0.5;
        carSpeed2 = -0.4f;
        carSpeed3 = 0.6f;
        carSpeed4 = -0.5f;

    }
}

// Mouse handler (currently empty)
void handleMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            // Left click - increase speed
            planeSpeed = planeSpeed * 2;
            trainSpeed = trainSpeed * 2;
            trainSpeed2 = trainSpeed2 * 2;
            planeSpeed2 = planeSpeed2 * 2;
            carSpeed1 = 0.5 * 5;
            carSpeed2 = -0.4f * 2;
            carSpeed3 = 0.6f * 3;
            carSpeed4 = -0.5f * 4;




        }
        else if (button == GLUT_RIGHT_BUTTON) {
            // Right click - decrease speed
            planeSpeed = planeSpeed / 2;
            trainSpeed = trainSpeed / 2;
            trainSpeed2 = trainSpeed2 / 2;
            planeSpeed2 = planeSpeed2 / 2;
            carSpeed1 = 0.5 / 5;
            carSpeed2 = -0.4f / 2;
            carSpeed3 = 0.6f / 3;
            carSpeed4 = -0.5f / 4;



        }
        else if (button == GLUT_MIDDLE_BUTTON) {
            // Middle click - reset to normal speed
            planeSpeed = 0.2f * 2;
            trainSpeed = -0.15f * 2;
            trainSpeed2 = 0.15f * 2;
            planeSpeed2 = 0.4;
            carSpeed1 = 0.5;
            carSpeed2 = -0.4f;
            carSpeed3 = 0.6f;
            carSpeed4 = -0.5f;

        }
    }
    glutPostRedisplay();
}

// Initialization
void initRendering() {
   
    glClearColor(0.5, 0.5, 0.5, 0.5);


}

// Resize handler
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 80.0); // 2D coordinates
    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("City_View_2D");

    initRendering();
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutReshapeFunc(handleResize);

    glutTimerFunc(0, updateClouds, 0);
    glutTimerFunc(0, updateCars, 0);
    glutTimerFunc(0, updateTrain, 0);
    glutTimerFunc(0, updatePlane, 0);

    glutMainLoop();
    return 0;
}
