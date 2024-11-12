#!/usr/bin/bash

rm -f ../../shaders/~

glslc shader.vert -o ../../shaders/vert.spv
glslc shader.frag -o ../../shaders/frag.spv