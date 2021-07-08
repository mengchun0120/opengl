#include <sharedlib_json_param.h>
#include <sharedlib_json_utils.h>
#include <sprlgt_app_config.h>

namespace sprlgt {

AppConfig::AppConfig(const std::string& fileName)
{
    load(fileName);
}

void AppConfig::load(const std::string& fileName)
{
    using namespace rapidjson;
    using namespace sharedlib;

    Document doc;
    readJson(doc, fileName);

    std::vector<JsonParamPtr> params{
        jsonParam(width_, {"window", "width"}, true, gt(width_, 0)),
        jsonParam(height_, {"window", "height"}, true, gt(height_, 0)),
        jsonParam(title_, {"window", "title"}),
        jsonParam(eye_, {"camera", "eye"}),
        jsonParam(at_, {"camera", "at"}),
        jsonParam(up_, {"camera", "up"}),
        jsonParam(near_, {"projection", "near"}),
        jsonParam(far_, {"projection", "far"}),
        jsonParam(center_, {"sphere", "center"}),
        jsonParam(radius_, {"sphere", "radius"}, true, gt(radius_, 0.0f)),
        jsonParam(numSteps_, {"sphereGenerator", "recursive", "numSteps"}, true,
                  gt(numSteps_, 0)),
        jsonParam(lightPos_, {"lighting", "source", "position"}),
        jsonParam(ambientLight_, {"lighting", "source", "ambient"}),
        jsonParam(diffuseLight_, {"lighting", "source", "diffuse"}),
        jsonParam(specularLight_, {"lighting", "source", "specular"}),
        jsonParam(ambientReflect_, {"lighting", "reflection", "ambient"}),
        jsonParam(diffuseReflect_, {"lighting", "reflection", "diffuse"}),
        jsonParam(specularReflect_, {"lighting", "reflection", "specular"})
    };

    parse(params, doc);
}

} // end of namespace sprlgt

