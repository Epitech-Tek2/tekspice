/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include "IComponent.hpp"

namespace nts
{
    class Input : public nts::IComponent
    {
    public:
	Input() noexcept;
        ~Input() = default;

	void setName(std::string &name) noexcept;
	void setValue(nts::Tristate value) noexcept;
	
        void simulate(std::size_t tick) noexcept;
        nts::Tristate compute(std::size_t pin) noexcept;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept;
        void dump() const noexcept;
    private:
	std::string _name;
	IComponent *_lkComp;
	std::size_t _lkPin;
	nts::Tristate _valuePin;
    };
}

#endif /* INPUT_HPP */
