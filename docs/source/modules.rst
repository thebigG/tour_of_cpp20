Modules
=========================================

Modules in C++20 are meant to replace header files. This is not meant to be official documentation on this subject but rather brief
and practical notes on them for myself and others that might be interested in using modules.
There are many examples in the repo that use modules. The simplest one is probably `Chapter2`'s module interface.

.. literalinclude:: ../../src/chapter2.cxx
    :language: C++

Notice I used the word `interface`. That's because modules have a couple of ways of separating the implementation and
interface. Very much like header files, except it's not done by the pre-processor and does not have the potential
of slowing down compilation. Below is the implementation of `Chapter2`.

.. literalinclude:: ../../src/chapter2_impl.cxx
    :language: C++
