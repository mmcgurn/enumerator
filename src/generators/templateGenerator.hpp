#ifndef ENUMERATOR_TEMPLATEGENERATOR_HPP
#define ENUMERATOR_TEMPLATEGENERATOR_HPP

#include "generator.hpp"
#include <filesystem>
namespace enumerator::generators {

class TemplateGenerator: public Generator {
   private:
    const std::string templateString;
    const std::filesystem::path outputDirectory;
    const std::string extension;
    
    std::string GetVariableReplacementString(const std::string varName);

   public:
    explicit TemplateGenerator(std::string templateString, std::string extension = "", std::filesystem::path outputDirectory = std::filesystem::current_path());

    void Generate(const std::string& caseName, const std::map<std::string, std::string>& values) override;

};

}
#endif  // ENUMERATOR_TEMPLATEGENERATOR_HPP
