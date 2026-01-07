# Setup Instructions

## Prerequisites

You'll need the following software installed:

### Required Tools

1. **C++ Compiler** (g++ or clang)
2. **Emscripten SDK** (emcc) - for WebAssembly compilation
3. **Python 3** - for local web server
4. **Make** - for build automation
5. **Git** - for version control

## Installation (Arch Linux)

### C++ Compiler

```bash
# Likely already installed, but just in case:
sudo pacman -S gcc
```

Verify:
```bash
g++ --version
# Should show version 9.0 or higher
```

### Emscripten SDK

Option 1 - From AUR:
```bash
yay -S emscripten
```

Option 2 - From source (recommended for latest version):
```bash
# Clone the emsdk repository
git clone https://github.com/emscripten-core/emsdk.git ~/emsdk
cd ~/emsdk

# Install and activate the latest SDK
./emsdk install latest
./emsdk activate latest

# Add to your shell profile (bash/zsh)
echo 'source "$HOME/emsdk/emsdk_env.sh"' >> ~/.bashrc  # or ~/.zshrc
source ~/.bashrc  # or source ~/.zshrc
```

Verify:
```bash
emcc --version
# Should show emscripten version info
```

### Python 3

```bash
# Likely already installed:
sudo pacman -S python
```

Verify:
```bash
python --version
# Should show Python 3.x
```

### Make

```bash
# Likely already installed:
sudo pacman -S make
```

Verify:
```bash
make --version
# Should show GNU Make info
```

## Verification

Run all verifications:

```bash
g++ --version
emcc --version
python --version
make --version
```

All commands should complete without errors.

## Project Setup

Clone or navigate to the project:

```bash
cd /path/to/wasmt
```

Test the build system:

```bash
make help
```

You should see a list of available make targets.

## Troubleshooting

### Emscripten not found

If `emcc` is not found after installation:

```bash
# Make sure emsdk_env.sh is sourced
source ~/emsdk/emsdk_env.sh

# Or add to your shell profile permanently
echo 'source "$HOME/emsdk/emsdk_env.sh"' >> ~/.bashrc
```

### Python command not found

Some systems use `python3` instead of `python`. Update the Makefile:

```makefile
# Change this line in Makefile:
serve:
	@python3 -m http.server 8000
```

### Permission denied on make targets

Make sure files are executable:

```bash
chmod +x build/native/*
```

## Next Steps

Once all tools are installed and verified, proceed to [QUICKSTART.md](QUICKSTART.md) to begin Task 01!
