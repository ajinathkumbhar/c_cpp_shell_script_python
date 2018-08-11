BIN=apptest
SRC=app.cpp

app: $(SRC)
	g++ $(SRC) -o $(BIN) -lpthread `pkg-config --cflags --libs gstreamer-1.0`
clean:
	rm -rf $(BIN)	
