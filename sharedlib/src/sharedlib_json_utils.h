#ifndef INCLUDE_SHAREDLIB_JSON_UTILS_H
#define INCLUDE_SHAREDLIB_JSON_UTILS_H

#include <string>
#include <vector>
#include <rapidjson/document.h>

namespace sharedlib {

void readJson(rapidjson::Document& doc,
              const std::string& fileName);

const rapidjson::Value* findJson(const rapidjson::Document& doc,
                                 const std::vector<std::string>& path);

} // end of namespace sharedlib

#endif

