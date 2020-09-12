//
// Created by Herman on 21.07.2020.
//

#ifndef CODEGENERATOR_LANGUAGETYPE_H
#define CODEGENERATOR_LANGUAGETYPE_H

#include <string>

enum class LanguageType {
    CPP,
    Python,
    Java,
};

LanguageType strToLanguageType(const std::string &str);
std::string languageTypeToStr(LanguageType fm);

#endif //CODEGENERATOR_LANGUAGETYPE_H
