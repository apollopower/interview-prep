from random import *

# Part 1 - Initialize Game Data Structures

class Tile:
    def __init__(self, hidden=True, mine=False):
        self.hidden = hidden
        self.mine = mine
        self.icon = '-'

class GameBoard:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.tiles = self.initialize_tiles()
        self.empty_tiles = width * height
    
    def initialize_tiles(self):
        tiles = [[Tile() for y in range(self.height)] for x in range(self.width)]
        return tiles
    
    # Randomly add mines throughout GameBoard
    def add_mines(self, max_mine_num):
        for i in range(max_mine_num):
            x = randint(0, self.width - 1)
            y = randint(0, self.height - 1)
            tile = self.tiles[x][y]
            if not tile.mine:
                tile.mine = True
                self.empty_tiles -= 1
    
    def update_board(self, x, y):
        tile = self.tiles[x][y]

        if not tile.mine:
            # Not a mine, calculate how many mines sorround this tile
            tile.hidden = False
            self.empty_tiles -= 1
            tile.icon = self.sorrounding_mines(x, y)
        else:
            tile.icon = '*'
            print("Game Over!")
            return False
    
    def sorrounding_mines(self, x, y):
        flag_num = 0
        above_row = [(x + 1, y - 1), (x + 1, y), (x + 1, y + 1)]
        bottom_row = [(x - 1, y - 1), (x - 1, y), (x - 1, y - 1)]
        left, right = (x, y - 1), (x, y + 1)

        for coords in above_row:
            x, y = coords
            if (x > -1 and x < self.width) and (y > -1 and y < self.height):
                if self.tiles[x][y].mine == True:
                    flag_num += 1
        
        for coords in bottom_row:
            x, y = coords
            if (x > -1 and x < self.width) and (y > -1 and y < self.height):
                if self.tiles[x][y].mine == True:
                    flag_num += 1
        
        x, y = left
        if (x > -1 and x < self.width) and (y > -1 and y < self.height):
            if self.tiles[x][y].mine == True:
                flag_num += 1
        
        x, y = right
        if (x > -1 and x < self.width) and (y > -1 and y < self.height):
            if self.tiles[x][y].mine == True:
                flag_num += 1

        return str(flag_num)


    

    def print_board(self):
        for y in range(self.height):
            for x in range(self.width):
                print(self.tiles[x][y].icon, end=" ")
            print("")

def player_wins():
    print("You win!")

def player_loses():
    print("You lose...")

game_board = GameBoard(5, 5)
game_board.add_mines(5)

game_board.print_board()

# Game introduction
print("Welcome to minesweeper!")

# Part 2 - Game Loop
while game_board.empty_tiles > 0:

    user_input = input("Please input x and y coordinates, seperated by a space, to choose a tile: ")
    coord_x, coord_y = int(user_input.split(" ")[0]), int(user_input.split(" ")[1])

    update = game_board.update_board(coord_x - 1, coord_y - 1)

    game_board.print_board()

    if update == False:
        break

# Part 3 - Player Updates
if update:
    player_wins()