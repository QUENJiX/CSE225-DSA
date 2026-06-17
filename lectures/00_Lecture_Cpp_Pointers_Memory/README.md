# Lecture 0: C++ OOP, Templates, and Dynamic Arrays

Source deck: `Lec_CPlusPlus.pptx`

This folder turns the lecture snippets into runnable C++ study files. A few slide typos were fixed
while preserving the intended concepts, for example `int main()` instead of `void main()`, normal
quotes instead of curly quotes, and `getValue()` where the slide had `get()`.

## Files

- `01_console_io.cpp` - `cout`, `printf`, `cin`, and `scanf` style examples.
- `02_box_class.cpp` - first class/object example using a `Box`.
- `03_constructor_destructor.cpp` - constructor and destructor timing.
- `04_copy_constructor_deep_copy.cpp` - why pointer-owning classes need deep copy.
- `05_inheritance_access.cpp` - public/protected/private inheritance access.
- `06_static_friend.cpp` - static members plus friend function/class access.
- `07_function_overloading.cpp` - valid overloads and overload selection.
- `08_template_functions.cpp` - generic functions and explicit overload preference.
- `09_dynarr_int.h`, `09_dynarr_int.cpp`, `09_dynarr_int_driver.cpp` - integer dynamic array.
- `10_dynarr_template.h`, `10_dynarr_template.cpp`, `10_dynarr_template_driver.cpp` - template dynamic array.

## Compile Examples

From this folder:

```powershell
g++ -std=c++17 -Wall -Wextra 02_box_class.cpp -o box_class
g++ -std=c++17 -Wall -Wextra 09_dynarr_int.cpp 09_dynarr_int_driver.cpp -o dynarr_int
g++ -std=c++17 -Wall -Wextra 10_dynarr_template_driver.cpp -o dynarr_template
```

The template driver includes `10_dynarr_template.cpp` directly because templates need their
definitions visible when the compiler instantiates `dynArr<int>` and `dynArr<double>`.
