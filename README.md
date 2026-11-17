# luna

Compiler for the Luna language to Lua, targeting LuaJIT.

## Build

```bash
# Initialize and build
./prepare.sh
cmake --build build/debug
cmake --build build/release

# Or manually with presets
cmake --preset debug && cmake --build build/debug
cmake --preset release && cmake --build build/release
```

## Run

```bash
./build/debug/luna
./build/release/luna

./build/debug/luna --help
./build/debug/luna --name NAME
```

## Tags

```bash
make tags
```
