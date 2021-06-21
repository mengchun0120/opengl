#include <iostream>
#include <lookatortho_app.h>

int main(int argc, char *argv[])
{
    using namespace lookatortho;

    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " vertexShaderFile "
                  << "fragShaderFile" << std::endl;
        return 1;
    }

    std::string vertexShaderFile(argv[1]);
    std::string fragShaderFile(argv[2]);

    try
    {
        LookAtOrthoApp::initInstance(vertexShaderFile, fragShaderFile);
        LookAtOrthoApp::getInstance()->run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception happened: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
