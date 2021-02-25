/*   
  Copyright (c) 2020 Eric Dürr Sierra, Todos los derechos reservados.

  Escuela Superior de Ingeniería y Tecnología.  
  Algoritmos y Estructuras de Datos Avanzados | ULL 2º curso de Ingeniería Informática
    
  Fecha de creación:            20/02/2021
  Fecha de última modificación: 22/02/2021
 
  Fichero que describe la clase que representa 
  el entorno donde se mueve el objeto hormiga.

  Realizado por: Eric Dürr Sierra (alu0101027005)
  e-mail:        eric.durr.20@ull.edu.es
 */

#include <iostream>
#include <vector>
#include <string>

#include "hormiga.h"

class LangtonEnvironment
{
private:
  int cols_, rows_;
  std::vector<std::vector<direction_color>> grid_;
  LangtonAnt ant_;

public:
  LangtonEnvironment(const int &n_rows, const int &n_cols,
                     int ant_pos_i, int ant_pos_j);

  inline const int size(void) const
  {
    return (cols_ * rows_);
  }
  inline const int &cols(void) const { return cols_; }
  inline const int &rows(void) const { return rows_; }
};