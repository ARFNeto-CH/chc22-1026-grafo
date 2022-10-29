
Here I changed

```C
template<typename T>
Node* LinkedList<T>::Find(const T& val) {
```
to 

```C
template<typename T>
LinkedList<T>::Node* LinkedList<T>::Find(const T& val) {
```

as `Node` is also templated. The compiler said:

```none
1>v1.cpp
1>C:\SO\v1.cpp(93,1): warning C4346: 'Node': dependent name is not a type
1>C:\SO\v1.cpp(93,1): message : prefix with 'typename' to indicate a type
1>C:\SO\v1.cpp(93,16): error C2061: syntax error: identifier 'Node'
1>C:\SO\v1.cpp(93,1): error C2143: syntax error: missing ';' before '{'
1>C:\SO\v1.cpp(93,1): error C2447: '{': missing function header (old-style formal list?)
1>Done building project "sop22-1026-compile.vcxproj" -- FAILED.
```

And as the compiler said I added `typename` prefix and it made it happy.

```C
1>v1.cpp
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```


I am using MS Compiler v. 19.33 and now I can not test in another env.




