/* -*- c++ -*- */
/*
 * Copyright 2014 Communications Engineering Lab, KIT
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

#ifndef INCLUDED_SPECEST_ARFMCOV_VCC_IMPL_H
#define INCLUDED_SPECEST_ARFMCOV_VCC_IMPL_H

#include <specest/arfmcov_algo.h>
#include <specest/arfmcov_vcc.h>

namespace gr {
namespace specest {

class arfmcov_vcc_impl : public arfmcov_vcc
{
private:
    unsigned d_blocklen; //!< Number of input samples per calculation
    unsigned d_order;    //!< Order of the AR model
    int d_normalise;
    arfmcov_algo* d_fmcov;

public:
    arfmcov_vcc_impl(unsigned blocklen, unsigned order, int normalise);
    ~arfmcov_vcc_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace specest
} // namespace gr

#endif /* INCLUDED_SPECEST_ARFMCOV_VCC_IMPL_H */
