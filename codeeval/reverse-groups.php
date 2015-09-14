<?php
/**
 * The code is my solution to the problem REVERSE GROUPS
 * on codeeval.com.
 * https://www.codeeval.com/public_sc/71/
 */
$fh = fopen($argv[1], "r");
//$fh = fopen('sample.txt', "r");
while (true) {
  $test = fgets($fh);
  if (empty($test)) {
    exit(0);
  }
  $op = get_reverse($test);
  echo $op . PHP_EOL;
}

function get_reverse($str) {
  $str_peices = explode(';', $str);
  $k = (int)$str_peices[1];
  $list_num = explode(',', $str_peices[0]);
  $op = array();
  if ($k <= count($list_num) && $k > 0) {
    $i = 0;
    for (; $i < count($list_num); $i += $k) {
      if ($i + $k > count($list_num)) break;
      $op = array_merge($op, array_reverse(array_slice($list_num, $i, $k)));
    }
    $op = array_merge($op, (array_slice($list_num, $i)));
  }
  else {
    return implode(',', $list_num);
  }
  return implode(',', $op);
}
?>