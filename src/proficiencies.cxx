#include "proficiencies.hxx"

#include <stdexcept>

Proficiency::Proficiency(std::string category, std::string name) : category_(std::move(category)), name_(std::move(name)) {
}

bool Proficiency::operator<(const Proficiency &other) const noexcept {
    if (category_ < other.category_) {
        return true;
    }
    if (other.category_ < category_) {
        return false;
    }
    return name_ < other.name_;
}

bool Proficiency::operator==(const Proficiency &other) const noexcept {
    if (category_ == other.category_) {
        return true;
    }
    return name_ == other.name_;
}

const std::string &Proficiency::category() const noexcept {
    return category_;
}

const std::string &Proficiency::name() const noexcept {
    return name_;
}

bool Proficiencies::has(const Proficiency &proficiency) const {
    return proficiencies.find(proficiency) != proficiencies.cend();
}

bool Proficiencies::add(Proficiency proficiency) {
    return proficiencies.insert(std::move(proficiency)).second;
}

decltype(Proficiencies::proficiencies)::const_iterator Proficiencies::cbegin() const noexcept {
    return proficiencies.cbegin();
}

decltype(Proficiencies::proficiencies)::const_iterator Proficiencies::begin() const noexcept {
    return proficiencies.begin();
}

decltype(Proficiencies::proficiencies)::const_iterator Proficiencies::cend() const noexcept {
    return proficiencies.cend();
}

decltype(Proficiencies::proficiencies)::const_iterator Proficiencies::end() const noexcept {
    return proficiencies.end();
}

decltype(Proficiencies::proficiencies)::const_reverse_iterator Proficiencies::crbegin() const noexcept {
    return proficiencies.crbegin();
}

decltype(Proficiencies::proficiencies)::const_reverse_iterator Proficiencies::rbegin() const noexcept {
    return proficiencies.rbegin();
}

decltype(Proficiencies::proficiencies)::const_reverse_iterator Proficiencies::crend() const noexcept {
    return proficiencies.crend();
}

decltype(Proficiencies::proficiencies)::const_reverse_iterator Proficiencies::rend() const noexcept {
    return proficiencies.rend();
}


