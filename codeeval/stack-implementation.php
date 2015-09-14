<?php
/**
 * The code is my solution to the problem STACK IMPLEMENTATION
 * on codeeval.com.
 * https://www.codeeval.com/open_challenges/9/
 */
//$fh = fopen($argv[1], "r");
$fh = fopen('sample.txt', "r");
while (true) {
  $test = fgets($fh);
  if (empty($test)) {
    exit(0);
  }
  $op = get_reverse($test);
  echo $op . PHP_EOL;
}

function get_reverse($str) {
  $arr_nums = explode(' ', $str);
  $arr_nums = array_reverse($arr_nums);
  $ret_arr = array();
  for ($i = 0; $i < count($arr_nums); $i+=2) {
    $ret_arr[] = (int)$arr_nums[$i];
  }
  return implode(' ', $ret_arr);
}
?>