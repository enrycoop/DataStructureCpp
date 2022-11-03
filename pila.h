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

#ifndef PILA_H
#define PILA_H
#include "lista.h"

/**
 * @todo write docs
 */
template <typename Item>
class Pila
{
public:
    Pila();
    
    bool isEmpty();
    
    void push(Item v);
    
    Item pop();
    
    Item top();
    
    void println();
    
    void print();
    
private:
    Lista<Item> items = Lista<Item>();
};

template <typename Item>
Pila<Item>::Pila(){}

template <typename Item>
bool Pila<Item>::isEmpty() {return this->items.isEmpty(); }

template <typename Item>
void Pila<Item>::push(Item v){
    items.print();
    std::cout << " <- " << v << std::endl;
    items.insert(items.tail(),v);
}

template <typename Item>
Item Pila<Item>::pop() {
    Item p = items.read(items.tail());
    items.remove(items.tail());
    
    items.print();
    std::cout << " -> " << p << std::endl;
    return p;
}

template <typename Item>
Item Pila<Item>::top(){
    return items.read(items.tail());
}

template <typename Item>
void Pila<Item>::println(){
    items.println();
}

template <typename Item>
void Pila<Item>::print(){
    items.print();
}

#endif // PILA_H
