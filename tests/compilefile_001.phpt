--TEST--
compilefile: Extensions exists
--FILE--
<?php

echo phpversion("compilefile");
--EXPECTF--
0.1.0
