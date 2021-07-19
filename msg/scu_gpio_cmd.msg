Header header

# BOARD_PIN_SET[x] is set with different values corresponding to different status:
#   BOARD_PIN_SET[x] = -1: unchange
#   BOARD_PIN_SET[x] = 0: output LOW
#   BOARD_PIN_SET[x] = 1: output HIGHT
#   BOARD_PIN_SET[x] = 2: input
#   BOARD_PIN_SET[x] = 3: alternative function

# Pin number 1 to 40 (skip index 0)

int8[41] BOARD_PIN_SET