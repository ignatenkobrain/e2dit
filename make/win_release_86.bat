g++ MainSFML.cpp -std=gnu++11 -Wall -O3 -D_win_ -D_x86_ -ffast-math -funsafe-math-optimizations -m32 -march=native -fwhole-program -mfpmath=sse -funroll-loops -flto -ftree-vectorize -w -funroll-loops -lm -lSOIL -lglew32 -lopengl32 -lglu32 -lfreetype -lsfml-graphics -lsfml-window -lsfml-system -lftgl -mwindows -o core