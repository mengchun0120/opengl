#ifndef INCLUDE_TETRA_APP_H
#define INCLUDE_TETRA_APP_H

#include "sharedlib_app.h"
#include "sharedlib_vertex_array.h"
#include "tetra_program.h"

namespace tetra {

class TetraApp: public sharedlib::App {
public:
    TetraApp(const std::string &vertexShaderFile,
             const std::string &fragShaderFile);

    void process() override;

private:
    void setupProgram();

    void setupOpenGL();

private:
    sharedlib::VertexArray va_;
    TetraProgram program_;
};

} // end of namespace tetra



#endif

