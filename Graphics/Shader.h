#ifndef SHADER_INCLUDED_H
#define SHADER_INCLUDED_H
#include <string>
#include <GL/glew.h>


class Shader
{
public:

	Shader(const std::string& fileName);
	void Bind();
	virtual ~Shader();

protected:
private:
	static const unsigned int NUM_SHADERS = 2;	
	void operator=(const Shader& shader) {}
	Shader(const Shader& shader) {}
	std::string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint CreateShader(const std::string& text,unsigned int shaderType);
};



#endif