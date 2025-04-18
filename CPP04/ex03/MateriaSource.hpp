/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:30:03 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/18 14:53:37 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        ~MateriaSource();
        MateriaSource &operator=(const MateriaSource &other);
        
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
        
    private:
        AMateria* _materias[4];
};

#endif // MateriaSource
