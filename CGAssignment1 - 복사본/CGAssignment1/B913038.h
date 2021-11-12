#pragma once
#include <gl\gl.H>

class B913038 {
public:
	static void drawCube() {

		
		glEnable(GL_LIGHTING);  // Enable Lightning

		/*
		glEnable(GL_LIGHT0);	// Enable Light0
		glEnable(GL_LIGHT1);	// Enable Light1

		GLfloat light_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
		GLfloat light_specualr[] = { 1.0f, 1.0f, 1.0f, 1.0f };	// Light properties
		GLfloat light_position[] = { 3.0f, 3.0f, 6.0f, 1.0f };  // Position property

		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);	// Set LIGHT0 Properties(diffuse)

		glLightfv(GL_LIGHT1, GL_POSITION, light_position);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specualr);  // Set LIGHT1 Properties (Position , Specular)
		*/	
		
		
		glEnable(GL_LIGHT2);	// Enable Spotlight 

		GLfloat spotlight_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // w=1 for positional light
		GLfloat spotlight_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat spotlight_position[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat spotlight_direction[] = { -1.0f, -1.0f, -1.0f };   // spotlight's position and direction defined
		
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 45);				// Spotlight Cutoff
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.01);	// Light Attenuation method : Quadratic
		glLightfv(GL_LIGHT2, GL_DIFFUSE, spotlight_diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, spotlight_specular);
		glLightfv(GL_LIGHT2, GL_POSITION, spotlight_position);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotlight_direction);
		


		GLfloat mat_green[] = { 0.0f, 1.0f, 0.0f, 1.0f };
		GLfloat mat_red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		GLfloat mat_blue[] = { 0.0f, 0.0f, 1.0f, 1.0f };	
		GLfloat mat_blueish[] = { 0.2f, 0.2f, 1.0f, 1.0f };	
		GLfloat mat_disable[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat mat_shinines[] = { 10.0f };			// define Material properties


		glBegin(GL_LINE_LOOP);		// Draw line (X axis)
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_green); // Set Material to green
		glVertex3f(10, 0, 0);		// (x,y,z) = (10,0,0)
		glVertex3f(-10, 0, 0);		// (x,y,z) = (-10,0,0)
		glEnd();

		glBegin(GL_LINE_LOOP);		// Draw line (Y axis)	
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_red); // Set Material to red
		glVertex3f(0, 10, 0);       // (x,y,z) = (0,10,0)
		glVertex3f(0, -10, 0);		// (x,y,z) = (0,-10,0)
		glEnd();


		glBegin(GL_LINE_LOOP);		// Draw line (Z axis)  
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_blue); // Set Material to blue
		glVertex3f(0, 0, 10);		// (x,y,z) = (0,0,10)
		glVertex3f(0, 0, -10);		// (x,y,z) = (0,0,-10)
		glEnd();


		glBegin(GL_TRIANGLE_STRIP); // Start Drawing Polygons for Cube

		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_disable); // Disable Emission properties used for Drawing Lines

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shinines);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_blueish); // Set Material to blue-ish color & set other properties

		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, -0.5);	// Draw each triangles. total 12 triangles


		glEnd();
	}
};