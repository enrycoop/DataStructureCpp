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

#ifndef LISTA_H
#define LISTA_H
#include <iostream>


template<typename Item>
class Lista
{
public:
    /*
     * Abstraction Type for position in the list
     */
    typedef Lista<Item>* Pos; 
    /**
     * Default constructor
     */
    Lista(){
        this->succ = this;
        this->pred = this;
    }
    
    bool isEmpty(){ return (pred==succ) && (pred == this);}
    
    Pos head() { return succ; }
    
    Pos tail() { return pred; }
    
    Pos next(Pos p) { return p->succ; }
    
    Pos prev(Pos p) { return p->pred; }
    
    bool finished(Pos p) { return p==this; }
    
    Item read(Pos p){ return p->value; }
    
    void write(Pos p, Item v) { p->value = v; }
    
    Pos insert(Pos p, Item v) {
        bool first = isEmpty();
        Pos t = new Lista;
        t->value = v;
        t->succ = p->succ;
        t->succ->pred = t;
        t->pred = p;
        p->succ = t;
        return t;
    }
    
    Pos remove(Pos p) {
    
        p->pred->succ = p->succ;
        p->succ->pred = p->pred;
        Pos t = p->succ;
        delete p;
        return t;
    }
    
    void print(){
        if(isEmpty()){
            std::cout << "[ ]" << std::endl;
        }
        
        std::cout << "[ ";
        Pos t = head();
        while(!finished(t)){
            std::cout << t->value << " ";
            t = next(t);
        }
        std::cout << "]";
    }
    
    void println(){
        print();
        std::cout << std::endl;
    }
    
    
    
private:
    Pos pred;
    Pos succ;
    Item value;
};

#endif // LISTA_H
