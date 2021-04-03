#ifndef INCLUDE_GASKET2DRAND_APP_H
#define INCLUDE_GASKET2DRAND_APP_H

#include "sharedlib_app.h"
#include "sharedlib_vertex_array.h"
#include "gasket2drand_program.h"

namespace gasket2drand {

class Gasket2DRandApp: public sharedlib::App {
public:
    Gasket2DRandApp(const std::string &vertexShaderFile,
                    const std::string &fragShaderFile);

    void setup() override;

    void process() override;

private:
    sharedlib::VertexArray vertices_;
    Gasket2DRandProgram program_;
};

} // end of namespace gasket2drand

#endif

