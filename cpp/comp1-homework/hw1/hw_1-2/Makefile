# 컴파일러 설정
CXX = g++
CXXFLAGS = -Wall -std=c++11

# 소스 파일 목록
SOURCES = jsoncpp.cpp main.cpp functions.cpp

# 헤더 파일 디렉토리 추가
INCLUDES = -I.

# 타겟 이름 설정
TARGET = main

# 오브젝트 파일 목록
OBJECTS = $(SOURCES:.cpp=.o)

# 규칙 작성
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)