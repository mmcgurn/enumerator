#include "enumerator.hpp"

enumerator::Enumerator::Enumerator(std::string name, std::vector<std::shared_ptr<enumerations::Enumeration>> enumerations, std::shared_ptr<Generator> generator, std::vector<std::shared_ptr<Reporter>> reporters):
name(name), enumerations(std::move(enumerations)), generator(std::move(generator)), reporters(std::move(reporters)){

}

void enumerator::Enumerator::Enumerate() {
    // March over each enumerate
    int caseCount = 0;
    Enumerate(enumerations, {}, caseCount);

}
std::string enumerator::Enumerator::BuildCaseName(const int& caseCount) { return name + std::to_string(caseCount); }

void enumerator::Enumerator::Enumerate(const std::vector<std::shared_ptr<enumerations::Enumeration>>& remainingEnumerations, const std::map<std::string, std::string>& values, int& caseCount) {
    // Build a list of remainingEnumerations
    std::vector<std::shared_ptr<enumerations::Enumeration>> nowRemainingEnumerations;
    if(remainingEnumerations.empty()){
        return;
    }
    else if (remainingEnumerations.size() > 1){
        nowRemainingEnumerations = std::vector<std::shared_ptr<enumerations::Enumeration>>(remainingEnumerations.begin() + 1, remainingEnumerations.end());
    }

    // March over each option
    for(auto optionValue : remainingEnumerations.front()->Values()){
        auto valuesCopy = values;
        valuesCopy[remainingEnumerations.front()->Name()] = optionValue;

        // build the name
        auto caseName = BuildCaseName(caseCount++);

        // Generate the value
        generator->Generate(caseName, valuesCopy);

        // report the value to the reporters
        for(const auto& reporter: reporters){
            reporter->Report(caseName, valuesCopy);
        }


        // Enumerate any remaining options
        Enumerate(nowRemainingEnumerations, valuesCopy, caseCount);
    }
}
