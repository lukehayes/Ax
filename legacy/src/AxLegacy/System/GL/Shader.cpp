#include "Ax/System/GL/Shader.h"

namespace Ax::System::GL
{

    Shader::Shader()
    {
        this->vertexSource   = this->_readShaderFile("assets/shaders/VSH-Default.glsl");
        this->fragmentSource = this->_readShaderFile("assets/shaders/FSH-Default.glsl");

        _createShader(this->vertexID, this->vertexSource.c_str(), GL_VERTEX_SHADER, "VERTEX");
        _createShader(this->fragmentID, this->fragmentSource.c_str(), GL_FRAGMENT_SHADER, "FRAGMENT");

        this->compile();

        glDeleteShader(this->vertexID);
        glDeleteShader(this->fragmentID);
    }

    Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        this->vertexSource   = this->_readShaderFile(vertexPath.c_str());
        this->fragmentSource = this->_readShaderFile(fragmentPath.c_str());

        _createShader(this->vertexID, this->vertexSource.c_str(), GL_VERTEX_SHADER, "VERTEX");
        _createShader(this->fragmentID, this->fragmentSource.c_str(), GL_FRAGMENT_SHADER, "FRAGMENT");

        this->compile();

        glDeleteShader(this->vertexID);
        glDeleteShader(this->fragmentID);
    }

    Shader::~Shader()
    {
        // delete the shaders as they're linked into our program now and no longer necessary
        //glDeleteShader(this->vertexID);
        //glDeleteShader(this->fragmentID);
    }

    void Shader::compile()
    {
        // shader Program
        ID = glCreateProgram();
        glAttachShader(ID, vertexID);
        glAttachShader(ID, fragmentID);
        glLinkProgram(ID);
        _checkCompileErrors(ID, "PROGRAM");
    }

    str Shader::_readShaderFile(const char* filePath)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::ifstream file;
        // ensure ifstream objects can throw exceptions:
        file.exceptions (std::ifstream::failbit | std::ifstream::badbit);

        try 
        {
            // open files
            file.open(filePath);
            std::stringstream fileStream;
            // read file's buffer contents into streams
            fileStream << file.rdbuf();
            // close file handlers
            file.close();
            // convert stream into string
            return fileStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
    }

    void Shader::_createShader(s16& id, const_str code, GLenum shaderType, std::string shaderName)
    {
        id = glCreateShader(shaderType);
        glShaderSource(id, 1, &code, NULL);
        glCompileShader(id);
        _checkCompileErrors(id, shaderName);
    }

    void 
    Shader::use() const
    { 
        glUseProgram(this->ID); 
    }

    void 
    Shader::setBool(const std::string &name, bool value) const
    {         
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
    }

    void 
    Shader::setInt(const std::string &name, int value) const
    { 
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
    }

    void 
    Shader::setFloat(const std::string &name, float value) const
    { 
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
    }

    void 
    Shader::setMat4(const std::string& name, const glm::mat4& mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    void
    Shader::setVec3(const std::string& name, const glm::vec3& value) const 
    {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    s16
    Shader::getID() const 
    {
        return this->ID;
    }

    void 
    Shader::_checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << std::endl;
            }
        }
    }
}

