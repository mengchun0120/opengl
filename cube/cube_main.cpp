#include <iostream>
#include <cube_app.h>

int main(int argc, char *argv[])
{
    using namespace cube;

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
        CubeApp::initInstance(vertexShaderFile, fragShaderFile);
        CubeApp::getInstance()->run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception happened: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
