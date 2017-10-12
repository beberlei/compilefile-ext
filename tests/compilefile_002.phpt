--TEST--
compilefile: Compile File without executing
--FILE--
<?php

compile_file(__DIR__ . '/test.php');

var_dump(class_exists("Foo"));
var_dump(new \ReflectionClass("Foo"));
var_dump(new Foo());
--EXPECTF--
bool(true)
object(ReflectionClass)#1 (1) {
  ["name"]=>
  string(3) "Foo"
}
object(Foo)#%d (0) {
}
