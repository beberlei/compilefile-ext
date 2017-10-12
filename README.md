# compilefile Extension

**EXPERIMENTAL**

This extension provides a single function `compile_file` that accepts a single
argument of a file path, that then gets compiled into the PHP engine without
executing its code. In that regard it uses the internals for require/include
and then throws away executable code.

The primary use case is making the PHP  internal Reflection API available to
static analysis tools without the risk of accidently executing code that causes
side-effects.

```php
<?php

class Foo
{
}

echo "Should not be executed";
```

```php
<?php

compile_file(__DIR__ . '/test.php');

var_dump(class_exists("Foo"));
var_dump(new \ReflectionClass("Foo"));
var_dump(new Foo());
```

Prints:

```
bool(true)
object(ReflectionClass)#1 (1) {
  ["name"]=>
  string(3) "Foo"
}
object(Foo)#%d (0) {
}
```
