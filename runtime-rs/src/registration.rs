use super::container::ContainerHandle;
use leetcode_rs::{problems, solutions};

macro_rules! register {
    ($handle:ident, $name:ident) => {
        $handle.register_problem(|_| problems::$name::ProblemImpl)?;
        $handle.register_solution(|_| solutions::$name::SolutionImpl)?;
    };
}

pub fn register_all(handle: ContainerHandle) -> anyhow::Result<()> {
    register!(handle, two_sum);

    register!(handle, add_two_numbers);

    register!(handle, longest_substring);
    handle.register_solution(|_| {
        solutions::longest_substring::SolutionImplHashMap
    })?;

    register!(handle, median_of_two_sorted_arrays);

    register!(handle, longest_palindromic_substring);
    handle.register_solution(|_| {
        solutions::longest_palindromic_substring::SolutionImplDP
    })?;

    register!(handle, zigzag_conversion);

    register!(handle, reverse_integer);

    register!(handle, string_to_integer);

    register!(handle, palindrome_number);

    register!(handle, regular_expression_matching);

    register!(handle, container_with_most_water);

    register!(handle, swap_nodes_in_pairs);

    register!(handle, remove_duplicates_from_sorted_array);

    register!(handle, find_first_occurrence);

    register!(handle, substring_with_concatenation);

    register!(handle, longest_valid_parentheses);

    register!(handle, find_first_last_in_sorted_array);

    register!(handle, search_insert_position);

    register!(handle, valid_sudoku);

    register!(handle, sudoku_solver);

    register!(handle, count_and_say);

    register!(handle, combination_sum);

    register!(handle, combination_sum2);

    register!(handle, first_missing_positive);

    register!(handle, trapping_rain_water);

    register!(handle, multiply_strings);

    register!(handle, wildcard_matching);

    register!(handle, jump_game_ii);

    register!(handle, permutations);

    register!(handle, permutations_ii);

    register!(handle, rotate_image);

    register!(handle, group_anagrams);

    register!(handle, pow_x_n);

    register!(handle, maximum_subarray);

    register!(handle, jump_game);

    register!(handle, unique_paths);

    register!(handle, unique_paths_ii);

    register!(handle, minimum_path_sum);

    register!(handle, climbing_stairs);

    register!(handle, rotate_list);

    register!(handle, sort_colors);

    register!(handle, remove_duplicates_from_sorted_array_ii);

    register!(handle, best_time_to_buy_and_sell_stock);

    register!(handle, best_time_to_buy_and_sell_stock_ii);

    register!(handle, gas_station);

    register!(handle, candy);

    register!(handle, largest_number);

    register!(handle, set_matrix_zeroes);

    register!(handle, minimum_window_substring);

    register!(handle, spiral_matrix);

    register!(handle, merge_intervals);

    register!(handle, insert_interval);

    register!(handle, length_of_last_word);

    register!(handle, spiral_matrix_ii);

    register!(handle, plus_one);

    register!(handle, add_binary);

    register!(handle, sqrtx);

    register!(handle, simplify_path);

    register!(handle, n_queens);

    register!(handle, n_queens_ii);

    register!(handle, permutation_sequence);

    register!(handle, valid_number);

    register!(handle, edit_distance);

    register!(handle, text_justification);

    register!(handle, search_2d_matrix);

    register!(handle, combinations);

    register!(handle, subsets);

    register!(handle, word_search);

    register!(handle, search_in_rotated_sorted_array_ii);

    register!(handle, house_robber_ii);

    register!(handle, combination_sum_iii);

    register!(handle, contains_duplicate);

    register!(handle, contains_duplicate_ii);

    register!(handle, maximal_square);

    register!(handle, invert_binary_tree);

    register!(handle, basic_calculator);

    register!(handle, basic_calculator_ii);

    Ok(())
}
