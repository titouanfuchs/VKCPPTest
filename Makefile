CFLAGS = -std=c++20
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

all: VulkanCPPTest

VulkanCPPTest: main.cpp
	g++ $(CFLAGS) -o VulkanCPPTest main.cpp $(LDFLAGS)

.PHONY: test clean

test: VulkanCPPTest
	./VulkanCPPTest

clean:
	rm -f VulkanCPPTest