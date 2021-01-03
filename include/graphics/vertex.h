#ifndef GFX_VERTEX_H
#define GFX_VERTEX_H

#include "common/types.h"
#include <array>

using Array3f = std::array<float,3>;

namespace Graphics {


    class Vertex
    {
        public:
            Vertex() 
                : position({1.0f, -0.5f, -1.0f}),
                  color({1.0f, 0.0f, 1.0f})
            {}
            Vertex(const std::array<float,3> position, const std::array<float,3> color) 
                : position(position),
                  color(color)
            {}

            ~Vertex() {}

            Array3f  getPosition() const;
            Array3f  getColor() const;



        private:
             Array3f position;
             Array3f color;

    };
}

inline Array3f  Graphics::Vertex::getPosition() const { return this->position; }
inline Array3f  Graphics::Vertex::getColor() const { return this->color; }
#endif
