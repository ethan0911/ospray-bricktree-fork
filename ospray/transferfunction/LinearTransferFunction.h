/********************************************************************* *\
 * INTEL CORPORATION PROPRIETARY INFORMATION                            
 * This software is supplied under the terms of a license agreement or  
 * nondisclosure agreement with Intel Corporation and may not be copied 
 * or disclosed except in accordance with the terms of that agreement.  
 * Copyright (C) 2014 Intel Corporation. All Rights Reserved.           
 ********************************************************************* */

#pragma once

#include <vector>
#include "ospray/transferfunction/TransferFunction.h"
#include "LinearTransferFunction_ispc.h"

namespace ospray {

    //! \brief A concrete implementation of the TransferFunction class for
    //!  piecewise linear transfer functions.
    //!
    class LinearTransferFunction : public TransferFunction {
    public:

        //! Constructor.
        LinearTransferFunction() {}

        //! Destructor.
        virtual ~LinearTransferFunction() { if (ispcEquivalent != NULL) ispc::LinearTransferFunction_destroy(ispcEquivalent); }

        //! Allocate storage and populate the transfer function.
        virtual void commit();

        //! A string description of this class.
        virtual std::string toString() const { return("ospray::LinearTransferFunction"); }

    protected:

        //! Create the equivalent ISPC transfer function.
        virtual void createEquivalentISPC();

    };

} // namespace ospray

