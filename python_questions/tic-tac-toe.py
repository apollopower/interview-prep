# Part 1 - Initialize Game Data Structures
# Part 2 - Build Basic Game Loop
# Part 3 - Define principal functions/methods

class Player:
    def __init__(self, icon):
        self.icon = icon


class Tile:
    def __init__(self, val='-', empty=True):
        self.val = val
        self.empty = empty


class GameBoard:
    def __init__(self, size=5):
        self.width = size
        self.height = size
        self.tiles = self.init_tiles()
    
    def init_tiles(self):
        tiles = [[Tile() for y in range(self.height)] for x in range(self.width)]
        return tiles
    
    def update(self, x, y, player):
        tile = self.tiles[x][y]
        if tile.empty:
            tile.val = player.icon
            tile.empty = False
        else:
            print("Tile is already marked!")
    
    def print_board(self):
        for y in range(self.height):
            for x in range(self.width):
                tile = self.tiles[x][y]
                print(tile.val, end=" ")
            print()


x_turn = True
player_x = Player('X')
player_o = Player('O')

board = GameBoard()

board.print_board()

print("Welcome to tic-tac-toe!")

# Main Game Loop
while True:
    if x_turn:

        x_input = input("X's turn: ")
        coord_x, coord_y = int(x_input.split(" ")[0]), int(x_input.split(" ")[1])

        board.update(coord_x - 1, coord_y - 1, player_x)

        x_turn = False


    else:

        o_input = input("O's turn: ")
        coord_x, coord_y = int(o_input.split(" ")[0]), int(o_input.split(" ")[1])

        board.update(coord_x - 1, coord_y - 1, player_o)

        x_turn = True
    
    board.print_board()
