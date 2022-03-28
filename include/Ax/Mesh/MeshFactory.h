#ifndef AX_MESHFACTORY_H
#define AX_MESHFACTORY_H

#include "Ax/Common/Types.h"
#include "Ax/GL/VertexArray.h"
#include <map>
#include <utility>
#include <memory>

namespace Ax::Mesh
{
    class MeshFactory
    {
    public:

        MeshFactory() noexcept;
        ~MeshFactory();

        /**
         * Build and load a single Cube Mesh into graphics memory ready for drawing.
         */
        void createCubeMesh();

        /**
         * Build and load a single Rectangle Mesh into graphics memory ready for drawing.
         */
        void createRectangleMesh();

        std::map<std::string, std::shared_ptr<Ax::GL::VertexArray>> getVAOMap()
        {
            return this->vertexArrays;
        }

    private:
        std::map<std::string, std::shared_ptr<Ax::GL::VertexArray>> vertexArrays;
    };
}



#endif
