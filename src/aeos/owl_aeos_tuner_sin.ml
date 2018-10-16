(*
 * OWL - OCaml Scientific and Engineering Computing
 * Copyright (c) 2016-2018 Liang Wang <liang.wang@cl.cam.ac.uk>
 *)

open Owl
open Owl_core_types

module N = Dense.Ndarray.S

open Bigarray

external baseline_float32_sin : int -> ('a, 'b) owl_arr -> ('a, 'b) owl_arr -> unit = "float32_sin"


let baseline_sin : type a b. (a, b) kind -> (a, b) owl_arr_op09 = fun k l x y ->
  match k with
  | Float32   -> baseline_float32_sin l x y
  | _         -> failwith "sin_baseline: unsupported operation"

let sizes = [|10; 100; 1000; 10000; 100000; 500000; 1000000|]


type t = {
  mutable c_macro : string;
  mutable measure : float array array;
  mutable params  : int;
}


let make () = {
  c_macro = "OWL_OMP_THRESHOLD_SIN"; (* [| OWL_OMP_THRESHOLD_SIN |] *)
  measure = [| [||]; [||] |];
  params  = max_int;
}


let tune t =
  Owl_log.info "AEOS: tune sin ...";
  (* Call C stub function to do measurement, then regression *)

  (*
   * 1. choose two different functions: current impl; non-omp version (impl the latter in stub.c file?)
   * 2. eval them at specified sizes: val1 = [|...|]; val2 = [|.....|]
   * 3. Lialg.intersect (val1, val2)
  *)

  let val1 = Array.make (Array.length sizes) 0. in
  let val2 = Array.make (Array.length sizes) 0. in

  Array.iteri (fun i sz ->
    let v1, _ = Owl_aeos_utils.timing
      (Owl_aeos_utils.eval_single_op Owl_ndarray._owl_sin sz) "sin" in
    let v2, _ = Owl_aeos_utils.timing
      (Owl_aeos_utils.eval_single_op baseline_sin sz) "sin_baseline" in
    val1.(i) <- v1;
    val2.(i) <- v2
  ) sizes;

  t.measure.(0) <- val1;
  t.measure.(1) <- val2;
  t.params <- Owl_aeos_utils.regression t.measure;
  ()

let to_string t =
  Printf.sprintf "#define %s %s" t.c_macro (string_of_int t.params)
