#pragma once
#include <gl\gl.H>

class B913038 {
public:
	static void DrawPlane(GLfloat plane_x, GLfloat plane_y, GLfloat plane_z, GLfloat pitch, GLfloat yaw) {


		glEnable(GL_LIGHTING);  // Enable Lightning

		glEnable(GL_LIGHT0);	// Enable Light0
		glEnable(GL_LIGHT1);	// Enable Light1

		GLfloat light_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
		GLfloat light_specualr[] = { 1.0f, 1.0f, 1.0f, 1.0f };	// Light properties
		GLfloat light_position[] = { 3.0f, 10.0f, 6.0f, 1.0f };  // Position property

		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);	// Set LIGHT0 Properties(diffuse)
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);	// Set LIGHT0 Properties(position)

		glLightfv(GL_LIGHT1, GL_POSITION, light_position);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specualr);  // Set LIGHT1 Properties (Position , Specular)

		GLfloat mat_green[] = { 0.0f, 1.0f, 0.0f, 1.0f };
		GLfloat mat_red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		GLfloat mat_blue[] = { 0.0f, 0.0f, 1.0f, 1.0f };	
		GLfloat mat_blueish[] = { 0.2f, 0.2f, 1.0f, 1.0f };	
		GLfloat mat_disable[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat mat_specular[] = { 0.3f, 0.3f, 0.7f, 1.0f };

		GLfloat mat_shinines[] = { 4.0f };			// define Material properties

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shinines);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_blueish); // Set Material to blue-ish color & set other properties
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_disable); // Disable Emission properties used for Drawing Lines
		
		
		glTranslatef(plane_x, plane_y, plane_z); // Translate Verticies
		glRotatef(pitch, 1, 0, 0);	// Rotate verticies accordingly with pitch and yaw
		glRotatef(yaw, 0, 0, 1);
		
		
		glBegin(GL_TRIANGLE_STRIP); // Struct Plane
		glVertex3f(2, -2.3, 0);
		glVertex3f(0, 3, 0);
		glVertex3f(0.3, -2, 0);
		glVertex3f(0, -2, -1);
		glVertex3f(0, 3, 0);
		glVertex3f(-0.3, -2, 0);
		glVertex3f(-2, -2.3, 0);
		glEnd();


		glTranslatef(0, 0, 0);


	}
	static void DrawStars() {
		GLfloat mat_white[] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glBegin(GL_POINTS);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_white); // Draw stars 

		int offset = 10;
		
		// place GL_Points in array with offset

		for (int i = -50; i < 50; i+=offset) {
			for (int j = -50; j < 50; j+=offset) {

				glVertex3f(-10+i,3+j,4);
				glVertex3f(13+i,5+j,-14);
				glVertex3f(3+i,-5+j,24);
				glVertex3f(-4+i,13+j,7);
				glVertex3f(13+i,0+j,-2);
				glVertex3f(7+i,3+j,8);
				glVertex3f(1+i,1+j,-4);
				glVertex3f(-13+i,9+j,0);
				glVertex3f(5+i,-14+j,1);
				glVertex3f(13+i,-20+j,-3);
				glVertex3f(-13+i,-20+j,-3);
				glVertex3f(-4+i,-10+j,-3);
				glVertex3f(-2+i,-8+j,3);
			}
		}
		glEnd();
	}
};