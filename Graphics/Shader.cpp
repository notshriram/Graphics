#include "shader.h"
#include <iostream>
#include <fstream>




Shader::Shader(const std::string& fileName)
{
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader("C:\Dev\Graphics\res\basicShader.vs"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader("C:\Dev\Graphics\res\basicShader.fs"), GL_FRAGMENT_SHADER);
	for (unsigned int i = 0; i < NUM_SHADERS; i++) {
		glAttachShader(m_program,m_shaders[i]);
	}
	glBindAttribLocation(m_program,0,"position");
	glLinkProgram(m_program);
	CheckShaderError(m_program,GL_LINK_STATUS,true,"Error linking");
	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error validatelinking");

}

Shader::~Shader()
{
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}

	glDeleteProgram(m_program);
}
std::string Shader::LoadShader(const std::string& fileName)

{
	std::ifstream file;
	file.open("C:\Dev\Graphics\res\basicShader.fs");
	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
			
		{			getline(file, line);
			output.append(line + "\n");
			
		}
		std::cout << output <<std::endl;
	}
	else
	{
		std::cerr << "Unable to load shader: " << fileName << std::endl;
	}
	return output;
}

void Shader::Bind()
{
	glUseProgram(m_program);
}



void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isProgram)
		glGetProgramiv(shader, flag, &success);
		else
		glGetShaderiv(shader, flag, &success);
		   	if (success == GL_FALSE)
			{
			if (isProgram)
				glGetProgramInfoLog(shader, sizeof(error), NULL, error);
			else
				glGetShaderInfoLog(shader, sizeof(error), NULL, error);
			std::cerr << errorMessage << ": '" << error << "'" << std::endl;
			}
	
}

GLuint Shader::CreateShader(const std::string & text, unsigned int shadertype)
{
	GLuint shader = glCreateShader(shadertype);
	if (shader == 0)std::cerr << "failed create shader";
	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringLengths[1];
	std::cout << text;
	if (shadertype == GL_VERTEX_SHADER) {
		shaderSourceStrings[0] = "#version 120\n attribute vec3 position;\nvoid main(){gl_Position=vec4(position,1.0);}";
		shaderSourceStringLengths[0] = 84;
	}
	if (shadertype == GL_FRAGMENT_SHADER) {
		shaderSourceStrings[0] = "#version 120\n void main(){gl_FragColor=vec4(0.794,0.302,0.745,1.0);}";
		shaderSourceStringLengths[0] = 69;
	}

	std::cout << shaderSourceStrings<<" length " << shaderSourceStringLengths[0];
	glShaderSource(shader,1,shaderSourceStrings,shaderSourceStringLengths);
	glCompileShader(shader);
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error shader compilation");
	return shader;
}