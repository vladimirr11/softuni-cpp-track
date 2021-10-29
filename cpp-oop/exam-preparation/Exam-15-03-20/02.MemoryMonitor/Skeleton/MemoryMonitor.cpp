#include "MemoryMonitor.h"

#include <iostream>

MemoryMonitor::MemoryMonitor() {}

MemoryMonitor::~MemoryMonitor() {}

void MemoryMonitor::pushNode(const int nodeSize) {
    MemoryNode mNode;
    mNode.size = nodeSize;
    mNode.data = new int[nodeSize];

    this->_nodes.push_back(mNode);

    std::cout << "Pushed node with memory occupation: " << (nodeSize * 4) << std::endl;
}

void MemoryMonitor::popNode() {
    if (!this->_nodes.empty()) {
        MemoryNode mNode = MemoryMonitor::getLastNode();
        this->_nodes.pop_back();

        std::cout << "Popped node with memory occupation: " << (mNode.size * 4) << std::endl;

        delete[] mNode.data;

    } else {
        std::cout << "No nodes to pop" << std::endl;
    }
}

void MemoryMonitor::printMemoryOccupation(const int numberOfNodes) {
    int numNodes = numberOfNodes;
    if (numberOfNodes > _nodes.size()) {
        numNodes = _nodes.size();
    }

    int memoryOccupation = 0;
    for (int i = 0; i < numNodes; i++) {
        memoryOccupation += (_nodes[i].size * 4);
    }

    std::cout << "Memory occupation for first " << numberOfNodes << " memory nodes is: " << memoryOccupation << std::endl;
}

MemoryNode MemoryMonitor::getLastNode() const {
    return this->_nodes.back();
}
