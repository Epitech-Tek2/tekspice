/*
** EPITECH PROJECT, 2020
** Clement-Muth && Sarah-Keppler
*/

#include <iostream>
#include "4011_nand.hpp"

nts::Nand4011::Nand4011() noexcept
{
    _values.fill(nts::Tristate::UNDEFINED);
    std::pair<IComponent *, std::size_t> defPair{nullptr, 0};

    for (int i = 0; 14 > i; ++i)
	_lks.insert(std::pair<std::size_t, LKINFO>{i + 1, defPair});
}

void nts::Nand4011::setName(std::string &name) noexcept
{
    _name = name;
}

void nts::Nand4011::simulate(std::size_t tick) noexcept
{
    return;
    std::cout << tick << std::endl;
}

nts::Tristate nts::Nand4011::compute(std::size_t pin) noexcept
{
    if (3 == pin || 4 == pin || 11 == pin || 10 == pin)
	computeOutput(pin);
    else
	computeInput(pin);
    return _values[pin - 1];
}

void nts::Nand4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept
{
    _lks[pin].first = &other;
    _lks[pin].second = otherPin;
}

void nts::Nand4011::dump() const noexcept
{
    std::cout << " composant 4011nand:" << std::endl;
    for (std::size_t it = 0, et = _values.size(); et != it; ++it)
	if (it && 7 != it && 14 != it) {
	    std::cout << "  pin " << it << ": ";
	    if (nts::Tristate::UNDEFINED == _values[it - 1])
		std::cout << "U" << std::endl;
	    else
		std::cout << _values[it - 1] << std::endl;
	}
}

void nts::Nand4011::computeOutput(const std::size_t pin) noexcept
{
    if (3 == pin) {
	computeInput(1);
	computeInput(2);
	_values[pin - 1] = nandBlock(1, 2);
    } else if (4 == pin) {
	computeInput(6);
	computeInput(5);
	_values[pin - 1] = nandBlock(6, 5);
    } else if (11 == pin) {
	computeInput(12);
	computeInput(13);
	_values[pin - 1] = nandBlock(12, 13);
    } else if (10 == pin) {
	computeInput(8);
	computeInput(9);
	_values[pin - 1] = nandBlock(8, 9);
    }
}

void nts::Nand4011::computeInput(const std::size_t pin) noexcept
{
    if (!_lks[pin].first)
	return;
    _values[pin - 1] = _lks[pin].first->compute(_lks[pin].second);
}

nts::Tristate nts::Nand4011::nandBlock(const std::size_t pin1, const std::size_t pin2) noexcept
{
    nts::Tristate vpin1 = _values[pin1 - 1], vpin2 = _values[pin2 - 1];
    if (nts::Tristate::TRUE == vpin1 && nts::Tristate::TRUE == vpin2)
	return nts::Tristate::FALSE;
    if ((nts::Tristate::UNDEFINED == vpin1 && nts::Tristate::TRUE == vpin2) ||
	(nts::Tristate::UNDEFINED == vpin1 && nts::Tristate::UNDEFINED == vpin2) ||
	(nts::Tristate::TRUE == vpin1 && nts::Tristate::UNDEFINED == vpin2))
	return nts::Tristate::UNDEFINED;
    return nts::Tristate::TRUE;
}
