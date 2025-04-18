/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:28:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/18 18:31:41 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#define MAX_INV_SIZE 4

class AMateria;

class Character : public ICharacter
{
    public:
        Character();
        Character(const Character &other);
        Character &operator=(const Character &other);
        ~Character();
        Character(std::string name);
        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria* getMateria(int idx) const;
        void setName(std::string name);
    private:
        AMateria* _dropped_items[100];
        std::string _name;
        AMateria* _inventory[MAX_INV_SIZE];
        void clearInventory();
        void copyInventory(const Character &other);
};

#endif // CHARACTER_HPP