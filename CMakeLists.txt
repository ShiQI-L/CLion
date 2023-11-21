cmake_minimum_required(VERSION 3.24)
project(CLion C)

set(CMAKE_C_STANDARD 99)

add_executable(CLion main.c demo.c LeetCode.c dataStructure/dataStructure.c
        dataStructure/DoubleLoopLinkedList.c
        dataStructure/SingleLinkedList.c
        dataStructure/DoubleLinkedList.c
        dataStructureTest.c
        tools.c
        dataStructure/Stack.c
        dataStructure/Queue.c
        dataStructure/CircularQueues.c
        dataStructure/StringKMP.c
        dataStructure/BinaryTree.c
        dataStructure/InThreadTree.c
        dataStructure/PreThreadTree.c
        dataStructure/PostThreadTree.c
        dataStructure/BinarySearchTree.c
        dataStructure/AVGBinaryTree.c
        dataStructure/HuffManTree.c
        dataStructure/RedBlackTree.c
        dataStructure/SortAlgorithm.c
)
