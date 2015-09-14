<?php
/**
 * The code is my solution to the problem STRING SUBSTITUTION
 * on codeeval.com.
 * https://www.codeeval.com/public_sc/50/
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
  $arr_main = explode(';', $str);
  $str_main = $arr_main[0];
  if (!(trim($arr_main[1]))) {
    return $str_main;
  }
  $arr_replacements = explode(',', $arr_main[1]);
  $arr_dict = array();
  for ($i = 0; $i < count($arr_replacements); $i += 2) {
    $str_main = str_replace($arr_replacements[$i], '[' . $i . ']', $str_main);
    $arr_dict[$i] = $arr_replacements[$i + 1];
  }
  foreach ($arr_dict as $key => $val) {
    $str_main = str_replace('[' . $key . ']', $val, $str_main);
  }
  $str_main = preg_replace('/\s+/', '', $str_main);
  return trim($str_main);
}
?>