#ifndef PROFICIENCIES_H
#define PROFICIENCIES_H

#include <string>
#include <string_view>
#include <set>

/** Proficiencies organization structure.
 */
class Proficiency {
    private:
        std::string category_;
        std::string name_;

    public:
        Proficiency(std::string category, std::string name);

        bool operator<(const Proficiency &other) const noexcept;

        bool operator==(const Proficiency &other) const noexcept;

        const std::string &category() const noexcept;
        const std::string &name() const noexcept;
};

class Proficiencies {
    private:
        std::set<Proficiency> proficiencies;

    public:
        bool has(const Proficiency &proficiency) const;

        /** Add a proficiency, returning a false if it already existed and was not added.
         */
        bool add(Proficiency proficiency);

        // Iterator functions, allowing iterating through set proficiencies

        decltype(proficiencies)::const_iterator cbegin() const noexcept;
        decltype(proficiencies)::const_iterator begin() const noexcept;
        decltype(proficiencies)::const_iterator cend() const noexcept;
        decltype(proficiencies)::const_iterator end() const noexcept;
        decltype(proficiencies)::const_reverse_iterator crbegin() const noexcept;
        decltype(proficiencies)::const_reverse_iterator rbegin() const noexcept;
        decltype(proficiencies)::const_reverse_iterator crend() const noexcept;
        decltype(proficiencies)::const_reverse_iterator rend() const noexcept;
};
#endif
