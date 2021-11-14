import cs50

# Ask user for change owed
answer1 = cs50.get_float("Change owed: ")
# make sure input is positive value
while answer1 < 0.001:
    answer1 = cs50.get_float("Change owed: ")

# make answer an int because of floating point imprecsion
answer = round(answer1 * 100)

# make a counter variable
counter = 0

# run through each coin value until answer is lower than the highest coin
while answer >= 25:
    answer -= 25
    counter += 1

while answer >= 10:
    answer -= 10
    counter += 1

while answer >= 5:
    answer -= 5
    counter += 1

while answer >= 1:
    answer -= 1
    counter += 1

print(counter)