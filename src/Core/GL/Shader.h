#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <string>

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{

public:


	Shader(const char* vertex, const char* fragment);
	Shader();

	GLuint getID() { return ID; }

	void Load(const char* vertex, const char* fragment);
	void Active() { glUseProgram(ID); }

	void setMat4(glm::mat4 mat4, const char* name) 
	{ 
		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(mat4));
	}

	void setVec4(glm::vec4 vec4, const char* name)
	{
		glUniform4fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vec4));
	}

	void setVec3(glm::vec4 vec3, const char* name)
	{
		glUniform3fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vec3));
	}

	void setVec2(glm::vec4 vec2, const char* name)
	{
		glUniform2fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vec2));
	}

private:
	GLuint ID{};


};

#endif