#include <sprlgt_sphere_generator.h>
#include <sprlgt_sphere_lighting_app.h>

using namespace sharedlib;

namespace sprlgt {

SphereLightingApp::SphereLightingApp(const std::string& vertexShaderFile,
                                     const std::string& fragShaderFile,
                                     const AppConfig& cfg)
    : App(cfg.width(), cfg.height(), cfg.title())
    , cfg_(cfg)
    , shader_(vertexShaderFile, fragShaderFile)
{
    setupOpenGL();
    setupSphere();
}

SphereLightingApp::~SphereLightingApp()
{
}

void SphereLightingApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void SphereLightingApp::setupOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    shader_.use();
}

void SphereLightingApp::setupSphere()
{
    using namespace std;
    using namespace sharedlib;

    constexpr unsigned int VERTEX_SIZE = 3 * sizeof(float);
    vector<Vector> vertices, normals;
    SphereGenerator g(cfg.numSteps());

    g.generate(vertices, normals, cfg.center(), cfg.radius());
    va_.load({
        BufferBlock(vertices.data(), vertices.size(), VERTEX_SIZE, 0),
        BufferBlock(normals.data(), vertices.size(), VERTEX_SIZE, 0)
    });
}

void SphereLightingApp::setupLighting()
{
}

} // end of namespace sprlgt

