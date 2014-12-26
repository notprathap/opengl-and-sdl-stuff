#OBJS specifies which files to compile as part of the project
OBJS = 50_SDL_and_opengl_2.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lGL -lGLU

#OBJ_NAME specifies the name of our executable
OBJ_NAME = 50_SDL_and_opengl_2

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
