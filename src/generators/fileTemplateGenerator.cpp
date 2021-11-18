#include "fileTemplateGenerator.hpp"
#include <fstream>
#include <sstream>

enumerator::generators::FileTemplateGenerator::FileTemplateGenerator(std::filesystem::path templatePath)
    : TemplateGenerator(ReadFile(templatePath), templatePath.extension(), templatePath.parent_path()) {}

std::string enumerator::generators::FileTemplateGenerator::ReadFile(const std::filesystem::path& path) {
    if (!exists(path)) {
        throw std::invalid_argument("Cannot locate path to template file " + path.string());
    }
    std::ifstream fileStream(path);
    std::stringstream buffer;
    buffer << fileStream.rdbuf();

    return buffer.str();
}

#include "registrar.hpp"
REGISTER(enumerator::Generator, enumerator::generators::FileTemplateGenerator, "Generates template from a provided file", ARG(std::filesystem::path, "path", "the template path"));
