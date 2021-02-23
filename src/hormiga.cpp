/*   
  Copyright (c) 2020 Eric Dürr Sierra, Todos los derechos reservados.

  Escuela Superior de Ingeniería y Tecnología.  
  Algoritmos y Estructuras de Datos Avanzados | ULL 2º curso de Ingeniería Informática
    
  Fecha de creación:            20/02/2021
  Fecha de última modificación: 22/02/2021
 
  Fichero para la implementación de los métodos 
  de la clase hormiga
  
  Realizado por: Eric Dürr Sierra (alu0101027005)
  e-mail:        eric.durr.20@ull.edu.es
 */

#include "../include/hormiga.h"

LangtonAnt::LangtonAnt(int pos_i, int pos_j, direction dir) : pos_i_(pos_i), pos_j_(pos_j), dir_(dir) {}

const std::vector<int> LangtonAnt::current_pos(void) const { return std::vector<int>{pos_i_, pos_j_}; }

void LangtonAnt::mod_pos(const int &new_i, const int &new_j)
{
  pos_i_ = new_i;
  pos_j_ = new_j;
}

const direction LangtonAnt::current_dir(void) const { return dir_; }
void LangtonAnt::mod_dir(const direction &new_dir) { dir_ = new_dir; };
