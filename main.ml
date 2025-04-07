(* Calculate the mean *)
let calculate_mean arr =
  let sum = List.fold_left ( + ) 0 arr in
  float_of_int sum /. float_of_int (List.length arr)

(* Calculate the median *)
let calculate_median arr =
  let sorted = List.sort compare arr in
  let n = List.length sorted in
  if n mod 2 = 1 then
    float_of_int (List.nth sorted (n / 2))
  else
    let mid1 = List.nth sorted (n / 2 - 1) in
    let mid2 = List.nth sorted (n / 2) in
    (float_of_int (mid1 + mid2)) /. 2.0

(* Calculate the mode *)
let calculate_mode arr =
  let count_occurrences lst elem =
    List.fold_left (fun acc x -> if x = elem then acc + 1 else acc) 0 lst
  in
  let unique_elements = List.sort_uniq compare arr in
  let occurrences =
    List.map (fun x -> (x, count_occurrences arr x)) unique_elements
  in
  let max_count =
    List.fold_left (fun acc (_, count) -> max count acc) 0 occurrences
  in
  List.iter
    (fun (x, count) ->
      if count = max_count then Printf.printf "%d " x)
    occurrences;
  print_newline ()

(* Main function *)
let () =
  let data = [4; 5; 6; 7; 4; 3; 4] in
  Printf.printf "Mean: %.2f\n" (calculate_mean data);
  Printf.printf "Median: %.2f\n" (calculate_median data);
  Printf.printf "Mode(s): ";
  calculate_mode data