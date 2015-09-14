<?php
/**
 * The code is my solution to the problem MTH TO LAST ELEMENT
 * on codeeval.com.
 * https://www.codeeval.com/public_sc/10/
 */
$fh = fopen($argv[1], "r");
//$fh = fopen('sample.txt', "r");
while (true) {
  $test = fgets($fh);
  if (empty($test)) {
    exit(0);
  }
  $op = get_op($test);
  echo $op . PHP_EOL;
}

function get_op($str) {
  $arr_chars = explode(' ', $str);
  $arr_chars = array_reverse($arr_chars);
  return $arr_chars[(int)$arr_chars[0]];
}
?>