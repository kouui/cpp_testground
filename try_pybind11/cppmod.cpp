#include<pybind11/pybind11.h>
#include<pybind11/numpy.h>
#include<algorithm>
namespace py = pybind11;

auto npadd(py::array_t<double> arr, const double v) {
    const auto size = arr.size();
    py::array_t<double> ret(size);
    std::transform(
        arr.data(),arr.data()+size,
        ret.mutable_data(), [v](auto e) { return e+v; });
    return ret;
}

PYBIND11_MODULE(cppmod, m) {
    m.doc() = "pybind11 example plugin";
    m.def("npadd", &npadd, "A function which adds scalar to ndarray");
}
