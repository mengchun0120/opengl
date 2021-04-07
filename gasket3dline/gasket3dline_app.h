#ifndef INLCLUDE_GASKET3DLINE_APP_H
#define INLCLUDE_GASKET3DLINE_APP_H

#include "sharedlib_app.h"
#include "sharedlib_vertex_array.h"
#include "gasket3dline_program.h"

namespace gasket3dline {

class Gasket3DLineApp: public sharedlib::App {
public:
    Gasket3DLineApp(const std::string &vertexShaderFile,
                    const std::string &fragShaderFile);

    void process() override;

private:
    void setupProgram();

    void setupOpenGL();

private:
    sharedlib::VertexArray va_;
    Gasket3DLineProgram program_;
};

} // end of namespace gasket3dline

#endif

