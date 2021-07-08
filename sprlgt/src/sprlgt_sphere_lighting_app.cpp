#include <sprlgt_sphere_generator.h>
#include <sprlgt_sphere_lighting_app.h>

using namespace sharedlib;
using namespace std;

namespace sprlgt {

SphereLightingApp::SphereLightingApp(const std::string& vertexShaderFile,
                                     const std::string& fragShaderFile,
                                     const AppConfig& cfg)
    : App(cfg.width(), cfg.height(), cfg.title())
    , cfg_(cfg)
    , shader_(vertexShaderFile, fragShaderFile)
{
    setupViewport();
    setupOpenGL();
    setupSphere();
    setupModelViewMatrix();
    setupProjMatrix();
    setupLighting();
}

SphereLightingApp::~SphereLightingApp()
{
}

void SphereLightingApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shader_.setPositionNormal(va_);
    glDrawArrays(GL_TRIANGLES, 0, va_.numVertices(0));
}

void SphereLightingApp::setupViewport()
{
    int width, height;

    glfwGetFramebufferSize(window(), &width, &height);
    viewportWidth_ = static_cast<float>(width);
    viewportHeight_ = static_cast<float>(height);
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
    using namespace sharedlib;

    constexpr unsigned int VERTEX_SIZE = 3 * sizeof(float);
    std::vector<Vector3> vertices, normals;
    RecursiveSphereGenerator g(cfg_.numSteps());

    g.generate(vertices, normals, cfg_.center(), cfg_.radius());
    va_.load({
        BufferBlock(vertices.data(), vertices.size(), VERTEX_SIZE, 0),
        BufferBlock(normals.data(), vertices.size(), VERTEX_SIZE, 0)
    });
}

void SphereLightingApp::setupModelViewMatrix()
{
    using namespace sharedlib;

    modelViewMatrix_ = lookAt(cfg_.eye(), cfg_.at(), cfg_.up());
    shader_.setModelViewMatrix(modelViewMatrix_);
}

void SphereLightingApp::setupProjMatrix()
{
    using namespace sharedlib;

    projMatrix_ = ortho(-viewportWidth_/2.0f, viewportWidth_/2.0f,
                        -viewportHeight_/2.0f, viewportHeight_/2.0f,
                        cfg_.near(), cfg_.far());
    shader_.setProjMatrix(projMatrix_);
}

void SphereLightingApp::setupLighting()
{
    using namespace sharedlib;

    eyePos_ = cfg_.eye();
    lightPos_ = cfg_.lightPos();
    ambientProduct_ = product(cfg_.ambientLight(), cfg_.ambientReflect());
    diffuseProduct_ = product(cfg_.diffuseLight(), cfg_.diffuseReflect());
    specularProduct_ = product(cfg_.specularLight(), cfg_.specularReflect());

    shader_.setEyePos(eyePos_);
    shader_.setLightPos(lightPos_);
    shader_.setAmbientProduct(ambientProduct_);
    shader_.setDiffuseProduct(diffuseProduct_);
    shader_.setSpecularProduct(specularProduct_);
    shader_.setShineness(cfg_.shineness());
}

} // end of namespace sprlgt

