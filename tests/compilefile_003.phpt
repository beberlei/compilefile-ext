--TEST--
compilefile: Compile File then include
--FILE--
<?php

compile_file(__DIR__ . '/test.php');

include __DIR__ . '/test.php';

var_dump(class_exists("Foo"));
var_dump(new \ReflectionClass("Foo"));
--EXPECTF--
Fatal error: Cannot declare class Foo, because the name is already in use %s
