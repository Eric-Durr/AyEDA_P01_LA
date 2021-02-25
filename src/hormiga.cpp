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

const int LangtonAnt::current_dir(void) const { return dir_; }
void LangtonAnt::mod_dir(const int &new_dir) { dir_ = new_dir; };

const int LangtonAnt::check_environment(const bool &slot_color)
{
  if (slot_color == WH)
  {
    rotate_ant(WH);
    move_ant();
    return WH;
  }
  else if (slot_color == BL)
  {
    rotate_ant(BL);
    move_ant();
    return BL;
  }
  else
  {
    return -1;
  }
}

std::string LangtonAnt::to_string(void) const
{
  switch (this->dir_)
  {
  case UP:
    return "↑";
    break;
  case RI:
    return "→";
    break;
  case DO:
    return "↓";
    break;
  case LE:
    return "←";
    break;
  default:
    return "?";
    break;
  }
}

// Private methods

void LangtonAnt::rotate_ant(int rule)
{
  switch (rule)
  {
  case WH:
    this->dir_ == UP ? (dir_ = LE) : (dir_ = this->current_dir() - 1);
    break;

  case BL:
    this->dir_ == LE ? (dir_ = UP) : (dir_ = this->current_dir() + 1);
    break;

  default:
    break;
  }
}
void LangtonAnt::move_ant(void)
{
  switch (this->dir_)
  {
  case UP:
    this->mod_pos(pos_i_ - 1, pos_j_);
    break;
  case RI:

    this->mod_pos(pos_i_, pos_j_ + 1);
    break;
  case DO:

    this->mod_pos(pos_i_ + 1, pos_j_);
    break;
  case LE:

    this->mod_pos(pos_i_, pos_j_ - 1);
    break;
  default:
    break;
  }
}
