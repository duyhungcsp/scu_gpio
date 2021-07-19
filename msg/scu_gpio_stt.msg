Header header

# BOARD_PIN_STT[x] is set with different values corresponding to different status:
#   BOARD_PIN_STT[x] = -1: unchange
#   BOARD_PIN_STT[x] = 0: output LOW
#   BOARD_PIN_STT[x] = 1: output HIGH
#   BOARD_PIN_STT[x] = 20: input LOW
#   BOARD_PIN_STT[x] = 21: input HIGH
#   BOARD_PIN_STT[x] = 3: alternative function

# Pin number 1 to 40 (skip index 0)
int8[41] BOARD_PIN_STT