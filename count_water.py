ram = [4, 6, 1, 4, 6, 5, 1, 4, 1, 2, 6, 5, 6, 1, 4, 2]

left_wall = False
air = False
counting = False
complete = False
water = 0
total_water = 0

while not complete:
    left_wall = False
    counting = False
    complete = True
    water = 0
    for i in range(0, 16):
        if ram[i] == 0:
            air = True
        else:
            air = False
        # 往左碰到墙先，防止数左边的空气
        if (air == False) and (counting == False):
            left_wall = True
            complete = False
        # 碰到空气了，左边也有墙，也没开始计数
        if (air == True) and (left_wall == True) and (counting == False):
            counting = True
        # 要是在计数，碰到空气了
        if (air == True) and (counting == True):
            water = water + 1
        # 要是在计数，碰到右边墙了
        if (air == False) and (counting == True):
            total_water = total_water + water
            water = 0
            counting = False
            complete = False
    for i in range(0, 16):
        if ram[i] != 0:
            ram[i] = ram[i] - 1

print(total_water)
