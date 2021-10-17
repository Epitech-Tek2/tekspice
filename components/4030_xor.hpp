/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#ifndef NTS_4030_XOR_HPP
#define NTS_4030_XOR_HPP

#include <string>
#include <array>
#include <vector>
#include <map>
#include "IComponent.hpp"

#define LKINFO std::pair<IComponent *, std::size_t>

namespace nts
{
    class Xor4030 : public nts::IComponent
    {
    public:
	Xor4030() noexcept;
        ~Xor4030() = default;

	void setName(std::string &name) noexcept;
	
        void simulate(std::size_t tick) noexcept;
        nts::Tristate compute(std::size_t pin) noexcept;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept;
        void dump() const noexcept;
    private:
	std::string _name;
	std::array<nts::Tristate, 14> _values;
	std::map<std::size_t, LKINFO> _lks;

	void computeOutput(const std::size_t pin) noexcept;
	void computeInput(const std::size_t pin) noexcept;
	nts::Tristate xorBlock(const std::size_t pin1, const std::size_t pin2) noexcept;
    };
}

#endif /* NTS_4030_HPP */
