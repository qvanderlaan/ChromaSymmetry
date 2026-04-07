# ChromaSymmetry

ChromaSymmetry is a C++98 procedural image generator designed to render complex mathematical spirals at ultra-high resolutions. By leveraging supersampling (SSAA) and smooth-edge falloff algorithms, it produces high-fidelity, vibrant imagery saved in the PPM format.

## Features

- **High Resolution:** Default output at 5K (5120x2880).
- **Supersampling:** 5x hardware-independent supersampling for superior anti-aliasing.
- **Color Logic:** Implementation of the Sextant Sector method for precise HSV-to-RGB conversion.
- **Mathematical Precision:** Uses sine-modulated radius functions for organic patterns.

## Installation & Usage

1. **Build the project:**
   ```bash
   make
   ```

2. **Run the generator:**
   ```bash
   ./spiral_gen
   ```

3. **View the output:**
   The program generates `output.ppm`. Open this file using Photoshop, GIMP, or an online PPM viewer.

## Project Structure

- `src/`: Implementation files (.cpp)
- `include/`: Header files (.hpp)
- `Makefile`: Build configuration
- `build/`: Temporary object files

## Configuration

You can modify the resolution and supersampling intensity in `src/main.cpp`:

```cpp
Renderer engine(5120, 2880, 5);
```

*Note: High supersampling levels (5+) provide extreme sharpness but require more RAM and processing time.*
