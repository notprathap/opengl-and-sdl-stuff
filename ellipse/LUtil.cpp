/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 017

#include "LUtil.h"
#include <IL/il.h>
#include <IL/ilu.h>
#include "Ellipse.h"
#include <vector>
#include <iostream>

//Quad vertices
LVertexPos2D gQuadVertices[ 4 ];

//Vertex Indices
GLuint gIndices[ 4 ];

//Vertex buffer
GLuint gVertexBuffer = 0;

//Index buffer
GLuint gIndexBuffer = 0;

//index for vertices
std::vector<LVertexPos2D> points;
std::vector<GLuint> indices;

bool initGL()
{
    //Initialize GLEW
    GLenum glewError = glewInit();
    if( glewError != GLEW_OK )
    {
        printf( "Error initializing GLEW! %s\n", glewGetErrorString( glewError ) );
        return false;
    }

    //Make sure OpenGL 2.1 is supported
    if( !GLEW_VERSION_2_1 )
    {
        printf( "OpenGL 2.1 not supported!\n" );
        return false;
    }

    //Set the viewport
    glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );

    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Enable texturing
    glEnable( GL_TEXTURE_2D );

    //Set blending
    glEnable( GL_BLEND );
    glDisable( GL_DEPTH_TEST );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    //Initialize DevIL and DevILU
    ilInit();
    iluInit();
    ilClearColour( 255, 255, 255, 000 );

    //Check for error
    ILenum ilError = ilGetError();
    if( ilError != IL_NO_ERROR )
    {
        printf( "Error initializing DevIL! %s\n", iluErrorString( ilError ) );
        return false;
    }

    return true;
}

bool loadVertices()
{
    // initialize ellipse
    initEllipse(10,5);

    // load first set of points
    points = getFirstSetOfPoints();

    // load second set of points
    std::vector<LVertexPos2D> secondSetOfpoints;
    secondSetOfpoints = getSecondSetOfPoints();

    // merge the points
    points.insert(points.end(), secondSetOfpoints.begin(), secondSetOfpoints.end());

    // copy the points to an array, so segmentation fault can be avoided in 
    // glbufferdata call - for some reason, it won't accept the address of the 
    // first element in the vector - hence this arrangement.
    LVertexPos2D gPointVertices[ points.size() ];

    // set indices
    for (int i = 0; i < points.size(); i++){
        // set vertices
        gPointVertices[i].x = points[i].x;
        gPointVertices[i].y = points[i].y;

        gIndices[ i ] = i;
    }

    // create vbo and ibo
    createVBO(gPointVertices);
    createIBO();
    return true;
}

void createVBO(LVertexPos2D* gPointVertices)
{
    //Create VBO
    glGenBuffers( 1, &gVertexBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, gVertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, points.size() * sizeof(LVertexPos2D), gPointVertices, GL_STATIC_DRAW );
}

void createIBO()
{
    //Create IBO
    glGenBuffers( 1, &gIndexBuffer );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIndexBuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, points.size() * sizeof(GLuint), gIndices, GL_STATIC_DRAW );
}

void update()
{

}

void render()
{
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    //Enable vertex arrays
    glEnableClientState( GL_VERTEX_ARRAY );

        //Set vertex data
		glBindBuffer( GL_ARRAY_BUFFER, gVertexBuffer );
        glVertexPointer( 2, GL_FLOAT, 0, NULL );

        //Draw quad using vertex data and index data
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIndexBuffer );

        // plot the points
        glDrawElements( GL_POINTS, points.size(), GL_UNSIGNED_INT, NULL );

    //Disable vertex arrays
    glDisableClientState( GL_VERTEX_ARRAY );

    //Update screen
    glutSwapBuffers();
}
