#include "Shader.h"

Shader::Shader(const char* vertex, const char* fragment)
{

	Load(vertex, fragment);

}

Shader::Shader()
{
}

void Shader::Load(const char* vertex, const char* fragment)
{

	std::ifstream vertexFill(vertex);

	std::string resultVertex, lineVertex;

	if (vertexFill.is_open())
	{

		while (std::getline(vertexFill, lineVertex))
		{
			resultVertex += lineVertex + "\n";
		}

		vertexFill.close();
	}
	else std::cout << "ERROR::LOAD::VERTEX::FILE\n";


	std::ifstream fragmentFill(fragment);

	std::string resultFragment, lineFragment;

	if (fragmentFill.is_open())
	{

		while (std::getline(fragmentFill, lineFragment))
		{
			resultFragment += lineFragment + "\n";
		}

		fragmentFill.close();
	}
	else std::cout << "ERROR::LOAD::VERTEX::FILE\n";


	const char* vertexShaderCode	= resultVertex.c_str();
	const char* fragmentShaderCode  = resultFragment.c_str();


	GLuint vertexSh = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexSh, 1, &vertexShaderCode, NULL);
	glCompileShader(vertexSh);

	GLuint fragmentSh = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentSh, 1, &fragmentShaderCode, NULL);
	glCompileShader(fragmentSh);

	ID = glCreateProgram();

	glAttachShader(ID, vertexSh);
	glAttachShader(ID, fragmentSh);

	glLinkProgram(ID);

	glDeleteShader(vertexSh);
	glDeleteShader(fragmentSh);

}
