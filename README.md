# Temperature
Control your CPU temperature

## Installation

### Dependencies

You'll need the following dependencies to build:

* libgranite-dev
* libgtk-3-dev
* meson
* valac

### Building

```bash
meson build --prefix=/usr
cd build
ninja
```

### Installing & executing

To install, use `ninja install`, then execute with `com.github.artempopof.temperature`.

```bash
sudo ninja install
com.github.artempopof.temperature
```
