#ifndef DEFINES_H
#define DEFINES_H

enum class Direction {
    SOUTH, EAST, NORTH, WEST
};

enum TileType {
    END_MARKER = 'S',
    START_MARKER = '@',
    TELEPORT = 'T',
    INVERTER = 'I',
    OBSTACLE = 'X',
    END_OF_MAP = '#',
    BEER = 'B',
    SOUTH_TYPE = 'S',
    EAST_TYPE = 'E',
    NORTH_TYPE = 'N',
    WEST_TYPE = 'W'
};

#endif // !DEFINES_H
