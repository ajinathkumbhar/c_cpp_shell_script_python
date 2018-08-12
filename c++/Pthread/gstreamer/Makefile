BIN=apptest
SRC=app.cpp

app: $(SRC)
	g++ $(SRC) -o $(BIN) -g -std=c++11 -lpthread `pkg-config --cflags --libs gstreamer-1.0`
clean:
	rm -rf $(BIN)	
