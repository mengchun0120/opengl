#ifndef INLCLUDE_GASKET2DLINE_APP_H
#define INLCLUDE_GASKET2DLINE_APP_H

#include "sharedlib_app.h"
#include "sharedlib_vertex_array.h"
#include "gasket2dline_program.h"

namespace gasket2dline {

class Gasket2DLineApp: public sharedlib::App {
public:
    Gasket2DLineApp(const std::string &vertexShaderFile,
                    const std::string &fragShaderFile);

    void process() override;

private:
    void setupProgram();

    void setupOpenGL();

private:
    sharedlib::VertexArray vertices_;
    Gasket2DLineProgram program_;
};

} // end of namespace gasket2dline

#endif

