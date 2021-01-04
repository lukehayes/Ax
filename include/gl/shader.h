#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "common/glm.h"

namespace AX::GL {
    
    class Shader
    {
    public:
                     Shader();
                     Shader(const char* vertexPath, const char* fragmentPath);

        void         use() const;

        void         setBool(const std::string &name, bool value) const;
        void         setInt(const std::string &name, int value) const;
        void         setFloat(const std::string &name, float value) const;
        void         setMat4(const std::string& name, const glm::mat4& mat) const;

        unsigned int getID() const;

    private:
        void         checkCompileErrors(unsigned int shader, std::string type);
        unsigned int ID;
    };

}
#endif
