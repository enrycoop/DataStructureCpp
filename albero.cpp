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

#include "albero.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

void testAlbero(){
    Albero<string> tree = Albero<string>("Regno Vegetale");
    tree.inserisciFiglio(new Albero<string>("Crittogame"));
    tree.getPrimoFiglio()->inserisciFiglio(new Albero<string>("Tallofite"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Cianoficee"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Batteri"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Alghe"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Mixomiceti"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Funghi"));
    tree.getPrimoFiglio()->inserisciFiglio(new Albero<string>("Archegoniate"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Briofite"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Pteridofite"));
    
    tree.inserisciFiglio(new Albero<string>("Fanerogame"));
    
    tree.getPrimoFiglio()->inserisciFiglio(new Albero<string>("Gimnosperme"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Cicadali"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Ginkgoali"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Coniferali"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Gnetali"));
    tree.getPrimoFiglio()->inserisciFiglio(new Albero<string>("Angiosperme"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Dicotiledoni"));
    tree.getPrimoFiglio()->getPrimoFiglio()->inserisciFiglio(new Albero<string>("Monocotiledoni"));
    tree.printStd();
}
