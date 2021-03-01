/*   
  Copyright (c) 2020 Eric Dürr Sierra, Todos los derechos reservados.

  Escuela Superior de Ingeniería y Tecnología.  
  Algoritmos y Estructuras de Datos Avanzados | ULL 2º curso de Ingeniería Informática
    
  Fecha de creación:            20/02/2021
  Fecha de última modificación: 22/02/2021
 
  Fichero para la implementación de los métodos 
  de la clase entorno

  Realizado por: Eric Dürr Sierra (alu0101027005)
  e-mail:        eric.durr.20@ull.edu.es
 */

#include "../include/entorno.h"

LangtonEnvironment::LangtonEnvironment(const int &n_rows, const int &n_cols,
                                       const int &ant_pos_i,
                                       const int &ant_pos_j,
                                       const direction &ant_dir)
    : cols_(n_cols), rows_(n_rows), steps_(0)
{

  if (ant_pos_i == -1 || ant_pos_j == -1)
  {
    ant_ = LangtonAnt{rows_ / 2, cols_ / 2, ant_dir}; // Default value (middle)
  }
  else
  {
    ant_ = LangtonAnt{ant_pos_i, ant_pos_j, ant_dir};
  }

  // Setting the grid to all
  for (int i = 0; i < n_rows; i++)
  {
    std::vector<direction_color> aux;
    for (int j = 0; j < n_cols; j++)
    {
      aux.push_back(WH);
    }
    grid_.push_back(aux);
  }
}

const bool LangtonEnvironment::all_white(void) const
{
  for (auto row : this->grid_)
    for (auto col : row)
      if (col == BL)
        return false;

  return true;
}

/* STRING OUTPUT METHOD */
const std::string LangtonEnvironment::to_string(void) const
{
  std::string output = "";

  /* top border */
  output += "\n┌";
  for (int k = 0; k < (cols_ * 3); k++)
    output += "─";
  output += "┐\n";
  /* ---------- */

  /* center part */

  for (int i = 0; i < rows_; i++)
  {
    output += "│";
    for (int j = 0; j < cols_; j++)
    {
      if (this->ant_at() == std::vector<int>{i, j})
      {
        output += (" " + ant_.to_string() + " ");
      }
      else
      {
        grid_[i][j] == WH ? output += "   " : output += " x ";
      }
    }
    output += "│\n";
  }
  /* ------------ */

  /* bottom border */
  output += "└";
  for (int k = 0; k < (cols_ * 3); k++)
    output += "─";
  output += "┘\n";
  /* ------------- */

  return output;
}

void LangtonEnvironment::step(const int &times)
{
  steps_ += times;
  direction_color current_slot;
  for (int i = 0; i < times; i++)
  {
    current_slot = grid_[ant_at()[0]][ant_at()[1]];

    grid_[ant_at()[0]][ant_at()[1]] = ant_.switch_color(current_slot);

    ant_.check_environment(current_slot);

    if (this->ant_hit_up())
      this->add_row_up(1);

    if (this->ant_hit_right())
      this->add_col_right(1);

    if (this->ant_hit_down())
      this->add_row_down(1);

    if (this->ant_hit_left())
      this->add_col_left(1);
  }
}

std::ostream &operator<<(std::ostream &os, const LangtonEnvironment &this_object)
{
  os << this_object.to_string();
  return os;
}

/* --- PRIVATE METHODS --- */

void LangtonEnvironment::add_col_right(const int &n)
{
  std::vector<std::vector<direction_color>> new_grid;
  // Creating new grid;
  for (int i = 0; i < rows_; i++)
  {
    std::vector<direction_color> aux;
    for (int j = 0; j < cols_ + n; j++)
    {
      aux.push_back(WH);
    }
    new_grid.push_back(aux);
  }

  // state copy
  for (int i = 0; i < rows_; i++)
  {
    for (int j = 0; j < cols_; j++)
    {
      new_grid[i][j] = grid_[i][j];
    }
  }

  // variable update
  cols_ += n;
  grid_ = new_grid;
}

void LangtonEnvironment::add_col_left(const int &n)
{
  std::vector<std::vector<direction_color>> new_grid;
  // Creating new grid;
  for (int i = 0; i < rows_; i++)
  {
    std::vector<direction_color> aux;
    for (int j = 0; j < cols_ + n; j++)
    {
      aux.push_back(WH);
    }
    new_grid.push_back(aux);
  }

  // state copy
  for (int i = 0; i < rows_; i++)
  {
    for (int j = 0; j < cols_; j++)
    {
      new_grid[i][j + n] = grid_[i][j];
    }
  }

  // variable update
  cols_ += n;
  grid_ = new_grid;
  ant_.mod_pos(this->ant_at()[0], this->ant_at()[1] + n);
}

void LangtonEnvironment::add_row_down(const int &n)
{
  std::vector<std::vector<direction_color>> new_grid;
  // Creating new grid;
  for (int i = 0; i < rows_ + n; i++)
  {
    std::vector<direction_color> aux;
    for (int j = 0; j < cols_; j++)
    {
      aux.push_back(WH);
    }
    new_grid.push_back(aux);
  }

  // state copy
  for (int i = 0; i < rows_; i++)
  {
    for (int j = 0; j < cols_; j++)
    {
      new_grid[i][j] = grid_[i][j];
    }
  }

  // variable update
  rows_ += n;
  grid_ = new_grid;
}

void LangtonEnvironment::add_row_up(const int &n)
{
  std::vector<std::vector<direction_color>> new_grid;
  // Creating new grid;
  for (int i = 0; i < rows_ + n; i++)
  {
    std::vector<direction_color> aux;
    for (int j = 0; j < cols_; j++)
    {
      aux.push_back(WH);
    }
    new_grid.push_back(aux);
  }

  // state copy
  for (int i = 0; i < rows_; i++)
  {
    for (int j = 0; j < cols_; j++)
    {
      new_grid[i + n][j] = grid_[i][j];
    }
  }

  // variable update
  rows_ += n;
  grid_ = new_grid;
  ant_.mod_pos(this->ant_at()[0] + n, this->ant_at()[1]);
}

const bool LangtonEnvironment::ant_hit_up(void) const
{
  return this->ant_at()[0] < 0;
}
const bool LangtonEnvironment::ant_hit_right(void) const
{
  return this->ant_at()[1] >= cols_;
}
const bool LangtonEnvironment::ant_hit_down(void) const
{
  return this->ant_at()[0] >= rows_;
}
const bool LangtonEnvironment::ant_hit_left(void) const
{
  return this->ant_at()[1] < 0;
}