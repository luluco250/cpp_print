# ***cpp_print***
## Simple python-like *print()* wrapper for *std::cout*

Defines a print() function that can receive
any number of arguments and them to *std::cout*.

You can specify end and separator
characters through template arguments:

```
print<end_character, separator_character>(...);
```

An if condition is used to make sure no character
is output when end or sep are zeroed, as passing **'\0'**
to cout on Windows inserts a space instead of nothing.

**This if condition is constant**, it does not make any
difference in the assembly, thus no performance impact.
The *constexpr* keyword is used if C++17 support is detected.

## Examples:
```
print("Hello World");

output:
    Hello World
```
```
print("Foo:", 123);
print("Bar:", 69);

output:
    Foo: 123
    Bar: 69
```
```
print<'\n'>("Test");
print<'\n'>("Memes");

output:
    Test
    Memes
```
```
print<0>("Cat");
print("dog");
print<'s'>();

output:
    Catdog
    s
```
```
int a = 10, b = 5;
print<'\n', ' '>("a:", a, "b:", b);

output:
    a: 10 b: 5
```
```
print<'\n', 0>("X: ", 3, ", Y: ", 7);

output:
    X: 3, Y: 7
```
```
string john = "John";
string doe = "Doe";
print<0, 0>("1:", john, doe);
print("...");

output:
    1:JohnDoe...
```
