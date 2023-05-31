/*******************************************************************************
    Copyright (c) 2016-2023 NVIDIA Corporation

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

        The above copyright notice and this permission notice shall be
        included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.

*******************************************************************************/

#include "uvm_hmm.h"

// TODO: Bug 1750144: Enable HMM by default once the feature is formally
// enabled for production use.

// Support for HMM ( https://docs.kernel.org/mm/hmm.html ). HMM features are
// disabled in this driver because they are still in development. In order to
// experiment with the early, "alpha" version of HMM features in this driver,
// set "uvm_disable_hmm=0" on the kernel or module loading command line.
// However, again:
//
//    HMM FEATURES IN THIS DRIVER ARE UNSUPPORTED BECAUSE THEY ARE NOT READY.
//
//    ENABLING HMM IN THIS DRIVER MAY CAUSE YOUR KERNEL TO CRASH, CORRUPT DATA,
//    OR OTHERWISE MISBEHAVE. DO NOT ENABLE HMM HERE UNLESS YOU ARE FULLY
//    PREPARED TO DEAL WITH THE INEVITABLE BUGS AND LIMITATIONS IN THIS ALPHA
//    FEATURE.
//
static bool uvm_disable_hmm = true;
module_param(uvm_disable_hmm, bool, 0444);
MODULE_PARM_DESC(uvm_disable_hmm,
                 "Force-disable HMM functionality in the UVM driver. "
                 "Default: true. Setting to false potentially enables HMM. USE "
                 "AT YOUR OWN RISK: HMM FEATURES ARE NOT READY IN THIS DRIVER. "
                 "Also, even with uvm_disable_hmm=false, HMM will not be "
                 "enabled if is not supported in this driver build "
                 "configuration, or if ATS settings conflict with HMM.");

