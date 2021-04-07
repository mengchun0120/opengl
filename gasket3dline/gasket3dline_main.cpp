#include <iostream>
#include "gasket3dline_app.h"

int main(int argc, char *argv[])
{
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
        gasket3dline::Gasket3DLineApp app(vertexShaderFile, fragShaderFile);
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception happened: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
