--TEST--
compilefile: Compile File then include
--FILE--
<?php

compile_file(__DIR__ . '/test2.php');

include __DIR__ . '/test2.php';

--EXPECTF--
Hello World!
