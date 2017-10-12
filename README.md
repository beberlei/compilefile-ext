# compilefile Extension

**EXPERIMENTAL**

This extension provides a single function `compile_file` that accepts a single
argument of a file path, that then gets compiled into the PHP engine without
executing its code. In that regard it uses the internals for require/include
and then throws away executable code.
