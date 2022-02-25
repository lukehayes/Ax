#ifndef AX_MATH_RANDOM_H
#define AX_MATH_RANDOM_H

#include <random>

namespace Ax::Math {

    class Random
    {
    public:

        static int randInt(int from, int to)
        {
            std::random_device device;
            std::uniform_int_distribution<int> dist(from, to);
            return dist(device);
        }
        static double randDouble(double from, double to)
        {
            std::random_device device;
            std::uniform_real_distribution<double> dist(from, to);
            return dist(device);
        }
        
    private:
        std::mt19937 m_generator;
        std::random_device m_device;
    };
    
} /* namespace Ax::System::Math */


#endif //  AX_SYS_MATH_RANDOM_H
