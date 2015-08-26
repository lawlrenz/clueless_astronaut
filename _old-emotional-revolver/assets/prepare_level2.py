import sys
import os

infile = sys.argv[1]

if not os.path.exists(infile):
	print '%s does not exist' % infile

def apply_to_level(level, ca):
	new_level = []
	for line in level:
		j = 0
		new_line = []
		for c in line:
			new_line.append(ca(c, j))
			j += 1
		new_level.append(new_line)
	return new_level

# transpose level
level = []
lines = [ x.strip() for x in open(infile) if x.strip() ]
for i in range(len(lines[0])):
	new_line = []
	for line in lines:
		if i < len(line): new_line.append(line[i])
		else: new_line.append('X')
	level.append(new_line)

# prepare container

# prepare dark bottom
#level = apply_to_level(level, lambda x, height: '_' if x == ' ' and height > 15 else x)

# apply mapping
mapping = {
	'I': '2 1103,3 1',
	'X': '1 2901',
	' ': '2 3006',
	'_': '2 0100',
	'm': '1 0204',
	'1': '2 1102',
	'2': '2 1103',
	'3': '2 1202',
	'4': '2 1203',
}

level = apply_to_level(level, lambda x, height: mapping[x])

for line in level:
	print ';'.join(line)

