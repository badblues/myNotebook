all:
	g++ $(FLAGS) main.cpp io.cpp shared.cpp menu.cpp -o progress_bar.exe

FLAGS = -Wall -Werror -Wextra