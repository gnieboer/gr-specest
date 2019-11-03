/* -*- c++ -*- */
/*
 * Copyright 2010,2013 Communications Engineering Lab, KIT
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

#ifndef INCLUDED_SPECEST_ESPRIT_VCF_H
#define INCLUDED_SPECEST_ESPRIT_VCF_H

#include <gnuradio/sync_block.h>
#include <specest/api.h>

namespace gr {
namespace specest {

/*! ESPRIT Parametric Spectrum Estimator
 *
 * This block will consume \p nsamples as a vector, and will then output \p
 * omega values as estimates.
 *
 * Note: This is a wrapper around the ZESPRIT() function.
 *
 * \ingroup specest
 */
class SPECEST_API esprit_vcf : virtual public gr::sync_block
{
public:
    typedef boost::shared_ptr<esprit_vcf> sptr;

    /*!
     * \param n Number of sinusoids to be modeled
     * \param m Dimensionality of covariance matrix R
     * \param nsamples Number of samples per estimate
     */
    static sptr make(unsigned int n, unsigned int m, unsigned int nsamples);
};

} // namespace specest
} // namespace gr

#endif /* INCLUDED_SPECEST_ESPRIT_VCF_H */
