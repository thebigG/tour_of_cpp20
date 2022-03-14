[![Build](https://github.com/thebigG/tour_of_cpp20/actions/workflows/ci.yaml/badge.svg)](https://github.com/thebigG/tour_of_cpp20/actions/workflows/ci.yaml)
# tour_of_cpp20
Exploring `C++20` and using [Tour Of C++](https://www.stroustrup.com/tour2.html) as a guide.

# Building
```
docker pull thebigg1/cpp20-linux:latest
docker run -it thebigg1/cpp20-linux:latest bash
git clone https://github.com/thebigG/tour_of_cpp20.git
mkdir build
cd build
cmake ..
make
./tour_of_cpp20
```
