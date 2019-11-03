/* -*- c++ -*- */
/*
 * Copyright 2011 Communications Engineering Lab, KIT
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <specest/esprit_fortran_algo.h>
#include <stdexcept>

extern "C" {
void zesprit_(const gr_complexd* samples,
              unsigned int* ldata,
              unsigned int* n,
              unsigned int* m,
              double* omegas);
void zesprit_spectrum_(const gr_complexd* samples,
                       unsigned int* ldata,
                       unsigned int* n,
                       unsigned int* m,
                       double* pspectrum,
                       unsigned int* lpspectrum);
}

namespace gr {
namespace specest {

esprit_fortran_algo::esprit_fortran_algo(unsigned n, unsigned m) : d_n(n), d_m(m)
{
    if (n > m)
        throw std::invalid_argument("esprit_fortran_algo: n cannot exceed m in length.");
}


esprit_fortran_algo::~esprit_fortran_algo() {}

void esprit_fortran_algo::calculate(const gr_complexd* data,
                                    unsigned int data_len,
                                    double* omegas)
{
    zesprit_(data, &data_len, &d_n, &d_m, omegas);
}

void esprit_fortran_algo::calculate_pseudospectrum(const gr_complexd* data,
                                                   unsigned int data_len,
                                                   double* pspectrum,
                                                   unsigned int pspectrum_len)
{
    zesprit_spectrum_(data, &data_len, &d_n, &d_m, pspectrum, &pspectrum_len);
}

} /* namespace specest */
} /* namespace gr */
