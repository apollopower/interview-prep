# 1) Initialize main data structs
# 2) Outline game loop
# 3) Define functions/methods

# Board
# Ship
# Tile
# Player

from random import randint

class Tile:
    def __init__(self, empty=True, icon='~'):
        self.empty = empty
        self.icon = icon


class GameBoard:
    def __init__(self, width=20, height=15):
        self.width = width
        self.height = height
        self.tiles = self.init_tiles()
    
    def init_tiles(self):
        tiles = [[Tile() for y in range(self.height)] for x in range(self.width)]
        return tiles
    
    def place_ships(self, player):
        ships = player.ships
    
    def print_board(self):
        for y in range(self.height):
            for x in range(self.width):
                tile = self.tiles[x][y]
                print(tile.icon, end=" ")
            print()


class Ship:
    def __init__(self, width=1, height=3):
        self.width = width
        self.height = height

class Player:
    def __init__(self):
        self.ships = self.init_ships()
    
    def init_ships(self, num_of_ships=3):
        ships = [Ship() for i in range(num_of_ships)]
        return ships
        

player_1 = Player()
player_2 = Player()

board_1 = GameBoard()
board_2 = GameBoard()

board_1.print_board()
