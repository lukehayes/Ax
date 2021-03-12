/*
 * =====================================================================================
 *
 *       Filename:  Builder.h
 *
 *    Description:  Base class for all builders inside Ax
 *    
 * =====================================================================================
 */
#ifdef  AX_SYS_BLDR_H
#define AX_SYS_BLDR_H

namespace Ax::System::Builder
{
    class Builder
    {
    public:

        Builder() {}
        virtual ~Builder() {}

        /**
         * Start the build/setup everything that is necessary
         * on the derived class.
         */
        virtual void build() = 0;
    }
}

#endif








