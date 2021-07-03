#include <pch.h>
#include "OpenGL/OpenGLShader.h"

namespace Spuget
{
	bool OpenGLShader::Load(const std::string& vertexShader, const std::string& fragmentShader)
	{
		std::ifstream vertexSource{ vertexShader };
		std::ifstream fragmentSource{ fragmentShader };

		std::stringstream vertexStream, fragmentStream;

		vertexStream << vertexSource.rdbuf();
		fragmentStream << fragmentSource.rdbuf();

		vertexSource.close();
		fragmentSource.close();

		std::string vertexCode = vertexStream.str();
		std::string fragmentCode = fragmentStream.str();

		unsigned int vertexShaderSource = CompileVertexShader(vertexCode);
		unsigned int fragmentShaderSource = CompileFragmentShader(fragmentCode);

		sShaderProgram = glCreateProgram();

		glAttachShader(sShaderProgram, vertexShaderSource);
		glAttachShader(sShaderProgram, fragmentShaderSource);
		glLinkProgram(sShaderProgram);

		glDeleteShader(vertexShaderSource);
		glDeleteShader(fragmentShaderSource);

		int success = 0;
		char infoLog[512];

		glGetProgramiv(sShaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(sShaderProgram, 512, NULL, infoLog);
			LOG("ERROR::LINKING::PROGRAM")
			LOG(infoLog)

			return false;
		}

		return true;
	}

	void OpenGLShader::Use()
	{
		assert(sShaderProgram);

		glUseProgram(sShaderProgram);
	}

	void OpenGLShader::SetVec2Int(const std::string& uniformName, int valueOne, int valueTwo)
	{
		assert(sShaderProgram);

		int uniformID = glGetUniformLocation(sShaderProgram, uniformName.c_str());
		glUniform2i(uniformID, valueOne, valueTwo);
	}

	OpenGLShader::~OpenGLShader()
	{
		if (sShaderProgram)
			glDeleteProgram(sShaderProgram);
	}

	unsigned int OpenGLShader::CompileVertexShader(const std::string& vertexCode)
	{
		unsigned int vertexShader;
		const char* cstring_vertexCode = vertexCode.c_str();

		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &cstring_vertexCode, NULL);
		glCompileShader(vertexShader);

		int success = 0;
		char infoLog[512];

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			LOG("VERT::SHADER::COMPILATION::ERROR")
		}

		return vertexShader;
	}

	unsigned int OpenGLShader::CompileFragmentShader(const std::string& fragmentCode)
	{
		unsigned int fragmentShader;
		const char* cstring_fragmentShader = fragmentCode.c_str();

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &cstring_fragmentShader, NULL);
		glCompileShader(fragmentShader);
		
		int success = 0;
		char infoLog[512];

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			LOG("FRAG::SHADER::COMPILATION::ERROR")
		}

		return fragmentShader;
	}
}