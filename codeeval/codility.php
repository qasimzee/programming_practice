<?php

function aksort(&$array,$valrev=false,$keyrev=false) {
  if ($valrev) { arsort($array); } else { asort($array); }
    $vals = array_count_values($array);
    $i = 0;
    foreach ($vals AS $val=>$num) {
        $first = array_splice($array,0,$i);
        $tmp = array_splice($array,0,$num);
        if ($keyrev) { krsort($tmp); } else { ksort($tmp); }
        $array = array_merge($first,$tmp,$array);
        unset($tmp);
        $i = $num;
    }
}  

function countTheString($str, $k) {
  $radix = array();
  $ret_arr = array();
  foreach (count_chars($str, 1) as $i => $val) {
    if ($val > $k) {
      $ret_arr[chr($i)] = $val;
    }
  }
  aksort($ret_arr, TRUE);
  
  return implode('', array_keys($ret_arr));
}

//$fp = fopen("php://stdin", "r");
$fp = fopen("sample.txt", "r");

$N = fgets($fp);
for ($i = 0; $i < $N; $i++) {
  $line1 = fgets($fp);
  $line1_parts = explode(' ', $line1);
  if ($line1_parts[0]) {
    $str = fgets($fp);
    $str = substr($str, 0, $line1_parts[0]);
    $ret = countTheString($str, $line1_parts[1]);
    echo ($ret ? $ret : 'NONE');
    if ($i < $N-1) {
      print PHP_EOL;
    }
  }
  
}


?>