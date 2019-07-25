# try_pybind11
this is a repository shows how to use pybind11 to interact c++ and python

aboud pybind11: [https://github.com/pybind/pybind11](https://github.com/pybind/pybind11)

two articals illustrating how to use pybind11:

  1. [pybind11でC++の関数をpythonから使う](https://qiita.com/ignis_fatuus/items/c7523c0fe2bc2f415d50)

  2. [[python高速化]pybind11によるc++組み込み](https://qiita.com/exy81/items/e309df7e33d4ff20a91a#_reference-c8a52580111447fade09), need modification, for example:

  ```
  PYBIND11_PLUGIN(mylibs) {
  py::module m("mylibs", "mylibs made by pybind11");
  m.def("add", &add);
  m.def("vec_double", &vec_double);
  m.def("vec_add", &vec_add);

  py::class_<POINT>(m, "POINT")
      .def_readwrite("sum", &POINT::sum)
      .def(py::init<int, int>())
      .def("X", &POINT::X)
      .def("Y", &POINT::Y);
  m.def("move_p", &move_p);

  return m.ptr();
  }
  ```

  to

  ```
  PYBIND11_MODULE(mylibs, m) {
  m.doc() = "mylibs made by pybind11";
  m.def("add", &add);
  m.def("vec_double", &vec_double);
  m.def("vec_add", &vec_add);

  py::class_<POINT>(m, "POINT")
      .def_readwrite("sum", &POINT::sum)
      .def(py::init<int, int>())
      .def("X", &POINT::X)
      .def("Y", &POINT::Y);
  m.def("move_p", &move_p);
  }
  ```
    
## install pybind11 on macOS

the easiest way to install pybind11 is using `pip`, with `pip` you even don't need to setup the path. If you install it with `git clone ...`, than you need to setup the path for pybind11's header files.

```
$ pip install pybind11
```

## how to write .cpp/.h files

see each example

[official illustration](http://pybind11.readthedocs.io/en/master/basics.html#header-and-namespace-conventions)

## how to compile .cpp files to .so shared library

see each example.

basically, on linux you execute

```
$ c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`
```

on macOS you need to add flag `-undefined dynamic_lookup` to ignore missing symbols

```
$ c++ -O3 -Wall -shared -std=c++14 -undefined dynamic_lookup `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`
```

[more details on the required compiler flags on Linux and MacOS](http://pybind11.readthedocs.io/en/master/compiling.html#building-manually)

