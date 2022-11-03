/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2022  <copyright holder> <email>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CODA_H
#define CODA_H
#include "lista.h"

/**
 * @todo write docs
 */
template <typename Item>
class Coda
{
public:
    Coda();
    
    bool isEmpty();
    
    void enqueque(Item v);
    
    Item dequeque();
    
    Item top();
    
    void print();
    
    void println();
    
private:
    Lista<Item> items = Lista<Item>();
};


template <typename Item>
Coda<Item>::Coda(){}

template <typename Item>
bool Coda<Item>::isEmpty() {return this->items.isEmpty(); }

template <typename Item>
void Coda<Item>::enqueque(Item v){
    items.print();
    std::cout << " <- " << v << std::endl;
    items.insert(items.tail(),v);
}

template <typename Item>
Item Coda<Item>::dequeque() {
    Item p = items.read(items.head());
    items.remove(items.head());
    
    std::cout << p << " <- ";
    items.println();
    
    return p;
}

template <typename Item>
Item Coda<Item>::top(){
    return items.read(items.head());
}

template <typename Item>
void Coda<Item>::println(){
    items.println();
}

template <typename Item>
void Coda<Item>::print(){
    items.print();
}

#endif // CODA_H
