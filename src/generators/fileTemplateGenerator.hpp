#ifndef ENUMERATOR_FILETEMPLATEGENERATOR_HPP
#define ENUMERATOR_FILETEMPLATEGENERATOR_HPP

#include <filesystem>
#include "templateGenerator.hpp"

namespace enumerator::generators {

class FileTemplateGenerator : public TemplateGenerator {
   private:
    static std::string ReadFile(const std::filesystem::path&);

   public:
    explicit FileTemplateGenerator(std::filesystem::path templatePath);
};

}  // namespace enumerator::generators
#endif  // ENUMERATOR_FILETEMPLATEGENERATOR_HPP
