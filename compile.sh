if g++ -o hello main.cpp Ground.cpp Body.cpp Axis.cpp Poly.cpp ContactListener.cpp \
    -lbox2d \
    -lsfml-graphics -lsfml-window -lsfml-system \
    -pedantic-errors -Wall -Wextra -Weffc++; then
    echo "compiled successfully"
    # ./hello
fi
#-Weffc++
# -Wsign-conversion
