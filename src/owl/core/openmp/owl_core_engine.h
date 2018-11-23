/*
 * OWL - OCaml Scientific and Engineering Computing
 * Copyright (c) 2016-2018 Liang Wang <liang.wang@cl.cam.ac.uk>
 */

#ifndef OWL_CORE_ENGINE_H
#define OWL_CORE_ENGINE_H

#include "owl_aeos_params_generated.h"

// threshold of the ndarray size to trigger openmp
#define OWL_OMP_THRESHOLD_DEFAULT 100000


#ifdef _OPENMP
  // choose OpenMP engine
  #define OWL_MATRIX_SWAP_IMPL   "owl_matrix_swap_impl_omp.h"
  #define OWL_NDARRAY_MATHS_CMP  "owl_ndarray_maths_cmp_omp.h"
  #define OWL_NDARRAY_MATHS_MAP  "owl_ndarray_maths_map_omp.h"
  #define OWL_NDARRAY_MATHS_FOLD "owl_ndarray_maths_fold_omp.h"
  #define OWL_SLICING_BASIC_IMPL "owl_slicing_basic_impl_omp.h"

#else
  // choose CPU engine
  #define OWL_MATRIX_SWAP_IMPL   "owl_matrix_swap_impl.h"
  #define OWL_NDARRAY_MATHS_CMP  "owl_ndarray_maths_cmp.h"
  #define OWL_NDARRAY_MATHS_MAP  "owl_ndarray_maths_map.h"
  #define OWL_NDARRAY_MATHS_FOLD "owl_ndarray_maths_fold.h"
  #define OWL_SLICING_BASIC_IMPL "owl_slicing_basic_impl.h"

#endif  /* _OPENMP */


/* Default tunable OpemMP paramters */

#define OWL_OMP_THRESHOLD_FUN_(A) OMP_THRESHOLD ## _ ## A
#define OWL_OMP_THRESHOLD_FUN(A) OWL_OMP_THRESHOLD_FUN_(A)

#ifndef OWL_AEOS_PARAMS_H

#define OMP_THRESHOLD OWL_OMP_THRESHOLD_DEFAULT

// FUN4

#define OWL_OMP_THRESHOLD_RECI OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ABS OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ABS2 OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_SIGNUM OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_SQR OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_SQRT OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_CBRT OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_EXP OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_EXPM1 OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_LOG OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_LOG1P OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_SIN OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_COS OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_TAN OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ASIN OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ACOS OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ATAN OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_SINH OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_COSH OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_TANH OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ASINH OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ACOSH OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ATANH OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ERF OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_ERFC OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_LOGISTIC OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_RELU OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_SOFTPLUS OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_SOFTSIGN OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_SIGMOID OMP_THRESHOLD

// FUN5

#define OWL_OMP_THRESHOLD_SUM OMP_THRESHOLD

#define OWL_OMP_THRESHOLD_PROD OMP_THRESHOLD


#endif

#endif  /* OWL_CORE_ENGINE_H */
