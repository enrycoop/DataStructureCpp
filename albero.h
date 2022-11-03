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

#ifndef ALBERO_H
#define ALBERO_H
#include "lista.h"
#include <stdexcept>

void testAlbero();

/**
 * @todo write docs
 */
template <typename Item>                               
class Albero
{
public:
    typedef Albero<Item>* Node;
    
    Albero(){
        this->padre = NULL;
        this->fratello = NULL;
        this->primo_figlio = NULL;
    }
    /**
    * @todo Costruisce un nuovo albero, costruito da un solo nodo contenente v
    */
    Albero(Item v){
        this->valore = v;
        this->padre = NULL;
        this->fratello = NULL;
        this->primo_figlio = NULL;
    }
    
    /**
    *  legge il valore
    */
    Item read(){
        return valore;
    }
    /**
     * scrive v nel nodo
     */
    void write(Item v){
        this->valore = v;
    }
    /*
     * restituisce il padre, NULL se questo nodo è radice
     */
    Node getPadre(){
        return padre;
    }
    /*
     * restituisce il primo figlio; NULL se questo è forglia
     */
    Node getPrimoFiglio(){
        return primo_figlio;
    }
    /*
     * restituisce il prossimo fratello del nodo a cui è applicato; NULL se assente
     */
    Node getProssimoFratello(){
        return fratello;
    }
    /**
    * @todo inserisce il sottoalbero t come primo figlio di questo nodo
    * t.getPadre deve essere NULL; ossia deve essere radice
    * 
    */
    void inserisciFiglio(Node t){
        if(t->padre != NULL)
            throw std::invalid_argument("Inserimento di un nodo non radice");
        
        t->padre = this;
        t->fratello = primo_figlio;  // inserisce t prima del vecchio primo figlio (inserimento in testa)
        primo_figlio = t;
    }
    
    /**
    * @todo inserisce il sottoalbero t come successivo fratello di questo nodo
    * t.getPadre deve essere NULL; ossia deve essere radice
    */
    void inserisciFratello(Node t){
        if(t->padre != NULL)
            throw std::invalid_argument("Inserimento di un nodo non radice");
        
        t->padre = padre;
        t->fratello = fratello;
        fratello = t;
    }
    
    /*
     * Distrugge il sottoalbero radicato nel primo figlio di questo nodo
     * 
     */
    void cancellaFiglio(){
        Node newBorn = primo_figlio->getProssimoFratello();
        cancellaSottoalbero(primo_figlio);
        primo_figlio = newBorn;
    }
    
    /*
     * Distrugge il sottoalbero radicato nel prossimo fratello di questo nodo
     */
    void cancellaFratello(){
        Node newBro = fratello->getProssimoFratello();
        cancellaSottoalbero(fratello);
        fratello = newBro;
    }
    
    void printStd(){
        stampaAlbero(*this,"");
    }
    
private:
    Item valore;
    Node padre;
    Node primo_figlio;
    Node fratello;
    
    void cancellaSottoalbero(Node t){
        Node u = t->getPrimoFiglio();
        while (u != NULL){
            Node next = u->getProssimoFratello();
            cancellaSottoalbero(u);
            u = next;
        }
        delete t;
    }
    
    void stampaAlbero(Albero<Item> tree, std::string lvl){
        std::cout << lvl << tree.read() << std::endl;
        Albero<Item>::Node u = tree.getPrimoFiglio();
        while(u != nullptr){
            stampaAlbero(*u,lvl+"\t");
            u = u->getProssimoFratello();
        }
    }
};

#endif // ALBERO_H
