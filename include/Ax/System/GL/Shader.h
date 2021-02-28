#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include "Ax/System/Common/glm.h"
#include "Ax/System/Common/Types.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Ax::System::GL {
    
    class Shader
    {
    public:
                  Shader();
                  Shader(const char* vertexPath, const char* fragmentPath);

        void      use() const;

        void      setBool(const std::string &name, bool value) const;
        void      setInt(const std::string &name, int value) const;
        void      setFloat(const std::string &name, float value) const;
        void      setMat4(const std::string& name, const glm::mat4& mat) const;

        s16       getID() const;

    private:

        void      _createShader(s16& id, const_str code, GLenum shaderType, std::string shaderName);
        void      _checkCompileErrors(unsigned int shader, std::string type);

        s16       ID;
        s16       m_vertID;
        s16       m_fragID;
        const_str m_vertCode;
        const_str m_fragCode;
    };

}
#endif
