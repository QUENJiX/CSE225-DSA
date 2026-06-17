# C++ OOP For Someone Who Knows Java

## Similar Ideas

- `class`, `private`, `public`, constructors, methods, inheritance, overriding, and interfaces/abstract classes all have close C++ equivalents.
- `virtual` methods in C++ are like Java methods that can be overridden dynamically.
- Abstract classes use at least one pure virtual function: `virtual void draw() = 0;`.

## Big Differences

- C++ objects can live on the stack. Java objects live through references.
- C++ has deterministic destructors. Java has garbage collection.
- C++ copy behavior matters. Passing an object by value can copy it.
- C++ has references (`T&`) and pointers (`T*`).
- C++ has multiple inheritance, but use it carefully.
- C++ has `const` methods: `int size() const`.
- C++ templates are compile-time generics and are more powerful than Java generics.

## Mental Translation

```cpp
Animal a;              // actual object on stack
Animal* p = new Dog;   // pointer; delete needed unless using smart pointer
unique_ptr<Animal> p;  // owning smart pointer
Animal& r = a;         // reference alias
```

Prefer normal objects, references, `vector`, and smart pointers before raw `new` and `delete`.

