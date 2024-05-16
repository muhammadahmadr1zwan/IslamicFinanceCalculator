CXX = g++
CXXFLAGS = -std=c++11 -Wall -I.
SRCS = UserInterface.cpp LocalizationManager.cpp ExportTool.cpp \
       MurabahaCalculator.cpp IjaraCalculator.cpp MudarabaCalculator.cpp \
       ZakatCalculator.cpp SadaqahCalculator.cpp UserLoginManager.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = FinanceCalculatorApp

.PHONY: all clean run

all: $(MAIN)
	@echo "Compilation complete."

$(MAIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(MAIN)

run: $(MAIN)
	./$(MAIN)
