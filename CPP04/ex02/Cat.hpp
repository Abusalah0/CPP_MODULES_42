/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:20:41 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/14 12:06:05 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &other);
        ~Cat();
        Cat &operator=(const Cat &other);
  
        void makeSound() const;
        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);
};

#endif //CAT_HPP    