# cmake-cpp-template

simple c++ & cmake project template for Linux with various features

## Features

- **CMake** build system for C++ projects
- C++ formatting with **[clang-format](https://clang.llvm.org/docs/ClangFormat.html)**
- CMake formatting with **[cmake-format](https://cmake-format.readthedocs.io/en/latest/)**
- Static code analysis with **[cppcheck](https://cppcheck.sourceforge.io/) & [clang-tidy](https://clang.llvm.org/extra/clang-tidy/)**
- Project configuration with **[Kconfiglib](https://pypi.org/project/kconfiglib/)**
- Documentation generation with **[MkDocs](https://www.mkdocs.org/)**, **[mkdocs-material](https://github.com/squidfunk/mkdocs-material)** theme with **[Github Pages](https://pages.github.com/)** deployment
- Testing with **[Catch2](https://github.com/catchorg/Catch2)**
- Automatic version header generation with **[Parse git tag](/cmake/parse_git_tag.cmake)**
- Install & Uninstall targets

## Pre-requisites

Every Dependency in this section is optional

CMake >= 3.12

C++ formatting:

```bash
sudo apt install clang-format
```

CMake formatting:

```bash
pip3 install cmake-format
```

Static code analysis:

```bash
sudo apt install cppcheck clang-tidy
```

Kconfig:

```bash
pip3 install kconfiglib
```

Documentation generation:

```bash
pip3 install mkdocs mkdocs-material pymdown-extensions
```

Testing:

- Install appropriate version of **Catch2** by dpkg or source build

### All dependencies can be installed by running the following command

```bash
sudo apt install clang-format cppcheck clang-tidy
pip3 install cmake-format kconfiglib mkdocs mkdocs-material pymdown-extensions
```

## Getting Started

Use this repository as a [template repository in github](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-template-repository) or clone this repository

Automatic setup

```bash
# prepare template for your project
# set PROJECT_NAME to your project name. Without space(" ")
make prepare_template PROJECT_NAME=$(PROJECT_NAME) 
```

Manual setup

- Change cmake/cpp-cmake-templateConfig.cmake.in to cmake/$(PROJECT_NAME)Config.cmake.in
- Change include/cpp-cmake-template to include/$(PROJECT_NAME)
- Replace 'cpp-cmake-template' to '$(PROJECT_NAME)' of CMakeLists.txt

## Documentation Generation

[**MkDocs tutorial**](https://www.mkdocs.org/getting-started/)

Go to the settings of your repository and ensure that the [publishing source branch](https://docs.github.com/en/pages/getting-started-with-github-pages/configuring-a-publishing-source-for-your-github-pages-site) for your GitHub Page is set to gh-pages

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Contact

lightAxis - <jisuk500@gmail.com>
