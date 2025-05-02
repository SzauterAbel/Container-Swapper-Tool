# 🛠️ Container Swapper Tool

[![Build](https://img.shields.io/github/actions/workflow/status/SzauterAbel/Container-Swapper-Tool/ci.yml?branch=master)](https://github.com/SzauterAbel/Container-Swapper-Tool/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

**A C++ source code container replacement utility based on Clang Tooling**

## 🚧 Project Status: In Development

This tool is currently under active development.  
It can analyze C++ source files and detect STL container declarations. Actual container replacement in source files is not yet implemented.

---

## 📦 Features

- Analyze C++ source files using `clang::tooling`
- Detect standard container declarations
- Support for multiple operation modes:
  - `map-to-unordered-map`
  - `unordered-map-to-map`
  - `set-to-unordered-set`
  - `unordered-set-to-set`
  - `list-to-vector`
  - `vector-to-list`
- Verbose mode for detailed logs
- Handle multiple files in one run

---

## 📑 Usage

### Command-line arguments:
```bash
container_swapper_tool [OPTIONS] files...