#ifndef INCLUDE_GASKET3DRAND_APP_H
#define INCLUDE_GASKET3DRAND_APP_H

#include "sharedlib_app.h"
#include "sharedlib_vertex_array.h"
#include "gasket3drand_program.h"

namespace gasket3drand {

class Gasket3DRandApp: public sharedlib::App {
public:
    Gasket3DRandApp(const std::string &vertexShaderFile,
                    const std::string &fragShaderFile);

    void process() override;

private:
    void setupProgram();

    void setupOpenGL();

private:
    sharedlib::VertexArray vertices_;
    Gasket3DRandProgram program_;
};

} // end of namespace gasket3drand

#endif

