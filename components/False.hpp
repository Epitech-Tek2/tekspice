/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#ifndef NTS_FALSE_HPP
#define NTS_FALSE_HPP

#include <string>
#include "IComponent.hpp"

namespace nts
{
    class False : public nts::IComponent
    {
    public:
	False() = default;
        ~False() = default;

	void setName(std::string &name) noexcept;
	
        void simulate(std::size_t tick) noexcept;
        nts::Tristate compute(std::size_t pin) noexcept;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept;
        void dump() const noexcept;
    private:
	std::string _name;
	IComponent *_lkComp;
	std::size_t _lkPin;
    };
}

#endif /* NTS_FALSE_HPP */
