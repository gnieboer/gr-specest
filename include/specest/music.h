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

#ifndef INCLUDED_SPECEST_MUSIC_H
#define INCLUDED_SPECEST_MUSIC_H

#include <gnuradio/hier_block2.h>
#include <specest/api.h>

namespace gr {
namespace specest {

/*! Convenience class to generate the MUSIC pseudospectrum
 *
 * This is a convenience wrapper around music_spectrum_vcf. It will automatically
 * convert sample streams to vectors.
 *
 * The estimator works on complex samples, if \p decimation is not set
 * it will attempt to work on the full samplerate. However if \p decimation is set
 * to anything else than one, it will throw away vectors of samples of length
 * \p nsamples to win some time for calculation.
 *
 * \ingroup specest
 *
 */
class SPECEST_API music : virtual public gr::hier_block2
{
public:
    typedef boost::shared_ptr<music> sptr;

    //! Return current decimation value
    virtual unsigned int decimation() = 0;

    //! Update current decimation value
    virtual void set_decimation(unsigned int n) = 0;

    /*!
     * \param n How many sinusoids does your model have?
     * \param m use a correlation matrix of dimension m x m
     * \param nsamples use \p nsamples to get an estimate of the correlation matrix
     * \param pspectrum_len length of the generated pseudospectrum
     * \param decimation process only one in \p decimation vectors of length \p nsamples.
     *                   Can be used to win some time for calculations.
     */
    static sptr make(unsigned int n,
                     unsigned int m,
                     unsigned int nsamples,
                     unsigned int pspectrum_len,
                     unsigned int decimation);
};

} // namespace specest
} // namespace gr

#endif /* INCLUDED_SPECEST_MUSIC_H */
